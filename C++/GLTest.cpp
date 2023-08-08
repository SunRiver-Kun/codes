#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <vector>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

struct Texture
{
	GLuint handle;
	GLint width, height, num_channels;
	const char* filename;
};
std::vector<Texture> textures;

void Matrial(const GLfloat* ambient, const GLfloat* diffuse, const GLfloat* specular, const GLfloat* emission, GLfloat shininess)
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_EMISSION, emission);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}

Texture LoadTexture(const char* filename)
{
	Texture texture;
	texture.filename = filename;
	glGenTextures(1, &texture.handle);
	glBindTexture(GL_TEXTURE_2D, texture.handle);
	// 为当前绑定的纹理对象设置环绕、过滤方式
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//纹理映射方法
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	// 加载并生成纹理
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(filename, &texture.width, &texture.height, &texture.num_channels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, 3, texture.width, texture.height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		//glGenerateMipmap(GL_TEXTURE_2D);
		textures.push_back(texture);
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
	const int pointsize = sizeof(double[2]);
	//上顶点 1 6 5 4 3
	double uppoints[][2] = {
		{4382.09,6150.82},
		{4533.84,6333.70},
		{4785.69,6347.30},
		{4912.10,6511.60},
		{5056.06,6215.76}
	};
	const int num_up = sizeof(uppoints) / pointsize;

	//下顶点 1 2 3
	double downpoints[][2] = {
		{4382.09,6150.82},
		{4770.93,6063.90},
		{5056.06,6215.76}
	};
	const int num_down = sizeof(downpoints) / pointsize;

	double up = 7000, down = 6000;
	double x1 = 4672.5;
	double x2 = 4847.8;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(-uppoints[0][0], -uppoints[0][1], 0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < num_up; ++i)
	{
		glVertex2dv(uppoints[i]);
	}
	glEnd();
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < num_down; ++i)
	{
		glVertex2dv(downpoints[i]);
	}
	glEnd();
	glBegin(GL_LINES);
	glVertex2d(x1, up);
	glVertex2d(x1, down);
	glVertex2d(x2, up);
	glVertex2d(x2, down);

	glEnd();

	glutSwapBuffers();
}

void OnReShape(GLint w, GLint h)
{
	const GLdouble LENGTH = 400;

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

	/*
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
	//*/
	//glEnable(GL_TEXTURE_2D);
	//LoadTexture("haha.png");
}

void OnKeyboard(GLubyte key, GLint x, GLint y)
{
	glutExit();
}

GLfloat mouseX = 0, mouseY = 0;
GLboolean isdrag = GL_FALSE, isscale = GL_FALSE;

void OnMouse(GLint mouse, GLint state, GLint x, GLint y)
{
	if (state == GLUT_DOWN)
	{
		mouseX = x;
		mouseY = y;
	}

	if (mouse == GLUT_LEFT_BUTTON)
	{
		isdrag = state == GLUT_DOWN;
	}
	else if (mouse == GLUT_RIGHT_BUTTON)
	{
		isscale = state == GLUT_DOWN;
	}
}

void OnMotion(GLint x, GLint y)
{
	glMatrixMode(GL_PROJECTION);
	if (isdrag)
	{
		float speed = 10;
		glTranslatef(speed * (x - mouseX), speed * (mouseY - y), 0);
	}
	if (isscale)
	{
		float scale = x > mouseX ? 1.2 : 0.8;
		glScalef(scale, scale, scale);
	}

	mouseX = x;
	mouseY = y;
	glutPostRedisplay();
	glMatrixMode(GL_MODELVIEW);
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
	glutMouseFunc(OnMouse);
	glutMotionFunc(OnMotion);
	glutMainLoop();
}