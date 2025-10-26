#include "radioModule.hpp"

RadioModule::RadioModule(Pin rxPin, Pin txPin): rxPin(rxPin), txPin(txPin) {}

void RadioModule::begin() {
}

void RadioModule::sendPrimaryData(float temperature, float pressure) {
}

void RadioModule::sendSecondaryData(Position position) {
}

void RadioModule::setRadioFrequency(RadioFrequency radioFrequency) {
}
