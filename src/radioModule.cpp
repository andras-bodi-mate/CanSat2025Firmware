#include <Arduino.h>
#include "radioModule.hpp"

String RadioModule::stringToHexStr(String str) {
    String out;
    for (char c : str) {
        out += String(c, HEX);
    }
    return out;
}

void RadioModule::sendMessage(String message) {
    String command = "radio tx " + stringToHexStr(message) + " 1\r\n";
    radioSerial.write(command.c_str());
    messageIndex++;
}

RadioModule::RadioModule(Pin rxPin, Pin txPin)
    : rxPin(rxPin), txPin(txPin), radioSerial(1) {}

void RadioModule::begin() {
    // Initialize hardware UART for the LoRa module
    radioSerial.begin(115384, SERIAL_8N1, rxPin, txPin);
    if (!radioSerial) {
        Serial.println("Error: radioSerial initialization failed!");
        return;
    }
    Serial.println("LoRa module initialized.");
}

void RadioModule::sendPrimaryData(float temperature, float pressure) {
    if (!radioSerial) {
        Serial.println("Error: radioSerial not initialized!");
        return;
    }
    char buffer[RadioModule::primaryDataSize]{};
    snprintf(buffer, RadioModule::primaryDataSize - 1, "[%i](%i)/1,%.2f,%.2f", messageIndex, millis(), temperature, pressure);
    sendMessage(buffer);
    Serial.println("Primary data sent: Temperature and pressure.");
}

void RadioModule::sendSecondaryData(ClimateData climateData, GpsData gpsData) {
    if (!radioSerial) {
        Serial.println("Error: radioSerial not initialized!");
        return;
    }
    char buffer[RadioModule::secondaryDataSize]{};
    snprintf(buffer, RadioModule::secondaryDataSize - 1, "[%i](%i)/2,%s,%.2f,%.2f,%.2f", messageIndex, millis(), gpsData.isValid ? "V" : "I", gpsData.position.latitude, gpsData.position.longitude, gpsData.position.altitude);
    sendMessage(buffer);
    Serial.println("Secondary data sent: Position.");
}

void RadioModule::setRadioFrequency(RadioFrequency radioFrequency) {
    if (!radioSerial) {
        Serial.println("Error: radioSerial not initialized!");
        return;
    }
    switch (radioFrequency) {
        case RadioFrequency::A:
            radioSerial.println("FREQ:000"); // example frequency in kHz
            Serial.println("Radio frequency set to 000 kHz.");
            break;
        case RadioFrequency::B:
            radioSerial.println("FREQ:868"); // example frequency in kHz
            Serial.println("Radio frequency set to 868 kHz.");
            break;
        case RadioFrequency::C:
            radioSerial.println("FREQ:433");
            Serial.println("Radio frequency set to 433 kHz.");
            break;
    }
}