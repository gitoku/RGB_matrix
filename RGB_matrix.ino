#include "sounds.h"
#include "pattern.h"


void setup(){
    pinMode( SWITCH_PIN, INPUT_PULLUP); 
    analogReference(INTERNAL);
    randomSeed(analogRead(0));

    Led::init();
    Led::setInterval(3);
}


void loop(){

    melody.setMelody( haurunomaintame_Melody, haurunomaintame_Duration, haurunomaintame_Length);

    playPattern(patternFlushPoint,allcolor);
    playPattern(patternFlushC,allcolor);
    playPattern(patternFlushPointSlow,allcolor);
    playPattern(patternFlushTurn,allcolor);
    playPattern(patternPitch2Color,allcolor);
    playPattern(patternRandom3,allcolor);
    playPattern(patternRandom3Blink,allcolor);

}

