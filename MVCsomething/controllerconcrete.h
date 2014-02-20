#ifndef CONTROLLERCONCRETE_H
#define CONTROLLERCONCRETE_H


#include "controller.h"
#include "modelconcrete.h"
#include "model.h"


class controllerconcrete:public controller
{


public:
    controllerconcrete(QObject *o=0);
    void setListModelConcrete( model *lmc);
    model *getLM();

    /*
    Q_INVOKABLE void add(QString fname);
    Q_INVOKABLE void remover(int i);
    Q_INVOKABLE void removerLastname(const QString&);
    */

private:
    model *_lmc;
    Q_DISABLE_COPY(controllerconcrete);




};

#endif // CONTROLLERCONCRETE_H
