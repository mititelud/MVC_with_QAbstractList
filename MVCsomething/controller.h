#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "modelconcrete.h"
#include <QObject>

//Abstract class controller
//inherited by controllerconcrete

class controller:public QObject
{
    Q_OBJECT
public:
    controller(QObject *parent=0);
    virtual void setListModelConcrete( model *lmc)=0;
    Q_INVOKABLE virtual model *getLM()=0;


    /*
    Q_INVOKABLE virtual void add(QString fname)=0;

public slots:
    virtual void remover(int i)=0;
    virtual void removerLastname(const QString &)=0;
    */
};

#endif // CONTROLLER_H
