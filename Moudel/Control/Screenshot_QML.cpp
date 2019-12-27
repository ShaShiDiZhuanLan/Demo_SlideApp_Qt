#include "Screenshot_QML.h"

Screenshot_QML::Screenshot_QML(QThread *parent) : QThread(parent),
    m_is_Clip_(false)
{

}

void Screenshot_QML::setItem(QObject *itemObj)
{

    m_grab_item_ = qobject_cast<QQuickItem*>(itemObj);//获取控件id
    m_grab_result_ = m_grab_item_->grabToImage();//获取控件图片
    QQuickItemGrabResult * grabResult = m_grab_result_.data();//获取数据
    //这里是必须这样写的，因为调用了ready（）这个准备函数，里面做了很多处理信号连接
    connect(grabResult,&QQuickItemGrabResult::ready,this,[=]{
        this->start();
    });

}

void Screenshot_QML::setClipSize(int clip_X, int clip_Y, QSize clipImageSize, QSize ImageSize)
{
    m_is_Clip_ = true;
    m_clip_X_ = clip_X;
    m_clip_Y_ = clip_Y;
    m_clip_Width_ = clipImageSize.width();
    m_clip_Height_ = clipImageSize.height();
    m_imageSize_ = ImageSize;
}

void Screenshot_QML::run()
{
   saveimage();
   exec();
}

void Screenshot_QML::saveimage()
{
    QImage imag = m_grab_result_->image();//这里转成图片

    if(m_is_Clip_)
    {
       imag = imag.copy(m_clip_X_, m_clip_Y_, m_clip_Width_,m_clip_Height_);
    }

#ifdef Q_OS_ANDROID
    if(imag.save(SAVEFILEADDI)){
        emit saveFinish(SAVEFILEADDI);
    }
#else
    if(imag.save(SAVEFILEADD)){
        emit saveFinish(SAVEFILEADD);
    }
#endif
    else
    {
         qInfo("save Fault");
    }

//    if(imag.save(SAVEFILEADD)){


//        QImageReader imageReader;

//         qInfo()<<" m_clip_Width = m_clip_Height_ = "<<m_clip_Width_<<m_clip_Height_<<m_imageSize_;
//        imageReader.setFileName(SAVEFILEADD);
//        QSize imageSize = imageReader.size();
//        imageSize.scale(m_imageSize_.width(), m_imageSize_.height(),Qt::IgnoreAspectRatio);
//     //   QImage img = m_grab_result_->image();

//        imageReader.setScaledSize(imageSize);
//        QImage img = imageReader.read();
//        qDebug()<<img;


//    }
//    else
//    {
//         qInfo("save Fault");
//    }

    m_is_Clip_ = false;
    quit();
    wait();
}
