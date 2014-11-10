#include "sounds.h"

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

    digitalWrite( 0, LOW);
    digitalWrite( 1, LOW);
    digitalWrite( 2, LOW);
    digitalWrite( 3, LOW);
    digitalWrite( 4, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);

    analogReference(INTERNAL);
}

void loop(){
    const int MODE0=0,MODE1=1,MODE2=2;
    static int mode = MODE0;

    //このタイミングでスイッチ押されていれば、モード変更
    if(!digitalRead(9)) mode=(++mode)%3;

    if(mode==MODE0)      start1();
    else if(mode==MODE1) music1();
    else if(mode==MODE2) music2();

    delay(500);
}

void start1(){
    //電源電圧を取得して11段階で評価
    //[0:260以下][1:280以下]...[9:440以下][10:440を超える]
    int voltage = constrain( analogRead(5)/20 - 13,0,10 );

    //電圧に対応した音程を算出[100~5100]
    int pitch = 100 + 500*voltage;
    tone(8, pitch, 100);
    delay(1000);
}

void music1(){
    for (int thisNote = 0; thisNote < 82; thisNote++) {
       if(thisNote == 0){
            digitalWrite(5,LOW);
            digitalWrite(6,LOW);
            digitalWrite(7,LOW);
        }
        else if(thisNote==5){
            digitalWrite(5,HIGH);
            digitalWrite(6,LOW);
            digitalWrite(7,LOW);
        }
        else if(thisNote==10){
            digitalWrite(5,LOW);
            digitalWrite(6,HIGH);
            digitalWrite(7,LOW);
        }
        else if(thisNote==15){
            digitalWrite(5,LOW);
            digitalWrite(6,LOW);
            digitalWrite(7,HIGH);
        } 
        else if(thisNote==20){
            digitalWrite(5,HIGH);
            digitalWrite(6,LOW);
            digitalWrite(7,LOW);
        }
        else if(thisNote==25){
            digitalWrite(5,LOW);
            digitalWrite(6,HIGH);
            digitalWrite(7,LOW);
        }
        else if(thisNote==30){
            digitalWrite(5,LOW);
            digitalWrite(6,LOW);
            digitalWrite(7,HIGH);
        }
        else if(thisNote==35){
            digitalWrite(5,HIGH);
            digitalWrite(6,LOW);
            digitalWrite(7,HIGH);
        } 
        else if(thisNote==40){
            digitalWrite(5,HIGH);
            digitalWrite(6,HIGH);
            digitalWrite(7,LOW);
        }
        else if(thisNote==45){
            digitalWrite(5,LOW);
            digitalWrite(6,HIGH);
            digitalWrite(7,HIGH);
        }
        else if(thisNote==50){
            digitalWrite(5,HIGH);
            digitalWrite(6,LOW);
            digitalWrite(7,HIGH);
        }
        else if(thisNote==55){
            digitalWrite(5,HIGH);
            digitalWrite(6,HIGH);
            digitalWrite(7,LOW);
        } 
        else if(thisNote==60){
            digitalWrite(5,LOW);
            digitalWrite(6,HIGH);
            digitalWrite(7,HIGH);
        }
        else if(thisNote==65){
            digitalWrite(5,HIGH);
            digitalWrite(6,LOW);
            digitalWrite(7,HIGH);
        }
        else if(thisNote==70){
            digitalWrite(5,HIGH);
            digitalWrite(6,HIGH);
            digitalWrite(7,LOW);
        }
        else if(thisNote==75){
            digitalWrite(5,LOW);
            digitalWrite(6,HIGH);
            digitalWrite(7,HIGH);
        } 
        else if(thisNote==80){
            digitalWrite(5,HIGH);
            digitalWrite(6,HIGH);
            digitalWrite(7,HIGH);
        }  
        int duration = 1000/noteDurations1[thisNote]; //発音時間を定める
        tone(8, melody1[thisNote],duration);  //発音
        int pause = duration * 1.5; //音符の間で時間をあける
        delay(pause);
    }
}

void music2(){
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);

    for (int thisNote = 0; thisNote < 68; thisNote++) {
        digitalWrite(5,HIGH);
        digitalWrite(6,HIGH);
        digitalWrite(7,HIGH);
        int duration = 1000/noteDurations2[thisNote];//発音時間を定める

        tone(8, melody2[thisNote],duration);   //発音 
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
        digitalWrite(7,LOW);
        int pause = duration * 1.5;  //音符の間で時間をあける
        
        delay(pause);
    }
}