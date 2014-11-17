// おぼろ月夜　　音符数：61

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
#define NOTE_R   1

int thisNote_max2 = 61;

int melody2[] = {
  NOTE_E5,NOTE_E5,NOTE_C5,NOTE_D5,NOTE_E5,NOTE_G5,
  NOTE_G5,NOTE_A5,NOTE_G5,NOTE_D5,NOTE_E5,NOTE_C5,
  NOTE_D5,NOTE_G5,NOTE_E5,NOTE_G5,NOTE_G5,NOTE_E5,
  NOTE_F5,NOTE_G5,NOTE_C6,NOTE_C6,NOTE_D6,NOTE_C6,
  NOTE_G5,NOTE_A5,NOTE_E5,NOTE_D5,NOTE_D5,NOTE_C5,
  NOTE_G5,NOTE_G5,NOTE_C6,NOTE_C6,NOTE_C6,NOTE_D6,
  NOTE_C6,NOTE_A5,NOTE_G5,NOTE_G5,NOTE_E5,NOTE_G5,
  NOTE_A5,NOTE_E5,NOTE_E5,NOTE_D5,NOTE_C5,NOTE_D5,
  NOTE_E5,NOTE_C5,NOTE_E5,NOTE_F5,NOTE_G5,NOTE_C6,
  NOTE_A5, NOTE_G5,NOTE_A5,NOTE_E5,NOTE_D5,NOTE_D5,
  NOTE_C5
};

int noteDurations2[] = {
  8,8,4,8,8,8,
  8,8,4,4,4,8,
  8,8,2,8,8,4,
  8,8,8,8,8,4,
  4,4,8,8,8,2,
  8,8,4,8,8,8,
  8,8,4,8,8,4,
  8,8,8,2,8,8,
  4,8,8,8,8,8,
  4,4,4,8,8,8,
  1
};
