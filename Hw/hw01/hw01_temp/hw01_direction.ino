int Line = 0;
int S_direction = 5;

void setup()
{
  Serial.begin(9600);
  Serial.println("~ Snake ~");
}

void loop() 
{
  //direction//
  if (Serial.available()>0)
  {
    S_direction = Serial.read();
    Serial.write(S_direction);
  }
  
  //control//
  if (S_direction=='8') //Forward
  {
    Serial.println("Forward");
    delay(100);
  }
  else if (S_direction=='2')  //Backward
  {
    Serial.println("Backward");
    delay(100);
  }
  else if (S_direction=='4')  //Left
  {
    Serial.println("Left");
    delay(100);
  }
  else if (S_direction=='6')  //Right
  {
    Serial.println("Right");
    delay(100);
  }
  else
  {
    //Serial.println("Stop");
  }
  
  //window//
  if (Line<8)
  {
    Serial.println("00000000");
    delay(1000);
    Line++;
  }
}
