#include <Arduino.h>
#include "climateSensor.hpp"
#include "gpsModule.hpp"
#include "parachuteDeployer.hpp"
#include "radioFrequencySelector.hpp"
#include "radioModule.hpp"
#include "sdCardModule.hpp"
#include "statusLed.hpp"

StatusLed statusLed(LED_BUILTIN);

void setup() {
  statusLed.begin();
}

void loop() {
  bool pattern[BlinkPattern::MAX_NUM_BLINKS] = {true, false, false, true, false, true};
  BlinkPattern blinkPattern(pattern, 6);
  statusLed.blink(blinkPattern);

  ClimateData c;
  GpsData data(true, DateTime(true, 2025, 10, 27, 10, 59, 12), Position());
}