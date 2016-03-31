#ifndef NODOGENERICO
#define NODOGENERICO
#include <stdlib.h>

template <class T> struct Nodo{
  T dato;
  int prioridad;
  Nodo<T>*sig;
  Nodo<T>*atras;
  Nodo(T t){this->dato=t;sig=NULL;atras=NULL;}
  Nodo(T t, int prioridad){this->dato=t;sig=NULL;atras=NULL, this->prioridad=prioridad;}
  T getDato(){return dato;}
  void setDato(T t){this->dato=t;}
};




#endif // NODOGENERICO

