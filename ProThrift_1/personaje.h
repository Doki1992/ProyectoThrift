#ifndef PERSONAJE
#define PERSONAJE
#include <QString>


struct Personaje{
    int movimiento;
    int vida;
    int ataque;
    int alcance;
    int index;
    QString nombre;
    Personaje(int movimiento, int vida, int ataque, int alcance, int index, QString nombre){
        this->movimiento=movimiento;
        this->alcance=alcance;
        this->movimiento=movimiento;
        this->vida=vida;
        this->ataque=ataque;
        this->index=index;
        this->nombre=nombre;
    }
    QString Mov(){return QString::number(this->movimiento);}
    QString Vid(){return QString::number(this->vida);}
    QString Ata(){return QString::number(this->vida);}
    QString Ala(){return QString::number(this->alcance);}
};


#endif // PERSONAJE

