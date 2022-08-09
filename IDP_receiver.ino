#include <NewPing.h>
#define trigger_pinF A0
#define echo_pinF A1
#define trigger_pinB A2
#define echo_pinB A3
#define max_distance 200
NewPing sonarF(trigger_pinF,echo_pinF,max_distance);
NewPing sonarB(trigger_pinB,echo_pinB,max_distance);
int speedL=10;
int left1  = 9;
int left2  = 8;
int speedR=5;
int right1 = 6;
int right2 = 7;
String command="";
void setup()
{
  pinMode(speedL , OUTPUT);
  pinMode(speedR , OUTPUT);
  pinMode(left1 , OUTPUT);
  pinMode(left2 , OUTPUT);
  pinMode(right1, OUTPUT);
  pinMode(right2, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  
  int distanceF=readPingF();
  int distanceB=readPingB();
  if (Serial.available()>0)
  {
    command=Serial.read();
    Serial.println(command);
  }
  if (command=="102")
  {  
   if (distanceF>=150)
      {      
      analogWrite(speedL,255);
      analogWrite(speedR,255);
      digitalWrite(left1,HIGH);
      digitalWrite(left2,LOW); 
      digitalWrite(right1,HIGH);
      digitalWrite(right2,LOW);  
      }
   else
      {
      analogWrite(speedL,0);
      analogWrite(speedR,0);
      digitalWrite(left1,LOW);
      digitalWrite(left2,LOW); 
      digitalWrite(right1,LOW);
      digitalWrite(right2,LOW); 
      }
   }
  else if (command=="98")
  {   
    if (distanceF>=150 )
      {      
      analogWrite(speedL,255);
      analogWrite(speedR,255);
      digitalWrite(left1,LOW);
      digitalWrite(left2,HIGH); 
      digitalWrite(right1,LOW);
      digitalWrite(right2,HIGH);  
      }
    else
      {
      analogWrite(speedL,0);
      analogWrite(speedR,0);
      digitalWrite(left1,LOW);
      digitalWrite(left2,LOW); 
      digitalWrite(right1,LOW);
      digitalWrite(right2,LOW); 
      }
    }
  else if (command=="102")
  {   
    if (distanceF>=150 )
      {      
      analogWrite(speedL,255);
      analogWrite(speedR,255);
      digitalWrite(left1,LOW);
      digitalWrite(left2,HIGH); 
      digitalWrite(right1,HIGH);
      digitalWrite(right2,LOW);  
      }
    else
      {
      analogWrite(speedL,255);
      analogWrite(speedR,255);
      digitalWrite(left1,LOW);
      digitalWrite(left2,LOW); 
      digitalWrite(right1,LOW);
      digitalWrite(right2,LOW); 
      }
    }
  else if (command=="114")
  {   
    if (distanceF>=150)
      {      
      analogWrite(speedL,255);
      analogWrite(speedR,255);
      digitalWrite(left1,HIGH);
      digitalWrite(left2,LOW); 
      digitalWrite(right1,LOW);
      digitalWrite(right2,HIGH);  
      }
    else
      {
      analogWrite(speedL,0);
      analogWrite(speedR,0);
      digitalWrite(left1,LOW);
      digitalWrite(left2,LOW); 
      digitalWrite(right1,LOW);
      digitalWrite(right2,LOW); 
      }
    }
        
    else if (command=="115")
    { 
       
      analogWrite(speedL,0);
      analogWrite(speedR,0);
      digitalWrite(left1,LOW);
      digitalWrite(left2,LOW); 
      digitalWrite(right1,LOW);
      digitalWrite(right2,LOW);  
    }
    
  }
  


int readPingF()
{
  int distance=sonarF.ping_cm();
  if(distance==0)
  {
    distance=200;
  }
  return distance;
}
int readPingB()
{
  int distance=sonarB.ping_cm();
  if(distance==0)
  {
    distance=200;
  }
  return distance;
}
