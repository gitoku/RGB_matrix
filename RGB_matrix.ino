#include "sounds.h"

void setup() {
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
}

const int MODE0=0;
const int MODE1=1;
const int MODE2=2;

int buttonState=1;
void loop() {
    static int next_mode = MODE0;
    if(next_mode==MODE0)      next_mode = start1();
    else if(next_mode==MODE1) next_mode = music1();
    else if(next_mode==MODE2) next_mode = music2();
}

int start1(){
    delay(500);
    buttonState=digitalRead(9); 
    if (buttonState ==LOW ) return MODE1;
    else{
        analogReference(INTERNAL);
        int x=analogRead(5);
        if(x<260){tone(8, 100,100);}
        else if(x<280){tone(8, 600,100);}
        else if(x<300){tone(8, 1100,100);}
        else if(x<320){tone(8, 1600,100);}
        else if(x<340){tone(8, 2100,100);}
        else if(x<360){tone(8, 2600,100);}
        else if(x<380){tone(8, 3100,100);}
        else if(x<400){tone(8, 3600,100);}
        else if(x<420){tone(8, 4100,100);}
        else if(x<440){tone(8, 4600,100);}
        else{tone(8, 5100,100);}
        delay(1000);
    }
    return MODE0;
}

int music1(){
    delay(500);
    buttonState=1;
    for (int thisNote = 0; thisNote < 82; thisNote++) { 
       buttonState=digitalRead(9); 
       if (buttonState ==LOW ) return MODE2;
       if(thisNote == 0){
            digitalWrite(5,LOW);
            digitalWrite(6,LOW);
            digitalWrite(7,LOW);
        }
        else if  (thisNote==5){
            digitalWrite(5,HIGH);
            digitalWrite(6,LOW);
            digitalWrite(7,LOW);
        }
        else if  (thisNote==10){
            digitalWrite(5,LOW);
            digitalWrite(6,HIGH);
            digitalWrite(7,LOW);
        }
        else if  (thisNote==15){
            digitalWrite(5,LOW);
            digitalWrite(6,LOW);
            digitalWrite(7,HIGH);
        } 
        else if  (thisNote==20){
            digitalWrite(5,HIGH);
            digitalWrite(6,LOW);
            digitalWrite(7,LOW);
        }
        else if  (thisNote==25){
            digitalWrite(5,LOW);
            digitalWrite(6,HIGH);
            digitalWrite(7,LOW);
        }
        else if  (thisNote==30){
            digitalWrite(5,LOW);
            digitalWrite(6,LOW);
            digitalWrite(7,HIGH);
        }
        else if  (thisNote==35){
            digitalWrite(5,HIGH);
            digitalWrite(6,LOW);
            digitalWrite(7,HIGH);
        } 
        else if  (thisNote==40){
            digitalWrite(5,HIGH);
            digitalWrite(6,HIGH);
            digitalWrite(7,LOW);
        }
        else if  (thisNote==45){
            digitalWrite(5,LOW);
            digitalWrite(6,HIGH);
            digitalWrite(7,HIGH);
        }
        else if  (thisNote==50){
            digitalWrite(5,HIGH);
            digitalWrite(6,LOW);
            digitalWrite(7,HIGH);
        }
        else if  (thisNote==55){
            digitalWrite(5,HIGH);
            digitalWrite(6,HIGH);
            digitalWrite(7,LOW);
        } 
        else if  (thisNote==60){
            digitalWrite(5,LOW);
            digitalWrite(6,HIGH);
            digitalWrite(7,HIGH);
        }
        else if  (thisNote==65){
            digitalWrite(5,HIGH);
            digitalWrite(6,LOW);
            digitalWrite(7,HIGH);
        }
        else if  (thisNote==70){
            digitalWrite(5,HIGH);
            digitalWrite(6,HIGH);
            digitalWrite(7,LOW);
        }
        else if  (thisNote==75){
            digitalWrite(5,LOW);
            digitalWrite(6,HIGH);
            digitalWrite(7,HIGH);
        } 
        else if  (thisNote==80){
            digitalWrite(5,HIGH);
            digitalWrite(6,HIGH);
            digitalWrite(7,HIGH);
        }  
        int duration = 1000/noteDurations1[thisNote]; //発音時間を定める
        tone(8, melody1[thisNote],duration);  //発音
        int pause = duration * 1.5; //音符の間で時間をあける
        delay(pause);
    }
    return MODE1;
}

int music2(){
    delay(500);
    buttonState=1;
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
        buttonState=digitalRead(9); 
        if (buttonState ==LOW ) return MODE0;
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
    return MODE2;
}