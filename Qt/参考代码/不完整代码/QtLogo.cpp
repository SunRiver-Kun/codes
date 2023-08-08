#include "QtLogo.h"

QtLogo::QtLogo(QObject *parent)
	: QObject(parent)
{
}

QtLogo::~QtLogo()
{
}

void Patch::draw() const
{
	glPushMatrix();
	glMultMatrixf(mat.data());
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, faceColor);
	const GLushort* indices = geom->faces.constData();
	glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_SHORT, indices + start);
	glPopMatrix();
}
