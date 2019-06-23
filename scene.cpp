#include "scene.h"


void Scene::mousePressEvent(QGraphicsSceneMouseEvent* event){
    emit mouseClicked(QPoint(static_cast<int>(event->scenePos().x()), static_cast<int>(event->scenePos().y())));
}

//Falls der User den Mauszeiger über den Graphen, bewegt sollen hierbei die X- und Y-Werte angezeigt werden.
//Aufgrund von Zeitgründen, wird dies erst nach Projektabagabe implementiert.
void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent* event){
    emit mouseMoved(QPoint(static_cast<int>(event->scenePos().x()), static_cast<int>(event->scenePos().y())));
}

