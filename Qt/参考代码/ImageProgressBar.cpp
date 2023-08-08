//.h
#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qprogressbar.h>
#include "ui_Task.h"

#undef LoadImage
class Task : public QMainWindow
{
	Q_OBJECT

public:
	Task(QWidget* parent = Q_NULLPTR);
public Q_SLOTS:
	void LoadImage();
	void ReSetLabelSize(int value);
	void AddProgressNum();
private:
	QLabel* label;
	QPushButton* bt_choose, * bt_add;
	QProgressBar* progressbar;
	double pixmapwidth = 0;
	Ui::TaskClass ui;
};

//.cpp
#include "Task.h"
#include <QtWidgets>
#undef LoadImage
#pragma execution_character_set("utf-8")

Task::Task(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	resize(1024, 1024);

	label = new QLabel(this);
	bt_choose = new QPushButton(tr("选择图片"), this);
	bt_add = new QPushButton(tr("增加进度"), this);
	progressbar = new QProgressBar(this);

	connect(bt_choose, SIGNAL(clicked()), this, SLOT(LoadImage()));
	connect(progressbar, SIGNAL(valueChanged(int)), this, SLOT(ReSetLabelSize(int)));
	connect(bt_add, SIGNAL(clicked()), this, SLOT(AddProgressNum()));

	bt_choose->setGeometry(50, 50, 200, 100);
	bt_choose->show();
	bt_add->hide();
	label->hide();
	progressbar->hide();
}

void Task::LoadImage()
{
	QString path = QFileDialog::getOpenFileName(this);//"C:/Users/Administrator.SUNRIVER/Pictures/Camera Roll/背景.jpg";
	QPixmap pixmap(path);
	pixmapwidth = (double)pixmap.width();
	label->setPixmap(pixmap);
	label->setGeometry(0, 0, 0, pixmap.height());
	bt_add->setGeometry(bt_choose->geometry());
	progressbar->setGeometry(0, label->height(), int(pixmapwidth), 50);

	bt_choose->hide();
	bt_add->show();
	label->show();
	progressbar->show();
}

void Task::ReSetLabelSize(int value)
{
	int width = pixmapwidth * value / double(progressbar->maximum() - progressbar->minimum() + 1);
	label->resize(width, label->height());
}

void Task::AddProgressNum()
{
	progressbar->setValue(std::min(progressbar->value() + 1, progressbar->maximum()));
}