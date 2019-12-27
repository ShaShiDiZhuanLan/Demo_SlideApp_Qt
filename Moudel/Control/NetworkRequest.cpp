#include "NetworkRequest.h"
#include <QThread>

NetworkRequest::NetworkRequest():m_mange_(nullptr)
  ,m_token_("")
{
    m_mange_ = new QNetworkAccessManager();
}

QNetworkReply *  NetworkRequest::doPostRequest(QString targetUrl)
{
    QNetworkRequest req;
    req.setUrl(QUrl(targetUrl));
    return this->doPostRequest(req);
}

QNetworkReply * NetworkRequest::doPostRequest(const QNetworkRequest &request)
{
    QByteArray PostData;
    QNetworkRequest request2 = request;

#define JSON  1  //1代表是Head set json数据请求
#if (JSON == 0)
    request2.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded"); //Qt默认的设置
#else
    request2.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
#endif

    // 构建 JSON 文档
    QJsonDocument document;
    document.setObject(m_json_);
    PostData = document.toJson(QJsonDocument::Compact);

    QStringList keyList = m_json_.keys();

    //将json清空
    foreach (QString it, keyList) {
         m_json_.remove(it);
    }

    qInfo()<<"当前解析的PostData = "<<PostData;
//具体set参数暂不明确，先注释
//    request2->setRawHeader("Accept","text/html, application/xhtml+xml, */*");
//    request2->setRawHeader("Referer","http://localhost:8888/login");
    //request2.setRawHeader("Accept","request2->setRawHeader(\"Access-Control-Allow-Origin\",\"*\");");
//    request2->setRawHeader("X-Requested-With","XMLHttpRequest");
    //request2.setRawHeader("User-Agent","iOS11");
    //request2.setRawHeader("Content-Type","application/json");
//    request2->setRawHeader("Accept-Encoding","gzip,deflate");
  //  request2.setRawHeader("Host","192.168.1.158:8080");
//    request2->setRawHeader("Content-Length","18");
//    request2->setRawHeader("Connection","Keep-Alive");
//    request2->setRawHeader("Cache-Control","no-cache");
 //   request2.setRawHeader("Access-Control-Allow-Origin","*");

    //m_token_非空就需要在头部加上token
    if(!m_token_.isEmpty())
    {
        request2.setRawHeader("Token",m_token_);
    }

    return m_mange_->post(request2,PostData);
}

QNetworkReply *NetworkRequest::doGetRequest(QString targetUrl)
{
    //todo...

    QNetworkRequest req;
    req.setUrl(QUrl(targetUrl));
    return this->doGetRequest(req);
}

QNetworkReply *NetworkRequest::doGetRequest(const QNetworkRequest &request)
{
    QNetworkRequest request2 = request;
    request2.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");

    //m_token_非空就需要在头部加上token
    if(!m_token_.isEmpty())
    {
        qInfo()<<"进来设置token头文件"<<m_token_;
        request2.setRawHeader("Token",m_token_);
    }

    return m_mange_->get(request2);
}

void NetworkRequest::setHeadData(QByteArray token)
{

    m_token_ = token;
    qInfo()<<"设置token"<<m_token_;
}

void NetworkRequest::addKeyValue(QString key, QJsonValue value)
{
    // 构建 JSON 对象
    m_json_.insert(key, value);
}
