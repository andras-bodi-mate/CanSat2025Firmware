#include "gpsData.hpp"

GpsData::GpsData(bool isValid,
                 DateTime dateTime,
                 Position position,
                 float speed)
    : isValid(isValid),
      dateTime(dateTime),
      position(position),
      speed(speed) {}
