#ifndef SIMPLECUSTOMEVENT_H
#define SIMPLECUSTOMEVENT_H
#include <QEvent>
#include <QString>
#include <QObject>

class SimpleCustomEvent : public QObject, public QEvent
{
    Q_OBJECT
public:
    SimpleCustomEvent(int arg1 = 0, const QString &arg2 = QString());
    ~SimpleCustomEvent();

    Q_INVOKABLE static Type eventType();

    Q_INVOKABLE  int m_arg1;
    Q_INVOKABLE  QString m_arg2;

private:
    static Type m_evType;

};

#endif // SIMPLECUSTOMEVENT_H
