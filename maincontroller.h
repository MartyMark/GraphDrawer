#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "mainwindow.h"
#include "mainmodel.h"
#include "graph.h"
#include "scene.h"
#include "functionPlotter.h"
#include <QChartView>
#include <QObject>
#include <QDebug>
#include <QColorDialog>
#include <QPoint>

/**
 * @brief This class represents the controller of the programm.
 * @details This class handles all operations between the view, the model or other classes.
 *
 * @author Marty Burghardt
 * @version 1.0
 * @date 28.12.18
 */
class MainController : public QObject{
    Q_OBJECT

private:
    MainWindow* view;
    MainModel* model;

    Ui::MainWindow* ui;
    Graph* graph;
    QGraphicsScene* scene;

    QList<QSplineSeries*>::iterator it;

public:
    MainController(MainWindow* view, MainModel* model);

    /**
     * @brief shows the main interface.
     */
    void showView();

    ~MainController(){
        delete view;
        delete model;
    }
private:
    /**
     * @brief initials the view.
     */
    void init();

    /**
     * @brief initials the connections, between the view and the controller.
     */
    void initConnections();

    /**
     * @brief creates a listitem for the functionslist, with the current function.
     * @return QListWidgetItem*
     */
    QListWidgetItem* createItem();

    /**
     * @brief validates the input, whether it can be plotted or not.
     * @param function as a String
     * @return bool
     */
    bool validateInput(QString func);

    /**
     * @brief creates a function-object.
     * @param function as a String
     * @return Function*
     */
    Function* createFunction(QString name);

public slots:
    /**
      * @brief reacts if the user pushed draw
      * @details draws the current function.
      */
     void pushedDraw();

     /**
       * @brief reacts if the user pushed clear
       * @details deletes all functions from the model and the view.
       */
     void pushedClear();

     /**
      * @brief reacts if the user pushed clear
      * @details deletes the last added function from the model and the view.
      */
     void pushedReset();

     /**
      * @brief reacts if the user pushed the colorchangerbutton.
      * @details opens the QColorDialog.
      */
     void pushedColorChanger();

     /**
      * @brief sets the Color of the colorchangerbutton
      * @details if the user choosed a color of the QColorDialog, the button will be coloured with this color.
      * @param color
      */
     void setColorButtonColor(QColor color);

     /**
      * @brief reacts if the user changed the values of the spinBox for the X-Range.
      * @param x-range value
      */
     void changedXRange(int);

     /**
      * @brief reacts if the user changed the values of the spinBox for the Y-Range.
      * @param y-range value
      */
     void changedYRange(int);

     void mouseMoving(QPoint point);
     void mouseClicked(QPoint point);
};



#endif // MAINCONTROLLER_H
