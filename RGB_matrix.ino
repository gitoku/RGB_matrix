#include "sounds.h"
#include "playMelody.h"
#include "led_fullcolor_9.h"

#define BUZZER_PIN 8
#define SWITCH_PIN 9
//#define isPress() digitalRead(SWITCH_PIN)
#define isPress() (false)

PlayMelody song1(BUZZER_PIN);
PlayMelody song2(BUZZER_PIN);

void setup(){
    pinMode( SWITCH_PIN, INPUT_PULLUP); 
    analogReference(INTERNAL);

    Led::init();
    Led::setInterval(20);

    song1.setMelody(melody1,noteDurations1,82);
    song2.setMelody(melody2,noteDurations2,68);
    
    Serial.begin(115200);
    Serial.println("Ready.");
}

void loop(){
    
    //音が変わるたびに発光箇所が変わる
    while( !isPress() ){
        delay(500);
        song1.play();
        while( song1.isPlaying() && !isPress() ){ 
            static unsigned long cnt=0;
            cnt += song1.play();
            Led::setAll(OFF);
            Led::set(cnt%9,WHITE);
//            Led::lighting();
            Serial.print(song1.isPlaying());
            Serial.print("_");
            Serial.println( song1.isPlaying() && !isPress());
        }
        song1.stop();
        Led::setAll(OFF);
//        Led::lighting();
    }
    while( isPress() );  //スイッチが離されるまで待つ



    //音の高さによって色が変わる
    while( !isPress() ){
        delay(500);
        song2.play();
        while( song2.isPlaying() || !isPress()){ 
            song2.play();
            LedColor color = int2color( song2.getPitch() );
            Led::setAll(color);
            Led::set(1,OFF);
            Led::set(2,OFF);
            Led::set(7,OFF);
            Led::set(8,OFF);
            Led::lighting();
        }
        song2.stop();
        Led::setAll(OFF);
        Led::lighting();
        Serial.println("_");
    }
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
