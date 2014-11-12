#include "sounds.h"
#include "led_fullcolor_9.h"

#define BUZZER_PIN 8
#define SWITCH_PIN 9


void setup(){
    pinMode( BUZZER_PIN, OUTPUT); 
    pinMode( SWITCH_PIN, INPUT_PULLUP); 
    analogReference(INTERNAL);
    Led::init();
}

void loop(){
    // tutorial();
    demo();
    play(melody1,noteDurations1,82);
}


int play(int melodyArr[],int durationArr[],int length){
	static unsigned long stopTime = 0;
	static int now = 0;
	static int nowSound;

	if(millis()>stopTime){ 
		int duration = 1000/durationArr[now];
		nowSound = melodyArr[now];
		tone(BUZZER_PIN,nowSound,duration);
		stopTime = millis() + (duration*3)/2;
		now++;
	}

	if( now > length+1 ) return 0;	//再生終了
	else return nowSound;	//再生中
}


void tutorial(){
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
}

void demo(){
    //700[ms]ごとに発光LEDを遷移
    for(int i=0;i<9;i++){
        Led::setAll(OFF);
        Led::set(i,WHITE);
        Led::lightingWhile(700);
    }
}