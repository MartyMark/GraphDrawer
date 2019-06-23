#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include "graph.h"
#include <QChartView>

using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),  ui(new Ui::MainWindow){
    ui->setupUi(this);
    this->setFixedSize(540, 738);
    buildColorButton();
    buildColorDialog();
}

void MainWindow::buildColorButton(){
    QString qss = QString("background-color: %1").arg(QColor(Qt::blue).name());
    ui->colorButton->setStyleSheet(qss);
}

void MainWindow::buildColorDialog(){
    this->colorDialog = new QColorDialog(this);
    colorDialog->setCurrentColor(QColor(Qt::blue));
}

QColorDialog* MainWindow::getColorDialog(){
    return colorDialog;
}

void MainWindow::addScene(QGraphicsScene* scene){
    ui->chartView->setScene(scene);
}

qreal MainWindow::getChartViewWidth(){
    return ui->chartView->width();
}

qreal MainWindow::getChartViewHeight(){
    return ui->chartView->height();
}

Ui::MainWindow* MainWindow::getUi(){
    return ui;
}

MainWindow::~MainWindow(){
    delete ui;
}
