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
import QtWebView 1.1
import QtQuick.Controls 2.2

//跳转显示的广告页面
Rectangle {

    property alias url:webview.url

    signal btnClick();
    signal imageClick();

    Rectangle
    {
        id:title
        width: parent.width
        height: 50
        color: "blue"
        Item
        {
            width:  parent.height
            height: parent.height
            Image
            {
                id:img
                width: 20
                height: 20
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                source: "/img/backBtn.png"
            }

            Text {

                anchors.left: img.right
                anchors.verticalCenter: parent.verticalCenter
                text: qsTr("返回")
                color: "white"
            }

            MouseArea
            {
                anchors.fill: parent
                onClicked:
                {
                    btnClick()
                }
            }
        }
        z:2
    }

    ProgressBar {
        id:progress
        width: parent.width
        visible: value == 1?false:true
        anchors.top: title.bottom
        value: 0
    }

    WebView{
        id:webview
        visible:loadProgress == 100?true:false
        width: parent.width
        height: parent.height - title.height
        anchors.top: title.bottom
        onLoadProgressChanged:
        {
            progress.value = loadProgress/100
        }
    }
}
