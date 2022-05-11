//
// Created by MazinZaouali on 11/04/2022.
//

#include "Rose.h"
#include <Stepper.h>

Rose:: Rose(){

}

Rose:: ~Rose(){

}

void Rose:: drop(Servo * myservo,int button){
  if (digitalRead(button)==0){
      pinMode(47,OUTPUT);
  }
  myservo->attach(3);
  delay(15);
  myservo->write(10);
  delay(400);
  myservo->detach();
  delay(1000);
  myservo->attach(3);
  if (digitalRead(button)==0){ //check right before writing again, and if button is pressed, put servo in the original spot and then stop the process
      myservo->write(170);
      delay(400);
      pinMode(47,OUTPUT);
  }  
  delay(15);
  myservo->write(170);
  delay(400);
  myservo->detach();
  if (digitalRead(button)==0){
      pinMode(47,OUTPUT);
  }
  delay(1000);
  if (digitalRead(button)==0){
      pinMode(47,OUTPUT);
  }
}

char Rose:: afficherCaracteristiques(){
  Serial.println("Je suis une Rose");
  return ('R');
}
