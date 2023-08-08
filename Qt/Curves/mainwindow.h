#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    virtual void drawHZ(QPainter* painter,int depth,QPointF pt1,float angel,float length);

private:
    Ui::MainWindow *ui;
    int m_depth = 0;
    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
};
#endif // MAINWINDOW_H
