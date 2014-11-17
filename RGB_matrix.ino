#include "sounds.h"
#include "playMelody.h"
#include "led_fullcolor_9.h"

#define BUZZER_PIN 8
#define SWITCH_PIN 9
#define isPress() (!digitalRead(SWITCH_PIN))

PlayMelody melodyA(BUZZER_PIN);
PlayMelody melodyB(BUZZER_PIN);
PlayMelody melodyC(BUZZER_PIN);


void setup(){
    pinMode( SWITCH_PIN, INPUT_PULLUP); 
    analogReference(INTERNAL);
    randomSeed(analogRead(0));

    Led::init();
    Led::setInterval(3);

    melodyA.setMelody( rpg_Melody, rpg_Duration, rpg_Length);
    melodyB.setMelody( senbonzakura_Melody, senbonzakura_Duration, senbonzakura_Length);
    melodyC.setMelody( ninjaribanban_Melody, ninjaribanban_Duration, ninjaribanban_Length);
}
//曲リスト
//[shikinouta] 四季の歌     音符数：83
//[haurunomame] ハウルのメインテーマ  音符数：69
//[takibi] たきび            音符数：49
//[wakeup] Wake up(120) 
//[rpg] RPG(sekai no owari)46
//[oboroduki] おぼろ月夜　　音符数：61
//[ninnjaribanban] ニンジャりバンバン（114） 
//[kutsuganaru] くつがなる       音符数：66
//[mikannnohanasakuoka] みかんの花咲く丘  　音符数：56
//[senbonzakura] 千本桜(配信用)112 
//[hakonehachiri] 箱根八里    音符数:163


void loop(){
    
    //音が変わるたびに発光箇所が変わる
    while( !isPress() ){
        delay(500);
        melodyA.play();
        while( melodyA.isPlaying() && !isPress() ){ 
            static unsigned long cnt=0;
            cnt += melodyA.play();
            Led::setAll(OFF);
            Led::set(cnt%9,WHITE);
            Led::lighting();
        }
        melodyA.stop();
        Led::setAll(OFF);
        Led::lighting();
    }
    while( isPress() );  //スイッチが離されるまで待つ



    //音の高さによって色が変わる
    while( !isPress() ){
        delay(500);
        melodyB.play();
        while( melodyB.isPlaying() && !isPress()){ 
            melodyB.play();
            LedColor color = int2color( melodyB.getPitch()%7+1 );
            Led::setAll(color);
            Led::lighting();
        }
        melodyB.stop();
        Led::setAll(OFF);
        Led::lighting();
    }
    while( isPress() );  //スイッチが離されるまで待つ


  
    //とにかくカラフル
    while( !isPress() ){
        delay(500);
        melodyC.play();
        while( melodyC.isPlaying() && !isPress() ){ 
            if( melodyC.play() ){
                for(int i=0;i<3;i++) Led::set(random(0,8),int2color(random(0,7)));
            }
            Led::lighting();
        }
        melodyC.stop();
        Led::setAll(OFF);
        Led::lighting();
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
