// #include "Oboroduki.h"       // おぼろ月夜
// #include "sikinouta.h"       // 四季の歌
// #include "haurunomaintame.h" // ハウルのメインテーマ
// #include "takibi.h"          // たきび
// #include "kutuganaru.h"      // くつがなる
// #include "hakone.h"          // 箱根八里
// #include "mikannosakuoka.h"  // みかんの花咲く丘
// #include "Wake_up.h"         // Wake up
// #include "ninnjaribanban.h"  // ニンジャりバンバン
#include "senbonzakura.h"    // 千本桜
// #include "RPG.h"             // RPG

// ふるさと
int thisNote_max1 = 45;
int melody1[] = {
  NOTE_C5, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_E5, NOTE_E5, NOTE_F5, NOTE_G5,
  NOTE_F5, NOTE_G5, NOTE_A5, NOTE_E5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_D5, NOTE_B4, NOTE_C5,
  NOTE_D5, NOTE_C5, NOTE_D5, NOTE_G4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_E5, NOTE_F5, NOTE_E5,
  NOTE_F5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_C5, NOTE_D5,
  NOTE_E5, NOTE_F5, NOTE_F5, NOTE_D5, NOTE_C5
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations1[] = {
  4, 4, 4, 4, 8, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 8, 4, 4, 4, 4, 2,
  8, 8, 4, 4, 8, 8, 4, 4, 8, 8,
  4, 8, 8, 8, 4, 4, 4, 4, 4, 8,
  4, 4, 4, 4, 2
};

void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, INPUT_PULLUP);
}

void loop() {
start:
  delay(500);
  int buttonState = 1;
  int cntMs = 1;
  int bottonSet = 0;

start1:
  buttonState = digitalRead(9);
  if (buttonState == LOW ) {
    bottonSet = 1;
  }
  if (cntMs == 0) {
    if (bottonSet == 1) {
      bottonSet = 0;
      goto music1;
    }
    else {
      analogReference(INTERNAL);
      int x = analogRead(5);
      if (x < 260) {
        tone(8, 100, 100);
      }
      else if (x < 280) {
        tone(8, 600, 100);
      }
      else if (x < 300) {
        tone(8, 1100, 100);
      }
      else if (x < 320) {
        tone(8, 1600, 100);
      }
      else if (x < 340) {
        tone(8, 2100, 100);
      }
      else if (x < 360) {
        tone(8, 2600, 100);
      }
      else if (x < 380) {
        tone(8, 3100, 100);
      }
      else if (x < 400) {
        tone(8, 3600, 100);
      }
      else if (x < 420) {
        tone(8, 4100, 100);
      }
      else if (x < 440) {
        tone(8, 4600, 100);
      }
      else {
        tone(8, 5100, 100);
      }
    }
  }
  delay(1);
  cntMs++;
  if (cntMs > 1000) {
    cntMs = 0;
  }
  goto start1;


music1:
  delay(500);
  buttonState = 1;
  for (int thisNote = 0; thisNote < thisNote_max1; thisNote++) {

    int duration = 1000 / noteDurations1[thisNote]; //発音時間を定める
    tone(8, melody1[thisNote], duration); //発音
    int pause = duration * 1.5; //音符の間で時間をあける
    for (cntMs = 0; cntMs < pause; cntMs++)
    {
      buttonState = digitalRead(9);
      if (buttonState == LOW ) {
        bottonSet = 1;
      }
      delay(1);
    }
    if (bottonSet == 1) {
      bottonSet = 0;
      goto music2;
    }
  }
  goto music1;

music2:
  delay(500);
  buttonState = 1;
  for (int thisNote = 0; thisNote < thisNote_max2; thisNote++) {
    int duration = 1000 / noteDurations2[thisNote]; //発音時間を定める
    tone(8, melody2[thisNote], duration);  //発音
    int pause = duration * 1.5;  //音符の間で時間をあける
    for (cntMs = 0; cntMs < pause; cntMs++)
    {
      buttonState = digitalRead(9);
      if (buttonState == LOW ) {
        bottonSet = 1;
      }
      delay(1);
    }
    if (bottonSet == 1) {
      bottonSet = 0;
      goto start;
    }
  }
  goto music2;
}

