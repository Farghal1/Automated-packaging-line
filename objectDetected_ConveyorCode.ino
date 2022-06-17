//#include <Arduino_FreeRTOS.h>

#define PWM 5
#define IN2 6
#define IN1 7

int piezo =11;
//int SendToRobot=12;
int seven_segment=9;
int IR=8;

void setup() {
  // put your setup code here, to run once:
  pinMode(piezo,OUTPUT);
//  pinMode(SendToRobot,OUTPUT);
  pinMode(seven_segment,OUTPUT);
  pinMode(IR,INPUT);

}

void rotate_Motor(int dir, int pwmVal, int pwm, int in1, int in2){
  analogWrite(pwm,pwmVal);
  if(dir == 1){
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
  }
  else if(dir == -1){
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
  }
  else{
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
  }  
}


void loop() {
  // put your main code here, to run repeatedly:
//   digitalWrite(SendToRobot,LOW);
   digitalWrite(seven_segment,LOW);
   int readObject=digitalRead(IR);
   if(digitalRead(IR)==1)
   {
     rotate_Motor(1,255,PWM,IN1,IN2);
     delay(25);
   }
   else
   {
    rotate_Motor(0, 0, PWM, IN1, IN2);
    digitalWrite(seven_segment,HIGH);
    while(digitalRead(IR)==0)
    {
      tone(piezo,30);
      delay(500);
      noTone(piezo);
      delay(25);
//      digitalWrite(SendToRobot,HIGH);
    }   
   }
}
