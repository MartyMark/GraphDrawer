#include "function.h"

void Function::setName(QString name){
    this->name = name;
}

void Function::setColor(QColor color){
    this->color = color;
}

void Function::setSeries(QSplineSeries* series){
    this->series = series;
}

QString Function::getName(){
    return name;
}

QColor Function::getColor(){
    return color;
}

QSplineSeries* Function::getSeries(){
    return series;
}
