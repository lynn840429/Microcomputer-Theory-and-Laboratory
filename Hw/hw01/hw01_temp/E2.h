byte nTo7[16]={B11111100,B01100000,B11011010,B11110010,B01100110,B10110110,B00111110,B11100100,B11111110,B11110110,B11101110,B00111110,B00011010,B01111010,B10011110,B10001110};
int led[16]={B0000,B0001,B0010,B0011,B0100,B0101,B0110,B0111,B1000,B1001,B1010,B1011,B1100,B1101,B1110,B1111};
int s = 0;
int x = 0;
int y = 0;
int flag = 0;

void setPort( byte a){
  for (int i=0;i<8;i++){
    if ( ((a>>i)&1) == 1 ) 
      digitalWrite(i,LOW);
    else
      digitalWrite(i,HIGH);
  }
}

void setLED( byte b){
  for (int i=0;i<4;i++){
    if ( ((b>>i)&1) == 1 ) 
      digitalWrite((i+8),HIGH);
    else
      digitalWrite((i+8),LOW);
  }
}

void setup() {
  for(int i=0;i<=11;i++){
    pinMode(i, OUTPUT);
  }
  pinMode(12, INPUT);
  pinMode(13, INPUT);
}

void loop() {
  if(digitalRead(13) != 0){
    delay(100);
    s++;
  }
  if(digitalRead(12) != 0){
    delay(100);
    s--;
  }
  
  if(s == 16)
    s = 0;
  if(s == (-1))
    s = 15;
      
  setPort(nTo7[s]);
  setLED(led[s]);
  delay(20);
   
}
