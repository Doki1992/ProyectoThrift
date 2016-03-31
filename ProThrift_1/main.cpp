

#include "nodo_fila.h"
#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <QStringBuilder>
#include "ProThrift_server.skeleton.cpp";

int main(int argc, char **argv) {

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

 // return 0;

    Arbol_jugador * arbol = new Arbol_jugador();
    for(int i =0; i<10; i++){
        Personaje * nuevo = new Personaje (23,23,23,23,i,"megatanque");
        arbol->insertar(nuevo,nuevo->index);
    }

    matriz * m1 = new matriz();
    Nodo_dato* dato = new Nodo_dato(1,2,0,"agua");
    Nodo_dato* dato1 = new Nodo_dato(2,3,0,"agua");
    Nodo_dato* dato2 = new Nodo_dato(3,3,0,"agua");
    Nodo_dato* dato3= new Nodo_dato(2,2,0,"agua");
    Nodo_dato* dato4= new Nodo_dato(7,2,0,"agua");
    Nodo_dato* dato5= new Nodo_dato(0,0,0,"agua");
    Nodo_dato* dato6= new Nodo_dato(0,2,0,"fuego");//->este es tipo fuego
    Nodo_dato* dato7= new Nodo_dato(0,1,0,"agua");

    m1->insertar_columna(dato,dato->pos_y);
    m1->insertar_columna(dato1,dato1->pos_y);
    m1->insertar_columna(dato2,dato2->pos_y);
    m1->insertar_columna(dato3,dato3->pos_y);
    m1->insertar_columna(dato4,dato4->pos_y);
    m1->insertar_columna(dato5,dato5->pos_y);
    m1->insertar_columna(dato6,dato6->pos_y);
    m1->insertar_columna(dato7,dato7->pos_y);
    Nodo_dato * prueba = m1->getDat(0,2);//debe devolver el tpo fuego

    m1->ejecuta_dot();
  return a.exec();
}
