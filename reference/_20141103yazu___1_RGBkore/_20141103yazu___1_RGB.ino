
#define NOTE_A1  55//ラ
#define NOTE_AS1 58
#define NOTE_B1  62//シ
#define NOTE_C2  65//ド
#define NOTE_CS2 69
#define NOTE_D2  73//レ
#define NOTE_DS2 78
#define NOTE_E2  82//ミ
#define NOTE_F2  87//ファ
#define NOTE_FS2 92
#define NOTE_G2  98//ソ
#define NOTE_GS2 104 //半音上げ
#define NOTE_A2  110//ラ
#define NOTE_AS2 117
#define NOTE_B2  123//シ
#define NOTE_C3  131//ド
#define NOTE_CS3 139
#define NOTE_D3  147//レ
#define NOTE_DS3 156
#define NOTE_E3  165//ミ
#define NOTE_F3  175//ファ
#define NOTE_FS3 185
#define NOTE_G3  196//ソ
#define NOTE_GS3 208
#define NOTE_A3  220//ラ
#define NOTE_AS3 233
#define NOTE_B3  247//シ
#define NOTE_C4  262//ド
#define NOTE_CS4 277
#define NOTE_D4  294//レ
#define NOTE_DS4 311
#define NOTE_E4  330//ミ
#define NOTE_F4  349//ファ
#define NOTE_FS4 370
#define NOTE_G4  392//ソ
#define NOTE_GS4 415
#define NOTE_A4  440//ラ
#define NOTE_AS4 466
#define NOTE_B4  494//シ
#define NOTE_C5  523//ド
#define NOTE_CS5 554
#define NOTE_D5  587//レ
#define NOTE_DS5 622
#define NOTE_E5  659//ミ
#define NOTE_F5  698//ファ
#define NOTE_FS5 740
#define NOTE_G5  784//ソ
#define NOTE_GS5 831
#define NOTE_A5  880//ラ
#define NOTE_AS5 932
#define NOTE_B5 988//シ
#define NOTE_C6  1047//ド
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978








// 四季の歌
int melody1[] = {
NOTE_E4,NOTE_E4,NOTE_D4,NOTE_C4,NOTE_D4,NOTE_C4,NOTE_B3,NOTE_A3,NOTE_A3,NOTE_A3,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_D4,NOTE_C4,NOTE_D4,NOTE_F4,
NOTE_E4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_D4,NOTE_D4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_C4,NOTE_A3,NOTE_B3,NOTE_E4,NOTE_D4,NOTE_C4,NOTE_B3,NOTE_C4,
NOTE_A3,NOTE_E4,NOTE_A4,NOTE_C5,NOTE_B4,NOTE_A4,NOTE_B4,NOTE_C5,NOTE_D5,NOTE_B4,NOTE_C5,NOTE_D5,NOTE_E5,NOTE_E5,NOTE_E5,NOTE_D5,NOTE_C5,NOTE_D5,NOTE_C5,NOTE_B4,
NOTE_A4,NOTE_A4,NOTE_A4,NOTE_F5,NOTE_F5,NOTE_E5,NOTE_D5,NOTE_C5,NOTE_D5,NOTE_F5,NOTE_E5,NOTE_F5,NOTE_F5,NOTE_E5,NOTE_D5,NOTE_D5,NOTE_F5,
NOTE_E5,NOTE_E5,NOTE_C5,NOTE_A4,NOTE_C5,NOTE_B4,NOTE_E5,NOTE_D5,NOTE_C5,NOTE_B4,NOTE_C5,NOTE_A4
  
  
} ;
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations1[] = {
4,8,8,16,16,16,16,4,4,2,4,8,8,16,16,16,16,
1,4,8,8,4,8,8,4,8,8,2,4,4,16,16,16,16,
2,16,16,16,16,16,16,16,16,16,16,16,1,4,8,8,16,16,16,16,
4,4,2,4,8,8,16,16,16,16,1,4,8,8,4,8,8,
4,8,8,4,4,4,4,16,16,16,16,1
  };

// ハウルのメインテーマ  
int melody2[] = {
  NOTE_AS4,NOTE_C5,NOTE_AS4,NOTE_C5,NOTE_AS4,NOTE_C5,NOTE_A4,NOTE_AS4,NOTE_A4,NOTE_AS4,NOTE_A4,NOTE_AS4,NOTE_G4,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_FS4,NOTE_E4,NOTE_DS4,
  NOTE_D3,NOTE_A3,NOTE_D4,NOTE_A4,
  NOTE_D4,NOTE_G4,NOTE_AS4,NOTE_D5,NOTE_D5,NOTE_C5,NOTE_AS4,NOTE_A4,NOTE_AS4,
  NOTE_G4,NOTE_AS4,NOTE_D5,NOTE_G5,NOTE_G5,NOTE_G5,NOTE_A5,NOTE_F5,NOTE_DS5,NOTE_F5,
  NOTE_A4,NOTE_D5,NOTE_F5,NOTE_A5,NOTE_G5,NOTE_G5,NOTE_F5,NOTE_E5,NOTE_DS5,NOTE_E5,NOTE_G5,NOTE_F5,
  NOTE_E5,NOTE_D5,NOTE_CS5,NOTE_D5,NOTE_D5,NOTE_C5,NOTE_D5,NOTE_C5,NOTE_AS4,NOTE_A4,NOTE_B4,NOTE_CS5,NOTE_D5

} ;
int noteDurations2[] = {
  8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,2,
  8,8,8,2,
  4,4,4,2,4,4,4,4,1,
  4,4,4,2,4,4,4,8,8,1,
  4,4,4,2,3,8,8,8,8,8,2,4,
  8,8,8,8,4,8,8,8,8,4,8,4,1
  };



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
