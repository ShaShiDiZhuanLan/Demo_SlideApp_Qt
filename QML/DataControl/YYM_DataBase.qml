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
pragma Singleton
import QtQuick 2.9
import QtQuick.Window 2.2

Item {
    id:singletonData

    readonly property int initwidth: is_android()?Screen.desktopAvailableWidth:380
    readonly property int initHeight: is_android()?Screen.desktopAvailableHeight:600

    function setcurrentPage(page)
    {
        singletonData.topPage.push(currentPage)
        currentPage = page
    }
    function is_android()
    {
        return Qt.platform.os === "android"?true:false
    }

    //控件间距
    readonly property int space_I: 10
    readonly property int space_II: 15
    readonly property int space_III: 20
    readonly property int space_IV: 25
    readonly property int space_V: 35
    readonly property int scanSpaceI: 45
    readonly property int scanSpace: 65

    //一般按钮大小
    readonly property int buttonHeight: 50
    readonly property int buttonWidth_I: 100
    readonly property int buttonWidth: 180
    readonly property int buttonWidth_II: 80
    readonly property int buttonWidth_III: 130
    readonly property int scanHeight: 155
    readonly property int scanWidth: 185
    readonly property int circleSize: 25
    readonly property real lineHeight: Qt.platform.os == "android"?0.7:1.0
    readonly property int offlineHeight: 220

    //颜色
    readonly property color blue_I:"#169BD5"

    readonly property color gray_I: "#969696"
    readonly property color gray_II: "#DCDCDC"
    readonly property color gray_III: "#EDEDED"
    readonly property color lightGreen: "#32CD32"

    readonly property color red_I: "#EE3B3B"
    readonly property color black_I: "#696969"
    readonly property color black_II: "#C9C9C9"

    readonly property color font_color:"#5E5E5E"//黒
    readonly property color font_color_I:black_I  //更黒
    readonly property color font_color_II:"#969696"//灰黒

    //字体大小
    property int font_I: 10 + font_volatile
    property int font_II: 12 + font_volatile
    property int font_III: 14 + font_volatile
    property int font_IV: 16 + font_volatile
    property int font_V: 18 + font_volatile

    //再按一次退出变量记录
    property bool pressAgain: false

    //上层页面
    property var topPage: []

    //控制字体增长变化的变量
    property int font_volatile : 0

    //网络状态 //默认没网
    property bool networkState: false;


    //版本号
    readonly property string versoin: "1.0.0"

    //sao扫描仪灯光开关 //1是开，0是关
    property int openLight: 1

    //线的颜色
    readonly property color lineColor: gray_II

    //字体大小
    readonly property int font_nomal: font_III

    //登录页面
    readonly property int login_TextHei: buttonHeight
    readonly property int login_BtnHei: buttonHeight

    //是否登录成功
    property bool loginSuccess:false //默认没网
    //记录token
    property var token
    //用户名称，全局记住
    property string userName: qsTr("李四")
    //用户名称ID，全局记住
    property var userid
    //点击合并提货单后记录的提货单号，只是记录当前的提货单号
    property var deliveryOrder

    // 主页面
    readonly property int main_BtnWei: buttonWidth
    readonly property int main_BtnHei: 120

    //溯源页面
    readonly property int traceSource_space: space_I
    readonly property real traceSource_lineHeight : 1.1
    readonly property int traceSource_btnHeight : 30
    readonly property int traceSource_MiddleRectHei: 230
    readonly property int traceSource_itemHei: 90

    //溯源页面子页面
    readonly property int dateMsg_dateWei: 50
    readonly property int dateMsg_imgWei: 15
    readonly property int dateMsg_imgHei: 15

    //发货详情
    readonly property int recordInfo_titleHei: 30
    readonly property color recordInfo_titleColor: "#CCCCCC"
    readonly property int recordInfo_space: space_I


    readonly property string imageUrl : "http://www.emto.cn/APP/xxhdpi/"

}
