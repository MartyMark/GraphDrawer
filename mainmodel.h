#ifndef MAINMODEL_H
#define MAINMODEL_H

#include "function.h"
#include <QObject>
#include <QColor>
#include <QtCharts/QSplineSeries>
#include <QMap>
#include <functionPlotter.h>

QT_CHARTS_USE_NAMESPACE

/**
 * @brief The MainModel class
 * @details This class represents the model of the programm.<br>
 * This class stores the important datas of the chart.<br>
 * It will be called by the MainController.
 *
 * @author Marty Burghardt
 * @version 1.0
 * @date 10.01.19
 */
class MainModel : public QObject{
    Q_OBJECT

private:
    QColor choosenColor;

    /**
     * @details all entered functions are stored here
     */
    QList <Function*>* functions;

    /**
     * @brief current plotter
     * @details This is the current Functionplotter.
     * If the controller is calculating some points, it uses this plotter.
     */
    FunctionPlotter* plotter;

    int x_range = 10;
    int y_range = 10;

public:
    MainModel(){
        choosenColor = QColor(Qt::blue);
        functions = new QList<Function*>();
    }

    QColor getCurrentFunctionColor();
    void addFunction(Function* function);
    QList <Function*>* getFunctions();

    void setFunctionPlotter(FunctionPlotter* plotter);
    FunctionPlotter* getFunctionPlotter();

    void setXRange(int range);
    int getXRange();

    void setYRange(int range);
    int getYRange();

    ~MainModel(){
//        qDeleteAll(functions);
        delete plotter;
    }

public slots:
    void setGraphColor(QColor color);
};

#endif // MAINMODEL_H
