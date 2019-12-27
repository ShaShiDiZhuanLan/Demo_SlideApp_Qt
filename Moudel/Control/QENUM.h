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
#ifndef QENUM_H
#define QENUM_H

/**
* @By QtCreator Create:
* @Brief: qml使用枚举类
* @Description:
*/
#include <QObject>


class QENUM: public QObject {

    Q_OBJECT

    Q_ENUMS(RequestType)
    Q_ENUMS(NetWorkState)
    Q_ENUMS(PageEnum)
public:

    explicit QENUM(QObject *parent = nullptr)
    {
        Q_UNUSED(parent);
    }

    enum NetWorkState{
        Unknown = 0,
        WIFI = 1
    };

    enum RequestType {
        Network,
        Comport,
        Filetrans
    };

    enum PageEnum{
        Page_Login,   //登陆
        Page_Logout,    //登出
        Page_HomeMain,  //主页面
        Page_SendCode,  //二维码扫描提货单页面
        Page_DeliveryCode, //二维码扫码发货页面
        Page_deliveryInfor,  //确认发货信息页面
        Page_ReduceDelivery,  //减少发货数量页面
        Page_SuYuan,    //溯源
        Page_Offline,   //离线信息
        Page_SendRecord, //发货记录
        Page_Setting,  //设置语言
        Page_FontSetting,   //字体设置页面
        Page_ScanConfig,    //扫描箱或垛的按钮设定
        Page_About          //关于界面
    };
};

#endif // QENUM_H
