#include <Arduino.h>

#include "infoLed.hpp"

void InfoLed::createTimer(void callback(void*), const char* name, esp_timer_handle_t* timer) {
    const esp_timer_create_args_t timerArgs = {
        .callback = callback,
        .arg = this,
        .name = name
    };

    esp_timer_create(&timerArgs, timer);
}

void InfoLed::ledOnTimerCallback(void* arg) {
    InfoLed* self = static_cast<InfoLed*>(arg);

    if (self->currentIndex == self->currentPattern.length) {
        self->currentIndex = 0;
        self->wasPatternCompleted = true;
        return;
    }

    digitalWrite(self->pin, HIGH);

    bool blinkType = self->currentPattern.pattern[self->currentIndex];
    int delay = blinkType ? BlinkPattern::shortBlinkDuration : BlinkPattern::longBlinkDuration;

    esp_timer_start_once(self->ledOffTimer, delay);

    self->currentIndex++;
}

void InfoLed::ledOffTimerCallback(void* arg) {
    InfoLed* self = static_cast<InfoLed*>(arg);

    digitalWrite(self->pin, LOW);

    int delay = (self->currentIndex == self->currentPattern.length) ? InfoLed::blinkPatternGap : BlinkPattern::blinkGap;
    esp_timer_start_once(self->ledOnTimer, delay);
}

void InfoLed::startBlinking() {
    esp_timer_start_once(ledOnTimer, 0);
}

InfoLed::InfoLed(Pin pin) : pin(pin) {}

void InfoLed::begin() {
    pinMode(pin, OUTPUT);

    createTimer(ledOnTimerCallback, "ledOnTimer", &ledOnTimer);
    createTimer(ledOffTimerCallback, "ledOffTimer", &ledOffTimer);
}

void InfoLed::blink(BlinkPattern pattern) {
    if (wasPatternCompleted) {
        currentPattern = pattern;
        wasPatternCompleted = false;
        startBlinking();
    }
}