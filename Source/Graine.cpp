//
// Created by MazinZaouali on 11/04/2022.
//
#include <Stepper.h>
#include <Servo.h>
#include "Graine.h"


Graine:: Graine(){

}


Graine:: Graine(int n){
  nbGraines=n;
}

Graine:: ~Graine(){

}

int Graine:: nbGraines = 0;



 void * Graine :: operator ++(){
  nbGraines= nbGraines+1;
}

void Graine::  afficher() {
        Serial.print("Nombre de graines plantées: ");
        Serial.println(nbGraines);
}

int Graine:: get_nbGraines(){ // returns private member nbGraines
  return nbGraines;
}
