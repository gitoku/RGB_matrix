#include "sounds.h"
#include "dynamic_fullcolor_9.h"

#define BUZZER_PIN 8
#define SWITCH_PIN 9


 void setup(){
    pinMode( BUZZER_PIN, OUTPUT); 
    pinMode( SWITCH_PIN, INPUT_PULLUP); 
    analogReference(INTERNAL);
    ledInit();

    // tutorial();
}



void tutorial(){
    LedColor pattern1[9];

    pattern1[0]=RED;    //[RED,GREEN,BLUE]で色を指定
    pattern1[1]=GREEN;
    pattern1[2]=CYAN;    //[CYAN,YELLOW,MAGENTA]からも選択可能
    // pattern1[3]=RED|BLUE; //(=MAGENTA)色の合成も可能
    pattern1[4]=WHITE;   //[WHITE]を選択可能
    // pattern1[5]=RED|GREEN|BLUE;  //(=WHITE)
    pattern1[6]=OFF;     //光らせない時は[OFF]
    pattern1[7]=OFF;
    pattern1[8]=OFF;    //[0~8]の9個のLEDの色を指定可能

    while(1){
        lighting(pattern1,1500);  //pattern1を1500[ms]出力し続ける

        LedColor pattern2[9];
        setAll(pattern2,RED);    //すべて同じ色ならsetAll()で設定可能
        lighting(pattern2,800);     //pattern2を800[ms]出力し続ける

        setAll(pattern2,OFF);     //pattern2に上書き
        lighting(pattern2,2000);     //pattern2を2000[ms]出力し続ける
    }
}


void loop(){
    demo1();
}

//700[ms]ごとに発光LEDを遷移
void demo1(){
    LedColor pattern[9];
    for(int i=0;i<9;i++){
        setAll(pattern,OFF);
        pattern[i]=WHITE;
        lighting(pattern,700);
    }
}