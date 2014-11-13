

void setup() {                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(5, OUTPUT);//カソード下
pinMode(6, OUTPUT);//カソード中
pinMode(7, OUTPUT);//カソード上
pinMode(8, OUTPUT);
 pinMode(9, INPUT);
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
 digitalWrite(3,HIGH);
  digitalWrite(4, LOW);
 digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
 digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  
 digitalWrite(5,HIGH);//G
 delay(1);
 digitalWrite(5,LOW);
 
  digitalWrite(0, HIGH);
 digitalWrite(1, LOW);
 digitalWrite(2, HIGH);
 digitalWrite(3,LOW);
  digitalWrite(4, HIGH);
 digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
 digitalWrite(12, LOW);
  digitalWrite(13, LOW);
 
  digitalWrite(6,HIGH);//B
  delay(1);
  digitalWrite(6,LOW);
  
   digitalWrite(0, HIGH);
 digitalWrite(1, HIGH);
 digitalWrite(2, LOW);
 digitalWrite(3,HIGH);
  digitalWrite(4, LOW);
 digitalWrite(10, LOW);
  digitalWrite(11, LOW);
 digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  
 digitalWrite(7,HIGH);//R
   delay(1);
   digitalWrite(7,LOW);

  
}
