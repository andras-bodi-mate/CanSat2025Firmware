#include "gpsModule.hpp"
#include <Arduino.h>
#include <TinyGPSPlus.h>


static TinyGPSPlus gps;
static GpsData latestData;

GpsModule::GpsModule(Pin rxPin, Pin txPin)
    : rxPin(rxPin), txPin(txPin) {}

void GpsModule::begin() {
    Serial2.begin(9600, SERIAL_8N1, rxPin, txPin);
}

GpsData& GpsModule::read() {
    while (Serial2.available()) {
        gps.encode(Serial2.read());
    }

    if (!gps.location.isValid() || !gps.date.isValid() || !gps.time.isValid()) {
        latestData = GpsData(false);
        return latestData;
    }

    DateTime dateTime(
        true,
        gps.date.year(),
        gps.date.month(),
        gps.date.day(),
        gps.time.hour(),
        gps.time.minute(),
        gps.time.second(),
        gps.time.centisecond() * 10000
    );

    Position position(
        gps.location.lat(),
        gps.location.lng(),
        gps.altitude.meters()
    );

    float speed = gps.speed.mps();

    latestData = GpsData(true, dateTime, position, speed);
    return latestData;
}

