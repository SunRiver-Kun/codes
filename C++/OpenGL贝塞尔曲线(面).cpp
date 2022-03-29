#include <GL/freeglut.h>

//����������
GLfloat points[4][3] = {
	{0,0},
	{1,1},
	{2,1},
	{3,0}
};

//����������
GLfloat points_surface[4][4][3] = {
	{{-1.5,-1.5,2.0},{-0.5,-1.5,2.0},{0.5,-1.5,-1.0},{1.5,-1.5,2.0}},
	{{-1.5,-0.5,1.0},{-0.5,1.5,2.0},{0.5,0.5,1.0},{1.5,-0.5,-1.0}},
	{{-1.5,0.5,2.0},{-0.5,0.5,1.0},{0.5,0.5,3.0},{1.5,-1.5,1.5}},
	{{-1.5,1.5,-2.0},{-0.5,1.5,-2.0},{0.5,0.5,1.0},{1.5,1.5,-1.0}}
};

void DrawBezierCurve()
{
	const int precision = 40;
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= precision; ++i)
	{
		glEvalCoord1f((GLfloat)i / (GLfloat)precision);
	}
	glEnd();
}

void DrawCurvePoints()
{
	glBegin(GL_POINTS);
	for (int i = 0; i < 4; ++i)
	{
		glVertex3fv(points[i]);
	}
	glEnd();
}

void DrawBezierSurface()
{
	const int precision_i = 8;	//Խ���϶ԽС
	const int precision_j = 30;	//Խ��ÿ����Խƽ��

	for (int i = 0; i <= precision_i; ++i)
	{
		//����
		glBegin(GL_LINE_STRIP);
		for (int j = 0; j <= precision_j; ++j)
		{
			glEvalCoord2f((GLfloat)i / precision_i, (GLfloat)j / precision_j);
		}
		glEnd();

		//����
		glBegin(GL_LINE_STRIP);
		for (int j = 0; j <= precision_j; ++j)
		{
			glEvalCoord2f((GLfloat)j / precision_j, (GLfloat)i / precision_i);
		}
		glEnd();
	}
}

void DrawSurfacePoints()
{
	glBegin(GL_POINTS);
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			glVertex3fv(points_surface[i][j]);
		}
	}
	glEnd();
}

void OnDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//������������
	glLoadIdentity();
	glTranslatef(-5, 0, 0);
	DrawBezierCurve();
	DrawCurvePoints();

	glLoadIdentity();
	glTranslatef(3, 0, 0);
	DrawBezierSurface();
	glColor3f(1, 0, 0);
	DrawSurfacePoints();
	glColor3f(1, 1, 1);
	glFlush();
}

void OnReShape(GLint w, GLint h)
{
	const double LENGTH = 5;
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

void Init()
{
	glEnable(GL_MAP1_VERTEX_3);
	glEnable(GL_MAP2_VERTEX_3);
	//zֱ��Ĭ��Ϊ0
	//GL_MAP1_VERTEX_3��Ӧ�����glEnable��3ά
	//0~1�Ǻ���ȡֵ�ķ�Χ
	//3�ǵ��ά��
	//4�ǵ�ĸ���
	glMap1f(GL_MAP1_VERTEX_3, 0, 1, 3, 4, *points);
	glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 4 * 3, 4, **points_surface);

	glPointSize(3);
	glLineWidth(2);
}

int main(int argn, char* argv[])
{
	glutInit(&argn, argv);
	//glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(600, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Hello World");
	Init();
	glutReshapeFunc(OnReShape);
	glutDisplayFunc(OnDisplay);

	glutMainLoop();
}