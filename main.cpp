/*-------------------------------------------------
#
# Project created by QtCreator
# Author: 沙振宇
# CreateTime: 2018-05-30
# UpdateTime: 2019-12-27
# Info: Qt版本手机APP模板框架
# Github:https://github.com/ShaShiDiZhuanLan/Demo_SlideApp_Qt
#
#-------------------------------------------------*/
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QDebug>
#include <QNetworkReply>
#include "Moudel/FunMoudel/HttpRequest.h"
int main(int argc, char *argv[])
{
    qInfo()<<"qt启动";
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<HttpRequest>("httpRequest",1,0,"HttpRequest");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
