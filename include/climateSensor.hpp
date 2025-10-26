#pragma once
#include "core.hpp"
#include "climateData.hpp"

/// Represents the climate sensor (BME280)
class ClimateSensor {
    private:
    Pin sclPin;
    Pin sdaPin;

    public:
    /** The sensor will use the given pins for I2C communication 
     * @param sclPin The pin that will be used as SCL
     * @param sdaPin The pin that will be used as SDA
    */
    ClimateSensor(Pin sclPin, Pin sdaPin);

    /// Initialises the sensor using the given pins
    void begin();

    /// Reads the latest data from the sensor
    /// @return Returns the climate data
    ClimateData read();
};