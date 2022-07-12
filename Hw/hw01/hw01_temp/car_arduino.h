#include<Servo.h>               //引用Servo Libary
#include <SoftwareSerial.h>     //引用藍芽相關 Libary
Servo servoRight;               //定義伺服馬達右邊輪子
Servo servoLeft;                //定義伺服馬達左邊輪子
SoftwareSerial BT(8, 9);        //接收腳(RX), 傳送腳(TX)
char val;                       //設定字元，用於接收資料的變數
int PinLed0=10;                 //設定前LED
int PinLed3=7;                  //設定左後LED
int PinLed4=6;                  //設定右後LED
int photoresisterPin=5;         //設定光敏電阻
int light_on;					//光敏電阻控制LED
int light_press=1;
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

  pinMode(2,INPUT);pinMode(3,OUTPUT);
  tone(BeepPin,3000,1000);         //tone(腳位,頻率,時間)
}

void loop() 
  {
    light_on=digitalRead(photoresisterPin);
    
    if (light_press==1)
      {
      if(light_on==0)                   //前方LED燈開
        digitalWrite(PinLed0,HIGH);
      else if(light_on==1)              //前方LED燈關
        digitalWrite(PinLed0,LOW);
      }
    else
      digitalWrite(PinLed0,HIGH);

    //紅外線感應
    int irLED=irDetect(3,2,41500);
    Serial.println(irLED);

    //偵測到藍芽
    if (BT.available()) 
    {
    val = BT.read();        //讀取藍芽的值
    Serial.println(val);    //顯示藍芽的值
    
    //控制車子方向 
    if(val=='B')				//前進
    {
      Serial.println("Forward");	//在模擬時顯示出"Forward"字串
      forward();
    }
    else if(val=='F')			//後退
    {
      Serial.println("Backward");	//在模擬時顯示出"Backward"字串
      backWard();
    }
    else if(val=='L')			//左前轉
    {
      Serial.println("Left");		//在模擬時顯示出"Left"字串
      turnLeft();
      digitalWrite(PinLed3,HIGH);	//使左後LED亮
      digitalWrite(PinLed4,LOW);	//使右後LED暗
    }
    else if(val=='R')			//右前轉
    {
      Serial.println("Right");		//在模擬時顯示出"Right"字串
      turnRight();
      digitalWrite(PinLed3,LOW);	//使左後LED暗
      digitalWrite(PinLed4,HIGH);	//使右後LED亮
    }
    else if(val=='I')			//原地右轉
    {
      Serial.println("RightUp");	//在模擬時顯示出"RightUp"字串
      turnRightUp();
      digitalWrite(PinLed3,LOW);	//使左後LED暗
      digitalWrite(PinLed4,HIGH);	//使右後LED亮
    }
    else if(val=='G')			//原地左轉
    {
      Serial.println("LeftUp");		//在模擬時顯示出"LeftUp"字串
      turnLeftUp();
      digitalWrite(PinLed3,HIGH);	//使左後LED亮
      digitalWrite(PinLed4,LOW);	//使右後LED暗
    }
    else if(val=='J')			//右後轉
    {
      Serial.println("RightDown");	//在模擬時顯示出"RightDown"字串
      turnRightDown();
    }
    else if(val=='H')			//左後轉
    {
      Serial.println("LeftDown");	//在模擬時顯示出"LeftDown"字串
      turnLeftDown();
    }
    else						//停止
    {
      bestop();
      digitalWrite(PinLed3,LOW);
      digitalWrite(PinLed4,LOW);
    }
    //蜂鳴器
    if(val=='V')                 
      tone(BeepPin,3000,90000);
    else if (val=='v')
      noTone(BeepPin);
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