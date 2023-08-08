#include<QtWidgets>
QGraphicsScene* scene = new QGraphicsScene(rect(), this);
auto background = scene->addRect(0, 0, 300, 300, QPen(Qt::NoPen), QBrush(Qt::white));
auto pixmap = scene->addPixmap(QPixmap("./±³¾°.jpg"));
pixmap->setScale(0.5);
pixmap->setParentItem(background);

auto effect = new QGraphicsOpacityEffect();
effect->setOpacity(0.5);

pixmap->setGraphicsEffect(effect);
//background->setGraphicsEffect(effect);

QGraphicsView* view = new QGraphicsView(scene, this);
view->resize(this->size());
view->show();