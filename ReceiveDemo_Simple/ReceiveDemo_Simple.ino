/*
  Simple example for receiving
  
  https://github.com/sui77/rc-switch/
*/

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
int r1 = 0; //D3
int r2 = 13; //D7
int b1 = 14; //D5 
int b2 = 12; //D6
int s1 = 0;
int s2 = 0;


void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(2);  // Receiver on interrupt 0 => that is pin #2

  pinMode(b1,INPUT); 
  pinMode(b2,INPUT); 

  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);

  digitalWrite(r1,LOW);
  digitalWrite(r2,LOW);


delay(1000);
  digitalWrite(r1,HIGH);
  
delay(1000);
  digitalWrite(r1,LOW);

  
}

void loop() {
    int value = mySwitch.getReceivedValue();
    
    Serial.print("value: ");
    Serial.println(value);

      if(value == 15113176){

        if( s1 == 0 ){
          digitalWrite(r1,HIGH);
          Serial.println("r1: HIGH");
          s1 = 1;
            delay(1000);
        }else{
          digitalWrite(r1,LOW);
          Serial.println("r1: LOW");
           s1 = 0;
             delay(1000);
        }

       
      }else if (value == 15113172) {

        
         if( s2 == 0 ){
          digitalWrite(r2,LOW);
          Serial.println("r2: LOW");
           s2 = 1;
             delay(1000);
        }else{
          digitalWrite(r2,HIGH);
          Serial.println("r2: HIGH");
          s2 = 0;
            delay(1000);
        }
       
      }else if (value == 15113170) {
         if( s1 == 0 ){
          digitalWrite(r1,LOW);
          digitalWrite(r2,LOW);
          Serial.println("r1: LOW");
          Serial.println("r2: LOW");
          s1 = 1;
            delay(1000);
        }else{
          digitalWrite(r1,HIGH);
          digitalWrite(r2,HIGH);
          Serial.println("r1: HIGH");
          Serial.println("r2: HIGH");
          s1 = 0;
            delay(1000);
          
        }
      
       }


   mySwitch.resetAvailable();
   delay(400);


/*



//      Serial.print("Received ");
//      Serial.print( mySwitch.getReceivedValue() );

      if(mySwitch.getReceivedValue() == 15113169){
        Serial.println("GISELE te amo vc e nossos babys");
      //  delay(300);
      }


      
      Serial.print(" / ");
      Serial.print( mySwitch.getReceivedBitlength() );
      Serial.print("bit ");
      Serial.print("Protocol: ");
      Serial.println( mySwitch.getReceivedProtocol() );

 
  */  
}
