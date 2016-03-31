#ifndef ARBOL_AVL
#define ARBOL_AVL
#include "nodo_avl.h"
#include <stdlib.h>
#include <QString>
#include <QProcess>
#include <QFile>
template <class T> class arbol_avl{
public:
  nodo_av<T>*raiz;

  bool h;
  arbol_avl()
  {
  raiz = NULL;
  valor= NULL;
  }

  arbol_avl(nodo_av<T> * r)
  {
  raiz = r;
  }
  nodo_av<T>* Oraiz ()
  {
  return raiz;
  }
  void Praiz(nodo_av<T> *r)
  {
  raiz = r;
  }
  nodo_av<T>* insertar(nodo_av<T>*nodo,T dato,bool &hc,int index);
  void eliminar(nodo_av<T>*raiz,int index);
  void eliminar(int index);
  void dibujarArbol();
  QString creaDot(nodo_av<T>*raiz);
  void escribeDot();
  void inse(T dato,int index);
  T getDato(int index, nodo_av<T> *raiz);
  T getDato(int index);
  nodo_av<T>* getRaiz(){return raiz;}


private:
  nodo_av<T> *rotacionII(nodo_av<T> *n,nodo_av<T>*nl);
  nodo_av<T> *rotacionDD(nodo_av<T> *n,nodo_av<T>*nl);
  nodo_av<T> *rotacionDI(nodo_av<T> *n,nodo_av<T>*nl);
  nodo_av<T> *rotacionID(nodo_av<T> *n,nodo_av<T>*nl);
  T valor;

};
#include "definiciones_avl.h"
#endif // ARBOL_AVL

