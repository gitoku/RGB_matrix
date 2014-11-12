#include "digiRW.h"

#define RED B001
#define GREEN B010
#define BLUE B100
#define CYAN B110
#define YELLOW B011
#define MAGENTA B101
#define WHITE B111
#define OFF B000

 void ledInit(){
    pinMode( 0, OUTPUT);
    pinMode( 1, OUTPUT);
    pinMode( 2, OUTPUT);
    pinMode( 3, OUTPUT);
    pinMode( 4, OUTPUT);
    pinMode( 5, OUTPUT);
    pinMode( 6, OUTPUT);
    pinMode( 7, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
    digiWrite( 0, LOW);
    digiWrite( 1, LOW);
    digiWrite( 2, LOW);
    digiWrite( 3, LOW);
    digiWrite( 4, LOW);
    digiWrite(10, LOW);
    digiWrite(11, LOW);
    digiWrite(12, LOW);
    digiWrite(13, LOW);
}


void setAll(byte data[],byte color){
    for(int i=0;i<9;i++) data[i]=color;
}


//色ごとのLEDのON/OFF出力(Anode:正論理)
void colorWrite(byte color){
    digiWrite( 5, color&RED);
    digiWrite( 6, color&GREEN);
    digiWrite( 7, color&BLUE);
}

//9個のLEDのON/OFF出力(Cathode:負論理)
void ledWrite(byte data[],byte bit){
    const int pins[]={0,1,2,3,4,10,11,12,13};
    for(int i=0;i<9;i++) digiWrite( pins[i], !bitRead(data[i],bit));
}


void lighting(byte data[]){
    const int INTERVAL=10;
    static unsigned long last_time=0;
    
    //前回実行(青色発光開始時)からINTERVAL[ms]待つ
    while( (millis()-last_time) > INTERVAL );

    //red
    colorWrite(OFF);
    ledWrite(data,0);
    colorWrite(RED);
    delay(INTERVAL);

    //green
    colorWrite(OFF);
    ledWrite(data,1);
    colorWrite(GREEN);
    delay(INTERVAL);

    //BLUE
    colorWrite(OFF);
    ledWrite(data,2);
    colorWrite(BLUE);
    last_time = millis();
}


void lighting(byte data[],unsigned long wait){
    unsigned long begin = millis();
    while( (millis()-begin)>wait ) lighting(data);
}
