#include <iostream>
#include <cmath>
using namespace std;

typedef float(*Func)(float x);

float SliceArea(Func fn, float x1, float x2, float max_error)
{
	//����˵���м�ֵ
	float y1 = fn(x1);
	float y2 = fn(x2);
	float xm = (x1 + x2) / 2;
	float ym = fn(xm);

	//�������Ƭ���������С��Ƭ������������ = (�ϵ�+�µ�)*��/2
	float area12 = (y1 + y2) * (x2 - x1) / 2;
	float area1m = (y1 + ym) * (xm - x1) / 2;
	float aream2 = (ym + y2) * (x2 - xm) / 2;
	float area1m2 = area1m + aream2;

	float error = fabs((area1m2 - area12) / area12);
	return error < max_error ? area1m2 : SliceArea(fn, x1, xm, max_error) + SliceArea(fn, xm, x2, max_error);
}

//����Ӧ���
//num_interavals: �ָ�ɶ��ٿ��С�������
float IntegrateAdaptiveMidpoint(Func fn, float xmin, float xmax, float max_error, int num_interavals)
{
	float dx = (xmax - xmin) / num_interavals;
	float sum = 0;

	for (int i = 0; i < num_interavals; ++i)
	{
		sum += SliceArea(fn, xmin, xmin + dx, max_error);
		xmin += dx;
	}
	return sum;
}

float fn(float x)
{
	return 1 + x + sin(2 * x);
}

int main()
{
	cout << fixed;
	cout.precision(10);
	float cal = IntegrateAdaptiveMidpoint(fn, 0, 5, 0.01, 24);
	float tr = 18 - 0.5 * cos(10);
	cout << "ca: " << cal << endl;
	cout << "tr: " << tr << endl;
	cout << "er: " << fabs((cal - tr) / tr) << endl;
	system("pause");
}