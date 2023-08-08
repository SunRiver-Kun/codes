#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Angle
{
public:
	Angle(double degree = 0, double min = 0, double sec = 0) { m_sec = degree * 3600 + min * 60 + sec; }
	double degree()const { return int(m_sec / 3600.0); }
	double min()const { return int((m_sec - sec()) / 60.0) % 60; }
	double sec()const { int integer = (int)m_sec; return integer % 60 + (m_sec - integer); }
	double data()const { return m_sec; }
	Angle operator+(const Angle& other)const { return Angle(0, 0, m_sec + other.m_sec); }
	Angle operator-(const Angle& other)const { return Angle(0, 0, m_sec - other.m_sec); }
	Angle operator*(double b)const { return Angle(0, 0, m_sec * b); }
	friend Angle operator*(double b, const Angle& a) { return Angle(0, 0, a.data() * b); }
	Angle operator/(double b) const { return Angle(0, 0, m_sec / b); }
	bool operator<(const Angle& other) { return m_sec < other.m_sec; }
	bool operator==(const Angle& other) { return m_sec == other.m_sec; }
	string ToString()const { string str = output(fabs(degree())) + "°" + output(fabs(min())) + "'" + output(fabs(sec())) + "\""; return m_sec < 0 ? " -" + str : str; }
	friend ostream& operator<<(ostream& os, const Angle& a) { os << a.ToString(); return os; }
private:
	double m_sec;
	static string output(double a) { return fabs(a - int(a)) < 1E-11 ? to_string(int(a)) : to_string(a); }
};

Angle Input(string mes = "")
{
	cout << mes;
	int a;
	cin >> a;
	int sec = a % 100;
	int min = (a / 100) % 100;
	int deg = a / 10000;
	return Angle(deg, min, sec);
}

void Cal_HA()
{
	Angle bl = Input("BL：");
	Angle br = Input("BR：");
	Angle fl = Input("FL：");
	Angle fr = Input("FR：");
	if (fl < bl) { fl = fl + Angle(360); }
	if (fr < br) { fr = fr + Angle(360); }
	Angle a1 = fl - bl;
	Angle a2 = fr - br;

	cout << "BL=" << bl << "\nFL=" << fl << "\nBR=" << br << "\nFR=" << fr << endl;
	cout << "FL-BL=" << a1 << "\nFR-BR=" << a2 << "\n平均：" << (a1 + a2) / 2 << "\n相差：" << a2 - a1 << endl;

	Angle bl2 = Input("\nBL2：");
	Angle br2 = Input("BR2：");
	Angle fl2 = Input("FL2：");
	Angle fr2 = Input("FR2：");
	if (fl2 < bl2) { fl2 = fl2 + Angle(360); }
	if (fr2 < br2) { fr2 = fr2 + Angle(360); }
	Angle a12 = fl2 - bl2;
	Angle a22 = fr2 - br2;
	cout << "BL2=" << bl2 << "\nFL2=" << fl2 << "\nBR2=" << br2 << "\nFR2=" << fr2 << endl;
	cout << "FL-BL=" << a12 << "\nFR-BR=" << a22 << "\n平均：" << (a12 + a22) / 2 << "\n相差：" << a22 - a12 << endl;

	cout << "平均差：" << (a12 + a22) / 2 - (a1 + a2) / 2 << endl << endl;
}

void _cal_va_helper(string mes1, string mes2)
{
	Angle bl = Input(mes1 + "：");
	Angle br = Input(mes2 + "：");
	Angle limit = (bl + br - Angle(360)) / 2;
	Angle a1 = bl - Angle(90);
	Angle a2 = br - Angle(270);
	cout << mes1 + "=" << bl << "\n" + mes2 + "=" << br << endl;
	cout << "竖直角L=" << a1 << "\n竖直角R=" << a2 << "\n平均=" << (a1 + a2) / 2 << "\n指标差=" << limit << endl << endl;
}
void Cal_VA()
{
	_cal_va_helper("BL", "BR");
	_cal_va_helper("FL", "FR");
	_cal_va_helper("BL2", "BR2");
	_cal_va_helper("FL2", "FR2");
}

int main()
{
	cout << "输入格式：前0可省，不为不可\n240°04′30″→2400430\n0°40′03″→4003\n0°0′03″→ 3\n" << endl;
	int choose;
	while (true)
	{
		cout << "1.计算水平角\n";
		cout << "2.计算竖直角\n";
		cout << "请选择：";
		cin >> choose;
		switch (choose)
		{
			case 1:
				cout << "=====水平角=====\n";
				Cal_HA();
				break;
			case 2:
				cout << "=====竖直角=====\n";
				Cal_VA();
				break;
			default:
				return 0;
		}
	}
}