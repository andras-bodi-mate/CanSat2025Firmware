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
}