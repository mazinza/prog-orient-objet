//
// Created by MazinZaouali on 11/04/2022.
//

#ifndef ROBOTGRAINE_ROBOT_H
#define ROBOTGRAINE_ROBOT_H


#include <AccelStepper.h>
#include <MultiStepper.h>
#include <Servo.h>
#include "Graine.h"
#include "Arduino.h"


/**
 * @class Robot
 * @brief Robot class
 */
class Robot {

public:
/**
  /**
   * @fn Robot()
   * @brief Default constructor
   */
    Robot();

   /**
   * @fn ~Robot()
   * @brief Default destructor
   */
    ~Robot();

   /**
   * @fn void turn_right(AccelStepper * left_wheel,AccelStepper * right_wheel,MultiStepper * steppers,long *positions, int button)
   * @param * left_wheel AccelStepper object, *right_wheel AccelStepper object, *steppers MultiStepper object, *positions long array, button number of pin used for RESET
   * @brief makes the Robot turn right
   */
    void turn_right(AccelStepper * left_wheel,AccelStepper * right_wheel,MultiStepper * steppers,long *positions, int button);

   /**
   * @fn void turn_left(AccelStepper * left_wheel,AccelStepper * right_wheel,MultiStepper * steppers,long *positions, int button)
   * @param * left_wheel AccelStepper object, *right_wheel AccelStepper object, *steppers MultiStepper object, *positions long array, button number of pin used for RESET
   * @brief makes the Robot turn left
   */
    void turn_left(AccelStepper * left_wheel,AccelStepper * right_wheel,MultiStepper * steppers,long *positions, int button);

   /**
   * @fn void go_forward(AccelStepper * left_wheel,AccelStepper * right_wheel,MultiStepper * steppers,long *positions, int button)
   * @param * left_wheel AccelStepper object, *right_wheel AccelStepper object, *steppers MultiStepper object, *positions long array, button number of pin used for RESET
   * @brief makes the Robot go forward
   */
    void go_forward(AccelStepper * left_wheel,AccelStepper * right_wheel,MultiStepper * steppers,long *positions, int button);
    
   /**
   * @fn  void motors_setup(AccelStepper *left_wheel,AccelStepper *right_wheel,MultiStepper *steppers, int speed, float acceleration)
   * @param * left_wheel AccelStepper object, *right_wheel AccelStepper object, *steppers MultiStepper object, speed motor speed, acceleration motor acceleration
   * @brief Setup for both wheel motors
   */
    void motors_setup(AccelStepper *left_wheel,AccelStepper *right_wheel,MultiStepper *steppers, int speed, float acceleration);
    
   /**
   * @fn void turn(Robot *myRobot,AccelStepper * left_wheel,AccelStepper * right_wheel,MultiStepper * steppers,long *positions, int button,int current_line)
   * @param * left_wheel AccelStepper object, *right_wheel AccelStepper object, *steppers MultiStepper object, *positions long array, button number of pin used for RESET, current_line number of current line
   * @brief makes the Robot turn left or right depending on the current line
   */
    void turn(Robot *myRobot,AccelStepper * left_wheel,AccelStepper * right_wheel,MultiStepper * steppers,long *positions, int button,int current_line);
    
   /**
   * @fn void plant(Robot *myRobot,Graine *ptr, Servo* myservo,AccelStepper * left_wheel,AccelStepper * right_wheel,MultiStepper * steppers,long *positions, int button, int plants_per_line)
   * @param *myRobot Robot object, *ptr Graine pointer, *myservo Servo object,AccelStepper * left_wheel,AccelStepper * right_wheel, *steppers MultiStepper object, *positions long array, button number of pin used for RESET, plants_per_line number of plants to drop per line
   * @brief makes the Robot drop a seed depending on the number of plants_per_line requested
   */
    void plant(Robot *myRobot,Graine *ptr, Servo* myservo,AccelStepper * left_wheel,AccelStepper * right_wheel,MultiStepper * steppers,long *positions, int button, int plants_per_line);
    
   /**
   * @fn bool getParity(unsigned int n)
   * @param n number of current line
   * @return bool indicating parity or not
   * @brief returns the parity of current line to adjust the turn function
   */
    bool getParity(unsigned int n);


};


#endif //ROBOTGRAINE_ROBOT_H
