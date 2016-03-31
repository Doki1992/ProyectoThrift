#ifndef NODO_FILA
#define NODO_FILA
#include "arbol_jugador.h"
#include <QString>

struct Nodo_dato{
    int pos_x;
    int pos_y;
    int profundida;
    //desde menos 2 hasta 0
    QString tipo;
    Nodo_dato(int px, int py, int pro, QString tipo){
        this->pos_x=px;
        this->pos_y=py;
        this->profundida=pro;
        this->tipo=tipo;
    }
    QString x(){return QString::number(pos_x);}
    QString y(){return QString::number(pos_y);}
    QString Tipo(){return tipo;}
};

struct nodo_fila{
    int numero_fila;
    ListaGenerica<Nodo_dato*> * Columnas;
    nodo_fila(int numero_fila){
        this->Columnas=new ListaGenerica<Nodo_dato*>();
        this->numero_fila=numero_fila;
    }
    QString f(){return QString::number(numero_fila);}
};


//solo usar insertar prioridad
struct matriz{
    ListaGenerica<nodo_fila*> * filas;
    matriz(){
      this->filas= new ListaGenerica<nodo_fila*>();
    }

     void insertar_columna(Nodo_dato * dato, int fila){
        if(getDato(fila)==1){
             getDato(fila,dato);
        }else if(getDato(fila)==0){
            nodo_fila * row = new nodo_fila(fila);
            filas->insertarPrioridad(row,fila);
            getDat(fila)->Columnas->insertarPrioridad(dato,dato->pos_x);
        }
    }

//si la fila existe se crea una nueva columna
 void getDato(int f,Nodo_dato * dato){
   Nodo<nodo_fila*>* primero = filas->Inicio();
   while(primero!=NULL){ 
       if(primero->dato->numero_fila==f){
           primero->dato->Columnas->insertarPrioridad(dato,dato->pos_x);
       }
       primero = primero->sig;
   }
 }
//este metodo devuelve 1 si la fila existe y 0 si no
 int getDato(int fila){
     Nodo<nodo_fila*>* primero = filas->Inicio();
     while(primero!=NULL){
         if(primero->dato->numero_fila==fila){
            return 1;
         }
         primero=primero->sig;
     }
     return 0;
 }
//retorna un nodo de la matriz
 nodo_fila * getDat(int fila){
     Nodo<nodo_fila*>* primero = filas->Inicio();
     while(primero!=NULL){
         if(primero->dato->numero_fila==fila){
            return primero->dato;
         }
         primero=primero->sig;
     }
     return NULL;
 }

 
 QString dibuja_matriz(){
     QString texto = "digraph matriz {";
     //creo rangos iguales
     int index = filas->Inicio()->prioridad;
     Nodo<nodo_fila*>* p = filas->Inicio();
     while(p!=NULL){
         if(p->sig!=NULL){
                texto.append(p->dato->f()).append("->").append(p->sig->dato->f()).append(";");
         }
         p=p->sig;
     }
     Nodo<nodo_fila*>* pi = filas->Inicio();
     for(int i =0; i<this->filas->tamano;i++,pi=pi->sig){

     texto.append("{rank= same; ").append(getDat(pi->dato->numero_fila)->f()).append(" ");
     for(Nodo<Nodo_dato*>*primero=getDat(pi->dato->numero_fila)->Columnas->Inicio();primero!=NULL ;primero=primero->sig){
         texto.append(primero->dato->x()).append(primero->dato->y()).append(" ");
     }
     texto.append("}");
     }
     pi=filas->Inicio();
     for(int i =0; i<this->filas->tamano;i++,pi=pi->sig){
     texto.append(getDat(pi->dato->numero_fila)->f()).append("->").append(getDat(pi->dato->numero_fila)->Columnas->Inicio()->dato->x()).append(getDat(pi->dato->numero_fila)->Columnas->Inicio()->dato->y()).append(";");
     for(Nodo<Nodo_dato*>*primero=getDat(pi->dato->numero_fila)->Columnas->Inicio();primero!=NULL ;primero=primero->sig){
        texto.append(primero->dato->x()).append(primero->dato->y());
        texto.append("[shape=box label=\"");
        texto.append("columna: ").append(primero->dato->x()).append(" ").append("fila: ").append(primero->dato->y()).append(" ").append("Tipo: ").append(primero->dato->tipo).append("\"").append("]").append(" ");
        if(primero->sig!=NULL){
            texto.append(primero->dato->x()).append(primero->dato->y()).append("->").append(primero->sig->dato->x()).append(primero->sig->dato->y()).append(" ");
        }
     }

     }
     texto.append("}");
return texto;
 }

 void ejecuta_dot(){
     QFile  * file = new QFile("matriz.txt");
     QString texto = dibuja_matriz();
     if(!file->open(QIODevice::WriteOnly | QIODevice::Text)){
         return;
     }else{
         //if(file->)
         QTextStream out(file);
         out<<texto;
     }
     file->flush();
     file->close();

     system("dot -Tpng matriz.txt -o matriz.png ");
     system("xdg-open matriz.png");
 }

 Nodo_dato* getDat(int fila, int columna){
   Nodo<nodo_fila*>* primero = filas->Inicio();
   while(primero!=NULL){
       if(primero->dato->numero_fila==fila){
       Nodo<  Nodo_dato *>* pri = primero->dato->Columnas->Inicio();
       int c =0;
         while(pri!=NULL){
             if(c==columna){
                 return pri->dato;
               }
             c++;
             pri=pri->sig;
           }
       }
       primero=primero->sig;
   }
   return NULL;
 }

};
#endif // NODO_FILA

