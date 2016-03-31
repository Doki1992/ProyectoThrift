#ifndef NODO_AVL
#define NODO_AVL
#include "stdlib.h"
template <class T> struct nodo_av{

  T tipo_dato;
  //derecho
  nodo_av<T>*R;
  //izquierdo
  nodo_av<T>*L;
  //factor de equilibrio
  int fe;
  //indice
  int index;
  nodo_av(T tipo_dato,int index){this->tipo_dato=tipo_dato;R=L=NULL;fe=0;this->index=index;}
  T valornodo(){return tipo_dato;}
  nodo_av<T> * getArbol_derecho(){return R;}
  nodo_av<T> * getArbol_izquierdo(){return L;}
  void nuevoValor(T nuevo_valor){tipo_dato=nuevo_valor;}
  void setRama_izquierda(nodo_av<T>* l){L=l;}
  void setRama_derecho(nodo_av<T>* r){R=r;}
  void setFactor_equilibrio(int factor){fe=factor;}
  int getIndice(){return index;}
  int getFactor_equilibrio(){return fe;}
  void setIndice(int in){this->index=in;}
};

#endif // NODO_AVL

