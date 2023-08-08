#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include<cstdlib>
using namespace std;
//������ת��Ϊ�ַ���
string num2str(int i)
{
    stringstream s;
    s << i;
    return s.str();
}
//һ����ǰ����
class Company;
class Station;
class MidStation;
class Temp;

class MidStation
{//ȫ����תվ��Ϣ��ʹ������ú������
public:
    int num;
    Station *stations[99];//ָ�����飬stations[i]��ʾһ��Stationָ��
    Station *parent;//��ת��:  ��˾1��1000վ������˾2��1000վ������ߵ�parentΪǰ��
    MidStation() { num = 0; parent = NULL; }//����ʱ��ʼ��
};
class Station
{
public:
    Company *company; 
    MidStation midstations;
    string name;
    int index;
    Station(){ }
    //���������������������
    //��ʼ��midstations
    void GetAllMidStation(const string start,const string end, Company *coms,const int num_coms);
    //���midstations
    void ClearAllMidStation();
    //���ر���˾���Ϊname��Index,��������������һ��
    int GetMidStationIndex(string name);
    int GetStationIndex(string name);
};
class Company
{
public:
    string name;
    int num_stations;
    Station stations[100]; //ǰ������ж����˵�Station

    Company() { }
    //���벢��ʼ��Stations
    void SetStations(const int size)
    {
        num_stations = size;
        for (int i = 0; i < size; i++)
        {
            cin >> stations[i].name;
            stations[i].index = i;
            stations[i].company = this;
        }
    }
    //debug�ã���ʾȫ����Ϣ
    void ShowInfo()
    {
        cout << name << " " << num_stations << endl;
        for (int i = 0; i < num_stations; i++)
            cout << stations[i].name << " ";
        cout << endl;
    }
};

class Temp
{//����ֵ�ļ���
public:
    bool IsExist;
    string path;
    int num_pass;
    Temp(bool IsExist=false,string path="",int num_pass=-1)
    {
        this->IsExist = IsExist;
        this->num_pass = num_pass;
        this->path = path;
    }
};

//��com��˾����name�ĳ�վ
Station *GetStation(string name,Company &com)
{
    for (int i = 0; i < com.num_stations; i++)
        if (name == com.stations[i].name)
            return &(com.stations[i]);
    return NULL;
}
Station *GetStation(string name,Company *com)
{
    for (int i = 0; i < com->num_stations; i++)
        if (name == com->stations[i].name)
            return &(com->stations[i]);
    return NULL;
}

/*!
Search:��Ѱ�̶������㵽Ŀ�ĵص����·��
begin:�ݹ��õĲ�������ʾ��ǰ��վ
start,end,coms,num_coms�ڵݹ��в���ı�
start:�����������
end:Ŀ�ĵص�����
coms��Company����
num_coms:Company������Ԫ�صĸ���
Ϊʲô��ָ�룿��Ȼ��
*/

