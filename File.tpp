/**
 * @file 	File.cpp
 * @date 	Created on: 12 avr. 2019
 * @author  guillaume.gourves@onera.fr
 * @brief Fichier source de la classe File.
 */
using namespace std;

template <typename T>
File<T>::File() : deb(NULL),fin(NULL),CountCell(0)
{

}

template <typename T>
File<T>::~File() 
{

}

template <typename T>
void File<T>::insertion(T val)
{
	if (deb==NULL)
	{
		deb=new Cellule<T>(val);
		fin=deb;
	}
	else
	{
		fin->SetNext(new Cellule<T>(val));
		fin=fin->GetNext();
	}
	CountCell++;
}

template <typename T>
void File<T>::suppression()
{
	if (CountCell!=0)
	{
		if (deb==fin)
		{
			delete deb;
			deb=NULL;
			fin=NULL;
			CountCell=0;
		}
		else
		{
			Cellule<T> *aux;
			aux=deb;
			deb=deb->GetNext();
			delete aux;
			CountCell--;
		}
	}
}

template <typename T>
void File<T>::suppression(T _myObject)
{
	if (CountCell!=0)
	{
		Cellule<T> *Cell_search;
		Cell_search = deb;
		if(Cell_search->GetObject()==_myObject)
		{
			deb = Cell_search->GetNext();
			delete Cell_search;
			CountCell--;
		}
		else
		{
			bool succes = false;
			while(Cell_search!=fin)
			{
				if(Cell_search->GetNext()->GetObject()==_myObject)
				{
					Cellule<T> *Cell_find = Cell_search->GetNext();
					Cell_search->SetNext(Cell_search->GetNext()->GetNext());
					delete(Cell_find);
					succes = true;
					CountCell--;
				}
				Cell_search=Cell_search->GetNext();
			}
			if(!succes)
			{
				throw Erreur(string("L'objet a supprimer n'est pas dans la liste"));
			}
		}
	}
	else
	{
		throw Erreur(string("Il n'y a rien dans la liste!!"));
	}
}

template <typename T>
T File<T>::FirstCell()
{
	T resultat;
	if (deb)
	{
		resultat = deb->GetObject();
	}
	else
	{
		throw Erreur(string("pas de myObject en tete"));
	}
	return resultat;
}

template <typename T>
T File<T>::queue()
{
	T resultat;
	if (fin)
	{
		resultat = fin->GetObject();
	}
	else
	{
		throw Erreur(string("pas de myObject en queue"));
	}
	return resultat;
}

template <typename T>
int File<T>::GetCountCell()
{
	return CountCell;
}

template <typename T>
bool File<T>::isEmpty()
{
	return(CountCell==0);
}

