#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

#include "sdCardModule.hpp"

SdCardModule::SdCardModule(Pin sckPin, Pin misoPin, Pin mosiPin, Pin csPin)
    : sckPin(sckPin), misoPin(misoPin), mosiPin(mosiPin), csPin(csPin) {}

void SdCardModule::begin() {
    SPI.begin(sckPin, misoPin, mosiPin, csPin);
    if (!SD.begin(csPin)) {
        Serial.println("SD card initialization failed!");
    } else {
        Serial.println("SD card initialized.");
    }
}

void SdCardModule::saveData(ClimateData &climateData, GpsData &gpsData) {
    File file = SD.open("/data.csv", FILE_APPEND);
    if (!file) {
        Serial.println("Failed to open file");
        return;
    }

    // Write climate data
    file.print("\"");
    file.print(climateData.isValid ? "VALID_CLIMATE_DATA" : "INVALID_CLIMATE_DATA");
    file.print(" ");
    file.print(gpsData.isValid ? "VALID_GPS" : "INVALID_GPS");
    file.print(" ");
    file.print(gpsData.position.isValid ? "VALID_POSITION" : "INVALID_POSITION");
    file.print(" ");
    file.print(gpsData.dateTime.isValid ? "VALID_DATETIME" : "INVALID_DATETIME");
    file.print(" ");
    file.print(gpsData.position.isValid ? "VALID_SPEED" : "INVALID_SPEED");
    file.print("\"");
    file.print(",");
    file.print(climateData.temperature, 2);
    file.print(",");
    file.print(climateData.pressure, 2);
    file.print(",");
    file.print(climateData.humidity, 2);
    file.print(",");
    file.print(climateData.altitude, 2);
    file.print(",");

    // Write GPS data to file
    file.print(gpsData.position.latitude, 6);
    file.print(",");
    file.print(gpsData.position.longitude, 6);
    file.print(",");
    file.print(gpsData.position.altitude, 2);
    file.print(",");
    file.print(gpsData.dateTime.year);
    file.print(",");
    file.print(gpsData.dateTime.month);
    file.print(",");
    file.print(gpsData.dateTime.day);
    file.print(",");
    file.print(gpsData.dateTime.hour);
    file.print(",");
    file.print(gpsData.dateTime.minute);
    file.print(",");
    file.print(gpsData.dateTime.second);
    file.print(",");
    file.print(gpsData.dateTime.millisecond);
    file.print(",");
    file.print(gpsData.speed.value);

    file.print("\n");

    file.close();
}
