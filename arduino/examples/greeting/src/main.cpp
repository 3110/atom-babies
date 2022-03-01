#include "AtomBabies.h"

using namespace M5Stack_AtomBabies;

const uint8_t PIR_INPUT_PIN = 33;  // with ATOM Mate
const CRGB FILL_COLOR(0x00, 0x64, 0x00);

AtomBabies babies;
bool wasDetected = false;

bool isDetected(void) {
    return digitalRead(PIR_INPUT_PIN) == 1;
}

void setup(void) {
    pinMode(PIR_INPUT_PIN, INPUT_PULLUP);
    babies.begin();
    babies.setOrientation(OrientationUpsideDown);
    babies.setFace(FaceNormal);
    babies.fillFace(FILL_COLOR);
}

void loop(void) {
    babies.update();
    if (isDetected()) {
        if (!wasDetected) {
            SERIAL_PRINTLN("PIR: Detected");
            wasDetected = true;
            babies.bow();
            delay(1000);
            babies.fillFace(FILL_COLOR);
        }
    } else {
        if (wasDetected) {
            SERIAL_PRINTLN("PIR: Got Away");
            wasDetected = false;
            babies.fillFace(FILL_COLOR);
        }
    }
}