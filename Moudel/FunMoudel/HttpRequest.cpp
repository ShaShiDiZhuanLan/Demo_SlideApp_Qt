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
#include "HttpRequest.h"

HttpRequest::HttpRequest(QObject *parent) : QObject(parent)
{
   getURLFun();
}

void HttpRequest::setKeyValue()
{
    emit jsonSend("接收1号");
}

void HttpRequest::getURLFun()
{
    QNetworkRequest request;
    request.setUrl(QUrl("http://www.emto.cn/APP/xxhdpi/urlAddress"));
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkReply *reply = manager->get(request);
    connect(reply,&QNetworkReply::readyRead, this, [=]{

        QByteArray aa = reply->readAll();
        aa = aa.trimmed();

        qInfo()<<"打开all"<<aa;

        if(aa.indexOf("http") == -1)
        {
            aa = "http://"+aa;
        }
        getUrl(aa);
    });
}

void HttpRequest::slotReadyRead()
{

}
