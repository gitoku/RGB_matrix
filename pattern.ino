

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
        Led::set(cnt%9,enable_color[0]);
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
                Led::set(random(0,8),int2color(random(0,100),enable_color,color_num));
        Led::lighting();
        if( isPress() ) return false;  //スイッチが押されたら再生停止
    }
    melody.stop();
    Led::setAll(OFF);
    Led::lighting();
    return true;
}
