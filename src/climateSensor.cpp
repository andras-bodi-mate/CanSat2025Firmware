#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_BME280.h>

#include "climateSensor.hpp"

static Adafruit_BME280 bme;

ClimateSensor::ClimateSensor(Pin sclPin, Pin sdaPin)
    : sclPin(sclPin), sdaPin(sdaPin) {}

void ClimateSensor::begin() {
    Wire.begin(sdaPin, sclPin);
    bme.begin(0x76);
}

ClimateData ClimateSensor::read() {
    if (!bme.sensorID()) {
        return ClimateData(false);
    }

    float temperature = bme.readTemperature();
    float pressure = bme.readPressure() / 1000.0f;
    float humidity = bme.readHumidity();
    float altitude = bme.readAltitude(1013.25);

    return ClimateData(true, temperature, pressure, humidity, altitude);
}
