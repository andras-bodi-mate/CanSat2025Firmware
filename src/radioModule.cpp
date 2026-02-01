#include <Arduino.h>
#include "radioModule.hpp"

RadioModule::RadioModule(Pin rxPin, Pin txPin)
    : rxPin(rxPin), txPin(txPin) {}

void RadioModule::begin() {
    // Initialize hardware UART for the LoRa module
    Serial2.begin(9600, SERIAL_8N1, rxPin, txPin);
    if (!Serial2) {
        Serial.println("Error: Serial2 initialization failed!");
        return;
    }
    Serial2.println("MODE:UPLOAD"); // configure module to upload mode
    Serial.println("LoRa module initialized in UPLOAD mode.");
}

void RadioModule::sendPrimaryData(float temperature, float pressure) {
    if (!Serial2) {
        Serial.println("Error: Serial2 not initialized!");
        return;
    }
    Serial2.print("TEMP:");
    Serial2.print(temperature, 2);
    Serial2.print(",PRESS:");
    Serial2.println(pressure, 2);
    Serial.println("Primary data sent: TEMP and PRESSURE.");
}

void RadioModule::sendSecondaryData(Position position) {
    if (!Serial2) {
        Serial.println("Error: Serial2 not initialized!");
        return;
    }
    Serial2.print("LAT:");
    Serial2.print(position.latitude, 6);
    Serial2.print(",LON:");
    Serial2.print(position.longitude, 6);
    Serial2.print(",ALT:");
    Serial2.println(position.altitude, 2);
    Serial.println("Secondary data sent.");
}

void RadioModule::setRadioFrequency(RadioFrequency radioFrequency) {
    if (!Serial2) {
        Serial.println("Error: Serial2 not initialized!");
        return;
    }
    switch (radioFrequency) {
        case RadioFrequency::A:
            Serial2.println("FREQ:000"); // example frequency in kHz
            Serial.println("Radio frequency set to 000 kHz.");
            break;
        case RadioFrequency::B:
            Serial2.println("FREQ:868"); // example frequency in kHz
            Serial.println("Radio frequency set to 868 kHz.");
            break;
        default:
            Serial2.println("FREQ:433");
            Serial.println("Radio frequency set to 433 kHz.");
            break;
    }
}