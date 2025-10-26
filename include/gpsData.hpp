#pragma once
#include "dateTime.hpp"
#include "position.hpp"

/// Represents the data that the GPS module returns
struct GpsData {
    /// The date and time when the GPS data was collected
    DateTime dateTime;

    /// The latitude, longitude and altitude
    Position position;

    /// Speed in meters per second
    float speed; 
};