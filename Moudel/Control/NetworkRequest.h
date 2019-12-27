#ifndef NETWORKREQUEST_H
#define NETWORKREQUEST_H

#include <QObject>
#include <QReplyTimeout.h>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QObject>
#include "QReplyTimeout.h"

/**
* @By QtCreator Create:2018年4月10日 13:21:38
* @Brief:网络请求
* @Author: fu_lin
* @Description:用于简化使用者使用Http请求访问
*/

class NetworkRequest
{

public:
    explicit NetworkRequest();

    //第一个是只传API
    QNetworkReply* doPostRequest(QString targetUrl);
    //第二个是传QNetworkRequest，记住QNetworkRequest是要加载API的
    QNetworkReply* doPostRequest(const QNetworkRequest &request);

    //GET请求传递目标url
    QNetworkReply* doGetRequest(QString targetUrl);
    QNetworkReply* doGetRequest(const QNetworkRequest &request);

    //外部调用设置token头数据，如果有增加的可以往里面添加相关参数
    void setHeadData(QByteArray token);
    void addKeyValue(QString key, QJsonValue value);

signals:
    void sigTimeOut();
private:
    QNetworkAccessManager * m_mange_;
    QJsonObject m_json_;
    QByteArray m_token_;
};

#endif // NETWORKREQUEST_H
