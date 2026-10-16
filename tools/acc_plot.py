import sys
import time
import serial
import pyqtgraph as pg
from pyqtgraph.Qt import QtCore

PORT = sys.argv[1] if len(sys.argv) > 1 else "/dev/ttyUSB0"
BAUD = 115200
FENSTER_S = 5          # so viele Sekunden zeigt das Live-Fenster
INTERVALLS_MS = 20

ser = serial.Serial(PORT, BAUD, timeout=0)
zeiten = []            # Sekunden seit Start
werte = []             # Messwert zur jeweiligen Zeit
puffer = b""
t0 = time.perf_counter()
letzte_zeit = 0.0
folgen = True          # True: Fenster läuft mit, False: du schaust dir etwas Altes an

pg.setConfigOptions(antialias=True)   # muss VOR dem Erzeugen des Fensters stehen

app = pg.mkQApp("Beschleunigung")
win = pg.GraphicsLayoutWidget(show=True, title="Beschleunigung")
win.resize(1000, 600)

plot = win.addPlot(title="Beschleunigung in m/s²")
plot.showGrid(x=True, y=True)
plot.setLabel("bottom", "Zeit in s")
plot.setLabel("left", "Beschleunigung in m/s²")
plot.setAutoVisible(y=True)           # Y-Achse passt sich nur dem sichtbaren Ausschnitt an
plot.enableAutoRange(axis="y")
kurve = plot.plot(pen='y')
kurve.setClipToView(True)             # nur zeichnen, was im Fenster liegt
kurve.setDownsampling(auto=True, method="peak")


def update():
    global puffer, letzte_zeit
    puffer += ser.read(ser.in_waiting)
    *zeilen, puffer = puffer.split(b"\n")

    neue = []
    for zeile in zeilen:
        try:
            neue.append(float(zeile.decode(errors="ignore")))
        except ValueError:
            pass                      # Textzeilen überspringen

    # Mehrere Zeilen in einem Durchlauf: Zeit gleichmäßig dazwischen verteilen
    jetzt = time.perf_counter() - t0
    for i, wert in enumerate(neue, start=1):
        zeiten.append(letzte_zeit + (jetzt - letzte_zeit) * i / len(neue))
        werte.append(wert)
    letzte_zeit = jetzt

    if not neue:
        return
    kurve.setData(zeiten, werte)
    if folgen:
        plot.setXRange(zeiten[-1] - FENSTER_S, zeiten[-1], padding=0)


def manuell_bewegt(*args):
    # Maus hat verschoben oder gezoomt: nicht mehr automatisch mitlaufen
    global folgen
    folgen = False


def klick(ev):
    # Doppelklick: zurück zur Live-Ansicht
    global folgen
    if ev.double():
        folgen = True


plot.getViewBox().sigRangeChangedManually.connect(manuell_bewegt)
win.scene().sigMouseClicked.connect(klick)

timer = QtCore.QTimer()
timer.timeout.connect(update)
timer.start(INTERVALLS_MS)

pg.exec()
