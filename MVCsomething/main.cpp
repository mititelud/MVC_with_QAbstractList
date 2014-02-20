#include <QtGui/QGuiApplication>
#include <QtQml>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQuickView>
#include "qtquick2applicationviewer.h"

#include "controllerconcrete.h"
#include "modelconcrete.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickView *view=new QQuickView();

    controller *c=new controllerconcrete();     //controller abstract class
    model *m=new modelconcrete();               //model abstract class

    c->setListModelConcrete(m);


    view->engine()->rootContext()->setContextProperty("myModel",c->getLM());

    view->setSource(QUrl::fromLocalFile("qml/MVCsomething/main.qml"));
    view->show();

    return app.exec();

    delete view;
    delete m;
    delete c;
}
