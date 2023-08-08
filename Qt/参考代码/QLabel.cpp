#include "Task.h"
#pragma execution_character_set("utf-8")

Task::Task(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	resize(640, 480);

	//������
	QLabel* linklabel = new QLabel(this);
	linklabel->setText("<h1><a href=\"https://www.baidu.com\">�ٶ�һ��</a></h1>");
	linklabel->setOpenExternalLinks(true);
	//connect(linklabel, &QLabel::linkActivated, this, &Task::slotOpenUrl);  �ֶ�Ҳ����

	//��ʾͼƬ
	QLabel* pixlabel = new QLabel(this);
	pixlabel->setPixmap(QPixmap(""));

	//����gif
	QMovie* movie = new QMovie(":/Mario.gif");
	movie->start();
	QLabel* label = new QLabel(this);
	label->setMovie(movie);
}

//�ۺ���
void Task::slotOpenUrl(const QString& link)
{
	QDesktopServices::openUrl(QUrl(link));
}
