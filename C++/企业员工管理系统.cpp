#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#define Find(FnName,type,key)   \
vector< vector<Employee>::iterator > FnName() \
{\
cout << "请输入"<<#key<<endl; \
type choice; \
cin>> choice; \
vector< vector<Employee>::iterator > ans;\
vector<Employee>::iterator it = employees.begin();\
while (it != employees.end()) \
{\
if(it->key == choice) ans.push_back(it);\
++it;\
}\
cout<<"查找完毕"<<endl;\
if(ans.size()==0){cout<<"未找到相关员工信息"<<endl;return ans;}\
cout << "显示员工信息：" << endl << "-----------------------------" << endl;\
int i = 0;\
for (const auto& v : ans)\
{  cout <<"编号："<<i++\
	    << " 工号：" << v->num << " 职务：" << v->duty << " 姓名：" << v->name << " 性别：" << v->age\
		<< " 年龄：" << v->age << " 文化程度：" << v->edu << " 工资：" << v->salary << " 办公电话：" << v->tel_office\
		<< " 家庭电话：" << v->tel_office << " 移动电话：" << v->mobile << " QQ：" << v->qq << " 地址：" << v->address << endl;\
}\
cout << "-----------------------------" << endl << "显示完毕" << endl;\
return ans;\
}

constexpr const char* filepath = "Employees.dat";
struct Employee
{
	int  qq, num;
	size_t age;
	string name, duty, edu, salary, tel_office, tel_home, mobile, address, sex;
};

vector<Employee> employees;

void cls();
void pause();
void AddEmployee();
void LoadEmployees();
void SaveInfo();
void ShowEmployees();
Find(FindByName, string, name)
Find(FindByNum, int, num)
void FindEmployee();
void DeleteEmployee();
void DeleteEmployee(vector< vector<Employee>::iterator > its);
void StartMenu();

int main()
{
	StartMenu();
}

void cls() { system("cls"); }
void pause() { system("pause"); }

void AddEmployee()
{
	char flag = 'y';
	while (flag == 'y')
	{
		system("cls");
		Employee temp;
		cout << "请输入第" << employees.size() + 1 << "个员工的信息：" << endl
			<< "-----------------------------" << endl;
		cout << "工号：";
		cin >> temp.num;
		cout << "职务：";
		cin >> temp.duty;
		cout << "姓名：";
		cin >> temp.name;
		cout << "性别：";
		cin >> temp.sex;
		cout << "年龄：";
		cin >> temp.age;
		cout << "文化程度：";
		cin >> temp.edu;
		cout << "工资：";
		cin >> temp.salary;
		cout << "办公电话：";
		cin >> temp.tel_office;
		cout << "家庭电话：";
		cin >> temp.tel_home;
		cout << "移动电话：";
		cin >> temp.mobile;
		cout << "QQ：";
		cin >> temp.qq;
		cout << "家庭地址：";
		cin >> temp.address;

		employees.push_back(temp);
		cout << "是否继续输入？y/n" << endl;
		cin >> flag;
	}
	cout << "输入完毕，开始录入数据库..." << endl;
	//记录完就写入
	ofstream fout(filepath, ios::app | ios::binary);
	for (auto& v : employees)
	{
		fout.write((const char*)&v, sizeof(Employee));  //sizeof(v) == sizeof(Employee)
	}
	fout.close();
	cout << "录入完毕！" << endl << endl;
	pause();
}

void LoadEmployees()
{
	ifstream fin(filepath, ios::in | ios::binary);
	if (!fin.is_open()) { return; }
	while (EOF != fin.peek())
	{
		Employee* temp = new Employee;
		fin.read((char*)temp, sizeof(Employee));
		employees.push_back(*temp);
	}
}

void SaveInfo()
{
	ofstream fout(filepath, ios::out | ios::binary);
	for (auto& v : employees)
	{
		fout.write((const char*)&v, sizeof(Employee));
	}
}

void ShowEmployees()
{
	cout << "显示员工信息：" << endl << "-----------------------------" << endl;
	for (auto& v : employees)
	{
		cout << "工号：" << v.num << " 职务：" << v.duty << " 姓名：" << v.name << " 性别：" << v.age
			<< " 年龄：" << v.age << " 文化程度：" << v.edu << " 工资：" << v.salary << " 办公电话：" << v.tel_office
			<< " 家庭电话：" << v.tel_office << " 移动电话：" << v.mobile << " QQ：" << v.qq << " 地址：" << v.address << endl;
	}
	cout << "-----------------------------" << endl << "显示完毕" << endl;
}

void FindEmployee()
{
	while (true)
	{
		cls();
		cout << "1.通过名字查找" << endl
			<< "2.通过工号查找" << endl
			<< "3.退出查找" << endl
			<< "请输入选择：";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			FindByName();
			break;
		case 2:
			FindByNum();
			break;
		default:
			return;
		}
		pause();
	}
}

void DeleteEmployee()
{
	cls();
	while (true)
	{
		cout << "1.通过名字删除" << endl
			<< "2.通过工号删除" << endl
			<< "3.显示全部员工信息" << endl
			<< "4.退出删除" << endl
			<< "请输入选择：";
		int choice;
		cin >> choice;
		vector< vector<Employee>::iterator > its;
		switch (choice)
		{
		case 1:
			its = FindByName();
			DeleteEmployee(its);
			break;
		case 2:
			its = FindByNum();
			DeleteEmployee(its);
			break;
		case 3:
			ShowEmployees();
			cout << endl;
			continue;
			break;
		default:
			return;
		}
		pause();
		cls();
	}
}

void DeleteEmployee(vector< vector<Employee>::iterator > its)
{
	char choice = 'n';
	switch (its.size())
	{
	case 0:return;
	case 1:
		cout << "是否删除？y/n" << endl;
		cin >> choice;
		if (choice == 'y') { employees.erase(its.front()); }
		break;
	default:
		cout << "全部删除|按编号删除|不删除，y/m/n" << endl;
		cin >> choice;
		if (choice == 'y') { for (auto& it : its) employees.erase(it); }
		else if (choice == 'm') { int index = 0; cout << "请输入编号："; cin >> index; employees.erase(its[index]); }
		else { cout << "已取消删除" << endl; }
		break;
	}
	cout << "删除完毕" << endl;
}

void StartMenu()
{
	LoadEmployees();
	bool save = false;
	while (true)
	{
		cls();
		cout << "欢迎使用本企业员工管理系统" << endl;
		cout << "1.显示员工信息" << endl
			<< "2.添加员工信息" << endl
			<< "3.查找员工信息" << endl
			<< "4.删除员工信息" << endl
			<< "5.退出系统" << endl;
		cout << "请输入对应功能的编号：";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			ShowEmployees();
			break;
		case 2:
			AddEmployee();
			break;
		case 3:
			FindEmployee();
			break;
		case 4:
			if (!employees.size()) { cout << "无信息，无法删除" << endl; continue; }
			DeleteEmployee();
			save = true;
			break;
		default:
			cout << "欢迎下次使用" << endl;
			if (save) { SaveInfo(); }
			pause();
			exit(EXIT_SUCCESS);
			break;
		}
		pause();
	}
}