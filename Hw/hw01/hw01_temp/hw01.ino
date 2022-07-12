// window //
char* Line[]={"1 0 0 0 0 0 0 0","0 1 0 0 0 0 0 0","0 0 1 0 0 0 0 0","0 0 0 1 0 0 0 0","0 0 0 0 1 0 0 0","0 0 0 0 0 1 0 0","0 0 0 0 0 0 1 0","0 0 0 0 0 0 0 1"};
char* empty[]={"0 0 0 0 0 0 0 0"};

// Declare //
int S_direction = 5;
int pos = 3;
int snake[5]={2,3,4,5,6};

// set up //
void setup()
{
  Serial.begin(9600);
  Serial.println("~ Snake ~");
}

// main //
void loop() 
{
  // direction //
  if (Serial.available()>0)
  {
    S_direction = Serial.read();
    //Serial.write(S_direction);
  }
  
  // window //
  if (S_direction=='0')
    {
      pos = 3;
      int snake[5]={2,3,4,5,6};
      for (int LineW=0; LineW<8; LineW++)
      {
          if ((LineW>=(snake[0]))&(LineW<=snake[4]))  
            Serial.println(Line[pos]);
          else
            Serial.println(empty[0]);
      }
      
      for (int Wash=0; Wash<7; Wash++)
      {
          Serial.println(" ");
      }
      delay(1000);
      }
  else
  {
    for (int LineW=0; LineW<8; LineW++)
    {
        if ((LineW>=(snake[0]))&(LineW<=snake[4]))  
          Serial.println(Line[pos]);
        else
          Serial.println(empty[0]);
    }
    
    for (int Wash=0; Wash<7; Wash++)
    {
        Serial.println(" ");
    }
    delay(1000);
  }

  // control //
  if (S_direction=='4')         //Left
  {
    if (pos==0)
      pos = 7;
    else
      pos--;
  }
  
  else if (S_direction=='6')    //Right
  {
    if (pos==7)
      pos = 0;
    else
      pos++;
  }
  else if (S_direction=='8')    //Up
  {
    for (int i=0; i<5; i++)
    {
      if (snake[i]==0)
        snake[i] = 7;
      else
          snake[i]--;
    }
  }
  else if (S_direction=='2')    //Down
  {
    if (snake[4]==7)
      snake[4] = 0;
    else
    {
      for (int i=0; i<5; i++)
      {
        snake[i]++;
      }
    }
  }
  else                          //Stop
  {
    pos = pos;
    for (int i=0; i<5; i++)
      {
        snake[i] = snake[i];
      }
  }
}

