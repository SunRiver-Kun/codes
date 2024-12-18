#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <Windows.h>

//浮点数最大误差
#define MAX_ERROR 1E-7

//使value保持在min和max之间
double clamp(double value, double min, double max)
{
	if (value < min) { return min; }
	if (value > max) { return max; }
	return value;
}

//折线函数，本程序中x是横坐标
double GetLinearValue(const double points[][2], int num_points, double x)
{
	assert(points != NULL && num_points > 1);
	if (x < points[0][0] || x > points[num_points - 1][0]) { return 0; }	//不在折线的定义域
	int i = 1;
	while (points[i][0] < x) { ++i; }	//找到第一个大于等于x值的顶点
	//y = y0 + (x-x0) * k
	return points[i][1] + (x - points[i][0]) * (points[i][1] - points[i - 1][1]) / (points[i][0] - points[i - 1][0]);
}

//折线函数的定积分
double AreaOfLinearFn(const double points[][2], int num_points, double begin, double end)
{
	//begin end
	//begin | end
	//begin || end
	//begin ||| end

	assert(points != NULL && num_points > 1 && begin <= end);
	begin = clamp(begin, points[0][0], points[num_points - 1][0]);
	end = clamp(end, points[0][0], points[num_points - 1][0]);

	if (begin >= end) { return 0; }	//[begin,end)全部不在定义域时
	int i = 0;
	while (points[i][0] < begin) { ++i; } //第一个大于等于begin的顶点
	if (points[i][0] >= end) { return (GetLinearValue(points, num_points, begin) + GetLinearValue(points, num_points, end)) * (end - begin) / 2; }	//begin,end直接没点
	double sum = (GetLinearValue(points, num_points, begin) + points[i][1]) * (points[i][0] - begin) / 2;	//开头
	//中间
	while (i < num_points - 1 && points[i + 1][0] < end)
	{
		sum += (points[i][1] + points[i + 1][1]) * (points[i + 1][0] - points[i][0]) / 2;
		++i;
	}
	//结尾
	sum += (points[i][1] + GetLinearValue(points, num_points, end)) * (end - points[i][0]) / 2;

	return sum;
}

//求n平分的平分点，类二分查找，通用，O(nlgn)
void GetDivisionPoints(const double uppoints[][2], int num_up, const double downpoints[][2], int num_down, int n, double divisionpoints[][2])
{
	assert(n > 1);
	double begin = uppoints[0][0], end = uppoints[num_up - 1][0];	//以uppoints的起末横坐标作总的分割线
	double target = (AreaOfLinearFn(uppoints, num_up, begin, end) - AreaOfLinearFn(downpoints, num_down, begin, end)) / n;
	double lastbegin = begin;

	for (int i = 1; i < n; ++i)
	{
		begin = lastbegin;
		end = uppoints[num_up - 1][0];
		//类二分查找，适用于全部的曲线
		while (begin < end)
		{
			double mid = (begin + end) / 2;
			//从lastbegin到mid的面积
			double area = AreaOfLinearFn(uppoints, num_up, lastbegin, mid) - AreaOfLinearFn(downpoints, num_down, lastbegin, mid);
			if (fabs(area - target) < MAX_ERROR)
			{
				//上面点的坐标
				**divisionpoints = mid;
				*(*divisionpoints + 1) = GetLinearValue(uppoints, num_up, mid);
				++divisionpoints;
				//下面点的坐标
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
		{4770.93,6036.90},
		{5056.06,6215.76}
	};
	const int num_down = sizeof(downpoints) / pointsize;

	printf("请输入要等分多少段：n>=2\n");
	int n = 3;
	scanf("%d", &n);
	assert(n > 1);
	double divisionpoints[300][2];	/*（n - 1） * 2个点，改n的时候记得把4改了 */

	GetDivisionPoints(uppoints, num_up, downpoints, num_down, n, divisionpoints);

	printf("输出坐标：（x，y），x指北\n");
	if (n == 3)
	{
		printf("P点坐标：(%lf,%lf)\n", divisionpoints[0][1], divisionpoints[0][0]);
		printf("Q点坐标：(%lf,%lf)\n", divisionpoints[1][1], divisionpoints[1][0]);
		printf("R点坐标：(%lf,%lf)\n", divisionpoints[2][1], divisionpoints[2][0]);
		printf("S点坐标：(%lf,%lf)\n", divisionpoints[3][1], divisionpoints[3][0]);
	}
	else
	{
		for (int i = 0; i < 2 * (n - 1); ++i)
		{
			printf("%d点坐标：(%lf,%lf)\n", i + 1, divisionpoints[i][1], divisionpoints[i][0]);
		}
	}

	printf("\n总面积：%lf\n", AreaOfLinearFn(uppoints, num_up, uppoints[0][0], uppoints[num_up - 1][0]) - AreaOfLinearFn(downpoints, num_down, uppoints[0][0], uppoints[num_up - 1][0]));
	printf("输出%d段的面积：\n", n);
	printf("1\t%lf\n", AreaOfLinearFn(uppoints, num_up, uppoints[0][0], divisionpoints[0][0]) - AreaOfLinearFn(downpoints, num_down, uppoints[0][0], divisionpoints[0][0]));
	for (int i = 2; i < 2 * (n - 1); i += 2)
	{
		printf("%d\t%lf\n", 1 + i / 2, AreaOfLinearFn(uppoints, num_up, divisionpoints[i - 2][0], divisionpoints[i][0]) - AreaOfLinearFn(downpoints, num_down, divisionpoints[i - 2][0], divisionpoints[i][0]));
	}
	printf("%d\t%lf\n", n, AreaOfLinearFn(uppoints, num_up, divisionpoints[2 * (n - 1) - 1][0], uppoints[num_up - 1][0]) - AreaOfLinearFn(downpoints, num_down, divisionpoints[2 * (n - 1) - 1][0], uppoints[num_up - 1][0]));
	system("pause");
}