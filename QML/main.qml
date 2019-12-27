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
import QtQuick 2.9
import QtQuick.Controls 2.2
import "."
import "./FunMoudel"
import httpRequest 1.0
ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Tabs")

    CustomWebView {
        anchors.fill: parent
        url: "http://www.baidu.com"
    }

//    property int currentPage: 0

//    property var mainUrl
//    Timer
//    {
//        interval: 3000
//        running: true
//        onTriggered:
//        {
//            currentPage = 0
//            logoImage.source = ""
//            logoImage.z = 0;
//            loader.item.running = true


//        }
//    }
//    HttpRequest
//    {
//        onGetUrl:{
//            mainUrl = url
//        }
//    }

//    Image
//    {
//        id:logoImage
//        cache: false
//        anchors.fill: parent
//        source: BaseData.imageUrl+"startdiagram_1.png"
//        z:1
//    }

//    Connections
//    {
//        target: loader.item
//        onBtnClick:{
//            currentPage = 1
//            loader.source = ""
//            loader.source = "./FunMoudel/CustomWebView.qml"
//        }
//        onImageClick:{
//            currentPage = 2
//            loader.source = "./FunMoudel/GuideWebview.qml"
//        }
//    }

//    Loader
//    {
//        id:loader

//        anchors.fill: parent

//        focus: true
//        source: "./FunMoudel/GuidePage.qml"
//        onLoaded:
//        {
//                if(currentPage == 1)
//                {
//                    item.url = mainUrl
//                    item.focus = true;
//                }
//        }
//     }
}
