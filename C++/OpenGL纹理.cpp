#include <GL/freeglut.h>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void Matrial(const GLfloat* ambient, const GLfloat* diffuse, const GLfloat* specular, const GLfloat* emission, GLfloat shininess)
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_EMISSION, emission);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}

GLuint LoadTexture(const char* filename)
{
	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	// 为当前绑定的纹理对象设置环绕、过滤方式
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//纹理映射方法
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	// 加载并生成纹理
	int width, height, nrChannels;
	unsigned char* data = stbi_load(filename, &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		//glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
	return texture;
}

void OnDisplay()
{
	const GLfloat LENGTH = 900;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex2f(0, 0);
	glTexCoord2f(1, 0); glVertex2f(LENGTH, 0);
	glTexCoord2f(1, 1); glVertex2f(LENGTH, LENGTH);
	glTexCoord2f(0, 1); glVertex2f(0, LENGTH);
	glEnd();
	glutSwapBuffers();
}

void OnReShape(GLint w, GLint h)
{
	const GLdouble LENGTH = 1600;

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

	glEnable(GL_TEXTURE_2D);
	LoadTexture("texture.jpg");
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