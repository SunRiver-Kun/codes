#pragma once

#include <QObject>
#include <QtWidgets>
#include <QtOpenGL/QtOpenGL>

struct Geometry
{
	QVector<GLushort> faces;
	QVector<QVector3D> vertices;
	QVector<QVector3D> normals;
	void appendSmooth(const QVector3D& a, const QVector3D& n, int from);
	void appendFaceted(const QVector3D& a, const QVector3D& n);
	void finalize();
	void loadArrays() const;
};

class Patch
{
public:
	enum Smoothing{ Faceted,Smooth };
	Patch(Geometry*);
	void setSmoothing(Smoothing s) { sm = s; }
	void translate(const QVector3D& t);
	void rotate(qreal deg, QVector3D axis);
	void draw() const;
	
	GLushort start;
	GLushort count;
	GLushort initv;
	GLfloat faceColor[4];
	QMatrix4x4 mat;
	Smoothing sm;
	Geometry* geom;
};

class QtLogo : public QObject
{
	Q_OBJECT

public:
	QtLogo(QObject *parent);
	~QtLogo();
	void setColor(QColor c);
	void draw() const;

private:
	void buildGeometry(int d, qreal s);
	
	QList<Patch*> parts;
	Geometry* geom;
};
