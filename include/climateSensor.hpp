#pragma once
#include "core.hpp"
#include "climateData.hpp"
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

/// Represents the climate sensor (BME280)
class ClimateSensor {
    private:
    Pin sclPin;
    Pin sdaPin;
    float seaLevelPressure;
    float temperatureOffset;
    Adafruit_BME280 bme;
    bool isInitialised;

    public:
    /** The sensor will use the given pins for I2C communication 
     * @param sclPin The pin that will be used as SCL
     * @param sdaPin The pin that will be used as SDA
     * @param seaLevelPressure Sea level pressure in kPa
    */
    ClimateSensor(Pin sclPin, Pin sdaPin, float seaLevelPressure, float temperatureOffset);

    /// Initialises the sensor using the given pins
    void begin();

    /// Reads the latest data from the sensor
    /// @return Returns the climate data
    ClimateData read();
};