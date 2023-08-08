#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <Windows.h>

//������������
#define MAX_ERROR 1E-7

//ʹvalue������min��max֮��
double clamp(double value, double min, double max)
{
	if (value < min) { return min; }
	if (value > max) { return max; }
	return value;
}

//���ߺ�������������x�Ǻ�����
double GetLinearValue(const double points[][2], int num_points, double x)
{
	assert(points != NULL && num_points > 1);
	if (x < points[0][0] || x > points[num_points - 1][0]) { return 0; }	//�������ߵĶ�����
	int i = 1;
	while (points[i][0] < x) { ++i; }	//�ҵ���һ�����ڵ���xֵ�Ķ���
	//y = y0 + (x-x0) * k
	return points[i][1] + (x - points[i][0]) * (points[i][1] - points[i - 1][1]) / (points[i][0] - points[i - 1][0]);
}

//���ߺ����Ķ�����
double AreaOfLinearFn(const double points[][2], int num_points, double begin, double end)
{
	//begin end
	//begin | end
	//begin || end
	//begin ||| end

	assert(points != NULL && num_points > 1 && begin <= end);
	begin = clamp(begin, points[0][0], points[num_points - 1][0]);
	end = clamp(end, points[0][0], points[num_points - 1][0]);

	if (begin >= end) { return 0; }	//[begin,end)ȫ�����ڶ�����ʱ
	int i = 0;
	while (points[i][0] < begin) { ++i; } //��һ�����ڵ���begin�Ķ���
	if (points[i][0] >= end) { return (GetLinearValue(points, num_points, begin) + GetLinearValue(points, num_points, end)) * (end - begin) / 2; }	//begin,endֱ��û��
	double sum = (GetLinearValue(points, num_points, begin) + points[i][1]) * (points[i][0] - begin) / 2;	//��ͷ
	//�м�
	while (i < num_points - 1 && points[i + 1][0] < end)
	{
		sum += (points[i][1] + points[i + 1][1]) * (points[i + 1][0] - points[i][0]) / 2;
		++i;
	}
	//��β
	sum += (points[i][1] + GetLinearValue(points, num_points, end)) * (end - points[i][0]) / 2;

	return sum;
}

//��nƽ�ֵ�ƽ�ֵ㣬����ֲ��ң�ͨ�ã�O(nlgn)
void GetDivisionPoints(const double uppoints[][2], int num_up, const double downpoints[][2], int num_down, int n, double divisionpoints[][2])
{
	assert(n > 1);
	double begin = uppoints[0][0], end = uppoints[num_up - 1][0];	//��uppoints����ĩ���������ܵķָ���
	double target = (AreaOfLinearFn(uppoints, num_up, begin, end) - AreaOfLinearFn(downpoints, num_down, begin, end)) / n;
	double lastbegin = begin;

	for (int i = 1; i < n; ++i)
	{
		begin = lastbegin;
		end = uppoints[num_up - 1][0];
		//����ֲ��ң�������ȫ��������
		while (begin < end)
		{
			double mid = (begin + end) / 2;
			//��lastbegin��mid�����
			double area = AreaOfLinearFn(uppoints, num_up, lastbegin, mid) - AreaOfLinearFn(downpoints, num_down, lastbegin, mid);
			if (fabs(area - target) < MAX_ERROR)
			{
				//����������
				**divisionpoints = mid;
				*(*divisionpoints + 1) = GetLinearValue(uppoints, num_up, mid);
				++divisionpoints;
				//����������
				**divisionpoints = mid;
				*(*divisionpoints + 1) = GetLinearValue(downpoints, num_down, mid);
				++divisionpoints;

				lastbegin = mid;
				break;
			}
			else if (area < target)
			{
				begin = mid;
			}
			else
			{
				end = mid;
			}
		}
	}
}

int main()
{
	const int pointsize = sizeof(double[2]);
	//�϶��� 1 6 5 4 3
	double uppoints[][2] = {
		{4382.09,6150.82},
		{4533.84,6333.70},
		{4785.69,6347.30},
		{4912.10,6511.60},
		{5056.06,6215.76}
	};
	const int num_up = sizeof(uppoints) / pointsize;

	//�¶��� 1 2 3
	double downpoints[][2] = {
		{4382.09,6150.82},
		{4770.93,6036.90},
		{5056.06,6215.76}
	};
	const int num_down = sizeof(downpoints) / pointsize;

	printf("������Ҫ�ȷֶ��ٶΣ�n>=2\n");
	int n = 3;
	scanf("%d", &n);
	assert(n > 1);
	double divisionpoints[300][2];	/*��n - 1�� * 2���㣬��n��ʱ��ǵð�4���� */

	GetDivisionPoints(uppoints, num_up, downpoints, num_down, n, divisionpoints);

	printf("������꣺��x��y����xָ��\n");
	if (n == 3)
	{
		printf("P�����꣺(%lf,%lf)\n", divisionpoints[0][1], divisionpoints[0][0]);
		printf("Q�����꣺(%lf,%lf)\n", divisionpoints[1][1], divisionpoints[1][0]);
		printf("R�����꣺(%lf,%lf)\n", divisionpoints[2][1], divisionpoints[2][0]);
		printf("S�����꣺(%lf,%lf)\n", divisionpoints[3][1], divisionpoints[3][0]);
	}
	else
	{
		for (int i = 0; i < 2 * (n - 1); ++i)
		{
			printf("%d�����꣺(%lf,%lf)\n", i + 1, divisionpoints[i][1], divisionpoints[i][0]);
		}
	}

	printf("\n�������%lf\n", AreaOfLinearFn(uppoints, num_up, uppoints[0][0], uppoints[num_up - 1][0]) - AreaOfLinearFn(downpoints, num_down, uppoints[0][0], uppoints[num_up - 1][0]));
	printf("���%d�ε������\n", n);
	printf("1\t%lf\n", AreaOfLinearFn(uppoints, num_up, uppoints[0][0], divisionpoints[0][0]) - AreaOfLinearFn(downpoints, num_down, uppoints[0][0], divisionpoints[0][0]));
	for (int i = 2; i < 2 * (n - 1); i += 2)
	{
		printf("%d\t%lf\n", 1 + i / 2, AreaOfLinearFn(uppoints, num_up, divisionpoints[i - 2][0], divisionpoints[i][0]) - AreaOfLinearFn(downpoints, num_down, divisionpoints[i - 2][0], divisionpoints[i][0]));
	}
	printf("%d\t%lf\n", n, AreaOfLinearFn(uppoints, num_up, divisionpoints[2 * (n - 1) - 1][0], uppoints[num_up - 1][0]) - AreaOfLinearFn(downpoints, num_down, divisionpoints[2 * (n - 1) - 1][0], uppoints[num_up - 1][0]));
	system("pause");
}