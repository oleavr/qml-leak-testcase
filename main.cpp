#include "badger.h"

#include <QApplication>
#include <QQuickView>
#include <QtQml>

static QObject *createBadgerSingleton(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);

    return new Badger();
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterSingletonType<Badger>("Badger", 1, 0, "Badger", createBadgerSingleton);

    QQuickView view(QUrl(QStringLiteral("qrc:///main.qml")));
    QObject::connect(view.engine(), SIGNAL(quit()), &app, SLOT(quit()));
    view.show();

    return app.exec();
}
