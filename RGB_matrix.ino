#include "sounds.h"
#include "playMelody.h"
#include "led_fullcolor_9.h"

#define BUZZER_PIN 8
#define SWITCH_PIN 9
#define isPress() (!digitalRead(SWITCH_PIN))
#define playPattern(x,y) playPat(x,y,(int)(sizeof(y)/sizeof(y[0])))

int playPat(int (*pattern)(LedColor*,int),LedColor*,int);
LedColor allcolor[7] = {WHITE,RED,GREEN,BLUE,CYAN,YELLOW,MAGENTA};


PlayMelody melody(BUZZER_PIN);

void setup(){
    pinMode( SWITCH_PIN, INPUT_PULLUP); 
    analogReference(INTERNAL);
    randomSeed(analogRead(0));

    Led::init();
    Led::setInterval(3);
}


//曲リスト
//[shikinouta] 四季の歌     音符数：83
//[haurunomaintame] ハウルのメインテーマ  音符数：69
//[takibi] たきび            音符数：49
//[wakeup] Wake up(120) 
//[rpg] RPG(sekai no owari)46
//[oboroduki] おぼろ月夜　　音符数：61
//[ninnjaribanban] ニンジャりバンバン（114） 
//[kutsuganaru] くつがなる       音符数：66
//[mikannnohanasakuoka] みかんの花咲く丘  　音符数：56
//[senbonzakura] 千本桜(配信用)112 
//[hakonehachiri] 箱根八里    音符数:163


void loop(){

      
    melody.setMelody( haurunomaintame_Melody, haurunomaintame_Duration, haurunomaintame_Length);
    playPattern(patternRandom3,haurunomaintame_Color);
    
   
     
   // melody.setMelody( shikinouta_Melody, shikinouta_Duration, shikinouta_Length);
   // playPattern(patternRandom3,allcolor);
   
   
     
   // melody.setMelody( wakeup_Melody, wakeup_Duration, wakeup_Length);
   // playPattern(patternRandom3,allcolor);


   // melody.setMelody( rpg_Melody, rpg_Duration, rpg_Length);
   // playPattern(patternFlushPoint,allcolor);


   // melody.setMelody( senbonzakura_Melody, senbonzakura_Duration, senbonzakura_Length);
   // playPattern(patternPitch2Color,allcolor);

 
     
   // melody.setMelody( ninjaribanban_Melody, ninjaribanban_Duration, ninjaribanban_Length);
   // playPattern(patternRandom3,allcolor);
   
   
     
   // melody.setMelody( takibi_Melody, takibi_Duration, takibi_Length);
   // playPattern(patternRandom3,allcolor);
}

