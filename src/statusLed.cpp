#include <Arduino.h>

#include "statusLed.hpp"

void StatusLed::createTimer(void (StatusLed::*callback)(), String name, esp_timer_handle_t* timer) {
    const esp_timer_create_args_t timerArgs = {
        .callback = [](void* arg){return ((StatusLed*)arg)->ledOnTimerCallback();},
        .arg = this,
        .name = name.c_str()
    };

    esp_timer_create(&timerArgs, timer);
}

void StatusLed::ledOnTimerCallback() {
    digitalWrite(pin, HIGH);

    if (currentIndex == currentPattern.length) {
        wasPatternCompleted = true;
        currentIndex = 0;
        return;
    }

    bool blinkType = currentPattern.pattern[currentIndex];
    int delay = blinkType ? BlinkPattern::shortBlinkDuration : BlinkPattern::longBlinkDuration;

    esp_timer_start_once(ledOffTimer, delay);

    currentIndex++;
}

void StatusLed::ledOffTimerCallback() {
    digitalWrite(pin, LOW);

    int delay = (currentIndex == currentPattern.length) ? BlinkPattern::shortBlinkDuration : StatusLed::blinkPatternGap;
    esp_timer_start_once(ledOnTimer, StatusLed::blinkPatternGap);
}

void StatusLed::startBlinking() {
    esp_timer_start_once(ledOffTimer, 0);
}

StatusLed::StatusLed(Pin pin) : pin(pin) {}

void StatusLed::begin() {
    pinMode(pin, OUTPUT);

    createTimer(ledOnTimerCallback, "ledOnTimer", &ledOnTimer);
    createTimer(ledOffTimerCallback, "ledOffTimer", &ledOffTimer);
}

void StatusLed::blink(BlinkPattern pattern) {
    if (wasPatternCompleted) {
        currentPattern = pattern;
        wasPatternCompleted = false;
        startBlinking();
    }
}