// window //
char* Line[]={"1 0 0 0 0 0 0 0","0 1 0 0 0 0 0 0","0 0 1 0 0 0 0 0","0 0 0 1 0 0 0 0","0 0 0 0 1 0 0 0","0 0 0 0 0 1 0 0","0 0 0 0 0 0 1 0","0 0 0 0 0 0 0 1"};
char* empty[]={"0 0 0 0 0 0 0 0","0 0 0 0 0 0 0 0","0 0 0 0 0 0 0 0","0 0 0 0 0 0 0 0","0 0 0 0 0 0 0 0","0 0 0 0 0 0 0 0","0 0 0 0 0 0 0 0","0 0 0 0 0 0 0 0"};

// Declare //
int S_direction = 5;
int pos = 3;
int L_head = 2;

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
  for (int Line2=0; Line2<8; Line2++)
  {
    if (Line2==L_head)
      Serial.println(Line[pos]);
    else
      Serial.println(empty[pos]);
  }
  
  for (int Wash=0; Wash<7; Wash++)
  {
      Serial.println(" ");
  }
  delay(300);

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
    if (L_head==0)
      L_head = 7;
    else
      L_head--;
  }
  else if (S_direction=='2')    //Down
  {
    if (L_head==7)
      L_head = 0;
    else
      L_head++;
  }
  else                          //Stop
  {
    pos = pos;
    L_head = L_head;
  }
}

