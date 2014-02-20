#include "controllerconcrete.h"

controllerconcrete::controllerconcrete(QObject *o):controller(o)
{
}


void controllerconcrete::setListModelConcrete(model *lmc)
{
    _lmc=lmc;
}

model * controllerconcrete::getLM()
{
    return _lmc;
}

/*
void controllerconcrete::remover(int i)
{
    // qDebug()<<"Controller::remover("<<i<<") was called\n"<<;
    _lmc->deleteItem(i);
}


void controllerconcrete::removerLastname(const QString&s)
{
    qDebug()<<"Controller::removerLastname("<<s<<") was called\n";

    _lmc->deleteItemByLastname(s);
}

void controllerconcrete::add(QString fname)
{
    qDebug()<<"Controller::add("<<fname<<") was called\n";
    beginResetModel();
    person e(fname);


    qDebug()<<"name of person "<<e.m_firstname;

    getLM()->m_items.push_front(e);
    endResetModel();

}

*/
