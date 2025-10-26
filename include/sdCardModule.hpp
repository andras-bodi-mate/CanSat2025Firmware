#pragma once
#include "core.hpp"
#include "climateData.hpp"
#include "gpsData.hpp"

/// Represents the SD card module
class SdCardModule {
    private:
    Pin sckPin;
    Pin misoPin;
    Pin mosiPin;
    Pin csPin;

    public:
    /// The SD card module will use the specified SCK, MISO, MOSI and CS pins
    /// @param sckPin The pin that will be used as SCK
    /// @param misoPin The pin that will be used as MISO (master in, slave out)
    /// @param mosiPin The pin that will be used as MOSI (master out, slave in)
    /// @param csPin The pin that will be used as CS
    SdCardModule(Pin sckPin, Pin misoPin, Pin mosiPin, Pin csPin);

    /// Sets up and mounts the SD card using the given SPI pins
    void begin();

    /// Save data to the SD card
    /// @param climateData Climate data from the climate sensor (BME280)
    /// @param gpsData GPS data from the GPS module
    void saveData(ClimateData& climateData, GpsData& gpsData);
};