#pragma once

#include <M5Atom.h>

#include "Debug.h"

namespace M5Stack_AtomBabies {

const char VERSION[] = "0.0.1";

enum FacePosition {
    FaceTop = 0,
    FaceUp,
    FaceNormal,
    FaceRight,
    FaceLeft,
    FaceDown,
    FaceBottom,
};

enum FaceOrientation {
    OrientationNormal = 0,
    OrientationRight,
    OrientationLeft,
    OrientationUpsideDown,
};

typedef struct {
    uint8_t loop;
    uint16_t open;
    uint16_t close;
    uint16_t interval;
} BlinkParam;

typedef struct {
    uint16_t before;
    uint16_t after;
} BowParam;

class AtomBabies {
public:
    static const size_t N_POSITIONS = 2;
    static const size_t MAX_POSITION = 25;
    static const CRGB DEFAULT_EYE_COLOR;
    static const CRGB DEFAULT_CHEEK_COLOR;
    static const CRGB DEFAULT_BACKGROUND_COLOR;
    static const BlinkParam DEFAULT_BLINK;
    static const BowParam DEFAULT_BOW;

    AtomBabies(FacePosition position = FaceNormal,
               FaceOrientation orientation = OrientationNormal,
               const CRGB& eyeColor = DEFAULT_EYE_COLOR,
               const CRGB& cheekColor = DEFAULT_CHEEK_COLOR,
               const CRGB& backgroundColor = DEFAULT_BACKGROUND_COLOR);
    virtual ~AtomBabies(void);

    virtual bool begin(void);
    virtual bool update(void);

    virtual void openEyes(void);
    virtual void closeEyes(void);

    virtual void setCheeks(void);
    virtual void clearCheeks(void);

    virtual void startBlink(void);
    virtual void stopBlink(void);
    virtual void toggleBlink(void);
    virtual bool isBlinking(void) const;
    virtual void setBlinkParam(const BlinkParam& param);

    virtual void setOrientation(FaceOrientation orientation);
    virtual void setFace(FacePosition position);
    virtual void clearFace(bool partial = false);
    virtual void fillFace(const CRGB& color);

    virtual void bow(bool deep = false);
    virtual void setBowParam(const BowParam& param);

    virtual void _doBlink(void);  // called from thread

protected:
    virtual void setLED(const CRGB& color, uint8_t position);
    virtual void setLEDs(const CRGB& color,
                         const uint8_t (&position)[N_POSITIONS]);
    virtual void setEyes(const CRGB& color);
    virtual void setCheeks(const CRGB& color);
    virtual uint8_t getLEDPosition(uint8_t position);

private:
    FacePosition _position;
    FaceOrientation _orientation;
    CRGB _eyeColor;
    CRGB _cheekColor;
    CRGB _backgroundColor;
    bool _blinking;
    BlinkParam _blinkParam;
    BowParam _bowParam;
};

}  // namespace M5Stack_AtomBabies