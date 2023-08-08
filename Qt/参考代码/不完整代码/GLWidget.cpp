#include "GLWidget.h"
#include <QtOpenGL/QtOpenGL>
#include <QtWidgets>

GLWidget::GLWidget(QWidget *parent): QGLWidget(QGLFormat(QGL::SampleBuffers),parent)
{
	logo = nullptr;
	xRot = yRot = zRot = 0;
	qtGreen = QColor::fromCmykF(0.4, 0.0, 1.0, 0.0);
	qtPurple = QColor::fromCmykF(0.39, 0.39, 0.0, 0.0);
}

GLWidget::~GLWidget()
{
	if (logo != nullptr)
	{
		delete logo;
		logo = nullptr;
	}
}

QSize GLWidget::minimumSizeHint() const
{
	return QSize(50,50);
}

QSize GLWidget::sizeHint() const
{
	return QSize(400,400);
}

void GLWidget::setXRotation(int angle)
{
	if (angle!=xRot)
	{
		xRot = angle;
		emit xRotationChanged(angle);
		updateGL();
	}
}

void GLWidget::setYRotation(int angle)
{
	if (angle != yRot)
	{
		yRot = angle;
		emit yRotationChanged(angle);
		updateGL();
	}
}

void GLWidget::setZRotation(int angle)
{
	if (angle != zRot)
	{
		zRot = angle;
		emit zRotationChanged(angle);
		updateGL();
	}
}

void GLWidget::initializeGL()
{
	qglClearColor(qtPurple.dark());

	//logo
	logo = new QtLogo(this);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_MULTISAMPLE);
	static GLfloat lightPosition[4] = { 0.5,5,7,1 };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void GLWidget::resizeGL(int w, int h)
{
	int side = qMin(w, h);
	glViewport((w - side) / 2, (h - side) / 2, side, side);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
#ifdef QT_OPENGL_ES_1
	glOrthof(-0.5, 0.5, -0.5, 0.5, 4.0, 15.0);
#else
	glOrtho(-0.5, 0.5, -0.5, 0.5, 4.0, 15.0);
#endif // QT_OPENGL_ES_1
	glMatrixMode(GL_MODELVIEW);
}

void GLWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -10.0);
	glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
	glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
	glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);
	logo->draw();
}

void GLWidget::mousePressEvent(QMouseEvent* event)
{
	lastpos = event->pos();
}

void GLWidget::mouseMoveEvent(QMouseEvent* event)
{
	int dx = event->x() - lastpos.x();
	int dy = event->y() - lastpos.y();

	if (event->buttons() & Qt::LeftButton)
	{
		setXRotation(xRot + 8 * dy);
		setYRotation(yRot + 8 * dx);
	}
	else if (event->buttons() & Qt::RightButton)
	{
		setXRotation(xRot + 8 * dy);
		setZRotation(zRot + 8 * dx);
	}
	lastpos = event->pos();
}
