#include <SoftwareSerial.h>
SoftwareSerial mySerial(13, 12); // RX, TX

#define m1 6
#define m2 5
#define m3 4
#define m4 3

#define led1 8
#define led2 9
#define led3 10
#define led4 11

int data=0,kec=0;

boolean maju=true;

//array kecepatan
int fast[11]={0,80,100,120,140,160,180,200,220,240,255};

void setup()
{
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(m4,OUTPUT);

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);

  // for HC-05 use 38400 when poerwing with KEY/STATE set to HIGH on power on
  mySerial.begin(9600);
}
 
void motorOut(unsigned char lpwm, unsigned char rpwm, boolean arrow)
{
  //arrow=false=maju; arrow=true=mundur;
  if(arrow==false)
  {
    digitalWrite(m3,HIGH);
    digitalWrite(m1,LOW);
    analogWrite(m4,255-lpwm);
    analogWrite(m2,rpwm);
  }
  else
  {
    digitalWrite(m3,LOW);
    digitalWrite(m1,HIGH);
    analogWrite(m4,lpwm);
    analogWrite(m2,255-rpwm);
  }
}

void loop()
{
  if(mySerial.available()>0)
  {
    data=mySerial.read();
    //penyimpan data kecepatan
    if (data =='0') { kec=0;} 
    else if (data =='1') { kec=1;}
    else if (data =='2') { kec=2;}
    else if (data =='3') { kec=3;}
    else if (data =='4') { kec=4;}
    else if (data =='5') { kec=5;}
    else if (data =='6') { kec=6;}
    else if (data =='7') { kec=7;}
    else if (data =='8') { kec=8;}
    else if (data =='9') { kec=9;}
    else if (data =='q') {kec=10;}


    //S= Stop
    if (!digitalRead(data == 'S'))
    {
      motorOut(0,0,false); 
    }
    //F=Maju
    if (!digitalRead(data=='F'))
    {
      motorOut(fast[kec],fast[kec],true); 
      digitalWrite(led1,HIGH);
    }
    //I=Maju sambil belok kanan
    if (!digitalRead(data=='I'))
    {
      motorOut(fast[kec],((fast[kec])/2),true);
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
    }
    //G=Maju sambil belok kiri
    if (!digitalRead(data=='G'))
    {
      motorOut(((fast[kec])/2),fast[kec],true); 
      digitalWrite(led1,HIGH);
      digitalWrite(led3,HIGH);
    }
    //R=Belok kanan
    if(!digitalRead(data=='R'))
    {
      motorOut(fast[kec],0,true); 
      digitalWrite(led2,HIGH);
    }
    //L=Belok kiri
    if(!digitalRead(data=='L'))
    {
      motorOut(0,fast[kec],true); 
      digitalWrite(led3,HIGH);
    }
    //B=Mundur
    if(!digitalRead(data=='B'))
    {
      motorOut(fast[kec],fast[kec],false); 
      digitalWrite(led4,HIGH);
    }
    //H=Mundur kiri
    if (data=='H')
    {
      motorOut(((fast[kec])/2),fast[kec],false); 
      digitalWrite(led4,HIGH);
      digitalWrite(led3,HIGH);
    }
    //J=Mundur kanan
    if (!digitalRead(data=='J'))
    { 
      motorOut(fast[kec],((fast[kec])/2),false); 
      digitalWrite(led4,HIGH);
      digitalWrite(led2,HIGH);
    }
  }
}
