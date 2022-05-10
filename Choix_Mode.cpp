//
// Created by MazinZaouali on 11/04/2022.
//

#include "Choix_Mode.hpp"
#include "Graine.h"
using namespace std;

template <typename T>
Choix_Mode<T>::Choix_Mode() : start(NULL),finish(NULL),CountCell(0)
{

}

template <typename T>
Choix_Mode<T>::~Choix_Mode() 
{

}

template <typename T>
void Choix_Mode<T>::insert(T obj)
{
  if (start==NULL)
  {
    start=new Ligne<T>(obj);
    finish=start;
  }
  else
  {
    finish->SetNext(new Ligne<T>(obj));
    finish=finish->GetNext();
  }
  CountCell++;
}

template <typename T>
void Choix_Mode <T>::delete_cell()
{
  if (CountCell!=0)
  {
    if (start==finish)
    {
      delete start;
      start=NULL;
      finish=NULL;
      CountCell=0;
    }
    else
    {
      Ligne<T> *aux;
      aux=start;
      start=start->GetNext();
      delete aux;
      CountCell--;
    }
  }
}

template <typename T>
void Choix_Mode<T>::delete_cell(T obj)
{
  if (CountCell!=0)
  {
    Ligne<T> *Cell_search;
    Cell_search = start;
    if(Cell_search->GetObject()==obj)
    {
      start = Cell_search->GetNext();
      delete Cell_search;
      CountCell--;
    }
    else
    {
      bool succes = false;
      while(Cell_search!=finish)
      {
        if(Cell_search->GetNext()->GetObject()==obj)
        {
          Ligne<T> *Cell_find = Cell_search->GetNext();
          Cell_search->SetNext(Cell_search->GetNext()->GetNext());
          delete(Cell_find);
          succes = true;
          CountCell--;
        }
        Cell_search=Cell_search->GetNext();
      }
      if(!succes)
      {
        Serial.print("Object to delete not found in the list!");
        //throw Error(string("Object to delete not found in the list!"));
      }
    }
  }
  else
  {
    Serial.print("List is empty!");
    // throw Error(string("List is empty!"));
  }
}

template <typename T>
T Choix_Mode<T>::FirstCell()
{
  T resultat;
  if (start)
  {
    resultat = start->GetObject();
  }
  else
  {
    Serial.print("No Object in first cell");
    // throw Error(string("No Object in first cell"));
  }
  return resultat;
}

template <typename T>
T Choix_Mode<T>::last()
{
  T resultat;
  if (finish)
  {
    resultat = finish->GetObject();
  }
  else
  {
    Serial.print("no Object in last cell");
    // throw Error(string("no Object in last cell"));
  }
  return resultat;
}

template <typename T>
int Choix_Mode<T>::GetCountCell()
{
  return CountCell;
}

template <typename T>
bool Choix_Mode<T>::isEmpty()
{
  return(CountCell==0);
}


template class Choix_Mode<Graine *>;
