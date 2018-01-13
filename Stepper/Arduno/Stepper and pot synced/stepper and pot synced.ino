
#include "Stepper.h";

int in1Pin = 12;
int in2Pin = 11;
int in3Pin = 10;
int in4Pin = 9;

int potPin = A0;
int d_steps = 0;

float step_angle;
// change this to the number of steps on your motor
#define STEPS 200

Stepper motor(STEPS, in1Pin, in2Pin, in3Pin, in4Pin);  

void setup()
{
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);

  step_angle = (360/(STEPS));

  motor.setSpeed(100);
}

void loop()
{
  int steps = int(map(analogRead(potPin),0,1023,0,200)/(step_angle));
  d_steps = steps - d_steps; 
    motor.step(d_steps);
    d_steps = steps;
    delay(50);
}

