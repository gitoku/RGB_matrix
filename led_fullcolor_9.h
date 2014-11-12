#include "digiRW.h"

enum LedColor {
    RED = B001,
    GREEN = B010,
    BLUE = B100,
    CYAN = B110,
    YELLOW = B011,
    MAGENTA = B101,
    WHITE = B111,
    OFF = B000
};


namespace Led{
    LedColor output[9];
    int interval;
    const int cat_pins[]={0,1,2,3,4,10,11,12,13};
    const int ano_pins[]={5,6,7};

    void init();
    void setInterval(int val);
    void set(byte bit,LedColor color);
    void setAll(LedColor color);
    void copy(LedColor in[],LedColor out[]);
    void colorWrite(LedColor color);
    void ledWrite(LedColor data[],byte bit);
    void lighting();
    void lighting(LedColor data[]);
    void lightingWhile(LedColor data[],unsigned long wait);
    void lightingWhile(unsigned long wait);
}

 void Led::init(){
    for(int i=0; i<9; i++){ 
        pinMode( cat_pins[i], OUTPUT);
        digiWrite(cat_pins[i],LOW);
    }
    for(int i=0; i<3; i++) pinMode( ano_pins[i], OUTPUT);

    setAll(OFF);
    interval=10;
}

void Led::setInterval(int val){
    interval=val;
}

void Led::set(byte bit,LedColor color){
    output[bit]=color;
}

void Led::setAll(LedColor color){
    for(int i=0;i<9;i++) output[i]=color;
}

void Led::copy(LedColor in[],LedColor out[]){
    for(int i=0;i<9;i++) out[i]=in[i];
}


//色ごとのLEDのON/OFF出力(Anode:正論理)
void Led::colorWrite(LedColor color){
    digiWrite( ano_pins[0], color&RED);
    digiWrite( ano_pins[1], color&GREEN);
    digiWrite( ano_pins[2], color&BLUE);
}

//9個のLEDのON/OFF出力(Cathode:負論理)
void Led::ledWrite(LedColor data[],byte bit){
    for(int i=0;i<9;i++) digiWrite( cat_pins[i], !bitRead(data[i],bit));
}


void Led::lighting(){
    static unsigned long last_time=0;
    
    //前回実行(青色発光開始時)からinterval[ms]待つ
    while( (millis()-last_time) > interval );

    //red
    colorWrite(OFF);
    ledWrite(output,0);
    colorWrite(RED);
    delay(interval);

    //green
    colorWrite(OFF);
    ledWrite(output,1);
    colorWrite(GREEN);
    delay(interval);

    //BLUE
    colorWrite(OFF);
    ledWrite(output,2);
    colorWrite(BLUE);
    last_time = millis();
}

void Led::lighting(LedColor data[]){
    copy(data,output);
    lighting();
}

void Led::lightingWhile(LedColor data[],unsigned long wait){
    unsigned long begin = millis();
    while( (millis()-begin)>wait ) lighting(data);
}


void Led::lightingWhile(unsigned long wait){
    unsigned long begin = millis();
    while( (millis()-begin)>wait ) lighting();
}
