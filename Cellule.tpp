/**
 * @fn Cellule.cpp
 * @date 5 avr. 2019
 * @author ggourves
 * @brief Fichier source de la classe Cellule.
 */

template <typename T>
Cellule<T>::Cellule(T val) : myObject(val),next(nullptr) 
{
	
}

template <typename T>
Cellule<T>::~Cellule() 
{
	
}

template <typename T> 
void Cellule<T>::SetNext(Cellule * _next)
{
	next = _next;
}

template <typename T> 
void Cellule<T>::SetObject(T _myObject)
{
	myObject = _myObject;
}
 
template <typename T> 
Cellule<T>* Cellule<T>::GetNext()
{
	return next;
}

template <typename T> 
T Cellule<T>::GetObject()
{
	return myObject;
}


