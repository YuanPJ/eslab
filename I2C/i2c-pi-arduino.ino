#include <Wire.h>
#define SLAVE_ADDRESS 0x04
int number = 0;
int state = 0;
void setup() {
   pinMode(13, OUTPUT);
   pinMode(8, OUTPUT);
   digitalWrite(8, LOW);
   Serial.begin(9600); // start serial for output
   // initialize i2c as slave
   Wire.begin(SLAVE_ADDRESS);
   // define callbacks for i2c communication
   Wire.onReceive(receiveData);
   Wire.onRequest(sendData);
   Serial.println("Ready!");
}
void loop() {
   delay(100);
}
// callback for received data
void receiveData(int byteCount){
   while(Wire.available()) {
      number = Wire.read();
      Serial.print("data received: ");
      Serial.println(number);
      if (number){
         if (state == 0){
            digitalWrite(13, HIGH); // set the LED on
            //digitalWrite(8, HIGH);
            state = 1;
         }
         else{
            digitalWrite(13, LOW); // set the LED off
            //digitalWrite(8, LOW);  
            state = 0;
         }
      }
      //Serial.print(digitalRead(8));
      digitalWrite(8, HIGH);
      digitalWrite(8, LOW);
      
   }
}
// callback for sending data
void sendData(){
      Wire.write(number+2);
}
