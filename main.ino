#include <Arduino.h>
#include "ultrasound.hpp"
#include "motor.hpp"
#include "rotaryEncoder.hpp"
#include "movement.hpp"
#include "jumper.hpp"

void setup()
{
    /// Init serial and send version number
    Serial.begin(115200);
    Serial.print(F("VERSION : "));
    Serial.println(F(VERSION));

    /// Init all modules
    ultrasoundInit();
    motorInit();
    rotaryEncoderInit();
    jumperInit();

    /// Wait jumper presence to init robot
    Serial.println(F("Wait jumper"));
    jumperWaitPresent();
    // Can do an action before waiting start of match
    // Wait 0.5s for debounce
    delay(500);

    /// Wait Start of match (jumper is not present)
    Serial.println(F("Wait match start"));
    jumperWaitUnpresent();
    // Start match timer
    jumperStartTimer();
}

void loop()
{
}
