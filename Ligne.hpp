//
// Created by MazinZaouali on 11/04/2022.
//

#ifndef LIGNE_H
#define LIGNE_H

#include "Arduino.h"

using namespace std;

template <typename T>
/**
 * @class Ligne
 * @brief Ligne class
 */
class Ligne
{
public :
  /**
   * @fn Ligne(T obj)
   * @param obj Object associated with Ligne
   * @brief main Constructor that associates an Object with a line
   */
  Ligne(T obj);

  /**
   * @fn ~Ligne()
   * @brief Destructor
   */
  ~Ligne();

  /**
   * @fn void SetNext(Ligne * _next)
   * @param _next Pointer on next Ligne
   * @brief Set pointer to next Ligne
   */
  void SetNext(Ligne * _next);

  /**
   * @fn void SetObject(T obj)
   * @param obj Address of object associated with current Ligne
   * @brief Set myObject of current Ligne
   */
  void SetObject(T obj);

  /**
   * @fn Ligne * GetNext()
   * @return Address of next Ligne
   * @brief Returns address of next Ligne
   */
  Ligne * GetNext();

  /**
   * @fn T GetObject()
   * @return Address of object associated with current Ligne
   * @brief Returns address of object associated with current Ligne
   */
  T GetObject();

private :
  T myObject;     //Object associated with Ligne
  Ligne * next;   //Pointer on next Ligne
};


#endif //LIGNE_H
