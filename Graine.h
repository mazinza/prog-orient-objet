//
// Created by MazinZaouali on 11/04/2022.
//

#ifndef ROBOTGRAINE_GRAINE_H
#define ROBOTGRAINE_GRAINE_H


#include "Arduino.h"
#include <Stepper.h>
#include <Servo.h>    
using namespace std; 


/**
 * @class Graine
 * @brief Graine class
 */
class Graine {

public:
/**
   /**
   * @fn Graine()
   * @brief Default Constructor
   */
    Graine();
   /**
   * @fn Graine(int n)
   * @param n number of seeds
   * @brief Constructor that initialises the number of seeds
   */
    Graine(int n);

   /**
   * @fn ~Graine()
   * @brief Default Destructor
   */
    virtual ~Graine();

   /**
   * @fn void * operator ++()
   * @brief operator ++ overload to calculate number of seeds dropped
   */
    void * operator ++();
    
   /**
   * @fn void afficher()
   * @brief prints number of seeds dropped
   */
    void afficher();
        
   /**
   * @fn virtual char afficherCaracteristiques()
   * @return char which indicates which subclass is used for RESET
   * @brief indicates which subclass is used
   */
    virtual char afficherCaracteristiques();

   /**
   * @fn virtual void drop(Servo *myservo,int button)
   * @param *myservo Servo object, button number of pin used for RESET
   * @brief drops a Rose or Tulipe seed
   */
    virtual void drop(Servo *myservo,int button);

   /**
   * @fn int get_nbGraines()
   * @return number of seeds dropped
   * @brief returns number of seeds dropped
   */
    int get_nbGraines();
private:

    static int nbGraines;


};


#endif //ROBOTGRAINE_GRAINE_H
