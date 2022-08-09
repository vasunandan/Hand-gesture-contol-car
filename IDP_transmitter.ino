#include<Wire.h>
int MPU_address=0x68;
int AcX,AcY,AcZ,GyX,GyY,GyZ;
int minVal=265;
int maxVal=402;
String Data="";
double x;
double y;
double z;

void setup(){
Wire.begin();
Wire.beginTransmission(MPU_address);
Wire.write(0x6B);
Wire.write(0);
Wire.endTransmission(true);
Serial.begin(9600);
}
void loop(){
Wire.beginTransmission(MPU_address);
Wire.write(0x3B);
Wire.endTransmission(false);
Wire.requestFrom(MPU_address,14,true);
AcX=Wire.read()<<8|Wire.read();
AcY=Wire.read()<<8|Wire.read();
AcZ=Wire.read()<<8|Wire.read();
int xAng = map(AcX,minVal,maxVal,-90,90);
int yAng = map(AcY,minVal,maxVal,-90,90);
int zAng = map(AcZ,minVal,maxVal,-90,90);
x= RAD_TO_DEG * (atan2(-yAng, -zAng)+PI);
y= RAD_TO_DEG * (atan2(-xAng, -zAng)+PI);
z= RAD_TO_DEG * (atan2(-yAng, -xAng)+PI);
if (((0<x && x<=40) || (320<=x && x<360))&&((0<y && y<=40) || (320<=y && y<360)) ){
  Serial.write("s");
  }
else if (x>40 && x<=180){
  Serial.write("f");
}
else if (x>180 && x<320){
  Serial.write("b");
}
else if (y>40 && y<=180){
  Serial.write("r");
}
else if (y>180 && y<320)
  {
  Serial.write("l");
}
delay(1000);



}
