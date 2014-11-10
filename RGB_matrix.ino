#include "sounds.h"

void setup() {
    pinMode(8, OUTPUT); 
    pinMode(9, INPUT_PULLUP); 
    pinMode(5, OUTPUT);//カソード下
    pinMode(6, OUTPUT);//カソード中
    pinMode(7, OUTPUT);//カソード上
    pinMode(0, OUTPUT);//アノード１
    pinMode(1, OUTPUT);//アノード２
    pinMode(2, OUTPUT);//アノード３
    pinMode(3, OUTPUT);//アノード４
    pinMode(4, OUTPUT);//アノード５
    pinMode(10, OUTPUT);//アノード６
    pinMode(11, OUTPUT);//アノード７
    pinMode(12, OUTPUT);//アノード８
    pinMode(13, OUTPUT);//アノード９
}

void loop() {
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);

    start:
    delay(500);
    int buttonState=1;

    start1:
    buttonState=digitalRead(9); 
    if (buttonState ==LOW ) {goto music1;}
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
    goto start1;


    music1:
    delay(500);
    buttonState=1;
    for (int thisNote = 0; thisNote < 82; thisNote++) { 
       buttonState=digitalRead(9); 
       if (buttonState ==LOW ) {goto music2;}
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
    goto music1;

    music2:
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
    if (buttonState ==LOW ) {goto start;}
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
    goto music2;  
}
