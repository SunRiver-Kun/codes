#include <GL/freeglut.h>

void OnDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glRotatef(5, 1, 1, 1);
	//glutSolidCube(5);
	glutSolidTeapot(5);
	glutSwapBuffers();
}

void OnReShape(GLint w, GLint h)
{
	const double LENGTH = 10;
	const GLdouble n = 0, f = 100;

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w < h)
	{
		glOrtho(-LENGTH, LENGTH, -LENGTH * h / w, LENGTH * h / w, -LENGTH, LENGTH);
	}
	else
	{
		glOrtho(-LENGTH * w / h, LENGTH * w / h, -LENGTH, LENGTH, -LENGTH, LENGTH);
	}
	glMatrixMode(GL_MODELVIEW);
}

void OnReShape_Frustum(GLint w, GLint h)
{
	const double LENGTH = 10;
	const GLdouble n = 0, f = 100;

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w < h)
	{
		glFrustum(-LENGTH, LENGTH, -LENGTH * h / w, LENGTH * h / w, n, f);
	}
	else
	{
		glFrustum(-LENGTH * w / h, LENGTH * w / h, -LENGTH, LENGTH, n, f);
	}
	glMatrixMode(GL_MODELVIEW);
}

void Init()
{
	glPointSize(3);
	glLineWidth(2);

	const GLfloat ambient[4] = { 1,0,0,1 };	//环境光
	const GLfloat diffuse[4] = { 0,1,0,1 };	//漫反射
	const GLfloat specular[4] = { 0,0,1,1 };	//镜面反射
	const GLfloat position[4] = { -1,1,1,0.1 };
	const GLfloat direction[3] = { 1,-1,-1 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, direction);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 10);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 30);
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.5);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void OnKeyboard(GLubyte key, GLint x, GLint y)
{
	glutExit();
}

int main(int argn, char* argv[])
{
	glutInit(&argn, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(600, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Hello World");
	Init();
	glutReshapeFunc(OnReShape);
	glutDisplayFunc(OnDisplay);
	glutKeyboardFunc(OnKeyboard);

	glutMainLoop();
}