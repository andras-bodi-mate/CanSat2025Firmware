#include "sdCardModule.hpp"

SdCardModule::SdCardModule(Pin sckPin, Pin misoPin, Pin mosiPin, Pin csPin):
sckPin(sckPin), misoPin(misoPin), mosiPin(mosiPin), csPin(csPin) {}

void SdCardModule::begin() {
}

void SdCardModule::saveData(ClimateData &climateData, GpsData &gpsData) {
}
