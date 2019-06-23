#include "maincontroller.h"

MainController::MainController(MainWindow* view, MainModel* model){
    this->view = view;
    this->model = model;

    this->ui = view->getUi();
    this->graph = new Graph(model);
    init();
    initConnections();
}

void MainController::init(){
    qreal width = view->getChartViewWidth();
    qreal heigt = view->getChartViewHeight();
    QChartView* chartView = graph->createView(width, heigt);

    scene = new QGraphicsScene();
    scene->addWidget(chartView);
    scene->setSceneRect(0,0,width-5,heigt-5);
    view->addScene(scene);
}

void MainController::showView(){
    view->show();
}

void MainController::setColorButtonColor(QColor color){
    QString qss = QString("background-color: %2").arg(color.name());
    ui->colorButton->setStyleSheet(qss);
}

void MainController::pushedDraw(){
    if(validateInput(ui->funcField->text())){
       return;
    }

    Function* function = createFunction(ui->funcField->text());
    model->addFunction(function);

    FunctionPlotter* plotter = new FunctionPlotter();
    graph->setPlotter(plotter);
    graph->draw(function);

    QListWidgetItem* item = createItem();
    view->getUi()->functionsList->addItem(item);
    view->getUi()->funcField->clear();
}

//Bisher wird nur überprüft, ob die Eingabe ein leerer String ist.
//Es soll zukünftig auch validieren, ob bspw. unzulässige Zeichen eingeben wurden oder in einer falschen reihenfolge.
//Wie zum Beispiel -> ** oder ^^.
//Falls dies der Fall ist soll das Textfeld einen roten Border erhalten.
//Falls die Funktion korrekt validiert werden kann, erhält sie einen grünen Border.
bool MainController::validateInput(QString func){
    return func.trimmed().isEmpty();
}

Function* MainController::createFunction(QString name){
    Function* function = new Function();
    function->setName(name);
    function->setColor(model->getCurrentFunctionColor());

    QSplineSeries* series = new QSplineSeries();
    series->setPen(QPen(function->getColor(), 2));
    function->setSeries(series);
    return function;
}

QListWidgetItem* MainController::createItem(){
    QListWidgetItem* item = new QListWidgetItem(ui->funcField->text());
    item->setTextColor(model->getCurrentFunctionColor());
    item->setSizeHint(QSize(20,20));
    item->setFont(QFont("arial", 13, QFont::AnyStyle, false));
    return item;
}

void MainController::pushedClear(){
    graph->clear();
    view->getUi()->functionsList->clear();
}

void MainController::pushedReset(){
    if(!model->getFunctions()->isEmpty()){
        graph->reset();

        QListWidget* list = view->getUi()->functionsList;
        delete list->item(list->count()-1);
    }
}

void MainController::pushedColorChanger(){
   view->getColorDialog()->show();
}

void MainController::changedXRange(int x_range){
    graph->setXRange(x_range);
    graph->refresh();
}

void MainController::changedYRange(int y_range){
    graph->setYRange(y_range);
    graph->refresh();
}

void MainController::mouseMoving(QPoint point){
    qDebug() << point.x() << " " << point.y();
}

void MainController::mouseClicked(QPoint point){
    qDebug() << point.x() << " " << point.y();
}

void MainController::initConnections(){
    view->connect(view->getUi()->clearButton, SIGNAL(pressed()), this, SLOT(pushedClear()));
    view->connect(view->getUi()->resetButton, SIGNAL(pressed()),this, SLOT(pushedReset()));
    view->connect(view->getUi()->funcField, SIGNAL(returnPressed()), this, SLOT(pushedDraw()));
    view->connect(view->getUi()->colorButton, SIGNAL(pressed()), this, SLOT(pushedColorChanger()));
    view->connect(view->getColorDialog(),SIGNAL(colorSelected(QColor)),model, SLOT(setGraphColor(QColor)));
    view->connect(view->getColorDialog(),SIGNAL(colorSelected(QColor)),this, SLOT(setColorButtonColor(QColor)));
    view->connect(view->getUi()->spinBox_x_range, SIGNAL(valueChanged(int)), this, SLOT(changedXRange(int)));
    view->connect(view->getUi()->spinBox_y_range, SIGNAL(valueChanged(int)), this, SLOT(changedYRange(int)));

//    view->connect(scene, SIGNAL(mouseMoved(QPoint)),this, SLOT(mouseMoving(QPoint)));
//    view->connect(scene, SIGNAL(mouseClicked(QPoint)),this, SLOT(mouseClicked(QPoint)));
}




