#pragma once
#include "core.hpp"
#include "position.hpp"
#include "radioFrequency.hpp"
#include "gpsData.hpp"
#include "climateData.hpp"

/// Represents the long-range radio module (LoRa)

class RadioModule {
    private:
    Pin rxPin;
    Pin txPin;
    HardwareSerial radioSerial;
    static constexpr int primaryDataSize = 256;
    static constexpr int secondaryDataSize = 256;
    uint32_t messageIndex = 0;

    static String stringToHexStr(String str);
    
    void sendMessage(String message);

    public:
    /// The long-range radio module (LoRa) will use these pins for recieving and transmitting data
    /// @param rxPin The pin that will be used for reciving data
    /// @param txPin The pin that will be used for transmitting data
    RadioModule(Pin rxPin, Pin txPin);

    /// Sets up the hardware UART connection and configures the radio module to upload mode
    void begin();

    /// Sends the primary data (temperature and pressure) to the ground station
    /// @param temperature Temperature in degrees celsius
    /// @param pressure Relative air pressure in hPa
    void sendPrimaryData(float temperature, float pressure);

    /// Sends the GPS position of the satellite to the ground station
    /// @param climateData The data from the climate sensor
    /// @param gpsData The data from the gps module
    void sendSecondaryData(ClimateData climateData, GpsData gpsData);

    #pragma once


    enum class RadioFrequency {
    A,  
    B,  
    C
    };

    /// Sets the operating radio frequency of the module
    /// @param radioFrequency Radio frequency in kHz
    void setRadioFrequency(RadioFrequency radioFrequency);
};