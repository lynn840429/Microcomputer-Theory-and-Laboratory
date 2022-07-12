///*************************************************************** 使用藍芽控制ABB Car
#include<Servo.h>             //引用Servo Libary
#include <SoftwareSerial.h>    //引用藍芽相關 Libary
Servo servoRight;             //定義伺服馬達右邊輪子
Servo servoLeft;              //定義伺服馬達左邊輪子
SoftwareSerial BT(8, 9);       //接收腳(RX), 傳送腳(TX)
char val;                     //設定字元，用於接收資料的變數
int PinLed1=7;                //設定左邊LED
int PinLed2=3;                //設定右邊LED
int BeepPin=4;
void setup(){
  servoRight.attach(12);      //右輪連結servo的12腳
  servoLeft.attach(13);       //左輪連結servo的13腳
  Serial.begin(9600);          //設定鮑率為9600
  BT.begin(9600);             //設定藍牙模組的連線速率
  pinMode(PinLed1,OUTPUT);    //設定左邊LED輸出腳位
  pinMode(PinLed2,OUTPUT);    //設定右邊LED輸出腳位
  tone(BeepPin,3000,1000);          //tone(腳位,頻率,時間);  
}

void loop() {
 // 若收到藍牙模組的資料，則送到「序列埠監控視窗」


  if (BT.available()) {   //偵測到藍芽
    val = BT.read();      //讀取藍芽的值
   Serial.println(val);   //顯示藍芽的值
  //控制車子方向 
    if(val=='F'){
      Serial.println(" Forward");
      forward();
     }
    else if(val=='B'){
      Serial.println("Backward");
      backWard();
      }
   else if(val=='L'){
      Serial.println("Left");
      turnLeft();
      }
   else if(val=='R'){
      Serial.println("Right");
      turnRight();
      }
   else if(val=='I'){
      Serial.println("RightUp");
      turnRightUp();
      }
   else if(val=='G'){
      Serial.println("LeftUp");
      turnLeftUp();
      }
      else if(val=='J'){
      Serial.println("RightDown");
      turnRightDown();
      }
   else if(val=='H'){
      Serial.println("LeftDown");
      turnLeftDown();
      }
   else{
      bestop();
      }
  
     if(val=='W'){                 //前方LED燈開關
     digitalWrite(PinLed1,HIGH);
     digitalWrite(PinLed2,HIGH);}
   else if(val=='w'){
     digitalWrite(PinLed1,LOW);   
     digitalWrite(PinLed2,LOW);}

   if(val=='V'){                  //Beep  
    tone(BeepPin,3000,90000);
   }else if (val=='v'){
    noTone(BeepPin);
   }
   
   
  }
      

  }


    

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
