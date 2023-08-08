#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include<cstdlib>
using namespace std;
//把整数转换为字符串
string num2str(int i)
{
    stringstream s;
    s << i;
    return s.str();
}
//一堆提前声明
class Company;
class Station;
class MidStation;
class Temp;

class MidStation
{//全部中转站信息，使用完调用函数清空
public:
    int num;
    Station *stations[99];//指针数组，stations[i]表示一个Station指针
    Station *parent;//跳转口:  公司1的1000站跳到公司2的1000站，则后者的parent为前者
    MidStation() { num = 0; parent = NULL; }//建立时初始化
};
class Station
{
public:
    Company *company; 
    MidStation midstations;
    string name;
    int index;
    Station(){ }
    //函数声明，定义在最后面
    //初始化midstations
    void GetAllMidStation(const string start,const string end, Company *coms,const int num_coms);
    //清空midstations
    void ClearAllMidStation();
    //返回本公司编号为name的Index,下面两函数功能一样
    int GetMidStationIndex(string name);
    int GetStationIndex(string name);
};
class Company
{
public:
    string name;
    int num_stations;
    Station stations[100]; //前面必须有定义了的Station

    Company() { }
    //输入并初始化Stations
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
    //debug用，显示全部信息
    void ShowInfo()
    {
        cout << name << " " << num_stations << endl;
        for (int i = 0; i < num_stations; i++)
            cout << stations[i].name << " ";
        cout << endl;
    }
};

class Temp
{//返回值的集合
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

//在com公司里找name的车站
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
Search:找寻固定出发点到目的地的最佳路径
begin:递归用的参数，表示当前车站
start,end,coms,num_coms在递归中不会改变
start:出发点的名字
end:目的地的名字
coms：Company数组
num_coms:Company数组里元素的个数
为什么用指针？当然是
*/

Temp Search(Station *begin,const string start,const string end,Company *coms,const int num_coms)
{//初始化midstations
    begin->GetAllMidStation(start,end,coms,num_coms);
    if (begin->midstations.num == 0) // 没有中转站
    {
        if (GetStation(end,begin->company)==NULL)  //无法达到目的地
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
        for (int i = 0; i < begin->midstations.num; i++)  //遍历所有中转站
        {
            Temp temp = Search(begin->midstations.stations[i],start,end,coms,num_coms);
            if (temp.IsExist)  //中转站可以到目的地
            {
                string name = begin->midstations.stations[i]->name;
                int index = begin->GetMidStationIndex(name);
                int num_pass = temp.num_pass + abs(begin->index - index);
                string path = "Go by the line of company #" + begin->company->name + " from " + begin->name + " to " + name + ".\n" + temp.path;
                //比较
                if (best.IsExist == false)
                {
                    best = Temp(true,path,num_pass);
                }
                else
                {
                    if (num_pass <= best.num_pass)
                    {   //过站少的优先，或者一样时中转少的优先(path短)
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
    {  //初始化所有公司和站点的所有数据
        coms[i].name = num2str(i+1);
        cin >> num_stas;
        coms[i].SetStations(num_stas);
    }

    cin >> num_customers;
    for (int i = 0; i < num_customers; i++)
    { 
        cin >> start >> end;  //给string，自动忽略空格,\n,缓存等 
        Station *a=NULL;
        Temp best(false,"",-1);
        for (int j = 0; j < num_coms; j++)  //遍历所有出发点找目标
        { //之后反复调用Search，并比较得到最好的路径
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
                        {//不能死循环了
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