#pragma once
#include "core.hpp"
#include "gpsData.hpp"

/// Represents the GPS module
class GpsModule {
    private:
    Pin rxPin;
    Pin txPin;

    public:
    /// The GPS module will use the given pins for its input and output
    /// @param rxPin The pin that will be used for recieving data
    /// @param txPin The pin that will be used for transmitting data
    GpsModule(Pin rxPin, Pin txPin);

    /// Sets up the hardware UART using the given pins
    void begin();

    /// Reads any new data from the GPS module and returns with the latest information
    GpsData& read();
};