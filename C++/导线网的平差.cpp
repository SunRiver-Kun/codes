#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#define DEBUG

constexpr double DEG2RAD = M_PI / 180.0;
constexpr double RAD2DEG = 180.0 / M_PI;

using namespace std;

struct Data
{
	string name;
	double angle;
	double length, x, y;
};

vector<Data> ReadFile(const char* filename)
{
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("打开文件%s失败\n", filename);
		system("pause");
		exit(EXIT_FAILURE);
	}
	vector<Data> data;
	Data temp;
	double degree, min, sec;
	char str[100] = "";
	fgets(str, sizeof(str), fp);  //忽略第一行
	//导入已知点2个
	for (int i = 0; i < 2; ++i)
	{
		fscanf(fp, "%s%lf`%lf'%lf\"%lf%lf%lf", str, &degree, &min, &sec, &temp.length, &temp.x, &temp.y);
		temp.name.assign(str);
		temp.angle = (degree + min / 60.0 + sec / 3600.0) * DEG2RAD;
		data.push_back(temp);
	}
	while (fscanf(fp, "%s%lf`%lf'%lf\"%lf", str, &degree, &min, &sec, &temp.length) > 0)
	{
		temp.name.assign(str);
		temp.angle = (degree + min / 60.0 + sec / 3600.0) * DEG2RAD;
		data.push_back(temp);
	}

	data[0].length = sqrt((data[0].x - data[1].x) * (data[0].x - data[1].x) + (data[0].y - data[1].y) * (data[0].y - data[1].y));

	fclose(fp);
	return data;
}

void SaveFile(const char* filename, const vector<Data>& data)
{
	ofstream file(filename);
	for (auto& v : data)
	{
		file << v.name << '\t' << v.x << '\t' << v.y << '\n';
	}
	file.close();
}

void Calculate(vector<Data>& data)
{
	//角度闭合差
	double anglesum = 0;
	for (auto& v : data)
	{
		anglesum = anglesum + v.angle;
	}
	anglesum = anglesum - (data.size() - 2) * M_PI;

#ifdef DEBUG
	cout << "角度闭合差：" << anglesum * RAD2DEG << endl;
#endif // DEBUG

	anglesum = anglesum * (-1.0 / data.size());	 //改正数

#ifdef DEBUG
	cout << "角度改正数：" << anglesum * RAD2DEG << endl;
	cout << "改正后的角度/rad：\n";
#endif // DEBUG

	for (auto& v : data)
	{
		v.angle = v.angle + anglesum;
#ifdef DEBUG
		cout << v.name << '\t' << v.angle * RAD2DEG << endl;
#endif // DEBUG
	}

	//坐标方位角的计算
	data[0].angle = atan2(data[1].x - data[0].x, data[1].y - data[0].y);
	for (int i = 1; i < data.size(); ++i)
	{
		data[i].angle = data[i - 1].angle + M_PI - data[i].angle;
	}
#ifdef DEBUG
	cout << "\n坐标方位角：\n";
	for (auto& v : data)
	{
		cout << v.name << '\t' << v.angle * RAD2DEG << endl;
	}
#endif // DEBUG
	//x, y 近似坐标计算
	double sumS = data[0].length + data[1].length;
	for (int i = 2; i < data.size(); ++i)
	{
		data[i].x = data[i - 1].x + data[i - 1].length * sin(data[i - 1].angle);
		data[i].y = data[i - 1].y + data[i - 1].length * cos(data[i - 1].angle);
		sumS += data[i].length;
	}
	auto&& back = data.back();
	double errorX = back.x + back.length * sin(back.angle) - data[0].x;
	double errorY = back.y + back.length * cos(back.angle) - data[0].y;
#ifdef DEBUG
	cout << "\n各点近似坐标：\n";
	for (auto& v : data)
	{
		cout << v.name << "\t( " << v.x << ", " << v.y << " )" << endl;
	}
	cout << "坐标闭合差：" << errorX << '\t' << errorY << endl;
#endif // DEBUG
	for (int i = 2; i < data.size(); ++i)
	{
		data[i].x -= data[i].length * errorX / sumS;
		data[i].y -= data[i].length * errorY / sumS;
	}
#ifdef DEBUG
	cout << "改正后的坐标：\n";
	for (auto& v : data)
	{
		cout << v.name << "\t( " << v.x << ", " << v.y << " )" << endl;
	}
#endif // DEBUG
}

int main(int argn, const char** argv)
{
	string input, output;

	if (argn <= 1)
	{
		cout << "输入文件名：";
		cin >> input;
		cout << "输出文件名：";
		cin >> output;
	}
	else
	{
		input = argv[1];
		output = argn > 2 ? argv[2] : "out_" + input;
	}

	//小数输出设置
	cout << fixed;
	cout.precision(8);

	auto data = ReadFile(input.c_str());
#ifdef DEBUG

	cout << "点名	内角	边长	X	Y\n";
	for (int i = 0; i < 2; ++i)
	{
		auto&& v = data[i];
		cout << v.name << '\t' << v.angle * RAD2DEG << '\t' << v.length << '\t' << v.x << '\t' << v.y << "\t已知点" << endl;
	}
	for (int i = 2; i < data.size(); ++i)
	{
		auto&& v = data[i];
		cout << v.name << '\t' << v.angle * RAD2DEG << '\t' << v.length << endl;
	}
	cout << endl;
#endif // DEBUG

	Calculate(data);
	SaveFile(output.c_str(), data);
	system("pause");
}