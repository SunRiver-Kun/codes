#include "Task.h"
#pragma execution_character_set("utf-8")

Task::Task(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	resize(640, 480);

	//超链接
	QLabel* linklabel = new QLabel(this);
	linklabel->setText("<h1><a href=\"https://www.baidu.com\">百度一下</a></h1>");
	linklabel->setOpenExternalLinks(true);
	//connect(linklabel, &QLabel::linkActivated, this, &Task::slotOpenUrl);  手动也可以

	//显示图片
	QLabel* pixlabel = new QLabel(this);
	pixlabel->setPixmap(QPixmap(""));

	//播放gif
	QMovie* movie = new QMovie(":/Mario.gif");
	movie->start();
	QLabel* label = new QLabel(this);
	label->setMovie(movie);
}

//槽函数
void Task::slotOpenUrl(const QString& link)
{
	QDesktopServices::openUrl(QUrl(link));
}
