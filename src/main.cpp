// import the library in the sketch
#include <L293.h>

// give a name to the pins that you use for the first motor
const int speedPin1 = 3;            // the pin that we use to control the motor's speed
const int forwardPin1 = 2;         // the pin that we use to tell the motor to go forward
const int reversePin1 = 4;         // the pin that we use to tell the motor to go reverse
const int forwardButton = 5;      // the pin that we use for the forward button
const int reverseButton = 6;      // the pin that we use for the reverse button
const int forwardContButton = 7;  // the pin that we use for the forward continuous button
const int reverseContButton = 8;  // the pin that we use for the reverse continuous button
const int potPin1 = A3;            // the pin that we use for the potentiometer
// give a name to the pins that you use for the second motor
const int speedPin2 = 9;            // the pin that we use to control the motor's speed
const int forwardPin2 = 10;        // the pin that we use to tell the motor to go forward
const int reversePin2 = 11;        // the pin that we use to tell the motor to go reverse
const int forwardButton2 = 12;     // the pin that we use for the forward button
const int reverseButton2 = 13;     // the pin that we use for the reverse button
const int forwardContButton2 = A1; // the pin that we use for the forward continuous button
const int reverseContButton2 = A2; // the pin that we use for the reverse continuous button
const int potPin2 = A4;            // the pin that we use for the potentiometer
// make a new instance of the L293 library and call it "motor1" and "motor2"
L293 motor(speedPin1, forwardPin1, reversePin1);
L293 motor2(speedPin2, forwardPin2, reversePin2);
  // initialize potentiometer pins

void setup()
{
  
  Serial.begin(9600);

  // initialize input pins for all buttons
  pinMode(forwardButton, INPUT_PULLUP);
  pinMode(reverseButton, INPUT_PULLUP);
  pinMode(forwardContButton, INPUT_PULLUP);
  pinMode(reverseContButton, INPUT_PULLUP);

  pinMode(forwardButton2, INPUT_PULLUP);
  pinMode(reverseButton2, INPUT_PULLUP);
  pinMode(forwardContButton2, INPUT_PULLUP);
  pinMode(reverseContButton2, INPUT_PULLUP);
   pinMode(potPin1, INPUT);
  pinMode(potPin2, INPUT);
}

void loop()
{
 
  // read the potentiometer values for each motor
  int potValue1 = analogRead(potPin1);
  int potValue2 = analogRead(potPin2);

  // map the potentiometer values to the range of 0-255 for motor speed
  int motorSpeed1 = map(potValue1, 0, 1023, 0, 255);
  int motorSpeed2 = map(potValue2, 0, 1023, 0, 255);
  // check if the forward button of motor 1 is pressed
  if (digitalRead(forwardButton) == LOW)
  {
    // call the forward function with the mapped speed value
    motor.forward(motorSpeed1);

    // loop until the button is released
    while (digitalRead(forwardButton) == LOW)
    {
      // do nothing, just wait for the button to be released
    }

    // stop the motor once the button is released
    motor.stop();
  }

  // check if the reverse button is pressed
  if (digitalRead(reverseButton) == LOW)
  {
    // call the back function with the mapped speed value
    motor.back(motorSpeed1);

    // loop until the button is released
    while (digitalRead(reverseButton) == LOW)
    {
      // do nothing, just wait for the button to be released
    }

    // stop the motor once the button is released
    motor.stop();
  }
  
  // check if the forward continuous button is pressed
  if (digitalRead(forwardContButton) == LOW)
  {
    // call the forward function with the mapped speed value
    motor.forward(motorSpeed1);
  }

  // check if the reverse continuous button is pressed
  if (digitalRead(reverseContButton) == LOW)
  {
    // call the back function with the mapped speed value
    motor.back(motorSpeed1);
  }

  if (digitalRead(forwardButton2) == LOW)
  {
    // call the forward function with the mapped speed value
    motor2.forward(motorSpeed2);

    // loop until the button is released
    while (digitalRead(forwardButton2) == LOW)
    {
      // do nothing, just wait for the button to be released
    }

    // stop the motor once the button is released
    motor2.stop();
  }

  // check if the reverse button is pressed
  if (digitalRead(reverseButton2) == LOW)
  {
    // call the back function with the mapped speed value
    motor2.back(motorSpeed2);

    // loop until the button is released
    while (digitalRead(reverseButton2) == LOW)
    {
      // do nothing, just wait for the button to be released
    }

    // stop the motor once the button is released
    motor2.stop();
  }
  
  // check if the forward continuous button is pressed
  if (digitalRead(forwardContButton2) == LOW)
  {
    // call the forward function with the mapped speed value
    motor2.forward(motorSpeed2);
  }

  // check if the reverse continuous button is pressed
  if (digitalRead(reverseContButton2) == LOW)
  {
    // call the back function with the mapped speed value
    motor2.back(motorSpeed2);
  }
}