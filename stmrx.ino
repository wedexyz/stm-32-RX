
#include <Servo.h>


//#define enablePin PA2 //tx
#define enablePin PA10 //rx
#define relay1 PB13
#define relay1 PB14
Servo myservo;

void setup(){
  Serial1.begin(9600);            // Begins Serial communication at serial1 Port PA9,PA10 at baudrate 9600
 // pinMode(PC13 , OUTPUT);
    pinMode(PB13 , OUTPUT);
     pinMode(PB14 , OUTPUT);
      myservo.attach(PA3);
    pinMode(enablePin, INPUT);
  delay(10); 
  digitalWrite(enablePin,LOW);        //  (Pin 8 always LOW to receive value from Master)
}

void loop()
{

  char c;
  if(Serial1.available()>0){
    c=Serial1.read();
    if(c=='1'){
      digitalWrite(PB13,LOW);
   
    }
    if(c=='2'){
      digitalWrite(PB13,HIGH);
    }
     if(c=='3'){
      digitalWrite(PB14,LOW);
         myservo.write(90);
    }
    if(c=='4'){
      digitalWrite(PB14,HIGH);
         myservo.write(0);
    }
  }

        
}


