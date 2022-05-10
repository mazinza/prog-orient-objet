//
// Created by MazinZaouali on 11/04/2022.
//

#ifndef CHOIX_MODE_H
#define CHOIX_MODE_H

#include "Arduino.h"
#include "Ligne.hpp"
//#include <exception>
using namespace std;

template <typename T>
/**
 * @class Choix_Mode
 * @brief Choix_Mode class
 */
class Choix_Mode
{
public :

// !!!!! ERROR CLASS COMMENTED DUE TO ARDUINO MEGA NOT SUPPORTING EXCEPTIONS !!!!! //
/**
   * @class Error
   * @brief Error class
   */
  //class Error
  //{
  //public:
    /**
     * @fn Error(string ch)
     * @param ch error message
     * @brief main Constructor
     */
   // Error(string ch):code(ch){}
    /**
     * @string getError()
     * @return message containing "Error"
     * @brief returns message containing "Error"
     */
   // string getError()
    //{
      //return code;
   // }
  //private:
    //string code;  //!< Infos sur l'Error.
  //};
// !!!!! ERROR CLASS COMMENTED DUE TO ARDUINO MEGA NOT SUPPORTING EXCEPTIONS !!!!! //

/**
  /**
   * @fn Choix_Mode()
   * @brief Default Constructor
   */
  Choix_Mode();

  /**
   * @fn ~Choix_Mode()
   * @brief Default Destructor
   */
  ~Choix_Mode();

  /**
   * @fn void insert(element obj)
   * @param obj Object to add in the linked list
   * @brief Associate an object to a cell in the linked list
   */
  void insert(T obj);

  /**
   * @fn void delete_cell()
   * @brief Delete the first cell
   */
  void delete_cell();

  /**
   * @fn void delete_cell(T obj)
   * @param obj Object to delete
   * @brief Delete an object in the linked list
   */
  void delete_cell(T obj);

  /**
   * @fn T FirstCell()
   * @return Address of the object associated with the first cell
   * @brief Returns the address of the object associated with the first cell
   */
  T FirstCell();

  /**
   * @fn T last()
   * @return Address of the object associated with the first cell
   * @brief Returns the address of the object associated with the last cell
   */
  T last();

  /**
   * @fn int GetCountCell()
   * @return Number of cells in the list
   * @brief Returns the number of cells in the linked list
   */
  int GetCountCell();

  /**
   * @fn bool isEmpty()
   * @return Boolean indicating if the list is empty or not
   * @brief Returns a boolean indicating if the list is empty or not
   */
  bool isEmpty();

protected :
  Ligne<T> * start; // Ptr on first cell
  Ligne<T> * finish; // Ptr on last cell
  int CountCell;    //! number of cells in the linked list
};

//#include "Choix_Mode.cpp"

#endif /* CHOIX_MODE_H */
