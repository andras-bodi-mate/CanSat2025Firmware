#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_BME280.h>

#include "climateSensor.hpp"

ClimateSensor::ClimateSensor(Pin sclPin, Pin sdaPin, float seaLevelPressure, float temperatureOffset): sclPin(sclPin), sdaPin(sdaPin), seaLevelPressure(seaLevelPressure), temperatureOffset(temperatureOffset) {}

void ClimateSensor::begin() {
    if (! bme.begin(0x77, &Wire)) {
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
        isInitialised = false;
    }
    else {
        isInitialised = true;
    }
}

ClimateData ClimateSensor::read() {
    return ClimateData(
        isInitialised,
        bme.readTemperature() + temperatureOffset,
        bme.readPressure(),
        bme.readHumidity(),
        bme.readAltitude(seaLevelPressure)
    );
}
