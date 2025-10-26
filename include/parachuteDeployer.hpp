#pragma once
#include "core.hpp"

/// Represents the mechanism that will release the parachute
class ParachuteDeployer {
    private:
    Pin pin;

    public:
    /** The solanoid will use the given pin for it's input
     * @param pin The output pin
    */
    ParachuteDeployer(Pin pin);

    /// Configures the given pin to OUTPUT mode
    void begin();

    /// Close the solanoid and lock the parachute
    void lock();

    /// Open the solanoid and release the parachute
    void release();
};