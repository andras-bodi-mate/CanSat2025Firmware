#include <Arduino.h>
#include "parachuteDeployer.hpp"

ParachuteDeployer::ParachuteDeployer(Pin pin)
    : pin(pin) {}

void ParachuteDeployer::begin() {
    pinMode(pin, OUTPUT);
    lock();
}

void ParachuteDeployer::lock() {
    digitalWrite(pin, LOW);
}

void ParachuteDeployer::release() {
    digitalWrite(pin, HIGH);
}
