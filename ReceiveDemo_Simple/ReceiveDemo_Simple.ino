/*
  Simple example for receiving
  
  https://github.com/sui77/rc-switch/
*/

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(2);  // Receiver on interrupt 0 => that is pin #2
}

void loop() {
    int value = mySwitch.getReceivedValue();
    

//      Serial.print("Received ");
//      Serial.print( mySwitch.getReceivedValue() );

      if(mySwitch.getReceivedValue() == 15113169){
        Serial.println("GISELE te amo vc e nossos babys");
        delay(300);
      }


      
/*      Serial.print(" / ");
      Serial.print( mySwitch.getReceivedBitlength() );
      Serial.print("bit ");
      Serial.print("Protocol: ");
      Serial.println( mySwitch.getReceivedProtocol() );
*/
    mySwitch.resetAvailable();
    
}
