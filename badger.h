#ifndef BADGER_H
#define BADGER_H

#include <QObject>
#include <QJsonObject>

class Badger : public QObject
{
    Q_OBJECT
public:
    explicit Badger(QObject *parent = 0);

signals:
    void message(QJsonObject object);

public slots:
    void update();
};

#endif // BADGER_H
