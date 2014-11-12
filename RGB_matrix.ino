#include "sounds.h"
#include "led_fullcolor_9.h"

#define BUZZER_PIN 8
#define SWITCH_PIN 9


 void setup(){
    pinMode( BUZZER_PIN, OUTPUT); 
    pinMode( SWITCH_PIN, INPUT_PULLUP); 
    analogReference(INTERNAL);
    Led::init();

    // tutorial();
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

    while(1){
        Led::lightingWhile(pattern1,1500);  //pattern1を1500[ms]出力し続ける

        Led::setAll(RED);    //すべて同じ色ならsetAll()で設定可能
        Led::lightingWhile(800);     //800[ms]出力し続ける

        Led::setAll(OFF);     //pattern2に上書き
        Led::lightingWhile(2000);     //2000[ms]出力し続ける
    }
}


void loop(){
    //700[ms]ごとに発光LEDを遷移
    for(int i=0;i<9;i++){
        Led::setAll(OFF);
        Led::set(i,WHITE);
        Led::lightingWhile(700);
    }
}