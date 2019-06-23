#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPixmap>
#include <QIcon>
#include <QColorDialog>

namespace Ui {
class MainWindow;
}

/**
 * @brief The MainWindow class
 * @details Here the components for the view are built.<br>
 * This class represents the view of the programm.<br>
 * It will be called by the MainController.
 *
 * @author Marty Burghardt
 * @version 1.0
 * @date 28.12.18
 */
class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void addScene(QGraphicsScene* scene);

    /**
     * @details detects the width of the chart.
     * @return chartViewWidth
     */
    qreal getChartViewWidth();

    /**
     * @details detects the heigt of the chart.
     * @return chartViewHeight
     */
    qreal getChartViewHeight();

    /**
     * @brief builds the colorDialog.
     * @details The colordialog is a QColorDialog.
     * The default choosen color is blue.
     */
    void buildColorDialog();

    Ui::MainWindow* getUi();
    QColorDialog* getColorDialog();

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QColorDialog* colorDialog;

    /**
     * @brief builds the colorbutton.
     * @details this method builds the colorbutton and sets the defaultcolor to blue.
     */
    void buildColorButton();
};

#endif // MAINWINDOW_H
