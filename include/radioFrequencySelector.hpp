#pragma once
#include "core.hpp"
#include "radioFrequency.hpp"

/// Represents the radio frequency selector switch
class RadioFrequencySelector {
    private:
    Pin pin;

    public:
    /// The specified pin will be used as input from the radio frequency selector switch
    /// @param pin The pin that will be configured as the input during begin()
    RadioFrequencySelector(Pin pin);

    /// Configures the given pin to INPUT mode
    void begin();

    /// Read the currently selected radio frequency
    /// @return Reaturns the currently selected radio frequency
    RadioFrequency read();
};