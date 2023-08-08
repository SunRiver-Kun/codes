#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#define Find(FnName,type,key)   \
vector< vector<Employee>::iterator > FnName() \
{\
cout << "������"<<#key<<endl; \
type choice; \
cin>> choice; \
vector< vector<Employee>::iterator > ans;\
vector<Employee>::iterator it = employees.begin();\
while (it != employees.end()) \
{\
if(it->key == choice) ans.push_back(it);\
++it;\
}\
cout<<"�������"<<endl;\
if(ans.size()==0){cout<<"δ�ҵ����Ա����Ϣ"<<endl;return ans;}\
cout << "��ʾԱ����Ϣ��" << endl << "-----------------------------" << endl;\
int i = 0;\
for (const auto& v : ans)\
{  cout <<"��ţ�"<<i++\
	    << " ���ţ�" << v->num << " ְ��" << v->duty << " ������" << v->name << " �Ա�" << v->age\
		<< " ���䣺" << v->age << " �Ļ��̶ȣ�" << v->edu << " ���ʣ�" << v->salary << " �칫�绰��" << v->tel_office\
		<< " ��ͥ�绰��" << v->tel_office << " �ƶ��绰��" << v->mobile << " QQ��" << v->qq << " ��ַ��" << v->address << endl;\
}\
cout << "-----------------------------" << endl << "��ʾ���" << endl;\
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
		cout << "�������" << employees.size() + 1 << "��Ա������Ϣ��" << endl
			<< "-----------------------------" << endl;
		cout << "���ţ�";
		cin >> temp.num;
		cout << "ְ��";
		cin >> temp.duty;
		cout << "������";
		cin >> temp.name;
		cout << "�Ա�";
		cin >> temp.sex;
		cout << "���䣺";
		cin >> temp.age;
		cout << "�Ļ��̶ȣ�";
		cin >> temp.edu;
		cout << "���ʣ�";
		cin >> temp.salary;
		cout << "�칫�绰��";
		cin >> temp.tel_office;
		cout << "��ͥ�绰��";
		cin >> temp.tel_home;
		cout << "�ƶ��绰��";
		cin >> temp.mobile;
		cout << "QQ��";
		cin >> temp.qq;
		cout << "��ͥ��ַ��";
		cin >> temp.address;

		employees.push_back(temp);
		cout << "�Ƿ�������룿y/n" << endl;
		cin >> flag;
	}
	cout << "������ϣ���ʼ¼�����ݿ�..." << endl;
	//��¼���д��
	ofstream fout(filepath, ios::app | ios::binary);
	for (auto& v : employees)
	{
		fout.write((const char*)&v, sizeof(Employee));  //sizeof(v) == sizeof(Employee)
	}
	fout.close();
	cout << "¼����ϣ�" << endl << endl;
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
	cout << "��ʾԱ����Ϣ��" << endl << "-----------------------------" << endl;
	for (auto& v : employees)
	{
		cout << "���ţ�" << v.num << " ְ��" << v.duty << " ������" << v.name << " �Ա�" << v.age
			<< " ���䣺" << v.age << " �Ļ��̶ȣ�" << v.edu << " ���ʣ�" << v.salary << " �칫�绰��" << v.tel_office
			<< " ��ͥ�绰��" << v.tel_office << " �ƶ��绰��" << v.mobile << " QQ��" << v.qq << " ��ַ��" << v.address << endl;
	}
	cout << "-----------------------------" << endl << "��ʾ���" << endl;
}

void FindEmployee()
{
	while (true)
	{
		cls();
		cout << "1.ͨ�����ֲ���" << endl
			<< "2.ͨ�����Ų���" << endl
			<< "3.�˳�����" << endl
			<< "������ѡ��";
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
		cout << "1.ͨ������ɾ��" << endl
			<< "2.ͨ������ɾ��" << endl
			<< "3.��ʾȫ��Ա����Ϣ" << endl
			<< "4.�˳�ɾ��" << endl
			<< "������ѡ��";
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
		cout << "�Ƿ�ɾ����y/n" << endl;
		cin >> choice;
		if (choice == 'y') { employees.erase(its.front()); }
		break;
	default:
		cout << "ȫ��ɾ��|�����ɾ��|��ɾ����y/m/n" << endl;
		cin >> choice;
		if (choice == 'y') { for (auto& it : its) employees.erase(it); }
		else if (choice == 'm') { int index = 0; cout << "�������ţ�"; cin >> index; employees.erase(its[index]); }
		else { cout << "��ȡ��ɾ��" << endl; }
		break;
	}
	cout << "ɾ�����" << endl;
}

void StartMenu()
{
	LoadEmployees();
	bool save = false;
	while (true)
	{
		cls();
		cout << "��ӭʹ�ñ���ҵԱ������ϵͳ" << endl;
		cout << "1.��ʾԱ����Ϣ" << endl
			<< "2.���Ա����Ϣ" << endl
			<< "3.����Ա����Ϣ" << endl
			<< "4.ɾ��Ա����Ϣ" << endl
			<< "5.�˳�ϵͳ" << endl;
		cout << "�������Ӧ���ܵı�ţ�";
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
			if (!employees.size()) { cout << "����Ϣ���޷�ɾ��" << endl; continue; }
			DeleteEmployee();
			save = true;
			break;
		default:
			cout << "��ӭ�´�ʹ��" << endl;
			if (save) { SaveInfo(); }
			pause();
			exit(EXIT_SUCCESS);
			break;
		}
		pause();
	}
}