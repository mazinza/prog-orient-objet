//
// Created by MazinZaouali on 11/04/2022.
//

#include <AccelStepper.h>
#include <MultiStepper.h>
#include "Robot.h"

Robot:: Robot(){

}

Robot:: ~Robot(){

}

void Robot :: motors_setup(AccelStepper *left_wheel, AccelStepper *right_wheel, MultiStepper *steppers ,int speed, float acceleration){
    
  // Configure each stepper
  left_wheel->setMaxSpeed(speed);
  left_wheel->setAcceleration(acceleration);
  right_wheel->setMaxSpeed(speed);
  right_wheel->setAcceleration(acceleration);
  // Then give them to MultiStepper to manage
  steppers->addStepper(*left_wheel);
  steppers->addStepper(*right_wheel);
  
}


void Robot :: go_forward(AccelStepper * left_wheel,AccelStepper * right_wheel,MultiStepper * steppers, long *positions, int button){
  positions[0] += -500;
  positions[1] += +500;
  steppers->moveTo(positions);
  int state=digitalRead(button);
  while (left_wheel->distanceToGo()!=0 && right_wheel->distanceToGo()!=0 && state!=0){    
    steppers->run(); // Blocks until all are in position
    state=digitalRead(button);
    if (state==0){
      pinMode(47,OUTPUT);
    }
  }
    delay(100);
}


void Robot:: turn_right(AccelStepper * left_wheel,AccelStepper * right_wheel,MultiStepper * steppers,long *positions, int button){
  positions[0] += 2000;
  steppers->moveTo(positions);
  int state=digitalRead(button);
  while (left_wheel->distanceToGo()!=0 && state!=0){    
    steppers->run(); // Blocks until all are in position
    state=digitalRead(button);
    if (state==0){
      pinMode(47,OUTPUT);
    }
  }
  delay(500);
}

void Robot:: turn_left(AccelStepper * left_wheel,AccelStepper * right_wheel,MultiStepper * steppers,long *positions, int button){
  
  positions[1] += -2000;
  steppers->moveTo(positions);
  int state=digitalRead(button);
  while (right_wheel->distanceToGo()!=0 && state!=0){    
    steppers->run(); // Blocks until all are in position
    state=digitalRead(button);
    if (state==0){
      pinMode(47,OUTPUT);
    }
  }
  delay(500);
}




bool Robot:: getParity(unsigned int n)
{
    bool parity = 0;
    while (n)
    {
        parity = !parity;
        n     = n & (n - 1);
    }    
    return parity;
}


void Robot:: turn(Robot *myRobot,AccelStepper * left_wheel,AccelStepper * right_wheel,MultiStepper * steppers,long *positions, int button,int current_line){
      myRobot->go_forward(left_wheel,right_wheel,steppers,positions,button);
      if (myRobot->getParity(current_line)==1 ){
        myRobot->turn_right(left_wheel,right_wheel,steppers,positions,button);
        myRobot->go_forward(left_wheel,right_wheel,steppers,positions,button);
        myRobot->turn_right(left_wheel,right_wheel,steppers,positions,button);
      } else if(myRobot->getParity(current_line)==0){
        myRobot->turn_left(left_wheel,right_wheel,steppers,positions,button);
        myRobot->go_forward(left_wheel,right_wheel,steppers,positions,button);
        myRobot->turn_left(left_wheel,right_wheel,steppers,positions,button);
      }
}


void Robot:: plant(Robot *myRobot,Graine *ptr, Servo* myservo,AccelStepper * left_wheel,AccelStepper * right_wheel,MultiStepper * steppers,long *positions, int button, int plants_per_line){
        while (plants_per_line>0){
          myRobot->go_forward(left_wheel,right_wheel,steppers,positions,button);
          ptr->drop(myservo, button);
          ++(*ptr);
          ptr->afficher();
          plants_per_line--;       
      }
}
