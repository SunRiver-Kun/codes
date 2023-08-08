
//.h
#pragma once

#include <QtWidgets/qwidget.h>

class SShapeWidget : public QWidget
{
	Q_OBJECT
		Q_PROPERTY(QPixmap pixmap READ pixmap WRITE setPixmap)
public:
	SShapeWidget(QWidget* parent = Q_NULLPTR);
	QPixmap pixmap()const;
	void setPixmap(const QPixmap& pixmap);
protected:
	void mousePressEvent(QMouseEvent* event)override;
	void mouseMoveEvent(QMouseEvent* event)override;
	void paintEvent(QPaintEvent* event)override;

private:
	QPixmap m_pixmap;
	QPoint m_dragPoint;
};

//.cpp
#include "SShapeWidget.h"
#include <qpainter.h>
#include <qevent.h>
SShapeWidget::SShapeWidget(QWidget* parent)
	: QWidget(parent)
{
	//������ȥ���߿����ô��ڵ�flags
	setWindowFlags(Qt::FramelessWindowHint | windowFlags());

	//����͸������
	setAttribute(Qt::WA_TranslucentBackground);
}

QPixmap SShapeWidget::pixmap() const
{
	return m_pixmap;
}

void SShapeWidget::setPixmap(const QPixmap& pixmap)
{
	m_pixmap = pixmap;
	resize(pixmap.width(), pixmap.height());
	repaint();
}

void  SShapeWidget::mousePressEvent(QMouseEvent* event)
{
	if (event->button() & Qt::LeftButton)
		m_dragPoint = event->globalPos() - frameGeometry().topLeft();
	else if (event->button() & Qt::RightButton)
		close();
}

void SShapeWidget::mouseMoveEvent(QMouseEvent* event)
{
	move(event->globalPos() - m_dragPoint);
}

void SShapeWidget::paintEvent(QPaintEvent* event)
{
	Q_UNUSED(event);
	QPainter painter(this);
	painter.setPen(Qt::NoPen);
	painter.setBrush(Qt::NoBrush);
	painter.drawPixmap(0, 0, m_pixmap);
}