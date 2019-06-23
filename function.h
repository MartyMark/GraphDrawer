#ifndef FUNCTIONCON_H
#define FUNCTIONCON_H

#include <QObject>
#include <QColor>
#include <QtCharts/QSplineSeries>

QT_CHARTS_USE_NAMESPACE

/**
 * @brief The Function class
 * @details This Class is a container for the function, which will be drawn.<br>
 * It contains the name, the  color and the series.
 *
 * @author Marty Burghardt
 * @version 1.0
 * @date 23.01.19
 */
class Function{

private:
    QString name;
    QColor color;
    QSplineSeries* series;

public:
    void setName(QString name);
    void setColor(QColor color);
    void setSeries(QSplineSeries* series);

    QString getName();
    QColor getColor();
    QSplineSeries* getSeries();

    ~Function(){
        delete series;
    }
};

#endif // FUNCTIONCON_H
