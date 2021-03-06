/*
  Photinus pallens (Eastern Firefly)
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
const int MouthTriggerPin = 3;     // the number of the pushbutton pin
const int abdomenLightPin =  0;      // the number of the LED pin
const int ShoulderLightsPin = 1;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int genderfemale = 1; //Switch to 0 if male costume

void setup() {
  // initialize the LED pin as an output:
  pinMode(abdomenLightPin, OUTPUT);
  pinMode(ShoulderLightsPin, OUTPUT);  
  // initialize the pushbutton pin as an input:
  pinMode(MouthTriggerPin, INPUT); 
  digitalWrite(MouthTriggerPin, HIGH);  
}

void loop(){


  // read the state of the pushbutton value:
  buttonState = digitalRead(MouthTriggerPin);

  //Ladies do this
  if(genderfemale==1){
    digitalWrite(ShoulderLightsPin, LOW);

    // check if the pushbutton is pressed.
    // iif it is, run flash pattern
    if (buttonState == LOW) {     
      //Run the response
      runFemaleFlash();
    } 
    else {
      // turn LED off:
      digitalWrite(abdomenLightPin, LOW); 
    }

  }


  //Guys do this
  if(genderfemale==0){

    digitalWrite(ShoulderLightsPin, HIGH);


    // check if the pushbutton is pressed.
    // iif it is, run flash pattern
    if (buttonState == LOW) {     
      //Run the response
      runMaleFlash();
    } 
    else {
      // turn LED off:
      digitalWrite(abdomenLightPin, LOW); 
    }

  }
}

void runFemaleFlash(){
    delay(1750); //Set delay of nearly 2 seconds after male is ID'ed

  analogWrite(ShoulderLightsPin, 255);
  analogWrite(abdomenLightPin, 255);
  
 //              Add some weirdness to the female's repsonse for extra human readability
   delay(700);               // wait for a second 
  analogWrite(abdomenLightPin, 100);
    analogWrite(ShoulderLightsPin, 150);
    delay(80);

  analogWrite(abdomenLightPin, 0);
    analogWrite(ShoulderLightsPin, 0);
      delay(1000);  //Disallow repeat flashes too quickly


}

void runMaleFlash(){

  ///Brightness can range from 0 - 255       analogWrite(abdomenLightPin, brightness);

  analogWrite(abdomenLightPin, 60);
  delay(125);               // wait for a second 
  analogWrite(abdomenLightPin, 0);
  delay(50);
  analogWrite(abdomenLightPin, 100);
  delay(90); 
  analogWrite(abdomenLightPin, 0); 
    delay(90); 

  analogWrite(abdomenLightPin, 120);
  delay(90); 
  analogWrite(abdomenLightPin, 0); //Turn off at end
  delay(90); 
 analogWrite(abdomenLightPin, 200);
  delay(90); 
  analogWrite(abdomenLightPin, 0); //Turn off at end
  delay(90); 
  analogWrite(abdomenLightPin, 240); //Turn off at end
  delay(90); 
    analogWrite(abdomenLightPin, 0); //Turn off at end
  delay(90); 
   analogWrite(abdomenLightPin, 240);
  delay(90); 
  analogWrite(abdomenLightPin, 0); //Turn off at end
  delay(90); 
    analogWrite(abdomenLightPin, 255); //Turn off at end
  delay(90); 
  analogWrite(abdomenLightPin, 0); //Turn off at end
  delay(1000);  //Disallow repeat flashes too quickly

}
