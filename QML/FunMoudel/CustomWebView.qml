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
import QtQuick.Controls 1.4
import ".."
import QtAndJavaNotity 1.0
import "../DataControl"
Rectangle {

    property alias url:webview.url

    property var mainUrl_

    signal btnClick()
    signal imageClick()

    signal jumpPage();
    focus: true

    QtJavaNotity
    {
         onBackBtn:{
             console.info("webview.url",webview.url,mainUrl_)
             if(webview.url == mainUrl_)
             {
                 console.info("进来推出")
                 backExit()
             }
             else
             webview.goBack();
         }
    }

    Slide_BusyIndicator {
         id:busy
         anchors.centerIn: parent
         running: true
         z:2
    }

    Text {
        visible: busy.running
        anchors.top: busy.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        text: qsTr("已加载:")+webview.loadProgress+"%"
        z:2
    }
    WebView{
        id:webview
     //   visible: !busy.running
        anchors.fill: parent
       // width: parent.width
        //height: parent.height - btnBar.height - 1

        onLoadProgressChanged: {
            if(loadProgress == 100 && busy.running)
            {
                busy.running = false
              //  mainUrl_ = webview.url
            }
        }
        onLoadingChanged:
        {
            if(loading && busy.running)
            {
                mainUrl_ = webview.url
            }
        }
    }
//    SwitchView{
//        id:switchview
//        width: parent.width
//        height: parent.height - btnBar.height

//        ExclusiveRectangle
//        {

//           anchors.fill: parent

//        }
//        ExclusiveRectangle
//        {
//            anchors.fill: parent
//            color: "blue"
//        }
//        ExclusiveRectangle
//        {
//            anchors.fill: parent
//            color: "yellow"
//        }
//        ExclusiveRectangle
//        {
//            anchors.fill: parent
//            color: "red"
//        }
//    }

//    Rectangle
//    {
//        id:line
//        width: parent.width
//        height: 0.7
//        color: "#9E9E9E"
//        anchors.top: switchview.bottom

//        z:2
//    }

//    ExclusiveGroup {
//        id: buttoninputGroup
//    }

//    Rectangle
//    {
//        id:btnBar
//        width: parent.width
//        height: 50
//        anchors.top: line.bottom

//        property var btnText:["首页","消息", "服务", "我的"]

//        Row
//        {
//            anchors.fill: parent
//            Repeater
//            {
//                model:btnBar.btnText
//                ExclusiveRectangle
//                {
//                    id:button
//                    visible: true
//                    width: btnBar.width/4
//                    height: btnBar.height
//                    checked: index == 0?true:false
//                    exclusiveGroup: buttoninputGroup
//                    Rectangle
//                    {
//                        id:topImg
//                        width: parent.width
//                        height: parent.height*2/3
//                    //    color: "blue"
//                        Image
//                        {
//                            anchors.centerIn: parent
//                            width: 21
//                            height: 21
//                            source: "/img/timg.jpg"
//                        }
//                    }

//                    Rectangle{
//                        id:topBtn
//                        width: parent.width
//                        height: parent.height - topImg.height
//                        anchors.bottom: parent.bottom
//                        anchors.bottomMargin: topBtn.height/4
//                        //color: "red"
//                        Text{
//                            font.pointSize: 12
//                            anchors.horizontalCenter: parent.horizontalCenter

//                            color: button.checked ?"#5CACEE":"#838B8B"
//                            text: modelData
//                        }
//                    }
//                    MouseArea
//                    {
//                        anchors.fill: parent
//                        onClicked:
//                        {
//                            button.checked = true
//                            switchview.currentIndex = index
//                        }
//                    }
//                }
//            }
//        }
//        z:2
//    }
}
