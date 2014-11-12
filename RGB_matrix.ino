#include "sounds.h"
#include "playMelody.h"
#include "led_fullcolor_9.h"

#define BUZZER_PIN 8
#define SWITCH_PIN 9

PlayMelody song1(BUZZER_PIN);
PlayMelody song2(BUZZER_PIN);

void setup(){
    pinMode( SWITCH_PIN, INPUT_PULLUP); 
    analogReference(INTERNAL);
    Led::init();
    song1.setMelody(melody1,noteDurations1,82);
    song2.setMelody(melody2,noteDurations2,68);
}

void loop(){

    //音が変わるたびに発光箇所が変わる
    while( song1.isPlaying() ){ 
        static int cnt=0;
        cnt += song1.play();
        Led::setAll(OFF);
        Led::set(cnt%9,WHITE);
        Led::lighting();
    }
    song1.stop();
    delay(1000);
    
    //音の高さによって色が変わる
    while( song2.isPlaying() ){ 
        song2.play();
        LedColor color = int2color( song2.getPitch() );
        Led::setAll(color);
        Led::lighting();
    }
    song2.stop();
    delay(1000);

}



void tutorial(){
    LedColor pattern1[9];
    pattern1[0]=RED;    //[RED,GREEN,BLUE]で色を指定
    pattern1[1]=GREEN;
    pattern1[2]=BLUE;
    pattern1[3]=CYAN;    //[CYAN,YELLOW,MAGENTA]からも選択可能
    pattern1[4]=YELLOW;
    pattern1[5]=MAGENTA;
    pattern1[6]=WHITE;   //[WHITE]を選択可能
    pattern1[7]=OFF;     //光らせない時は[OFF]
    pattern1[8]=OFF;
    Led::lightingWhile(pattern1,1500);  //pattern1を1500[ms]出力し続ける

    Led::setAll(OFF);
    Led::set(0,BLUE);    //set(led,color):指定ledを指定色に設定
    Led::set(3,RED);
    Led::set(5,GREEN);
    Led::set(8,BLUE);
    Led::lightingWhile(800);     //設定済みの色で800[ms]出力し続ける

    Led::setAll(OFF);     //すべて同じ色ならsetAll()で設定可能
    Led::lightingWhile(2000);     //設定済みの色で2000[ms]出力し続ける
}

void demo(){
    //700[ms]ごとに発光LEDを遷移
    for(int i=0;i<9;i++){
        Led::setAll(OFF);
        Led::set(i,WHITE);
        Led::lightingWhile(700);
    }
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