#pragma once

/// Represents data from the climate sensor (BME280)
struct ClimateData {
    /// If this is false, it means that there was a problem while reading from the climate sensor
    bool isValid;

    /// Temperature in degrees celsius
    float temperature;

    /// Relative air pressure in kPa
    float pressure;

    /// Relative humidity in percentages
    float humidity;

    /// Altitude in meters above sea level
    float altitude;

    /// Constructor
    ClimateData(bool isValid = false, float temperature = 0, float pressure = 0, float humidity = 0, float altitude = 0);
};