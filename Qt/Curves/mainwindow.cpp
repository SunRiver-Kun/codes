#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QtMath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->bt_draw,&QPushButton::clicked,[this](){
        this->m_depth = this->ui->in_depth->value();
        this->repaint();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawHZ(QPainter *painter, int depth, QPointF pt1, float angle, float length)
{
    float dx = qCos(qDegreesToRadians(angle)) * length;
    float dy = qSin(qDegreesToRadians(angle)) * length;
    if(depth <= 0)
    {
        painter->drawLine(pt1.x(),pt1.y(),pt1.x() + dx, pt1.y() +dy);
        return;
    }
    QPointF pt2(pt1.x()+dx/3,pt1.y()+dy/3);
    QPointF pt3(pt2.x()+ qCos(qDegreesToRadians(angle-60)) * length/3
                ,pt2.y()+ qSin(qDegreesToRadians(angle-60)) * length/3);
    QPointF pt4(pt1.x()+2*dx/3,pt1.y()+2*dy/3);

    drawHZ(painter,depth-1,pt1,angle,length/3);
    drawHZ(painter,depth-1,pt2,angle-60,length/3);
    drawHZ(painter,depth-1,pt3,angle+60,length/3);
    drawHZ(painter,depth-1,pt4,angle,length/3);

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(Qt::blue);

    float mid_x = width()/2.f;
    float mid_y = height()/2.f;
    float l = qMin(width(),height()) /3.f;
    float length = l * qSqrt(3);
    QPointF top(mid_x ,mid_y - l);
    QPointF left(mid_x + qCos(qDegreesToRadians(150.f))*l,mid_y + qSin(qDegreesToRadians(150.f))*l);
    QPointF right(mid_x + qCos(qDegreesToRadians(30.f))*l,mid_y + qSin(qDegreesToRadians(30.f))*l);
    drawHZ(&painter,m_depth,left,-60,length);
    drawHZ(&painter,m_depth,top,60,length);
    drawHZ(&painter,m_depth,right,-180,length);
}

