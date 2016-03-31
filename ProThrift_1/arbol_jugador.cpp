#include "arbol_jugador.h"

Arbol_jugador::Arbol_jugador()
{

}

Personaje  * Arbol_jugador :: getPersonaje(){
    return this->raiz->tipo_dato;
}

void Arbol_jugador :: insertar(Personaje *nuevo, int index){
    this->inse(nuevo,index);
}

QString Arbol_jugador :: getDibujo(nodo_av<Personaje*> *raiz){
    if(raiz!=NULL){
        dibujo->append(QString::number(raiz->index)).append("[shape = box label=\"");
        dibujo->append("Nombre: ").append(raiz->tipo_dato->nombre).append(" Movimiento: ").append(raiz->tipo_dato->Mov()).append(" Vida: ").append(raiz->tipo_dato->Vid()).append(" Ataque: ").append(raiz->tipo_dato->Ata()).append(" Alcance: ").append(raiz->tipo_dato->Ala()).append(" ID: ").append(QString::number(raiz->index)).append("\"").append("]");
        if(raiz->L!=NULL){
            QString padre = QString::number(raiz->index);
            QString derecho = QString::number(raiz->L->index);
            dibujo->append(padre).append("->").append(derecho).append(";");
        }
        if(raiz->R!=NULL){
            QString padre = QString::number(raiz->index);
            QString derecho = QString::number(raiz->R->index);
            dibujo->append(padre).append("->").append(derecho).append(";");
        }
        getDibujo(raiz->L);
        getDibujo(raiz->R);
    }
    return *dibujo;
}

void Arbol_jugador ::guarda_texto(){
QFile  * file = new QFile("arbol.txt");
*dibujo="";
    dibujo->append("digraph uni{");
QString texto = getDibujo(this->raiz);
texto.append("}");
if(!file->open(QIODevice::WriteOnly | QIODevice::Text)){
    return;
}else{
    //if(file->)
    QTextStream out(file);
    out<<texto;
}
file->flush();
file->close();
system("dot -Tpng arbol.txt -o arbol.png ");
system("xdg-open arbol.png");
}
ListaGenerica<Personaje*> * lista = new ListaGenerica<Personaje*>();
void Arbol_jugador :: eliminar(int index){
    lista->fin();
    ListaGenerica<Personaje*>*list=eliminar(this->raiz, index);
    this->raiz = NULL;
    Nodo<Personaje*> *primero = list->Inicio();
    while(primero!=NULL){
        insertar(primero->getDato(),primero->getDato()->index);
        primero=primero->sig;
    }

}

ListaGenerica<Personaje *> *Arbol_jugador::eliminar(nodo_av<Personaje *> *raiz, int index){
    if(raiz!=NULL){
        if(raiz->index!=index){
            lista->insertarCabeza(raiz->tipo_dato);
        }
        eliminar(raiz->L,index);
        eliminar(raiz->R,index);
    }
    return lista;
}
