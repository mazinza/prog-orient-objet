//
// Created by MazinZaouali on 11/04/2022.
//

#include "Ligne.hpp"
#include "Graine.h"

template <typename T>
Ligne<T>::Ligne(T obj) : myObject(obj),next(nullptr) 
{
  
}

template <typename T>
Ligne<T>::~Ligne() 
{
  
}

template <typename T> 
void Ligne<T>::SetNext(Ligne * _next)
{
  next = _next;
}

template <typename T> 
void Ligne<T>::SetObject(T obj)
{
  myObject = obj;
}
 
template <typename T> 
Ligne<T>* Ligne<T>::GetNext()
{
  return next;
}

template <typename T> 
T Ligne<T>::GetObject()
{
  return myObject;
}

template class Ligne<Graine *>;
