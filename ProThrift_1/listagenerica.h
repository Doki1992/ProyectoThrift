#ifndef LISTAGENERICA_H
#define LISTAGENERICA_H
#include <QDebug>
#include "nodogenerico.h"
template <class T> class ListaGenerica
{
public:

  ListaGenerica();
  void insertarCabeza(T dato);
  void insertarCola(T dato);
  void insertarCicular(T dato);
  void insertarDoble(T dato);
  void insertarPrioridad(T dato, int prioridad);
  void ver();
  bool esVacia();
  Nodo<T> *Inicio();
  Nodo<T> *Final();
  void fin(){cabeza=NULL; cola=NULL;}
  int tamano=0;
private:
  Nodo<T>*cabeza;
  Nodo<T>*cola;


};
#include "definiciones.h"
#endif // LISTAGENERICA_H

