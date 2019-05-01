#include <IRremote.h>           //IRremote.h
int RECV_PIN = 11;              //RECV_PIN 11    
int ledPin = 10;                // LED – digital 10
boolean ledState = LOW;         // ledstate
IRrecv irrecv(RECV_PIN);        //RECV_PIN11
decode_results results;         //results

void setup(){
  Serial.begin(9600);          //Baud rate 9600
  irrecv.enableIRIn();          //Enable IR pin
  pinMode(ledPin,OUTPUT);       //Set LED pin as OUTPUT
}

void loop() {
  if (irrecv.decode(&results)) // recive IR data
  {
      Serial.println(results.value, HEX);
    
      if(results.value == 0xFD00FF){
               ledState = !ledState;             //toggle LED state      
               digitalWrite(ledPin,ledState);    //write to pin       
           }     
      irrecv.resume();  // receive more data via IR
   }
}
