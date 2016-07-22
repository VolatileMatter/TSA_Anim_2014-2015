
#include <Servo.h>
Servo servoMain; // Define our Servo

int redPin = 11;
int greenPin = 10;
int bluePin = 9;

int sensorP = A3; // analog pin used to connect the sharp sensor
int valueP = 0; // variable to store the values from sensor(initially zero)
int sensorL = A5;
int valueL = 0;
int novaValP = 0; 
int prevValP = 0;
int prev2ValP = 0; 
boolean ruThere = false; 
int counter = 0; 
int FIRSTRUN = 1; 


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  //pinMode(13, OUTPUT);
  servoMain.attach(13); // servo on digital pin 10
  pinMode(12, OUTPUT);
  Serial.begin(9600); // starts the serial monitor
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
}
void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
// the loop function runs over and over again forever
void loop() {
  
  if (FIRSTRUN == 1) {
    servoMain.write(0);
    FIRSTRUN = 0; 
    Serial.println("first run");
    delay(500);
  }
  digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
   
   if (counter == 10) {
   servoMain.write(180);  // Turn Servo Left to 45 degrees  
        Serial.println("Writing 90");
 }

   setColor(0, 255, 0);
  
  prevValP = valueP;
  
  valueP = analogRead(sensorP); // reads the value of the sharp sensor
  
  
  Serial.print("Short sensor:");
  Serial.println(valueP); // prints the value of the sensor to the serial monitor
//  valueL = analogRead(sensorL); // reads the value of the sharp sensor
//  Serial.print("Long sensor:");
//  Serial.println(valueL); // prints the value of the sensor to the serial monitor
   
   
  novaValP = ((prevValP + valueP)/2);


  
//  if (((prevValP - valueP) > 5) || ((prevValP - valueP) < -5)) {
//   novaValP = 0; }
   


if (novaValP > 30) { 
   novaValP = novaValP/2;
   setColor(novaValP, 0, 0); 
}
    
  delay(250);
  digitalWrite(12, LOW);   // turn the LED on (HIGH is the voltage level)
     
     if (counter == 20) {
     servoMain.write(0);  // Turn Servo Left to 45 degrees
     counter = 0; 
     Serial.println("Writing Zero");
 
     }
       counter++;
  delay(250);
  ruThere = true; 


}
