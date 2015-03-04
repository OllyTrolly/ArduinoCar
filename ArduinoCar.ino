#include <Stepper.h>

/*
  A program to drive my Arduino car
 */

// Initialise stepper motors
float stepsPerRev = 5.625;
int stepDegs = 360/stepsPerRev; //Motor does 8 steps per rev, so each step is this many degrees
Stepper leftStepper  = Stepper(stepDegs/8, 8, 9, 10, 11);
Stepper rightStepper = Stepper(stepDegs/8, 4, 5, 6, 7);
int rpm = 1000; //Revs per minute
float rotateCoEff = 20; //Rough coefficient to determine number of steps per degree, taken at 1000rpm
float distanceCoEff = 25; //Rough coefficient to determine number of steps per mm, taken at 1000rpm

void setup() {
  leftStepper.setSpeed(rpm);
  rightStepper.setSpeed(rpm);
  
  forward(500);
  rotateRight(90);
  forward(500);
  rotateRight(90);
  forward(500);
  rotateRight(90);
  forward(500);
  rotateRight(90);
}
// the loop function runs over and over again forever
void loop() {
  
}

void forward(int mm) {
   int steps = mm * distanceCoEff;
   for(int s = 0; s < steps; s++)
   {
     leftStepper.step(1);
     rightStepper.step(-1);
   } 
}

void backward(int mm) {
  int steps = mm * distanceCoEff;
  for(int s = 0; s < steps; s++)
  {
    leftStepper.step(-1);
    rightStepper.step(1);
  }
}

void rotateLeft(int degs) {
  int steps = degs * rotateCoEff;
  for(int s = 0; s < steps; s++)
  {
    leftStepper.step(-1);
    rightStepper.step(-1);
  } 
}

void rotateRight(int degs) {
  int steps = degs * rotateCoEff;
  for(int s = 0; s < steps; s++)
  {
    leftStepper.step(1);
    rightStepper.step(1);
  }
}

//Ratio should be positive and larger than 1
void bearRight(int ratio, int steps) {
  for(int s = 0; s < steps; s++)
  {
    leftStepper.step(ratio);
    rightStepper.step(-1);
  }
}

//Ratio should be positive and larger than 1
void bearLeft(int ratio, int steps) {
  for(int s = 0; s < steps; s++)
  {
    leftStepper.step(1);
    rightStepper.step(-ratio);
  }
}


