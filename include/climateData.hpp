/// Represents data from the climate sensor (BME280)
struct ClimateData {
    /// Temperature in degrees celsius
    float temperature;

    /// Relative air pressure in kPa
    float pressure;

    /// Relative humidity in percentages
    float humidity;

    /// Altitude in meters above sea level
    float altitude;
};