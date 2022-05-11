/**
 * @file sketch_apr06a.ino     
 * @date Created on 11/04/2022.    
 * @author Mazin Zaouali
 * @brief Source File that contains the main program   
*/

#include <AccelStepper.h>
#include <MultiStepper.h>
#include <Servo.h>
#include "Graine.h"
#include "Rose.h"
#include "Tulipe.h"
#include "Robot.h"
#include "Choix_Mode.hpp"
#include "Ligne.hpp"
#include "Display.hpp"
#include "LedControl.h"
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>
//#include <exception> // !!!!! ERROR CLASS COMMENTED DUE TO ARDUINO MEGA NOT SUPPORTING EXCEPTIONS !!!!! //


// -------------------------------- LCD SCREEN ----------------------------------- //
 
U8G2_SH1107_SEEED_128X128_1_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);


// -------------------------------- SCREEN ----------------------------------- //

String nb;
int button=12;
int finish=0;
int robot_start=0;

LedControl lc=LedControl(28,32,30,0);
byte r[9]={B10000000,B11110000,B10000000,B00000000,B00000000,B01010000,B10100000,B11110000};


Display myScreen;


// -------------- MOTORS --------------------- //

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

long positions[2]; // Array of desired stepper positions

//Stepper myStepper (stepsPerRevolution,8, 10, 9, 11);
AccelStepper left_wheel(AccelStepper::FULL4WIRE, 8, 10, 9, 11);
AccelStepper right_wheel(AccelStepper::FULL4WIRE, 4, 6, 5, 7);

MultiStepper steppers;
Robot myRobot;
Rose R1;
Tulipe T1;

// -------------- LIST --------------------- //

int current_line=1; //set the current line at 1 for pre-incrementation and getParity function param
Choix_Mode <Graine *> myList;


void setup() 
{
  // ------------------ LCD SCREEN  --------------------- //
  
  myScreen.LCD_setup(&u8g2);

  // ------------------ SCREEN  --------------------- //
  
  Serial.begin(9600);
  myScreen.display_setup(&lc,button);
  
  // ------------------ MOTORS ------------------------ //

  myRobot.motors_setup(&left_wheel,&right_wheel,&steppers, 400,100.0);

}

void loop() {

  // myRobot.go_forward(&left_wheel,&right_wheel,&steppers, positions, button);
  robot_start=myScreen.screen_display(&lc, &myList, button, finish, robot_start, r); // displays the seed options (per line) on screen and then starts the robot. Limit is 8 lines. 
                                                                                     // Use joystick to choose (left: R, right: T, down: "confirm", click or hold: "RESET")
  
  if (robot_start==1){ // if robot is started with joystick
    
   while (!myList.isEmpty()){ // this loop can be interrupted anytime by holding the joystick for around 2 seconds
      
      static int plants_per_line=2; // can replace by input
      current_line++;
      
      Graine *ptr=myList.FirstCell(); 
      ptr->afficherCaracteristiques();

      myRobot.plant(&myRobot, ptr, &myservo, &left_wheel, &right_wheel, &steppers, positions, button, plants_per_line); // the robot will plant seeds according to the number requested with plants_per_line
      String myString = String(ptr->get_nbGraines());
      myScreen.LCD_display(&u8g2,myString); //displays the number of seeds planted on the LCD screen after each line is finished

      myRobot.turn(&myRobot,&left_wheel,&right_wheel,&steppers,positions, button,current_line); // the robot will turn (left or right) after finishing each line
      
      myList.delete_cell(ptr); //delete the cell from list
      delete(ptr); //delete the pointer from memory
    }
    if (myList.isEmpty()){ // if the list is empty, go back to requesting new orders on screen
      robot_start=0;
    }
  }
}    
