#include <GL/freeglut.h>
#include <stdio.h>

void Matrial(const GLfloat* ambient, const GLfloat* diffuse, const GLfloat* specular, const GLfloat* emission, GLfloat shininess)
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_EMISSION, emission);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}

void DrawSphere(GLfloat x, GLfloat y, GLfloat z, GLfloat radius = 2)
{
	//glPushMatrix();
	glTranslatef(x, y, z);
	glutSolidSphere(radius, 30, 10);
	//glPopMatrix();
}

void OnDisplay()
{
	const GLfloat no_mat[4] = { 0,0,0,1 };
	const GLfloat ambient[4] = { 0.7,0.7,0.7,1 };
	const GLfloat diffuse[4] = { 0.1,0.5,0.8,1 };
	const GLfloat specular[4] = { 1,1,1,1 };
	const GLfloat emission[4] = { 0.3,0.2,0.2,0 };
	const GLfloat no_shiniess = 0, low_shininess = 5, high_shininess = 100;
	const GLfloat shiniess = high_shininess;

	const GLfloat RADIUS = 2;
	const GLfloat LENGTH = 10;
	const GLfloat D = (2 * LENGTH - 2 * 4 * RADIUS) / 2.0 + RADIUS + 0.5;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(-LENGTH + RADIUS, LENGTH - RADIUS, 0);

	//第一排
	Matrial(no_mat, no_mat, no_mat, no_mat, shiniess);
	DrawSphere(0, 0, 0, RADIUS);
	Matrial(no_mat, no_mat, no_mat, emission, shiniess);
	DrawSphere(D, 0, 0, RADIUS);
	Matrial(no_mat, no_mat, specular, no_mat, shiniess);
	DrawSphere(D, 0, 0, RADIUS);
	Matrial(no_mat, no_mat, specular, emission, shiniess);
	DrawSphere(D, 0, 0, RADIUS);

	//第二排
	Matrial(no_mat, diffuse, no_mat, no_mat, shiniess);
	DrawSphere(0, -D, 0, RADIUS);
	Matrial(no_mat, diffuse, no_mat, emission, shiniess);
	DrawSphere(-D, 0, 0, RADIUS);
	Matrial(no_mat, diffuse, specular, no_mat, shiniess);
	DrawSphere(-D, 0, 0, RADIUS);
	Matrial(no_mat, diffuse, specular, emission, shiniess);
	DrawSphere(-D, 0, 0, RADIUS);

	//第三排
	Matrial(ambient, no_mat, no_mat, no_mat, shiniess);
	DrawSphere(0, -D, 0, RADIUS);
	Matrial(ambient, no_mat, no_mat, emission, shiniess);
	DrawSphere(D, 0, 0, RADIUS);
	Matrial(ambient, no_mat, specular, no_mat, shiniess);
	DrawSphere(D, 0, 0, RADIUS);
	Matrial(ambient, no_mat, specular, emission, shiniess);
	DrawSphere(D, 0, 0, RADIUS);

	//第四排
	Matrial(ambient, diffuse, no_mat, no_mat, shiniess);
	DrawSphere(0, -D, 0, RADIUS);
	Matrial(ambient, diffuse, no_mat, emission, shiniess);
	DrawSphere(-D, 0, 0, RADIUS);
	Matrial(ambient, diffuse, specular, no_mat, shiniess);
	DrawSphere(-D, 0, 0, RADIUS);
	Matrial(ambient, diffuse, specular, emission, shiniess);
	DrawSphere(-D, 0, 0, RADIUS);

	glutSwapBuffers();
}

void OnReShape(GLint w, GLint h)
{
	const GLdouble LENGTH = 10;

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
	const GLdouble LENGTH = 10;
	const GLdouble DISTANCE = 20;
	const GLdouble n = DISTANCE / 2, f = DISTANCE + LENGTH / 2;

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glTranslatef(0, 0, DISTANCE);

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

void OnReShape_Perspective(GLint w, GLint h)
{
	const double LENGTH = 10;

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glTranslatef(0, 0, 1);
	gluPerspective(180, 4.0 / 3.0, 0.03, 100);
	/*if (w < h)
	{
		gluPerspective(180, 4.0 / 3.0, 0, 100);
		glOrtho(-LENGTH, LENGTH, -LENGTH * h / w, LENGTH * h / w, -LENGTH, LENGTH);
	}
	else
	{
		glOrtho(-LENGTH * w / h, LENGTH * w / h, -LENGTH, LENGTH, -LENGTH, LENGTH);
	}*/
	glMatrixMode(GL_MODELVIEW);
}

void Init()
{
	glPointSize(3);
	glLineWidth(2);

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	const GLfloat ambient[4] = { 0,0,0,1 };	//环境光
	const GLfloat diffuse[4] = { 1,1,1,1 };	//漫反射
	const GLfloat specular[4] = { 1,0,0,1 };	//镜面反射
	const GLfloat position[4] = { -1,1,1,0 };
	const GLfloat direction[3] = { 1,-1,-1 };
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

	//glMaterialfv(GL_SHININESS)
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

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			for (int k = 0; k < 2; ++k)
			{
				for (int l = 0; l < 2; ++l)
				{
					printf("%d %d %d %d\n", i, j, k, l);
				}
			}
		}
	}

	glutMainLoop();
}