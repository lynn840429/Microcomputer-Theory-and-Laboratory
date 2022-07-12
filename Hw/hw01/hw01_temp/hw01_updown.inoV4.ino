// window //
char* Line[] = {"1 0 0 0 0 0 0 0","0 1 0 0 0 0 0 0","0 0 1 0 0 0 0 0","0 0 0 1 0 0 0 0","0 0 0 0 1 0 0 0","0 0 0 0 0 1 0 0","0 0 0 0 0 0 1 0","0 0 0 0 0 0 0 1"};
char* empty[] = {"0 0 0 0 0 0 0 0"};

// Declare //
int S_direction = 5;
int Lnum = 5;
int pos[5] = {3,3,3,3,3};
int Snake_ud[5] = {2,3,4,5,6}; 

// set up //
void setup(){
  Serial.begin(9600);
  Serial.println("~ Snake ~");
}

// main //
void loop() {
  // direction //
  if (Serial.available()>0){
    S_direction = Serial.read();
    //Serial.write(S_direction);
  } 
  
  // window //
  for (int wLine=0; wLine<8; wLine++){ 
    if ((wLine==Snake_ud[0]) & (Lnum>=1))
      Serial.println(Line[pos[0]]);
    else if ((wLine==Snake_ud[1]) & (Lnum>=2))
      Serial.println(Line[pos[1]]);
    else if ((wLine==Snake_ud[2]) & (Lnum>=3))
      Serial.println(Line[pos[2]]);
    else if ((wLine==Snake_ud[3]) & (Lnum>=4))
      Serial.println(Line[pos[3]]);
    else if ((wLine==Snake_ud[4]) & (Lnum>=5))
      Serial.println(Line[pos[4]]);
    else
      Serial.println(empty[0]);
  }
  
  for (int Wash=0; Wash<7; Wash++){
      Serial.println(" ");
  }
  delay(1000);

  // control //
  if (S_direction=='4'){         //Left
    for (int i=0; i<5; i++){
      if (pos[i]==0)
        pos[i] = 8;
    }
    pos[0] = pos[0] - 1;
    if (Lnum==1)
      Lnum = Lnum;
    else
      Lnum--;
  }
  
  else if (S_direction=='6'){    //Right
    for (int i=0; i<5; i++){
      if (pos[i]==7)
        pos[i] = -1;
    }
    pos[0] = pos[0] + 1;
    if (Lnum==1)
      Lnum = Lnum;
    else
      Lnum--;
  }
  else if (S_direction=='8'){    //Up
    for (int i=0; i<5; i++){
      if (Snake_ud[i]==0)
        Snake_ud[i] = 7;
      else
        Snake_ud[i]--;
    }
  }
  else if (S_direction=='2'){    //Down
    for (int i=0; i<5; i++){
      if (Snake_ud[i]==7)
        Snake_ud[i] = 0;
      else
        Snake_ud[i]++;
    }
  }
  else{                          //Stop
    for (int i=0; i<5; i++){
      pos[i] = pos[i];
    }
    for (int i=0; i<5; i++){
      Snake_ud[i] = Snake_ud[i];
    }
  }
}


