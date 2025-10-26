#include "radioFrequencySelector.hpp"

RadioFrequencySelector::RadioFrequencySelector(Pin pin): pin(pin) {}

void RadioFrequencySelector::begin() {
    
}

RadioFrequency RadioFrequencySelector::read() {
    return RadioFrequency::A;
}
