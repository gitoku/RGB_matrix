#include "sounds.h"
#include "digiRW.h"

#define RED B001
#define GREEN B010
#define BLUE B100
#define CYAN B110
#define YELLOW B011
#define MAGENTA B101
#define WHITE B111
#define OFF B000

 void setup(){
    pinMode( 0, OUTPUT);
    pinMode( 1, OUTPUT);
    pinMode( 2, OUTPUT);
    pinMode( 3, OUTPUT);
    pinMode( 4, OUTPUT);
    pinMode( 5, OUTPUT);
    pinMode( 6, OUTPUT);
    pinMode( 7, OUTPUT);
    pinMode( 8, OUTPUT); 
    pinMode( 9, INPUT_PULLUP); 
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

    analogReference(INTERNAL);

    // tutorial();
}

void loop(){
    demo1();
}

//700[ms]ごとに発光LEDを遷移
void demo1(){
    byte pattern[9];
    for(int i=0;i<9;i++){
        setAll(pattern,OFF);
        pattern[i]=WHITE;
        lighting(pattern,700);
    }
}

void tutorial(){
    byte pattern1[9];

    pattern1[0]=RED;    //[RED,GREEN,BLUE]で色を指定
    pattern1[1]=GREEN;
    pattern1[2]=CYAN;    //[CYAN,YELLOW,MAGENTA]から選択可能
    pattern1[3]=RED|BLUE; //(=MAGENTA)色の合成も可能
    pattern1[4]=WHITE;   //[WHITE]を選択可能
    pattern1[5]=RED|GREEN|BLUE;  //(=WHITE)
    pattern1[6]=OFF;     //光らせない時は[OFF]
    pattern1[7]=B001;    //２進数で直接指定でも可[RED:B001,GREEN:B010,BLUE:B100]
    pattern1[8]=B000;    //(=OFF)[0~8]の9個のLEDの色を指定可能

    while(1){
        lighting(pattern1,1500);  //pattern1を1500[ms]出力し続ける

        byte pattern2;
        setAll(pattern2,RED);    //すべて同じ色ならsetAll()で設定可能
        lighting(pattern2,800);     //pattern2を800[ms]出力し続ける

        setAll(pattern2,OFF);     //pattern2に上書き
        lightning(pattern2,2000);     //pattern2を2000[ms]出力し続ける
    }
}

void setAll(byte data[],byte color){
    for(int i=0;i<9;i++) data[i]=color;
}

void lighting(byte data[],int wait){
    unsigned long begin = millis();
    while( (millis()-begin)>wait ) lighting(data);
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