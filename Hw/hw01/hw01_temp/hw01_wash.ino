void setup()
{
  Serial.begin(9600);
  Serial.println("~ Snake ~");
}

void loop() 
{
  //position//
  for (int Line=0; Line<8; Line++)
  {
    Serial.println("0 0 0 0 0 0 0 0");
  }
  
  for (int Wash=0; Wash<7; Wash++)
  {
    Serial.println(" ");
  }
  delay(300);
}

