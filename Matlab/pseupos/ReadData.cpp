#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#define PEXIT(code) system("pause"); exit(code);
using namespace std;

struct Satellite
{
	string name;
	double x, y, z;
};

double pos_station[3];  //基站的位置，xyz
double pdistances[8];  //前8个卫星的伪距
map<int, Satellite> sats; //八颗卫星的索引和名字

void Read21o(string path);	//只读取GPS卫星,即G开头的
void Readsp3(string path);
void OutputData(string path);

int main()
{
	bool def_data = true;
	string path_21o = "gode0010.21o";
	string path_sp3 = "igs21386.sp3";

	cout << "是否使用默认数据？1是，0否" << endl;
	cin >> def_data;
	if (!def_data)
	{
		cout << "请输入21o文件的路径：";
		cin >> path_21o;
		cout << "请输入sp3文件的路径：";
		cin >> path_sp3;
	}
	Read21o(path_21o);
	Readsp3(path_sp3);
	OutputData("output.txt");	//与matlab交互的文件，这个路径改了，在 readdata.m 里的path也要改
	system("pause");
	return 0;
}

//读取伪距和基站位置
void Read21o(string path)
{
	ifstream fin(path);
	if (!fin.is_open()) { cout << "21o文件打开失败！\n"; PEXIT(EXIT_FAILURE) }
	char buffer[100] = "";
	double num_sats, num_types;  //卫星数量
	int index = -1; //伪距C1的index是多少
	bool flag_XYZ = true, flag_C1 = true;
	do
	{
		fin.getline(buffer, sizeof(buffer));  //会自动加'\0'

		//读取基站XYZ
		if (flag_XYZ && strstr(buffer, "XYZ"))
		{
			flag_XYZ = false;
			stringstream s;
			s << buffer;
			s >> pos_station[0] >> pos_station[1] >> pos_station[2];
		}

		//确认C1的位置
		if (flag_C1 && strstr(buffer, "C1"))
		{
			flag_C1 = false;
			char temp[3] = "";
			int i = -1;
			stringstream s;
			s << buffer;
			s >> num_types;
			do
			{
				s >> temp;
				++i;
			} while (strcmp(temp, "C1"));
			index = i;
		}
	} while (!strstr(buffer, "END OF HEADER"));  //一直读到  END OF HEADER 那行
	for (int i = 0; i < 7; ++i) { fin >> num_sats; }  //忽略多余参数
	fin >> num_sats;	//读取一共的卫星数
	if (num_sats < 8) { cout << "卫星数不够8颗！\n"; PEXIT(EXIT_FAILURE) }
	for (int i = 0; i < num_sats; ++i)
	{
		while (fin.peek() == ' ' || fin.peek() == '\n') { fin.read(buffer, 1); }	//忽略空格和换行
		fin.read(buffer, 3);
		if (sats.size() < 8 && buffer[0] == 'G')	//读取GPS卫星数据
		{
			Satellite s{ string(buffer,3),0,0,0 }; //XYZ之后确定
			sats.insert(make_pair(i, s));
		}
	}

	while (fin.peek() == ' ' || fin.peek() == '\n') { fin.read(buffer, 1); }	//忽略空格和换行
	for (int i = 0, j = 0; i < num_sats && j < 8; ++i)
	{
		//读取伪距，一颗卫星有2行数据
		stringstream s;
		fin.getline(buffer, sizeof(buffer));   s << buffer;
		fin.getline(buffer, sizeof(buffer));   s << buffer;

		auto sat = sats.find(i);	//是否是我们需要的卫星
		if (sat == sats.end()) { continue; }
		try
		{
			double temp;
			int k = 0;
			while (true)
			{
				s >> temp;
				if (temp < 10) { continue; }  //跳过小于10的数
				if (k++ == index)
				{
					pdistances[j++] = temp;
					break;
				}
			}
		}
		catch (...) {}
	}
}

//读取卫星位置
void Readsp3(string path)
{
	ifstream fin(path);
	if (!fin.is_open()) { cout << "21o文件打开失败！\n"; PEXIT(EXIT_FAILURE) }
	char buffer[100] = "";
	while (fin.peek() != 'P') { fin.getline(buffer, sizeof(buffer)); }
	size_t num = 0;
	while (num < sats.size())
	{
		fin.read(buffer, 1);  //忽略前面的P
		fin.getline(buffer, sizeof(buffer));
		stringstream s;
		s << buffer;
		string name;
		s >> name;
		for (auto& v : sats)
		{
			if (v.second.name == name)
			{
				++num;
				s >> v.second.x >> v.second.y >> v.second.z;
				v.second.x *= 1000;	//单位转为m
				v.second.y *= 1000;
				v.second.z *= 1000;
				break;
			}
		}
	}
}

void OutputData(string path)
{
	/*输出：
		基站X Y Z 0
		卫星X Y Z 伪距
		...
	*/
	ofstream fout(path);
	cout << "基站的XYZ：";
	for (auto& v : pos_station)
	{
		fout << v << ' ';
		cout << v << ' ';
	}
	fout << 0 << '\n';  cout << '\n';

	cout << "卫星名\t卫星X\tY\tZ\t伪距\t单位m" << endl;;
	int i = 0;
	for (auto& v : sats)
	{
		fout << v.second.x << ' ' << v.second.y << ' ' << v.second.z << ' ' << pdistances[i] << '\n';
		cout << v.second.name << ' ' << v.second.x << ' ' << v.second.y << ' ' << v.second.z << ' ' << pdistances[i] << '\n';
		++i;
	}
	cout << "数据输出成功！路径为：" << path << endl;
}