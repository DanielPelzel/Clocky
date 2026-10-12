#include "Rfid.h"
#include "config.h"
#include <SPI.h>
#include <MFRC522v2.h>
#include <MFRC522DriverSPI.h>
#include <MFRC522DriverPinSimple.h>
#include <MFRC522Debug.h>

MFRC522DriverPinSimple ssPin(RFID_SS);
MFRC522DriverSPI driver{ssPin};
MFRC522 rfid{driver};

bool Rfid::init() {
    // SPI vor PCD_Init mit eigenen Pins starten; der spätere SPI.begin()
    // in der Bibliothek ändert dann nichts mehr daran.
    SPI.begin(RFID_SCK, RFID_MISO, RFID_MOSI, RFID_SS);
    bool ok = rfid.PCD_Init();
    // Zeigt die Chip-Version: 0x91 oder 0x92 = RC522 antwortet,
    // 0x00 oder 0xFF = keine Verbindung (Verkabelung pruefen)
    MFRC522Debug::PCD_DumpVersionToSerial(rfid, Serial);
    return ok;
}

bool Rfid::is_close() {
    return rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial();
}

void Rfid::update() {

    if (is_close()) {
        lastTime=millis();
        if (!tagDa) {
            Serial.println("Tagging erkannt");
            tagDa=true;
        }

    }

    if (tagDa && millis()-lastTime > 500) {
        Serial.println("tag entfernt");
        tagDa=false;
    }
}