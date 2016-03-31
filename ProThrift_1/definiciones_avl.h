#ifndef DEFINICIONES_AVL
#define DEFINICIONES_AVL
//#include "arbol_avl.h"
#include <QTextStream>

template <class T>
nodo_av<T> *arbol_avl<T>::rotacionII(nodo_av<T> *n,nodo_av<T>*nl){
  n->setRama_izquierda(nl->getArbol_derecho());
  nl->setRama_derecho(n);
  if(nl->fe==-1){
      n->setFactor_equilibrio(0);
      nl->setFactor_equilibrio(0);
    }else{
      n->setFactor_equilibrio(-1);
    }
  return nl;
}
template <class T>
nodo_av<T> *arbol_avl<T>::rotacionDD(nodo_av<T> *n,nodo_av<T>*nl){
  n->setRama_derecho(nl->getArbol_izquierdo());
  nl->setRama_izquierda(n);
  if(nl->fe==+1){
      n->setFactor_equilibrio(0);
      nl->setFactor_equilibrio(0);
    }else{
      n->setFactor_equilibrio(+1);
      n->setFactor_equilibrio(-1);
    }
  return nl;
}
template <class T>
nodo_av<T> *arbol_avl<T>::rotacionDI(nodo_av<T> *n,nodo_av<T>*nl){
nodo_av<T>  *n2;
n2=nl->getArbol_izquierdo();
n->setRama_derecho(n2->getArbol_izquierdo());
n2->setRama_izquierda(n);
nl->setRama_izquierda(n2->getArbol_derecho());
n2->setRama_derecho(nl);
if(n2->fe==+1){
    n->setFactor_equilibrio(-1);
  }else{
    n->setFactor_equilibrio(0);
  }
if(n2->fe==-1){
    nl->setFactor_equilibrio(+1);
  }else{
    nl->setFactor_equilibrio(0);
  }
n2->setFactor_equilibrio(0);
return n2;
}
template <class T>
nodo_av<T> *arbol_avl<T>:: rotacionID(nodo_av<T> *n,nodo_av<T>*nl){
nodo_av<T>  *n2;
n2=nl->getArbol_derecho();
n->setRama_izquierda(n2->getArbol_derecho());
n2->setRama_derecho(n);
nl->setRama_derecho(n2->getArbol_izquierdo());
n2->setRama_izquierda(nl);
if(n2->fe==+1){
    nl->setFactor_equilibrio(-1);
  }else{
    nl->setFactor_equilibrio(0);
  }

if(n2->fe==-1){
    n->setFactor_equilibrio(1);
  }else{
    n->setFactor_equilibrio(0);
  }
n2->setFactor_equilibrio(0);
return n2;
}
template <class T>
nodo_av<T>* arbol_avl<T>:: insertar(nodo_av<T>*raiz,T dato,bool &hc,int index){
  nodo_av<T>* nl;
  if(raiz==NULL){

     raiz = new nodo_av<T>(dato,index);
     h=hc=true;
    }else if(index<raiz->getIndice()){
      nodo_av<T>*iz;
      iz=insertar(raiz->getArbol_izquierdo(),dato,hc,index);
      raiz->setRama_izquierda(iz);
      if(h){
          switch(raiz->getFactor_equilibrio()){
            case 1:
             raiz->setFactor_equilibrio(0);
              hc=h=false;
              break;
            case 0:
              raiz->setFactor_equilibrio(-1);
              break;
            case -1:
              nl=raiz->getArbol_izquierdo();
              if(nl->getFactor_equilibrio()==-1){
                  raiz=rotacionII(raiz,nl);
                }else{
                 raiz=rotacionID(raiz,nl);
                }
              hc=h=false;
            }
        }
    }else if(index>raiz->getIndice()){
      nodo_av<T>*de;
      de=insertar(raiz->getArbol_derecho(),dato,hc,index);
      raiz->setRama_derecho(de);
      if(h){
          switch(raiz->getFactor_equilibrio()){
            case 1:
              nl=raiz->getArbol_derecho();
              if(nl->getFactor_equilibrio()==+1){
                  raiz=rotacionDD(raiz,nl);
                }else{
                  raiz=rotacionDI(raiz,nl);
                }
              hc=h=false;
              break;
            case 0:
              raiz->setFactor_equilibrio(+1);
              break;
            case -1:
              raiz->setFactor_equilibrio(0);
              break;
            }
        }
    }else{
      //nada
    }
  return raiz;

}
template <class T>
void arbol_avl<T>:: dibujarArbol(){
  system("dot -Tjpg arbol.txt -o arbol.jpg");
  system("arbol.jpg");
}
template <class T>
void arbol_avl<T>:: escribeDot(){
  QString texto=" digraph arbol{"+creaDot(raiz)+"}";
  QFile *archivo=new QFile("arbol.txt");
  archivo->open(QIODevice::WriteOnly | QIODevice::Truncate);
  QTextStream * buffer=new QTextStream(archivo);
  *buffer<<texto;
  archivo->close();
}
template <class T>
QString arbol_avl<T>:: creaDot(nodo_av<T>*raiz){
  QString cuerpo;
  QString flecha="->";
  QString pcoma=";";
  if(raiz!=NULL){
      if(raiz->getArbol_izquierdo()!=NULL)
      cuerpo+=QString::number(raiz->valornodo())+flecha+QString::number(raiz->getArbol_izquierdo()->valornodo())+pcoma;
      if(raiz->getArbol_derecho()!=NULL)
      cuerpo+=QString::number(raiz->valornodo())+flecha+QString::number(raiz->getArbol_derecho()->valornodo())+pcoma;

      cuerpo +=creaDot(raiz->getArbol_izquierdo());
      cuerpo +=creaDot(raiz->getArbol_derecho());
    }
return cuerpo;
}
template <class T>
void arbol_avl<T>::inse(T dato,int index){

this->raiz=insertar(this->raiz,dato,h,index);
}

template <class T>
T arbol_avl<T>::getDato(int index, nodo_av<T>*raiz){
  if(raiz!=NULL){
      if(raiz->getIndice()==index){
         valor=raiz->valornodo();
        }
        getDato(index,raiz->getArbol_izquierdo());
        getDato(index,raiz->getArbol_derecho());
    }
  return valor;
}

template <class T>
T arbol_avl<T>::getDato(int index){
  return getDato(index,raiz);
}

template <class T>
void  arbol_avl<T>::eliminar(int index){
 //eliminar publico
}

template <class T>
void arbol_avl<T>::eliminar(nodo_av<T>*raiz,int index){
 //eliminar privado

}


#endif // DEFINICIONES_AVL

