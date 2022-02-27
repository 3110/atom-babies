#include "AtomBabies.h"

using namespace M5Stack_AtomBabies;

AtomBabies babies;
uint32_t bowCount = 0;

void setup(void) {
    babies.begin();
    babies.setFace(FaceNormal);
    babies.startBlink();
}

void loop(void) {
    babies.update();
    if (M5.Btn.wasPressed()) {
        ++bowCount;
        for (uint32_t i = 0; i < bowCount; ++i) {
            babies.bow();
        }
    }
}