#pragma once
#include <Arduino.h>

#include "core.hpp"
#include "blinkPattern.hpp"

/// Represents the status LED
class StatusLed {
    private:
    static const int blinkPatternGap = 500; // The gap between each blink pattern in milliseconds

    Pin pin; /// The pin that will be used as ouput to the LED
    BlinkPattern currentPattern; /// The current blink pattern
    bool wasPatternCompleted = true; /// Was the current pattern completed
    int currentIndex = 0; /// The current index in the pattern
    esp_timer_handle_t ledOffTimer; /// The timer that will turn off the LED when it runs out
    esp_timer_handle_t ledOnTimer; /// The timer that will turn on the LED when it runs out

    /// Creates a timer using the given arguments
    /// @param callback The member function to use as the callback
    /// @param name The name of the timer
    /// @param timer The timer handle
    void createTimer(void (StatusLed::*callback)(), String name, esp_timer_handle_t* timer);

    /// Turns on the LED and starts the ledOffTimer after a delay
    void ledOnTimerCallback();

    /// Turns on the LED and starts the ledOnTimer after a delay
    void ledOffTimerCallback();

    /// Starts the ledOffTimerCallback immediately
    void startBlinking();

    public:
    /// The specified pin will be used as output to the status LED
    /// @param pin The pin that will be configured as the output during begin()
    StatusLed(Pin pin);

    /// Sets the given pin to OUTPUT
    void begin();

    /// Starts blinking the given pattern if there is no active pattern
    void blink(BlinkPattern pattern);
};