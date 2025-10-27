#pragma once
#include "dateTime.hpp"
#include "position.hpp"

/// Represents the data that the GPS module returns
struct GpsData {
    /// If this is false, it means that there was a problem while reading from the GPS module or it hasn't yet gotten a GPS fix
    bool isValid;

    /// The date and time when the GPS data was collected
    DateTime dateTime;

    /// The latitude, longitude and altitude
    Position position;

    /// Speed in meters per second
    float speed; 

    /// Constructor
    /// @param isValid Wheather there was a problem while reading from the GPS module
    /// @param dateTime The date and time when the GPS data was collected
    /// @param position The latitude, longitude and altitude
    /// @param speed Speed in meters per second
    GpsData(bool isValid = false, DateTime dateTime = DateTime(), Position position = Position(), float speed = 0);
};