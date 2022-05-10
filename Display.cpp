//
// Created by MazinZaouali on 11/04/2022.
//

#include "Display.hpp"


Display:: Display(){

}

Display:: ~Display(){

}

void Display :: display_setup(LedControl *lc, int button){
  
  lc->shutdown(0,false);// turn off power saving, enables display
  lc->setIntensity(0,8);// sets brightness (0~15 possible values)
  lc->clearDisplay(0);// clear screen
  pinMode(button, INPUT); // button is input
  digitalWrite(button, HIGH); // initalize button as ON  

}

int Display:: screen_display(LedControl *lc, Choix_Mode <Graine *> *myList, int button, int finish, int robot_start, byte *r){ //IL FAUT GERER LES COINS DU JOYSTICK

  static int i=0;

  lc->setRow(0,0,r[0]);
  lc->setRow(0,1,r[1]);
  lc->setRow(0,2,r[2]);
  lc->setRow(0,3,r[3]);
  lc->setRow(0,4,r[4]);
  lc->setRow(0,5,r[5]);
  lc->setRow(0,6,r[6]);
  lc->setRow(0,7,r[7]);
  lc->setRow(0,8,r[8]);
  lc->setRow(0,9,r[9]);
 
  int UD = analogRead(A1); // read analog value at pin A1 and stores as UD
  int LR = analogRead(A0);  // read analog value at pin A0 and stores as LR
  int state=digitalRead(button); //determines the state of button (HIGH or LOW)
  //Serial.println(digitalRead(button));
  
  // scales down the value from 0-1023 to 0-7
  char x_translate = map(LR, 0,1023, 7, -1); 
  char y_translate = map(UD, 0,1023, 0, 8);

 /* Serial.print ("Button=");
  Serial.print(state, DEC);
  Serial.print(", UD = ");
  Serial.print(UD, DEC);
  Serial.print(", LR = ");
  Serial.print(LR, DEC);
  Serial.print(", x = ");
  Serial.print(x_translate, DEC); 
  Serial.print(", y = ");
  Serial.println(y_translate, DEC); */

   // clears display whenever a new value is updated 
    //lc.clearDisplay(0);
    lc->setLed(0,x_translate,y_translate,true);  
    // if button is pressed, LED is OFF and vice versa 
    if (state==1){
    lc->setLed(0,x_translate,y_translate,true);
    }
    else {
    lc->setLed(0,x_translate,y_translate,false); 
    
    }

    if (i<=8 && finish!=1){
      
      if (x_translate>6){
        r[i]=r[i]|B00000111;
        i=i+1;

        myList->insert(new Tulipe);
        Serial.println("Vous avez choisi de planter des Tulipes");

        
      }
      else{
        if (x_translate<3){
        r[i]=r[i]|B00000101;
        i=i+1;


        myList->insert(new Rose);
        Serial.println("Vous avez choisi de planter des Roses");
        
        }
      }

      if (y_translate>6 && !myList->isEmpty()){
        finish=1;
        robot_start=1;
      }
    }
    
      if (state==0){
        pinMode(47,OUTPUT);
      }
    delay(170);

    return robot_start;

}


void Display:: LCD_setup(U8G2_SH1107_SEEED_128X128_1_SW_I2C *u8g2){
  u8g2->begin();
}


void Display:: LCD_display(U8G2_SH1107_SEEED_128X128_1_SW_I2C *u8g2,String myString){
  u8g2->firstPage();
  do {
    u8g2->setFont(u8g2_font_ncenB10_tr);
    u8g2->drawStr(20,40,"Seeds planted: ");
    u8g2->drawStr(30,80,myString.c_str());
  } while ( u8g2->nextPage() );
}
