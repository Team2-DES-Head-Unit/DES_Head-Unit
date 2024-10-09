#ifndef GAUGE_H
#define GAUGE_H

#include <QObject>
#include <QQuickPaintedItem>

class gauge : public QQuickPaintedItem
{
    Q_OBJECT

    Q_PROPERTY(qreal speedometerSize READ getspeedometerSize WRITE setSpeedometerSize NOTIFY speedometerSizeChanged)
    Q_PROPERTY(qreal startAngle READ getStartAngle WRITE setStartAngle NOTIFY startAngleChanged)
    Q_PROPERTY(qreal alignAngle READ getAlignAngle WRITE setAlignAngle NOTIFY alignAngleChanged)
    Q_PROPERTY(qreal lowestRange READ getLowestRange WRITE setLowestRange NOTIFY lowestRangeChanged)
    Q_PROPERTY(qreal highestRange READ getHighestRange WRITE setHighestRange NOTIFY highestRangeChanged)
    Q_PROPERTY(qreal battery READ getRPM WRITE setRPM NOTIFY RPMChanged)
    Q_PROPERTY(int arcWidth READ getArcWidth WRITE setArcWidth NOTIFY arcWidthChanged)
    Q_PROPERTY(QColor outerColor READ getOuterColor WRITE setOuterColor NOTIFY outerColorChanged)
    Q_PROPERTY(QColor innerColor READ getInnerColor WRITE setInnerColor NOTIFY innerColorChanged)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor NOTIFY textColorChanged)
    Q_PROPERTY(QColor backgroundColor READ getBackgroundColor WRITE setBackgroundColor NOTIFY backgroundColorChanged)

public:
    gauge(QQuickItem *parent = 0);
    virtual void paint(QPainter *painter);

    // return property value
    qreal getspeedometerSize();
    qreal getStartAngle();
    qreal getAlignAngle();
    qreal getLowestRange();
    qreal getHighestRange();
    qreal getRPM();
    int  getArcWidth();
    QColor getOuterColor();
    QColor getInnerColor();
    QColor getTextColor();
    QColor getBackgroundColor();

    // set property value
    void setSpeedometerSize(qreal size);
    void setStartAngle(qreal startAngle);
    void setAlignAngle(qreal angle);
    void setLowestRange(qreal losbwestRange);
    void setHighestRange(qreal highestRange);
    void setRPM(qreal RPM);
    void setArcWidth(int arcWidth);
    void setOuterColor(QColor outerColor);
    void setInnerColor(QColor innerColor);
    void setTextColor(QColor textColor);
    void setBackgroundColor(QColor backgroundColor);

    // signal that occur when modify(change) property
signals:
    void speedometerSizeChanged();
    void startAngleChanged();
    void alignAngleChanged();
    void lowestRangeChanged();
    void highestRangeChanged();
    void RPMChanged();
    void arcWidthChanged();
    void outerColorChanged();
    void innerColorChanged();
    void textColorChanged();
    void backgroundColorChanged();

    // store(save) the property values
private:
    qreal   m_SpeedometerSize;
    qreal   m_StartAngle;
    qreal   m_AlignAngle;
    qreal   m_LowestRange;
    qreal   m_HighestRange;
    qreal   m_RPM;
    int     m_ArcWidth;
    QColor  m_OuterColor;
    QColor  m_InnerColor;
    QColor  m_TextColor;
    QColor  m_BackgroundColor;

};

#endif // GAUGE_H
