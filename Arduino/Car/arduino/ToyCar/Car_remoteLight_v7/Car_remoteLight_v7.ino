//*************************************************************** 使用藍芽控制ABB Car
#include<Servo.h>               //引用Servo Libary
#include <SoftwareSerial.h>      //引用藍芽相關 Libary
Servo servoRight;               //定義伺服馬達右邊輪子
Servo servoLeft;                //定義伺服馬達左邊輪子
SoftwareSerial BT(8, 9);         //接收腳(RX), 傳送腳(TX)
char val;                       //設定字元，用於接收資料的變數

//int PinLed1=11;               //設定左前LED
//int PinLed2=10;               //設定右前LED
int PinLed0=10;                 //設定前LED
int PinLed3=7;                  //設定左後LED
int PinLed4=6;                  //設定右後LED
int photoresisterPin=5;         //設定光敏電阻
int light_on;
int light_press=1;/////////////////////////////////
int rLed=2;
int BeepPin=4;                  //設定蜂鳴器


void setup()
{
  servoRight.attach(12);            //右輪連結servo的12腳
  servoLeft.attach(13);             //左輪連結servo的13腳
  Serial.begin(9600);               //設定鮑率為9600
  BT.begin(9600);                  //設定藍牙模組的連線速率
  pinMode(PinLed0,OUTPUT);         //設定前LED輸出腳位
  pinMode(PinLed3,OUTPUT);         //設定左後LED輸出腳位
  pinMode(PinLed4,OUTPUT);         //設定右後LED輸出腳位
  pinMode(photoresisterPin,INPUT); //設定光敏電阻
  pinMode(2,INPUT);                //設定redLED
  pinMode(4,OUTPUT);               //設定蜂鳴器
  //pinMode(2,INPUT);pinMode(3,OUTPUT);
  tone(BeepPin,3000,1000);         //tone(腳位,頻率,時間)
}

void loop() 
  {
     //LED
    light_on=digitalRead(photoresisterPin);
    
    if (light_press==1)
      {
      if(light_on==0)                   //前方LED燈開
        {                 
          //digitalWrite(PinLed1,HIGH);
          //digitalWrite(PinLed2,HIGH);
          digitalWrite(PinLed0,HIGH);
         // Serial.println("light_on");
        }
      else if(light_on==1)              //前方LED燈關
        {
           //digitalWrite(PinLed1,LOW);   
           //digitalWrite(PinLed2,LOW);
           digitalWrite(PinLed0,LOW);
           //Serial.println("light_off");
        }
      }
    else
      digitalWrite(PinLed0,HIGH);
      
    //LED燈開
    int irLed = digitalRead(rLed);
    Serial.println(irLed);
    delay(100);
    //蜂鳴器
    if (irLed==0)
    {
      tone(BeepPin,3000,500);
      bestop();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
    }
    /////////////////////////      
    //偵測到藍芽
    if (BT.available()) 
    {
      val = BT.read();        //讀取藍芽的值
      Serial.println(val);    //顯示藍芽的值
      
      //控制車子方向 
      if(val=='F')
      {
        Serial.println(" Forward");
        forward();
        digitalWrite(PinLed3,LOW);
        digitalWrite(PinLed4,LOW);

        //light_press=0;///////////////////
      }
      else if(val=='B')
      {
        Serial.println("Backward");
        backWard();
        digitalWrite(PinLed3,LOW);
        digitalWrite(PinLed4,LOW);
  
        //light_press=1;///////////////////
      }
      else if(val=='L')
      {
        Serial.println("Left");
        turnLeft();
        digitalWrite(PinLed3,HIGH);
        digitalWrite(PinLed4,LOW);
      }
      else if(val=='R')
      {
        Serial.println("Right");
        turnRight();
        digitalWrite(PinLed3,LOW);
        digitalWrite(PinLed4,HIGH);
      }
      else if(val=='I')
      {
        Serial.println("RightUp");
        turnRightUp();
        digitalWrite(PinLed3,LOW);
        digitalWrite(PinLed4,HIGH);
      }
      else if(val=='G')
      {
        Serial.println("LeftUp");
        turnLeftUp();
        digitalWrite(PinLed3,HIGH);
        digitalWrite(PinLed4,LOW);
      }
      else if(val=='J')
      {
        Serial.println("RightDown");
        turnRightDown();
      }
      else if(val=='H')
      {
        Serial.println("LeftDown");
        turnLeftDown();
      }
      else
      {
        bestop();
        digitalWrite(PinLed3,LOW);
        digitalWrite(PinLed4,LOW);
      }
    }
  }


//redLED
int irDetect(int irLedPin,int irReceiverPin,long frequency)
{
  tone(irLedPin,frequency,8);
  delay(10);
  int ir=digitalRead(irReceiverPin);
  delay(10);
  return ir;
}
//control
int forward(){                              //前進
  servoRight.writeMicroseconds(1700);
  servoLeft.writeMicroseconds(1300);
}
int turnLeft(){                               //左
  servoRight.writeMicroseconds(1300);
  servoLeft.writeMicroseconds(1300);
}
int turnLeftUp(){                             //左上
  servoRight.writeMicroseconds(1500);
  servoLeft.writeMicroseconds(1300);
}
int turnLeftDown(){                           //左下
  servoRight.writeMicroseconds(1500);
  servoLeft.writeMicroseconds(1700);
}
int turnRight(){                              //右
  servoRight.writeMicroseconds(1700);
  servoLeft.writeMicroseconds(1700);
}
int turnRightUp(){                            //右上
  servoRight.writeMicroseconds(1700);
  servoLeft.writeMicroseconds(1500);
}
int turnRightDown(){                          //右下
  servoRight.writeMicroseconds(1300);
  servoLeft.writeMicroseconds(1500);
}
int backWard(){                               //後退
  servoRight.writeMicroseconds(1300);
  servoLeft.writeMicroseconds(1700);
}
int bestop(){                                 //停止
  servoRight.writeMicroseconds(1500);
  servoLeft.writeMicroseconds(1500); 
}


