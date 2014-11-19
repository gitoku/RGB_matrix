#include "arduino.h"

class PlayMelody{
	public:
		PlayMelody(int _pin){ pin = _pin; };
		void setMelody(int* _melodyArr,int* _durationArr,int _length);	//メロディーの設定
		int play();	//再生(戻り値[1:新しい音の出力][0:前回と同じ音を出力])
		void pause();	//一時停止、再び再生するときは停止したところから
		void stop();	//停止、再び再生するときははじめから
		void moveTo(int _position);	//再生位置移動
		int getPosition();	//再生位置を返す
		int getPitch();	//再生中の音程を返す
		int getDuration();	//再生中の音の残り再生時間を返す
		int isPlaying();	//戻り値[0:再生終了][その他:再生中の音程]
	private:
		int pin;
		int* melodyArr;
		int* durationArr;
		int length;
		unsigned long stopTime;
		int position;
		int nowSound;
};


void PlayMelody::setMelody(int* _melodyArr,int* _durationArr,int _length){
	melodyArr = _melodyArr;
	durationArr = _durationArr;
	length = _length;
	stopTime = 0;
	position = 0;
	nowSound = 0;
    pinMode( pin, OUTPUT); 
}


int PlayMelody::play(){
	if( position > length+1 ) nowSound = 0;	//再生終了

	else if( millis() > stopTime ){ 	//直前の音の再生が終了したら
		int nowDuration = 1000/durationArr[position];
		nowSound = melodyArr[position];
		tone(pin,nowSound,nowDuration);
		stopTime = millis() + (nowDuration*3)/2;
		position++;
		return 1;
	}

	return 0;
}

void PlayMelody::pause(){
	noTone(pin);
	nowSound = 0;
}

void PlayMelody::stop(){
	noTone(pin);
	nowSound = 0;
	position = 0;
}

void PlayMelody::moveTo(int _position){
	if(_position > length) position = 0;
	position = _position;
}


int PlayMelody::getPosition(){ return position; };
int PlayMelody::getPitch(){ return nowSound; };
int PlayMelody::getDuration(){ return (stopTime-millis()); };
int PlayMelody::isPlaying(){ return nowSound; };
