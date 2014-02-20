#ifndef MODEL_H
#define MODEL_H

#include "person.h"
#include <QObject>
#include <QAbstractListModel>

//Abstract class model
//inherited by modelconcrete

class model:public QAbstractListModel
{
    Q_OBJECT
public:
    model(QObject *parent=0);

    Q_INVOKABLE virtual void deleteItem(quint8 id)=0;
    Q_INVOKABLE virtual void deleteItemByLastname(QString s)=0;
    Q_INVOKABLE virtual void addItem(QString fname)=0;
    Q_INVOKABLE virtual void sort()=0;

private:
    Q_DISABLE_COPY(model);

};

#endif // MODEL_H
