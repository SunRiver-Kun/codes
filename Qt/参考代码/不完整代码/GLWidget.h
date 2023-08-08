#pragma once

#include "QtLogo.h"
#include <QtOpenGL/qgl.h>

class GLWidget : public QGLWidget
{
	Q_OBJECT

public:
	GLWidget(QWidget *parent);
	~GLWidget();
	
	QSize minimumSizeHint() const;
	QSize sizeHint() const;
public Q_SLOTS:
	void setXRotation(int angle);
	void setYRotation(int angle);
	void setZRotation(int angle);
Q_SIGNALS:
	void xRotationChanged(int angle);
	void yRotationChanged(int angle);
	void zRotationChanged(int angle);

protected:
	virtual void initializeGL() override; 
	virtual void resizeGL(int w, int h) override;
	virtual void paintGL() override;
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	
private:
	QtLogo* logo;
	int xRot, yRot, zRot;
	QPoint lastpos;
	QColor qtGreen;
	QColor qtPurple;
};

