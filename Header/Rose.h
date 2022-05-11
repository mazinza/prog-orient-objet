//
// Created by MazinZaouali on 11/04/2022.
//

#ifndef ROBOTGRAINE_ROSE_H
#define ROBOTGRAINE_ROSE_H


#include "Arduino.h"
#include "Graine.h"
#include <Stepper.h>


/**
 * @class Rose
 * @brief Rose class, Graine subclass
 */
class Rose: public Graine{
public:
/**
  /**
   * @fn Rose()
   * @brief Default constructor
   */
    Rose();

   /**
   * @fn ~Rose()
   * @brief Default destructor
   */
    ~Rose();

   /**
   * @fn char afficherCaracteristiques()
   * @return char indicating R
   * @brief returns a char indicating that object is a Rose
   */
    char afficherCaracteristiques();
    
   /**
   * @fn  void drop(Servo *myservo,int button)
   * @param *myservo Servo object, button number of pin used for RESET
   * @brief drops a Rose seed
   */
    void drop(Servo *myservo,int button);
    
};


#endif //ROBOTGRAINE_ROSE_H
