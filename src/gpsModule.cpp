#include "gpsModule.hpp"
#include <Arduino.h>
#include <TinyGPSPlus.h>

GpsModule::GpsModule(Pin rxPin, Pin txPin)
    : rxPin(rxPin), txPin(txPin), gpsSerial(2) {}

void GpsModule::begin() {
    gpsSerial.begin(9600, SERIAL_8N1, rxPin, txPin);
}

GpsData& GpsModule::read() {
    while (gpsSerial.available() > 0) {
        char data = gpsSerial.read();
        gps.encode(data);
    }

    if (!gps.location.isValid() && !gps.date.isValid() && !gps.time.isValid() && !gps.speed.isValid()) {
        latestData = GpsData(false);
        return latestData;
    }

    DateTime dateTime(
        gps.date.isValid() && gps.time.isValid(),
        gps.date.year(),
        gps.date.month(),
        gps.date.day(),
        gps.time.hour(),
        gps.time.minute(),
        gps.time.second(),
        gps.time.centisecond() * 10
    );

    Position position(
        gps.location.isValid(),
        gps.location.lat(),
        gps.location.lng(),
        gps.altitude.meters()
    );

    Speed speed(
        gps.speed.isValid(),
        gps.speed.mps()
    );

    latestData = GpsData(true, dateTime, position, speed);
    return latestData;
}

