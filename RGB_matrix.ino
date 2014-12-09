#include "sounds.h"
#include "playMelody.h"
#include "led_fullcolor_9.h"

#define BUZZER_PIN 8
#define SWITCH_PIN 9
#define isPress() (!digitalRead(SWITCH_PIN))
#define playPattern(x,y) playPat(x,y,(int)(sizeof(y)/sizeof(y[0])))

int playPat(int (*pattern)(LedColor*,int),LedColor*,int);
LedColor allcolor[7] = {WHITE,RED,GREEN,BLUE,CYAN,YELLOW,MAGENTA};



PlayMelody melody(BUZZER_PIN);

void setup(){
    pinMode( SWITCH_PIN, INPUT_PULLUP); 
    analogReference(INTERNAL);
    randomSeed(analogRead(0));

    Led::init();
    Led::setInterval(3);
}


void loop(){
    melody.setMelody( takibi_Melody, takibi_Duration, takibi_Length);
    playPattern(patternFlushC,allcolor);
    
    melody.setMelody( rpg_Melody, rpg_Duration, rpg_Length);
    playPattern(patternFlushTurnC,allcolor);
    
    melody.setMelody( haurunomaintame_Melody, haurunomaintame_Duration, haurunomaintame_Length);
    playPattern(patternFlushPoint,haurunomaintame_Color);

    melody.setMelody( merrychristmas_Melody, merrychristmas_Duration, merrychristmas_Length);
    playPattern(patternFlushPointSlow,allcolor);

    melody.setMelody( bell_Melody, bell_Duration, bell_Length);
    playPattern(patternFlushTurn,allcolor);
    
    melody.setMelody( letitgo_Melody, letitgo_Duration, letitgo_Length);
    playPattern(patternRandom3Blink,allcolor);


}

