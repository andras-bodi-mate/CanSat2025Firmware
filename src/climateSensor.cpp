#include "climateSensor.hpp"

ClimateSensor::ClimateSensor(Pin sclPin, Pin sdaPin): sclPin(sclPin), sdaPin(sdaPin) {}

void ClimateSensor::begin() {
}

ClimateData ClimateSensor::read() {
    return ClimateData();
}