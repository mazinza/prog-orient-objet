//
// Created by MazinZaouali on 11/04/2022.
//

#ifndef ROBOTGRAINE_DISPLAY_H
#define ROBOTGRAINE_DISPLAY_H

#include "LedControl.h"
#include "Choix_Mode.hpp"
#include "Graine.h"
#include "Tulipe.h"
#include "Rose.h"
#include "Arduino.h"
#include <U8g2lib.h>


/**
 * @class Display
 * @brief Display class
 */
class Display{

public:
/**
    /**
   * @fn Display()
   * @brief Default Constructor
   */
    Display();

 
    /**
     * @fn ~Display()
     * @brief Default Destructor
     */   
    ~Display();

  
    /**
     * @fn void display_setup(LedControl *lc, int button)
     * @param *lc Ledcontrol object, button Number of pin used
     * @brief Setup for the screen display
     */
    void display_setup(LedControl *lc, int button);

     /**
     * @fn  int screen_display(LedControl *lc, Choix_Mode <Graine *> *myList, int button, int finish, int robot_start, byte *r)
     * @param *lc Ledcontrol object, *myList Choix_Mode <Graine *> object,  button Number of pin used for RESET, finish flag, robot_start flag, *r bytes to display on screen
     * @brief Display for choosing Modes (between R and T)
     */
    int screen_display(LedControl *lc, Choix_Mode <Graine *> *myList, int button, int finish, int robot_start, byte *r);

     /**
     * @fn  void LCD_setup(U8G2_SH1107_SEEED_128X128_1_SW_I2C *u8g2)
     * @param *u8g2 U8G2_SH1107_SEEED_128X128_1_SW_I2C object
     * @brief Setup for the LCD display
     */
    void LCD_setup(U8G2_SH1107_SEEED_128X128_1_SW_I2C *u8g2);

     /**
     * @fn  void LCD_display(U8G2_SH1107_SEEED_128X128_1_SW_I2C *u8g2,String myString)
     * @param *u8g2 U8G2_SH1107_SEEED_128X128_1_SW_I2C object, myString String to print on lcd
     * @brief Display to indicate number of seeds planted in total
     */
    void LCD_display(U8G2_SH1107_SEEED_128X128_1_SW_I2C *u8g2,String myString);

};


#endif //ROBOTGRAINE_DISPLAY_H
