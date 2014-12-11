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

    melody.setMelody( haurunomaintame_Melody, haurunomaintame_Duration, haurunomaintame_Length);
    playPattern(patternFlushC,allcolor);

    melody.setMelody( haurunomaintame_Melody, haurunomaintame_Duration, haurunomaintame_Length);
    playPattern(patternFlushPointSlow,allcolor);

    melody.setMelody( haurunomaintame_Melody, haurunomaintame_Duration, haurunomaintame_Length);
    playPattern(patternFlushTurn,allcolor);

    melody.setMelody( haurunomaintame_Melody, haurunomaintame_Duration, haurunomaintame_Length);
    playPattern(patternPitch2Color,allcolor);

    melody.setMelody( haurunomaintame_Melody, haurunomaintame_Duration, haurunomaintame_Length);
    playPattern(patternRandom3,allcolor);

    melody.setMelody( haurunomaintame_Melody, haurunomaintame_Duration, haurunomaintame_Length);
    playPattern(patternRandom3Blink,allcolor);

}

