#ifndef pattern_h
#define pattern_h
#include "playMelody.h"
#include "led_fullcolor_9.h"


#define BUZZER_PIN 8
#define SWITCH_PIN 9
#define isPress() (!digitalRead(SWITCH_PIN))
#define playPattern(x,y) playPat(x,y,(int)(sizeof(y)/sizeof(y[0])))

int playPat(int (*pattern)(LedColor*,int),LedColor*,int);
int pos2turn(int pos);
LedColor int2color(int num);
LedColor int2color(int num,LedColor enable_color[],int color_num);


PlayMelody melody(BUZZER_PIN);
LedColor allcolor[7] = {WHITE,RED,GREEN,BLUE,CYAN,YELLOW,MAGENTA};


int playPat(int (*pattern)(LedColor*,int),LedColor enable_color[],int color_num){
    while( pattern(enable_color,color_num) );
    while( isPress() );
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

LedColor int2color(int num,LedColor enable_color[],int color_num){
    return enable_color[num%color_num];
}






int patternFlushPoint(LedColor enable_color[],int color_num){
    delay(500);
    melody.play();
    while( melody.isPlaying() ){   //曲が終わるまで再生を継続
        static unsigned long cnt=0;
        cnt += melody.play();
        Led::setAll(OFF);
        Led::set(pos2turn(cnt),enable_color[(cnt)%color_num]);
        Led::lighting();
        if( isPress() ) return false;   //スイッチが押されたら再生停止
    }
    melody.stop();
    Led::setAll(OFF);
    Led::lighting();
    return true;
}


int patternFlushPointSlow(LedColor enable_color[],int color_num){
    delay(500);
    melody.play();
    while( melody.isPlaying() ){   //曲が終わるまで再生を継続
        static unsigned long cnt=0;
        int now = melody.play();
        cnt += now;
        if((cnt%4)==1 && now) Led::setAll(enable_color[(cnt/3)%color_num]); //3音再生ごとに色変更
        Led::lighting();
        if( isPress() ) return false;   //スイッチが押されたら再生停止
    }
    melody.stop();
    Led::setAll(OFF);
    Led::lighting();
    return true;
}

int patternFlushC(LedColor enable_color[],int color_num){
    delay(500);
    melody.play();
    while( melody.isPlaying() ){   //曲が終わるまで再生を継続
        static unsigned long cnt=0;
        cnt += melody.play();
        Led::setAll(enable_color[0]);
        Led::set(4,OFF);
        Led::set(pos2turn(cnt),enable_color[1]);
        Led::set(pos2turn(cnt+1),enable_color[1]);
        Led::set(pos2turn(cnt+2),enable_color[1]);
        Led::lighting();
        if( isPress() ) return false;   //スイッチが押されたら再生停止
    }
    melody.stop();
    Led::setAll(OFF);
    Led::lighting();
    return true;
}

int pos2turn(int pos){
    switch (pos%8) {
        case 0: return 0;
        case 1: return 1;
        case 2: return 2;
        case 3: return 5;
        case 4: return 8;
        case 5: return 7;
        case 6: return 6;
        case 7: return 3;
    }
}


int patternFlushTurn(LedColor enable_color[],int color_num){
    delay(500);
    melody.play();
    while( melody.isPlaying() ){   //曲が終わるまで再生を継続
        static unsigned long cnt=0;
        static int pos=0;
        cnt += melody.play();
        pos = (int)(melody.getRestRate()*9)%9;
        if(pos==0) Led::setAll(OFF);
        else Led::set(pos2turn(pos-1),enable_color[cnt%color_num]);
        Led::lighting();
        if( isPress() ) return false;   //スイッチが押されたら再生停止
    }
    melody.stop();
    Led::setAll(OFF);
    Led::lighting();
    return true;
}

int patternFlushTurnC(LedColor enable_color[],int color_num){
    delay(500);
    melody.play();
    while( melody.isPlaying() ){   //曲が終わるまで再生を継続
        static unsigned long cnt=0;
        static int pos=0;
        cnt += melody.play();
        pos = (int)(melody.getRestRate()*9)%9;
        Led::setAll(enable_color[0]);
        Led::set(4,OFF);
        Led::set(pos2turn(pos),OFF);
        Led::set(pos2turn(pos+1),OFF);
        Led::set(pos2turn(pos+2),OFF);
        Led::set(pos2turn(pos+3),OFF);
        Led::lighting();
        if( isPress() ) return false;   //スイッチが押されたら再生停止
    }
    melody.stop();
    Led::setAll(OFF);
    Led::lighting();
    return true;
}


int patternPitch2Color(LedColor enable_color[],int color_num){
    delay(500);
    melody.play();
    while( melody.isPlaying() ){   //曲が終わるまで再生を継続
        melody.play();
        //現在再生中の音程から色を決定
        LedColor color = int2color( melody.getPitch(),enable_color,color_num );
        Led::setAll(color);
        Led::lighting();
        if( isPress() ) return false;  //スイッチが押されたら再生停止
    }
    melody.stop();
    Led::setAll(OFF);
    Led::lighting();
    return true;
}



int patternRandom3(LedColor enable_color[],int color_num){
    delay(500);
    melody.play();
    while( melody.isPlaying() ){   //曲が終わるまで再生を継続
        if( melody.play() )    //新しい音の再生が始まったら
            for(int i=0;i<3;i++)    //３回「ランダムに選んだLEDをランダムな色に設定」する
                Led::set(random(0,9),int2color(random(0,100),enable_color,color_num));
        Led::lighting();
        if( isPress() ) return false;  //スイッチが押されたら再生停止
    }
    melody.stop();
    Led::setAll(OFF);
    Led::lighting();
    return true;
}

int patternRandom3Blink(LedColor enable_color[],int color_num){
    delay(500);
    melody.play();
    while( melody.isPlaying() ){   //曲が終わるまで再生を継続
        static int state = 0;
        int now = melody.play();
        state += now;
        if( state%4==1 && now )    //新しい音の再生が始まったら
            for(int i=0;i<3;i++)    //３回「ランダムに選んだLEDをランダムな色に設定」する
                for(int j=0;j<9;j++)
                    Led::set(j,int2color(random(0,100),enable_color,color_num));
        else if( state%4==0 && now) Led::setAll(OFF);
        Led::lighting();
        if( isPress() ) return false;  //スイッチが押されたら再生停止
    }
    melody.stop();
    Led::setAll(OFF);
    Led::lighting();
    return true;
}


#endif