#ifndef SPAINTERITEM_H
#define SPAINTERITEM_H
#include <QQuickPaintedItem>
#include <QPainterPath>
#include <QPainter>
#include <QPointF>
#include <QImage>
#include <QPen>
#include <QBrush>
#include <QColor>
#include <QDebug>

class SPainterItem : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(int penWidth READ penWidth WRITE setPenWidth)
    Q_PROPERTY(QColor penColor READ penColor WRITE setPenColor)
    Q_PROPERTY(bool erasered READ isErasered WRITE setErasered)
public:
    explicit SPainterItem(QQuickItem  *parent = nullptr);
    int penWidth() const { return m_penWidth; }
    void setPenWidth(int width) { m_penWidth = width; }
    QColor penColor() const { return m_brushColor; }
    void setPenColor(QColor color) { m_brushColor = color; }
    bool isErasered() const{ return m_bErasered; }
    void setErasered(bool erasered){ m_bErasered = erasered; }
    void paint(QPainter *painter);
    Q_INVOKABLE void init();
    Q_INVOKABLE void clear();
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    void drawTmpLine();
    void drawBgLine(const QPainterPath &path);
    void drawPenStyle(QPainter *painter);
private:
    QImage m_bgImage;
    QImage m_tempImage;
    QColor m_brushColor;
    QColor m_eraserColor;
    QPointF m_nowPoint;
    QPointF m_lastPoint;
    QPainterPath *m_pDrawPath;
    int m_penWidth;
    bool m_bFlag;
    bool m_bErasered;
};

#endif // SPAINTERITEM_H
