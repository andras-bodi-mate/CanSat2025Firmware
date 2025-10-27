#pragma once

/// Represents date and time
struct DateTime {
    /// If this is false, it probably means that the GPS module hasn't yet gotten a time fix
    bool isValid;

    /// Year
    int year;

    /// Month (1-12)
    int month;

    /// Day
    int day;

    /// Hour
    int hour;

    /// Minute
    int minute;

    /// Second
    int second;

    /// Microsecond
    int microsecond;

    /// Constructor
    DateTime(bool isValid = false, int year = 0, int month = 0, int day = 0, int hour = 0, int minute = 0, int second = 0, int microsecond = 0);
};