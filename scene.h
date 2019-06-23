#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QPoint>
#include <QGraphicsSceneMouseEvent>

class Scene : public QGraphicsScene{
    Q_OBJECT
/**
 * @brief This Class represents the Scene.
 * @details It conatins only Events, which are modified for special handling.
 *
 * @author Marty Burghardt
 * @version 1.0
 * @date 28.12.18
 */
public:
    void mousePressEvent(QGraphicsSceneMouseEvent* event)override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event)override;

    ~Scene(){}
signals:
  void mouseClicked(QPoint point);
  void mouseMoved(QPoint point);
};

#endif // SCENE_H
