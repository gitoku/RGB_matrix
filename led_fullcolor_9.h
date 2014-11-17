#include "arduino.h"
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
    const int ano_pins[]={7,5,6};
    
    //public
    void init();    //初期化
    void setInterval(int val);  //ダイナミック点灯制御の切り替え周期[ms]
    void set(byte bit,LedColor color);  //{bit}番目のLEDを{color}色に設定
    void setAll(LedColor color);    //すべてのLEDを{color}色に設定
    void lighting();    //設定された状態に発光({interval}[ms]以内に定期的に呼び出しする必要あり)
    void lighting(LedColor data[]); //{data}の定義どうりに発光({interval}[ms]以内に定期的に呼び出しする必要あり)
    void lightingWhile(unsigned long wait);    //設定された状態に{wait}[ms]発光
    void lightingWhile(LedColor data[],unsigned long wait); //{data}のどうりに{wait}[ms]発光

    //private
    void copy9(LedColor in[],LedColor out[]);    //要素9のLedColor配列{in}を同サイズの{out}にコピー
    void colorWrite(LedColor color);    //アノード側LEDを{color}に設定して出力
    void ledWrite(LedColor data[],byte bit);    //カソード側LEDを{data}のどうり出力(ただしアノード側状態を{bit}で指定)
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

void Led::copy9(LedColor in[],LedColor out[]){
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
    while( (millis()-last_time) < interval );

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
    copy9(data,output);
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
