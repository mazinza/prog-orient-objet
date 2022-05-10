//
// Created by MazinZaouali on 11/04/2022.
//

#include "Tulipe.h"
#include <Servo.h>

Tulipe:: Tulipe(){

}

Tulipe:: ~Tulipe(){

}

void Tulipe:: drop(Servo * myservo,int button){

  if (digitalRead(button)==0){
      pinMode(47,OUTPUT);
  }
  myservo->attach(3);
  delay(15);
  myservo->write(170);
  delay(400);
  myservo->detach(); 
  delay(1000);
  myservo->attach(3);
  if (digitalRead(button)==0){ //check right before writing again, and if button is pressed, put servo in the original spot and then stop the process
      myservo->write(10);
      delay(400);
      pinMode(47,OUTPUT);
  } 
  delay(15);
  myservo->write(10);
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

char Tulipe:: afficherCaracteristiques(){
  Serial.println("Je suis une Tulipe");
  return ('T');
}
