#include <Arduino.h>
#include "core.hpp"
#include "climateSensor.hpp"
#include "gpsModule.hpp"
#include "parachuteDeployer.hpp"
#include "radioFrequencySelector.hpp"
#include "radioModule.hpp"
#include "sdCardModule.hpp"
#include "infoLed.hpp"

InfoLed infoLed(5);
SdCardModule sdCardModule(32, 35, 33, 25);
ClimateSensor climateSensor(26, 27, 998, 0.0);
GpsModule gpsModule(14, 13);
ParachuteDeployer parachuteDeployer(17);
RadioFrequencySelector radioFrequencySelector(23);
RadioModule radioModule(18, 19);

bool pattern[BlinkPattern::MAX_NUM_BLINKS] = {true, false, false, true, false, false, true};
BlinkPattern blinkPattern(pattern, 7);

uint32_t lastPrint = 0;

void setup() {
  Serial.begin(115200);

  Serial.println("Initialising info led...");
  infoLed.begin();
  Serial.println("Info led successfully initialised\n");

  Serial.println("Initialising SD card module...");
  sdCardModule.begin();
  Serial.println("SD card module successfully initialised\n");

  Serial.println("Initialising climate sensor...");
  climateSensor.begin();
  Serial.println("Climate sensor successfully initialised\n");

  Serial.println("Initialising GPS module...");
  gpsModule.begin();
  Serial.println("GPS module successfully initialised\n");

  Serial.println("Initialising parachute deployer...");
  parachuteDeployer.begin();
  Serial.println("Parachute deployer initialised\n");

  Serial.println("Initialising radio frequency selector...");
  radioFrequencySelector.begin();
  Serial.println("Radio frequency selector successfully initialised\n");

  Serial.println("Initialising radio module...");
  radioModule.begin();
  Serial.println("Radio module successfully initialised\n");
}

void loop() {
  infoLed.blink(blinkPattern);

  auto climateData = climateSensor.read();
  auto gpsData = gpsModule.read();
  auto selectedRadioFrequency = radioFrequencySelector.read();

  uint32_t currentTime = millis();
  if (currentTime - lastPrint > 1000) {
    lastPrint = currentTime;
    
    if (climateData.isValid) {
      Serial.printf("temperature: %f\n", climateData.temperature);
      Serial.printf("humidity: %f\n", climateData.humidity);
      Serial.printf("pressure: %f\n", climateData.pressure);
      Serial.printf("altitude: %f\n", climateData.altitude);
    }
    else {
      Serial.println("climate data was invalid");
    }

    if (gpsData.isValid) {
      if (gpsData.dateTime.isValid) {
        Serial.printf("year: %i\n", gpsData.dateTime.year);
        Serial.printf("month: %i\n", gpsData.dateTime.month);
        Serial.printf("day: %i\n", gpsData.dateTime.day);
        Serial.printf("hour: %i\n", gpsData.dateTime.hour);
        Serial.printf("minute: %i\n", gpsData.dateTime.minute);
        Serial.printf("second: %i\n", gpsData.dateTime.second);
        Serial.printf("millisecond: %i\n", gpsData.dateTime.millisecond);
      }
      else {
        Serial.println("date time was invalid");
      }

      if (gpsData.position.isValid) {
        Serial.printf("latitude: %f\n", gpsData.position.latitude);
        Serial.printf("longitude: %f\n", gpsData.position.longitude);
        Serial.printf("altitude: %f\n", gpsData.position.altitude);
      }
      else {
        Serial.println("position was invalid");
      }

      if (gpsData.speed.isValid) {
        Serial.printf("speed: %f\n", gpsData.speed);
      }
      else {
        Serial.println("speed was invalid");
      }
    }
    else {
      Serial.println("gps data was invalid");
    }

    if (selectedRadioFrequency) {
      Serial.printf("selected radio frequency: %s\n", selectedRadioFrequency == RadioFrequency::A ? "434.0" : "868.2");
    }
    else {
      Serial.println("selected radio frequency was invalid");
    }
    Serial.print("\n");

    sdCardModule.saveData(climateData, gpsData);

    radioModule.sendPrimaryData(21.2, 101.5);
    radioModule.sendSecondaryData(climateData, gpsData);
  }
}