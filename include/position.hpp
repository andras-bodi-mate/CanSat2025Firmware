#pragma once

/// Represents the location of the satellite
struct Position {
    /// If this is false, it probably means that the GPS module hasn't yet gotten a position fix
    bool isValid;

    /// Latitude in decimal degrees
    float latitude;

    /// Longitude in decimal degrees
    float longitude;

    /// Altitude in meters above sea level
    float altitude;

    /// Constructor
    /// @param isValid If this is false, it probably means that the GPS module hasn't yet gotten a position fix
    /// @param latitude Latitude in decimal degrees
    /// @param longitude Longitude in decimal degrees
    /// @param altitude Altitude in meters above sea level
    Position(bool isValid = false, float latitude = 0, float longitude = 0, float altitude = 0);
};