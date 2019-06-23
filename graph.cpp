#include "graph.h"

Graph::Graph(MainModel* model){
    this->model = model;

    legend()->hide();

    QSplineSeries *series = new QSplineSeries;
    addSeries(series);

    buildXAxis(series, model->getXRange());
    buildYAxis(series, model->getYRange());

    createDefaultAxes();
}

QChartView* Graph::createView(qreal width, qreal height){
    QChartView* chartView = new QChartView(this);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setSceneRect(0, 0, width, height);
    return chartView;
}

void Graph::addFunction(Function* function){
    this->model->getFunctions()->push_back(function);
}

void Graph::setPlotter(FunctionPlotter* plotter){
    this->model->setFunctionPlotter(plotter);
}

void Graph::draw(Function* function){
    model->getFunctionPlotter()->setCurrentFunction(function);

    for(double x = 0; x < model->getXRange(); x+=0.1){
       double y = model->getFunctionPlotter()->calculate(x);
       function->getSeries()->append(x, y);
    }
    addSeries(function->getSeries());
    buildXAxis(function->getSeries(), model->getXRange());
    buildYAxis(function->getSeries(), model->getYRange());
    createDefaultAxes();
}

void Graph::buildXAxis(QSplineSeries* series, int x_range){
    QValueAxis* axisX = new QValueAxis;
    axisX->setRange(0, x_range);
    setAxisX(axisX, series);
}

void Graph::buildYAxis(QSplineSeries* series, int y_range){
    QValueAxis* axisY = new QValueAxis;
    axisY->setRange(0, y_range);
    setAxisY(axisY, series);
}

void Graph::clear(){
//    qDeleteAll(model->getFunctions());
    model->getFunctions()->clear();
    removeAllSeries();
//    delete model->getFunctionPlotter();
}

void Graph::reset(){
    removeSeries(model->getFunctions()->last()->getSeries());
    model->getFunctions()->removeLast();
    createDefaultAxes();
}

void Graph::refresh(){
   removeAllSeries();

   //Da removeAllSeries die Series* löscht. Müssen diese leider wieder neugebaut werden
   //und den entsprechenden Funktions-Objekten hinzugefügt werden.
   for (auto it = model->getFunctions()->begin(); it != model->getFunctions()->end(); it++){
        Function* function = (*it);
        QSplineSeries* serie = new QSplineSeries();
        serie->setPen(QPen(function->getColor(), 2));
        function->setSeries(serie);
        draw(function);
    }
}

void Graph::setXRange(int x_range){
    model->setXRange(x_range);
}

void Graph::setYRange(int y_range){
    model->setYRange(y_range);
}
