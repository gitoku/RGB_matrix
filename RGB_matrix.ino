#include <avr/pgmspace.h> 
#include "sounds_flash.h"
#include "playMelody.h"
#include "led_fullcolor_9.h"

#define BUZZER_PIN 8
#define SWITCH_PIN 9
#define isPress() (!digitalRead(SWITCH_PIN))

PlayMelody melody(BUZZER_PIN);

void setup(){
    pinMode( SWITCH_PIN, INPUT_PULLUP); 
    analogReference(INTERNAL);
    randomSeed(analogRead(0));

    Led::init();
    Led::setInterval(3);
}


//曲リスト
//[shikinouta] 四季の歌     音符数：83
//[haurunomaintame] ハウルのメインテーマ  音符数：69
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
    

    
    
        //とにかくカラフル        
    melody.setMelody( haurunomaintame_Melody, haurunomaintame_Duration, haurunomaintame_Length);
    while( patternRandom3() );   //スイッチが押されるまで繰り返す
    while( isPress() );  //スイッチが離されるまで待つ
    
    
        //とにかくカラフル        
    melody.setMelody( shikinouta_Melody, shikinouta_Duration, shikinouta_Length);
    while( patternRandom3() );   //スイッチが押されるまで繰り返す
    while( isPress() );  //スイッチが離されるまで待つ
    
    
        //とにかくカラフル        
    melody.setMelody( wakeup_Melody, wakeup_Duration, wakeup_Length);
    while( patternRandom3() );   //スイッチが押されるまで繰り返す
    while( isPress() );  //スイッチが離されるまで待つ

    //音が変わるたびに発光箇所が変わる
    melody.setMelody( rpg_Melody, rpg_Duration, rpg_Length);
    while( patternFlushPoint() );//スイッチが押されるまで繰り返す
    while( isPress() );  //スイッチが離されるまで待つ


    //音の高さによって色が変わる
    melody.setMelody( senbonzakura_Melody, senbonzakura_Duration, senbonzakura_Length);
    while( patternPitch2Color() );  //スイッチが押されるまで繰り返す
    while( isPress() );  //スイッチが離されるまで待つ

  
    //とにかくカラフル        
    melody.setMelody( ninjaribanban_Melody, ninjaribanban_Duration, ninjaribanban_Length);
    while( patternRandom3() );   //スイッチが押されるまで繰り返す
    while( isPress() );  //スイッチが離されるまで待つ
    
    
        //とにかくカラフル        
    melody.setMelody( takibi_Melody, takibi_Duration, takibi_Length);
    while( patternRandom3() );   //スイッチが押されるまで繰り返す
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

int patternFlushPoint(){
    delay(500);
    melody.play();
    while( melody.isPlaying() ){   //曲が終わるまで再生を継続
        static unsigned long cnt=0;
        cnt += melody.play();
        Led::setAll(OFF);
        Led::set(cnt%9,WHITE);
        Led::lighting();
        if( isPress() ) return false;   //スイッチが押されたら再生停止
    }
    melody.stop();
    Led::setAll(OFF);
    Led::lighting();
    return true;
}

int patternPitch2Color(){
    delay(500);
    melody.play();
    while( melody.isPlaying() ){   //曲が終わるまで再生を継続
        melody.play();
        //現在再生中の音程から色を決定
        LedColor color = int2color( melody.getPitch()%7+1 );
        Led::setAll(color);
        Led::lighting();
        if( isPress() ) return false;  //スイッチが押されたら再生停止
    }
    melody.stop();
    Led::setAll(OFF);
    Led::lighting();
    return true;
}

int patternRandom3(){
    delay(500);
    melody.play();
    while( melody.isPlaying() ){   //曲が終わるまで再生を継続
        if( melody.play() )    //新しい音の再生が始まったら
            for(int i=0;i<3;i++)    //３回「ランダムに選んだLEDをランダムな色に設定」する
                Led::set(random(0,8),int2color(random(0,7)));
        Led::lighting();
        if( isPress() ) return false;  //スイッチが押されたら再生停止
    }
    melody.stop();
    Led::setAll(OFF);
    Led::lighting();
    return true;
}
