#include <Arduino.h>
#include "radioFrequencySelector.hpp"

RadioFrequencySelector::RadioFrequencySelector(Pin pin)
    : pin(pin) {}

void RadioFrequencySelector::begin() {
    pinMode(pin, INPUT);
}

RadioFrequency RadioFrequencySelector::read() {
    // Return based on the pin state
    return digitalRead(pin) ? RadioFrequency::B : RadioFrequency::A;
}
