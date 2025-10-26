#pragma once
#include "core.hpp"
#include "position.hpp"
#include "radioFrequency.hpp"

/// Represents the long-range radio module (LoRa)
class RadioModule {
    private:
    Pin rxPin;
    Pin txPin;

    public:
    /// The long-range radio module (LoRa) will use these pins for recieving and transmitting data
    /// @param rxPin The pin that will be used for reciving data
    /// @param txPin The pin that will be used for transmitting data
    RadioModule(Pin rxPin, Pin txPin);

    /// Sets up the hardware UART connection and configures the radio module to upload mode
    void begin();

    /// Sends the primary data (temperature and pressure) to the ground station
    /// @param temperature Temperature in degrees celsius
    /// @param pressure Relative air pressure in kPa
    void sendPrimaryData(float temperature, float pressure);

    /// Sends the GPS position of the satellite to the ground station
    /// @param position The current GPS position of the satellite
    void sendSecondaryData(Position position);

    /// Sets the operating radio frequency of the module
    /// @param radioFrequency Radio frequency in kHz
    void setRadioFrequency(RadioFrequency radioFrequency);
};