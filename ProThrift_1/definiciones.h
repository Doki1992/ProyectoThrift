#ifndef DEFINICIONES
#define DEFINICIONES
#include "listagenerica.h"
template <class T>
ListaGenerica<T>::ListaGenerica()
{
cabeza=NULL;
cola=NULL;
tamano=0;
}

template <class T>
void ListaGenerica<T>::insertarCabeza(T dato){
Nodo<T>* nuevo= new Nodo<T>(dato);
nuevo->sig=cabeza;
cabeza=nuevo;
tamano++;
}

template <class T>
void ListaGenerica<T>::insertarCola(T dato){
  Nodo<T>* nuevo = new Nodo<T>(dato);
  if(cola==NULL){
     nuevo->sig=cola;
     cabeza=nuevo;
     cola=nuevo;
    }else{
      cola->atras=nuevo;
      nuevo->sig=cabeza;
      cabeza=nuevo;
    }
}

template <class T>
void ListaGenerica<T>::insertarCicular(T dato){
  Nodo<T>* nuevo = new Nodo<T>(dato);
  if(esVacia()){
      cabeza=nuevo;
      cola=nuevo;
      nuevo->sig=nuevo;
      nuevo->atras=nuevo;
    }else{
      nuevo->sig=cabeza;
      cabeza->atras=nuevo;
      cabeza=nuevo;
      nuevo->atras=cola;
      cola->sig=nuevo;

    }
 }


template <class T>
void ListaGenerica<T>::insertarPrioridad(T dato, int prioridad){
  Nodo<T> * nuevo  = new Nodo<T>(dato,prioridad);
  Nodo<T> * Pos=this->cabeza;
  Nodo<T> * Ant = NULL;
  int encontrando =0;
  while(encontrando!=1 && (Pos)){
    if((Pos)->prioridad<=prioridad){
        (Ant) = (Pos);
        (Pos) = (Pos)->sig;
      }else{
        encontrando=1;
      }
    }

  if((Ant)!=NULL){
      nuevo->sig=(Ant)->sig;
      (Ant)->sig=nuevo;
      tamano++;
    }else{
      this->cabeza=nuevo;
      nuevo->sig=(Pos);
      tamano++;
    }

}


template <class T>
void ListaGenerica<T>::insertarDoble(T dato){
  Nodo<T>*nuevo=new Nodo<T>(dato);
  if(cabeza==NULL){
      nuevo->sig=cabeza;
      cabeza=nuevo;
    }else{
      nuevo->sig=cabeza;
      cabeza->atras=nuevo;
      cabeza=nuevo;
    }
}

template <class T>
void ListaGenerica<T>::ver(){
  Nodo<T>*aux = cabeza;
  Nodo<T>*primero = cabeza;
  while(aux!=NULL){
      qDebug()<<aux->getDato();
      aux=aux->sig;
      if(aux!=NULL){
      if(primero->getDato()==aux->getDato()){
          break;
        }
        }
    }
}



template <class T>
Nodo<T> *ListaGenerica<T>::Inicio(){
  return cabeza;
}

template <class T>
Nodo<T>* ListaGenerica<T>::Final(){
  return NULL;
}

template <class T>
bool ListaGenerica<T>::esVacia(){
  return cola==NULL && cabeza==NULL;
}





#endif // DEFINICIONES

