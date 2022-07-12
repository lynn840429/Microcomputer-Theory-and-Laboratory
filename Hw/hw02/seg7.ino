bool mode = 0;
int seg7_1[6]={B1100000,B0110000,B0011000,B0001100,B0000110,B1000010};
int run1 = 0;

void setport(byte a){
  for (int i=0;i<=6;i++){
    if ( ((a>>i)&1) == 1 ) 
      digitalWrite((i+3),LOW);
    else
      digitalWrite((i+3),HIGH);
  }
}

void stop1(){
  mode = !mode;
  run1 = 0;
}

void setup() {
  for(int i=3;i<=10;i++)
    pinMode(i, OUTPUT);
  attachInterrupt(0,stop1,FALLING);
}

void loop() {
  if(mode == 0){
    digitalWrite(10, HIGH);
    setport(seg7_1[run1]);
    delay(500);
    run1++;
    if(run1 == 6)
      run1 = 0;
  }
  
  else{
    digitalWrite(10, HIGH);
    setport(B1111110);
    delay(500);
    setport(B0000000);
    delay(500);
    setport(B1111110);
    delay(500);
    setport(B0000000);
    delay(500);
    setport(B0000001);
    delay(500);
    setport(B0000000);
    delay(500);
  }
}
