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
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import ".."
Rectangle {
    id:guide
    implicitHeight: Screen.desktopAvailableHeight
    implicitWidth: Screen.desktopAvailableWidth


    property var guideImage:/*["/img/1.jpg","/img/2.jpg","/img/3.jpg"] // */[BaseData.imageUrl+"startdiagram_2.png",BaseData.imageUrl+"startdiagram_3.png",BaseData.imageUrl+"startdiagram_4.png"]
    property int currentTime: BaseData.gbTime;

    property alias running: timer.running

    signal btnClick();
    signal imageClick()  ;

    function http()
    {
        console.info("调用成功")
        httprequest.setKeyValue();
    }

    Timer
    {
        id:timer
        interval:1500
        repeat: true
        running: false;
        onTriggered:
        {
            console.info("进来")
            currentTime--;
            if(view.currentIndex < 2)
            {
                view.currentIndex++;
            }
            else
            {
                if(currentTime == 0)
                {
                    timer.stop()
                    btnClick()
                }
            }
        }
    }

    Rectangle
    {
        id:showTimeRect
       width: text.implicitWidth+10
       height: 30
       color: "#20000000"

       anchors.right: parent.right
       anchors.rightMargin: 10
       anchors.top: parent.top
       anchors.topMargin: 10
       radius: 20

        Text {
        id: text
        anchors.centerIn: parent
        font.pointSize: 14
        color: "white"
        text: qsTr("跳过: "+currentTime+"S")
        }
        z:2
        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
               btnClick();
            }
        }
    }



    SwipeView {
        id: view

        currentIndex: 0
        anchors.fill: parent

        Repeater
        {
            model: guideImage
            Image{
                source: modelData
                MouseArea
                {
                    anchors.fill: parent
                    onClicked:
                    {
                        //点击该图片是为了跳转广告页面

                      //  imageClick();
                    }
                }
            }
        }
    }

    PageIndicator {
        id: indicator

        interactive: true
        count: view.count
        currentIndex: view.currentIndex

        anchors.bottom: view.bottom
        anchors.bottomMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        z:3
    }

    Button
    {
        visible: indicator.currentIndex == 2?true:false
        anchors.bottom: indicator.top
        anchors.bottomMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter

        highlighted:true
        text:"立即体验"
        onClicked:
        {
            btnClick();
        }
    }
}
