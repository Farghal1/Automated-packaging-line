#include <SoftwareSerial.h>
#include <Servo.h>

Servo waistServo;
Servo shoulderServo;
Servo elbowServo;
Servo gripperServo;

int waistPos [10];
int shoulderPos [10];
int elbowPos [10];
int gripperPos [10];

int Index= 0;
int seven_seg= 5;
int piezo= 4;
String Data="";

int waistServoNewPos=0;
int waistServoOldPos=0;

int shoulderServoNewPos=0;
int shoulderServoOldPos=0;

int elbowServoNewPos=0;
int elbowServoOldPos=0;

int gripperServoNewPos=0;
int gripperServoOldPos=0;


SoftwareSerial bluetooth(10,11); //rx 10 , tx 11 --> connect tx of BT module to pin 10
void setup() {
  // put your setup code here, to run once:
   waistServo.attach(9);
   shoulderServo.attach(8);
   elbowServo.attach(7);
   gripperServo.attach(6);
   
   pinMode(10,INPUT);
   pinMode(11,OUTPUT);
   
   bluetooth.begin(9600);
   Serial.begin(9600);
   bluetooth.setTimeout(1);
   delay(50);

   waistServo.write(90);
   shoulderServo.write(90);
   elbowServo.write(90);
   gripperServo.write(90);

   waistServoOldPos=90;
   shoulderServoOldPos=90;
   elbowServoOldPos=90;
   gripperServoOldPos=90;
}

void moveWaist()
{
  if(waistServoNewPos>waistServoOldPos)
  {
      for(int i=waistServoOldPos;i<=waistServoNewPos;i++)
      {
        waistServo.write(i);
        delay(20);
      }
  }
      else
      {
        for(int j=waistServoOldPos;j>=waistServoNewPos;j--)
        {
          waistServo.write(j);
          delay(20);
        }
      }
}
void moveShoulder()
{
  if(shoulderServoNewPos>shoulderServoOldPos)
  {
      for(int i=shoulderServoOldPos;i<=shoulderServoNewPos;i++)
      {
        shoulderServo.write(i);
        delay(20);
      }
  }
      else
      {
        for(int j=shoulderServoOldPos;j>=shoulderServoNewPos;j--)
        {
          shoulderServo.write(j);
          delay(20);
        }
      }
}
void moveElbow()
{
  if(elbowServoNewPos>elbowServoOldPos)
  {
      for(int i=elbowServoOldPos;i<=elbowServoNewPos;i++)
      {
        elbowServo.write(i);
        delay(20);
      }
  }
      else
      {
        for(int j=elbowServoOldPos;j>=elbowServoNewPos;j--)
        {
          elbowServo.write(j);
          delay(20);
        }
      }
}
void moveGripper()
{
  if(gripperServoNewPos>gripperServoOldPos)
  {
      for(int i=gripperServoOldPos;i<=gripperServoNewPos;i++)
      {
        gripperServo.write(i);
        delay(20);
      }
  }
      else
      {
        for(int j=gripperServoOldPos;j>=gripperServoNewPos;j--)
        {
          gripperServo.write(j);
          delay(20);
        }
      }
}

void savePosition()
{
  waistPos[Index]= waistServoNewPos;
  shoulderPos[Index]= shoulderServoNewPos;
  elbowPos[Index]= elbowServoNewPos;
  gripperPos[Index]= gripperServoNewPos;
  Index++;
}

