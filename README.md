RGB matrix
==========

八頭ものづくり教室(第三回)スケッチ


Pin assign
----------
|pin name|pin mode|connect circuit|
|:-------|:-------|:--------------|
|d0      |OUT     |Anode1
|d1      |OUT     |Anode2
|d2      |OUT     |Anode3
|d3      |OUT     |Anode4
|d4      |OUT     |Anode5
|d5      |OUT     |Cathode green
|d6      |OUT     |Cathode blue
|d7      |OUT     |Cathode red
|d8      |OUT     |Buzzer
|d9      |PULLUP  |Tact switch
|d10     |OUT     |Anode6
|d11     |OUT     |Anode7
|d12     |OUT     |Anode8
|d13     |OUT     |Anode9

Files
------

|ファイル名|内容|
|:-------|:---|
|RGB_matrix.ino|スケッチのメイン|
|led_fullcolor_9.h|9個のフルカラーLEDをダイナミック点灯制御するためのライブラリ|
|digiRW.h|高速にIO処理を行うためのライブラリ|
|playMelody.h|メロディの再生のためのライブラリ|
|sounds.h|メロディを記述|
|README.md|このファイル|
|LICENCE|The MIT License|
|reference**(フォルダ)**|参考プロジェクト|


How to Use
----------

### Led
namespaceで定義している

#### functions
    void init();    //初期化
    void setInterval(int val);  //ダイナミック点灯制御の切り替え周期[ms]
    void set(byte bit,LedColor color);  //{bit}番目のLEDを{color}色に設定
    void setAll(LedColor color);    //すべてのLEDを{color}色に設定
    void lighting();    //設定された状態に発光({interval}[ms]以内に定期的に呼び出しする必要あり)
    void lighting(LedColor data[]); //{data}の定義どうりに発光({interval}[ms]以内に定期的に呼び出しする必要あり)
    void lightingWhile(unsigned long wait);    //設定された状態に{wait}[ms]発光
    void lightingWhile(LedColor data[],unsigned long wait); //{data}のどうりに{wait}[ms]発光

#### tutorial
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
    Led::lightingWhile(pattern1,1500);  //pattern1を1500[ms]出力し続ける

    Led::setAll(OFF);
    Led::set(0,BLUE);    //set(led,color):指定ledを指定色に設定
    Led::set(3,RED);
    Led::set(5,GREEN);
    Led::set(8,BLUE);
    Led::lightingWhile(800);     //設定済みの色で800[ms]出力し続ける

    Led::setAll(OFF);     //すべて同じ色ならsetAll()で設定可能
    Led::lightingWhile(2000);     //設定済みの色で2000[ms]出力し続ける

### PlayMelody
classとして定義している  
曲ごとに宣言する想定

#### functions
	PlayMelody(int pin);
	void setMelody(int* melodyArr,int* durationArr,int _length);	//メロディーの設定
	int play();	//再生(戻り値[0:再生終了][その他:再生中の音程])
	void pause();	//一時停止、再び再生するときは停止したところから
	void stop();	//停止、再び再生するときははじめから
	void moveTo(int _position);	//再生位置移動
	int getPosition();	//再生位置を返す
	int getPitch();	//再生中の音程を返す
	int getDuration();	//再生中の音の残り再生時間を返す

#### sample
曲の再生と1000[ms]の無音を交互に繰り返すスケッチ
(曲はsound.h内に定義)

	#include "sounds.h"
	#include "playMelody.h"
	#define BUZZER_PIN 8

	PlayMelody song1(BUZZER_PIN);
	void setup(){
	    song1.setMelody(melody1,noteDurations1,82);
	}
	void loop(){
	    while( song1.play() );
	    song1.stop();
	    delay(1000);
	}