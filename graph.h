#ifndef GRAPH_H
#define GRAPH_H

#include "ui_mainwindow.h"
#include "functionPlotter.h"
#include "mainmodel.h"
#include <QList>
#include <QChart>
#include <QObject>
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QValueAxis>
#include <QDebug>

QT_CHARTS_USE_NAMESPACE

/**
 * @brief The Graph class
 * @details This class represents a graph of the programm.
 * It will be called by the MainController.
 *
 * @author Marty Burghardt
 * @version 1.0
 * @date 28.12.18
 */
class Graph : public QChart{
    Q_OBJECT

private:
    MainModel* model;

public:
    Graph(MainModel* model);

    /**
     * @brief This method creates the QCahrtView-object, which will be insert into the scene.<br>
     * It contains QChart-object.
     * @param width
     * @param height
     * @return QChartView*
     */
    QChartView* createView(qreal width, qreal height);

    /**
     * @brief adds a Function to the model
     * @param function
     */
    void addFunction(Function* function);

    /**
     * @brief sets the plotter in the model
     * @param plotter
     */
    void setPlotter(FunctionPlotter* plotter);

    /**
     * @brief draws the function, by accessing the setted plotter.
     * @param function
     */
    void draw(Function* function);

    /**
     * @brief deletes the functions from the view and the model.
     */
    void clear();

    /**
     * @brief deletes the last added function from the model and the view.
     */
    void reset();

    /**
     * @brief refresh the whole chart.
     * @details The refresh is done by deleting all graphs and drawing them<br>
     * with the new values.
     */
    void refresh();

    /**
     * @brief build the X-Axis.
     * @details Builds a QValueAxis fills it with the new range and adds it the QChart.
     * @param series
     * @param x_range
     */
    void buildXAxis(QSplineSeries* series, int x_range);

    /**
     * @brief build the Y-Axis.
     * @details Builds a QValueAxis fills it with the new range and adds it the QChart.
     * @param series
     * @param y_range
     */
    void buildYAxis(QSplineSeries* series, int y_range);

    /**
     * @brief set the X range to the model.
     * @param x_range
     */
    void setXRange(int x_range);

    /**
     * @brief set the Y range to the model.
     * @param y_range
     */
    void setYRange(int y_range);
};

#endif // GRAPH_H