Temp Search(Station *begin,const string start,const string end,Company *coms,const int num_coms)
{//��ʼ��midstations
    begin->GetAllMidStation(start,end,coms,num_coms);
    if (begin->midstations.num == 0) // û����תվ
    {
        if (GetStation(end,begin->company)==NULL)  //�޷��ﵽĿ�ĵ�
            return Temp(false,"",-1);
        else
        {
            string path = "Go by the line of company #" + begin->company->name + " from " + begin->name + " to " + end + ".\n";
            return Temp(true,path,abs(begin->index - begin->GetStationIndex(end)));
        }
    }
    else
    {
        Temp best(false,"",-1);
        if (GetStation(end,begin->company))
        {
            string path_direct = "Go by the line of company #" + begin->company->name + " from " + begin->name + " to " + end + ".\n";
            best = Temp(true,path_direct,abs(begin->index - begin->GetStationIndex(end)));//go directly
        }
        for (int i = 0; i < begin->midstations.num; i++)  //����������תվ
        {
            Temp temp = Search(begin->midstations.stations[i],start,end,coms,num_coms);
            if (temp.IsExist)  //��תվ���Ե�Ŀ�ĵ�
            {
                string name = begin->midstations.stations[i]->name;
                int index = begin->GetMidStationIndex(name);
                int num_pass = temp.num_pass + abs(begin->index - index);
                string path = "Go by the line of company #" + begin->company->name + " from " + begin->name + " to " + name + ".\n" + temp.path;
                //�Ƚ�
                if (best.IsExist == false)
                {
                    best = Temp(true,path,num_pass);
                }
                else
                {
                    if (num_pass <= best.num_pass)
                    {   //��վ�ٵ����ȣ�����һ��ʱ��ת�ٵ�����(path��)
                        if (num_pass < best.num_pass || path.length() < best.path.length())
                            best = Temp(true,path,num_pass);
                    }
                }
            }
        }
        return best;
    }
}
/*/debug
void ShowPath(Station *begin)
{
if(begin->midstations.parent)
cout <<"parent: "<<begin->midstations.parent->company->name << " " << begin->midstations.parent->name << endl;
cout << "now: " << begin->company->name << " " << begin->name << endl;
cout << "childe: " << endl;
for (int i = 0; i < begin->midstations.num; i++)
cout << begin->midstations.stations[i]->company->name << " " << begin->midstations.stations[i]->name << endl;
cout << "------------------------------" << endl;
}

//debug*/
int main()
{
    int num_coms,num_stas,num_customers;
    string start,end;

    cin >> num_coms;
    Company *coms = new Company[num_coms];
    for (int i = 0; i < num_coms; i++)
    {  //��ʼ�����й�˾��վ�����������
        coms[i].name = num2str(i+1);
        cin >> num_stas;
        coms[i].SetStations(num_stas);
    }

    cin >> num_customers;
    for (int i = 0; i < num_customers; i++)
    { 
        cin >> start >> end;  //��string���Զ����Կո�,\n,����� 
        Station *a=NULL;
        Temp best(false,"",-1);
        for (int j = 0; j < num_coms; j++)  //�������г�������Ŀ��
        { //֮�󷴸�����Search�����Ƚϵõ���õ�·��
            a = GetStation(start,coms[j]);
            if (a != NULL)
            {
                Temp temp = Search(a,start,end,coms,num_coms);
                a->ClearAllMidStation();
                if (temp.IsExist)
                {
                    if (!best.IsExist)
                        best = temp;
                    else
                    {
                        if (temp.num_pass <= best.num_pass)
                        {
                            if (temp.num_pass < best.num_pass || temp.path.length() < best.path.length())
                                best = temp;
                        }
                    }
                }
            }         
        }

        if (best.IsExist)
        {
            cout << best.num_pass << endl;
            cout << best.path;
        }        
        else
        {
            cout << "Sorry, no line is available."<<endl;
        }

    }
}

void Station::GetAllMidStation(const string start,const string end,Company *coms,const int num_coms)
{
    this->midstations.num = 0;
    for (int i = 0; i < this->company->num_stations; i++)
    {
        string name = this->company->stations[i].name;
        if ( name != start && name != end)
            for (int j = 0; j < num_coms; j++)
            {
                if (coms[j].name != this->company->name)
                {
                    Station *sta = GetStation(name,coms[j]);
                    if (sta != NULL)
                    {
                        Station *no = this->midstations.parent;
                        while (no != NULL)
                        {//������ѭ����
                            if (no->name == sta->name && no->company->name == sta->company->name)
                                break;
                            no = no->midstations.parent;
                        }
                        if (no == NULL)
                        {
                            sta->midstations.parent = this;
                            this->midstations.stations[this->midstations.num] = sta;
                            this->midstations.num++;
                        }
                    }
                }
            }
    }
}
void Station::ClearAllMidStation()
{
    if (this->midstations.parent != NULL)
    {
        this->midstations.parent = NULL;
    }

    if (this->midstations.num != 0)
    {
        for (int i = 0; i < this->midstations.num; i++)
        {
            this->midstations.stations[i]->ClearAllMidStation();
            this->midstations.stations[i] = NULL;
        }
        this->midstations.num = 0;
    }
}
int Station::GetMidStationIndex(string name)
{//name is unique in company,so index too;
    for (int i = 0; i < (company->num_stations); i++)
    {
        if (company->stations[i].name == name)
            return company->stations[i].index;
    }
    return -1;
}
int Station::GetStationIndex(string name)
{
    return Station::GetMidStationIndex(name);
}