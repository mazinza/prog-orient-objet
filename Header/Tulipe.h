//
// Created by MazinZaouali on 11/04/2022.
//

#ifndef ROBOTGRAINE_TULIPE_H
#define ROBOTGRAINE_TULIPE_H

#include "Arduino.h"
#include "Graine.h"

/**
 * @class Tulipe
 * @brief Tulipe class, Graine subclass
 */
class Tulipe : public Graine{

public:
/**
  /**
   * @fn Tulipe()
   * @brief Default constructor
   */
    Tulipe();

   /**
   * @fn ~Tulipe()
   * @brief Default destructor
   */
    ~Tulipe();
    
   /**
   * @fn char afficherCaracteristiques()
   * @return char indicating R
   * @brief returns a char indicating that object is a Tulipe
   */
    char afficherCaracteristiques();
    
   /**
   * @fn  void drop(Servo *myservo,int button)
   * @param *myservo Servo object, button number of pin used for RESET
   * @brief drops a Tulipe seed
   */
    void drop(Servo *myservo,int button);
};


#endif //ROBOTGRAINE_TULIPE_H
