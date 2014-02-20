#ifndef MODELCONCRETE_H
#define MODELCONCRETE_H

#include <QDebug>
#include <QObject>
#include "model.h"
#include "person.h"

class modelconcrete:public model//,public QAbstractListModel
{

public:
    modelconcrete(QObject *o=0);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;


    void deleteItem(quint8 id);
    void deleteItemByLastname(QString s);
    void addItem(QString fname);
    void sort();

    QList<person> m_items;

private:
    Q_DISABLE_COPY(modelconcrete);
    static const int FirstNameRole;
};

#endif // MODELCONCRETE_H
