#ifndef SCREENSHOT_QML_H
#define SCREENSHOT_QML_H

/**
* @By QtCreator Create: 2018年4月20日 09:50:18
* @Brief: 用于qml截图使用
* @Author: fu_lin
* @Description:
*/

#include <QObject>
#include <QQuickItem>
#include <QQuickItemGrabResult>
#include <QDebug>
#include <QByteArray>
#include <QThread>
#include <QImageReader>
#include <QImage>

#ifdef Q_OS_ANDROID
#define SAVEFILEADD "/storage/emulated/0/DCIM/bbb.png"
#define SAVEFILEADDI "/storage/emulated/0/DCIM/AAA.png"
#else
#define SAVEFILEADD "C:\\Users\\Administrator\\Desktop\\assssa.jpg"
#endif


class Screenshot_QML :public QThread
{
    Q_OBJECT
public:
    explicit Screenshot_QML(QThread *parent = nullptr);

    Q_INVOKABLE void setItem(QObject *itemObj);     // 保存图片
    Q_INVOKABLE void setClipSize(int clip_X, int clip_Y, QSize clipImageSize, QSize ImageSize);

    void run();
signals:
    void saveFinish(QString filePath);
public slots:
     void saveimage();

private:

  QQuickItem * m_grab_item_;
  QThread m_workerThread_;
  QSharedPointer<QQuickItemGrabResult> m_grab_result_;
  bool m_is_Clip_;
  int m_clip_X_;
  int m_clip_Y_;
  int m_clip_Width_;
  int m_clip_Height_;
  QSize m_imageSize_;

};

#endif // SCREENSHOT_QML_H
