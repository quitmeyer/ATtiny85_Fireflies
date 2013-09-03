/*
  Photinus Pyralis (Eastern Firefly) MALE
 ------------------------------------------
Flash patterns adapted from photinus pyralis
and costume design adapted from pyrophorus noctilucus
 
 
 The circuit:
 * Butt LED attached from pin 0 to ground 
 * Shoulder LEDs attached to pin 1
 * Mouth Trigger attached to pin 3 from -GROUND
 

 
 
 created 2013
 by Andrew Quitmeyer quitmeyer.org
 
 This example code is in the public domain.
 
*/

// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = 3;     // the number of the pushbutton pin
const int ledPin =  0;      // the number of the LED pin
const int alwaysLED = 1;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
pinMode(alwaysLED, OUTPUT);  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT); 
digitalWrite(buttonPin, HIGH);  
}

void loop(){
  
  digitalWrite(alwaysLED, HIGH);
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == LOW) {     
    // turn LED on:    
runMaleFlash();
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW); 
  }
}

void runFemaleFlash(){
  
  
}

void runMaleFlash(){
     digitalWrite(ledPin, HIGH); 
      delay(500);               // wait for a second 
        digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(250);
     digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(400);               // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(500);   
              // wait for a second 
        digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(250);
     digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);               // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(500);  
}
