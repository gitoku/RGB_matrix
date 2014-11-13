#include "sounds.h"
#include "playMelody.h"
#include "led_fullcolor_9.h"

#define BUZZER_PIN 8
#define SWITCH_PIN 9
#define isPress() digitalRead(SWITCH_PIN)

PlayMelody song1(BUZZER_PIN);
PlayMelody song2(BUZZER_PIN);

void setup(){
    pinMode( SWITCH_PIN, INPUT_PULLUP); 
    analogReference(INTERNAL);

    Led::init();
    Led::setInterval(20);

    song1.setMelody(melody1,noteDurations1,82);
    song2.setMelody(melody2,noteDurations2,68);
}

void loop(){
    
    //音が変わるたびに発光箇所が変わる
    song1.play();
    while( song1.isPlaying() || !isPress() ){ 
        static int cnt=0;
        cnt += song1.play();
        Led::setAll(OFF);
        Led::set(cnt%9,WHITE);
        Led::lighting();
    }
    song1.stop();
    Led::setAll(OFF);
    Led::lighting();
    delay(200);
    while( isPress() );  //スイッチが離されるまで待つ



    //音の高さによって色が変わる
    song2.play();
    while( song2.isPlaying() || !isPress()){ 
        song2.play();
        LedColor color = int2color( song2.getPitch() );
        Led::setAll(color);
        Led::lighting();
    }
    song2.stop();
    Led::setAll(OFF);
    Led::lighting();
    delay(200);
    while( isPress() );  //スイッチが離されるまで待つ

}


LedColor int2color(int num){
    switch (num%8) {
        case 0: return OFF;
        case 1: return RED;
        case 2: return GREEN;
        case 3: return BLUE;
        case 4: return CYAN;
        case 5: return MAGENTA;
        case 6: return YELLOW;
        case 7: return WHITE;
    }
}