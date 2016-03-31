#ifndef ARBOL_JUGADOR_H
#define ARBOL_JUGADOR_H
#include "arbol_avl.h"
#include "personaje.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QLinkedList>
#include "listagenerica.h"
class Arbol_jugador : arbol_avl<Personaje*>
{
public:
    Arbol_jugador();
    Personaje * getPersonaje();
    void insertar(Personaje* nuevo, int index);
    QString getDibujo(nodo_av<Personaje*> * raiz);
    void guarda_texto();
    QString * dibujo = new QString();

    ListaGenerica<Personaje*> * eliminar(nodo_av<Personaje *> *raiz, int index);
    void eliminar(int index);
};

#endif // ARBOL_JUGADOR_H
