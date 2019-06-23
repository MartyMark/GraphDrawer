#include "mainmodel.h"

QColor MainModel::getCurrentFunctionColor(){
    return choosenColor;
}

void MainModel::setGraphColor(QColor color){
    choosenColor = color;
}

void MainModel::addFunction(Function* function){
    this->functions->push_back(function);
}

QList<Function*>* MainModel::getFunctions(){
    return functions;
}

void MainModel::setXRange(int range){
    this->x_range = range;
}

int MainModel::getXRange(){
    return x_range;
}

void MainModel::setYRange(int range){
    this->y_range = range;
}

int MainModel::getYRange(){
    return y_range;
}

void MainModel::setFunctionPlotter(FunctionPlotter* plotter){
    this->plotter = plotter;
}

FunctionPlotter* MainModel::getFunctionPlotter(){
    return plotter;
}
