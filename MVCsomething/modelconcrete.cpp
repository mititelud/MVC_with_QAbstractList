#include <QDebug>
#include "modelconcrete.h"

// You can define custom data roles starting with Qt::UserRole
const int modelconcrete::FirstNameRole = Qt::UserRole + 1;

modelconcrete::modelconcrete(QObject *o):model(o)//,QAbstractListModel(o)
{
    for(int i=25;i>0;i--)
    {
        person p(QString::number(qrand()%25));
        m_items.push_front(p);
    }
}

QHash<int, QByteArray> modelconcrete::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles.insert(FirstNameRole, QByteArray("firstName"));
    return roles;
}

int modelconcrete::rowCount(const QModelIndex &) const
{
    return m_items.size();
}

QVariant modelconcrete::data(const QModelIndex &index,int role) const
{
    if (!index.isValid())
        return QVariant(); // Return Null variant if index is invalid
    if (index.row() > (m_items.size()-1) )
        return QVariant();

    person dobj = m_items.at(index.row());

    switch (role)
    {
    case Qt::DisplayRole: // The default display role now displays the first name as well

    case FirstNameRole:
        return QVariant::fromValue(dobj.m_firstname);
    default:
        return QVariant();
    }
}

void modelconcrete::deleteItem(quint8 id)
{
    beginResetModel();
    m_items.removeAt(id);
    endResetModel();
}

void modelconcrete::addItem(QString fname)
{

    beginResetModel();
    person e(fname);


    qDebug()<<"name of person "<<e.m_firstname;

    m_items.push_front(e);
    endResetModel();
}

void modelconcrete::deleteItemByLastname(QString s)
{

    int i=0;
    beginResetModel();

    for(QList<person>::iterator it=m_items.begin();it!=m_items.end();it++)
    {
        person e=*it;
        std::string s1=e.m_firstname.toStdString();

        if ((s.toStdString()==s1))
        {
            qDebug()<<(s.toStdString()==s1);
            m_items.removeAt(i);
            break;
        }
        i++;
    }
    endResetModel();
}

void modelconcrete::sort()
{
    beginResetModel();
    for(QList<person>::iterator it1=m_items.begin();it1!=m_items.end()-1;it1++)
    {
        for(QList<person>::iterator it2=it1+1;it2!=m_items.end();it2++)
        {
            person p1=*it1,p2=*it2;
            if(p1.m_firstname.toInt()>p2.m_firstname.toInt())
            {
                person aux=p1;
                p1=p2;
                p2=aux;
            }
            *it1=p1;
            *it2=p2;
        }
    }
    endResetModel();
}