void pickFrom()
{
 if(waistPos[1]>waistPos[0])
  {
      for(int i=waistPos[1];i>=waistPos[0];i--)
      {
        waistServo.write(i);
        delay(20);
      }
  }
 else
  {
      for(int j=waistPos[1];j<=waistPos[0];j++)
      {
          waistServo.write(j);
          delay(20);
      }
  }

   if(shoulderPos[1]>shoulderPos[0])
  {
      for(int i=shoulderPos[1];i>=shoulderPos[0];i--)
      {
        shoulderServo.write(i);
        delay(20);
      }
  }
 else
  {
      for(int j=shoulderPos[1];j<=shoulderPos[0];j++)
      {
          shoulderServo.write(j);
          delay(20);
      }
  }

  if(elbowPos[1]>elbowPos[0])
  {
      for(int i=elbowPos[1];i>=elbowPos[0];i--)
      {
        elbowServo.write(i);
        delay(20);
      }
  }
 else
  {
      for(int j=elbowPos[1];j<=elbowPos[0];j++)
      {
          elbowServo.write(j);
          delay(20);
      }
  }

  if(gripperPos[1]>gripperPos[0])
  {
      for(int i=gripperPos[1];i>=gripperPos[0];i--)
      {
        gripperServo.write(i);
        delay(20);
      }
  }
 else
  {
      for(int j=gripperPos[1];j<=gripperPos[0];j++)
      {
          gripperServo.write(j);
          delay(20);
      }
  }
  tone(piezo,400);
  delay(1000);
  noTone(piezo);
  digitalWrite(seven_seg,HIGH);
  delay(50);
  digitalWrite(seven_seg,LOW);
  delay(50);
}

void placeIn()
{
   if(shoulderPos[1]<shoulderPos[0])
  {
      for(int i=shoulderPos[0];i>=shoulderPos[1];i--)
      {
        shoulderServo.write(i);
        delay(20);
      }
  }
 else
  {
      for(int j=shoulderPos[0];j<=shoulderPos[1];j++)
      {
          shoulderServo.write(j);
          delay(20);
      }
  }

  if(elbowPos[1]<elbowPos[0])
  {
      for(int i=elbowPos[0];i>=elbowPos[1];i--)
      {
        elbowServo.write(i);
        delay(20);
      }
  }
 else
  {
      for(int j=elbowPos[0];j<=elbowPos[1];j++)
      {
          elbowServo.write(j);
          delay(20);
      }
  }

  if(waistPos[1]<waistPos[0])
  {
      for(int i=waistPos[0];i>=waistPos[1];i--)
      {
        waistServo.write(i);
        delay(20);
      }
  }
 else
  {
      for(int j=waistPos[0];j<=waistPos[1];j++)
      {
          waistServo.write(j);
          delay(20);
      }
  }

  if(gripperPos[1]<gripperPos[0])
  {
      for(int i=gripperPos[0];i>=gripperPos[1];i--)
      {
        gripperServo.write(i);
        delay(20);
      }
  }
 else
  {
      for(int j=gripperPos[0];j<=gripperPos[1];j++)
      {
          gripperServo.write(j);
          delay(20);
      }
  }

}

void repeatMotion()
{
  while(true)
  {
    pickFrom();
    delay(1000);
    placeIn();
    delay(1000);
  }
}  

void loop() 
{  
  if(bluetooth.available()>0){
    delay(20);
    Data=bluetooth.readString();
    delay(20);

  Serial.println(Data);
  
  if(Data.substring(0,2).equals("s1"))
  {
    String servoData=Data.substring(2,Data.length());
    waistServoNewPos=servoData.toInt();
    moveWaist();
    waistServoOldPos=waistServoNewPos;    
  }
  
  if(Data.substring(0,2).equals("s2"))
  {
    String servoData=Data.substring(2,Data.length());
    shoulderServoNewPos=servoData.toInt();
    moveShoulder();
    shoulderServoOldPos=shoulderServoNewPos;
  }
  
   if(Data.substring(0,2).equals("s3"))
  {
    String servoData=Data.substring(2,Data.length());
    elbowServoNewPos=servoData.toInt();
    moveElbow();
    elbowServoOldPos=elbowServoNewPos;
  }
  
  if(Data.substring(0,2).equals("s4"))
  {
    String servoData=Data.substring(2,Data.length());
    gripperServoNewPos=servoData.toInt();
    moveGripper();
    gripperServoOldPos=gripperServoNewPos;
  }
  if(Data.equals("sa"))
  {
    if(Index<10)
      savePosition();
  }

  if(Data.equals("re"))
  {
    if(Index>=2)
      repeatMotion();
  }

  } // end of bluetooth available
   
} // end of loop
