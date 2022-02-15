/*!
The max route of taking stations(最佳乘车路线问题)

当初写这个的时候甚至没学完《数据结构与算法》，当时想了几天最后还是给我写出来了
*/
#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include<cstdlib>
using namespace std;
string num2str(int i)
{
    stringstream s;
    s << i;
    return s.str();
}
class Company;
class Station;
class MidStation;
class Temp;
Station *GetStation(string name,Company &com);

class MidStation
{
public:
    int num;
    Station *stations[99];
    Station *parent;
    MidStation() { num = 0; parent = NULL; }
};
class Station
{
public:
    Company *company; //用指针的化,声明就可以了
    MidStation midstations;
    string name;
    int index;
    Station(){ }
    void GetAllMidStation(string start,string end,Company *coms,int num_coms);
    void ClearAllMidStation();
    int GetMidStationIndex(string name);
};
class Company
{
public:
    string name;
    int num_stations;
    Station stations[100]; //前面必须有定义了的Station

    Company() { }
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
    void ShowInfo()
    {
        cout << name << " " << num_stations << endl;
        for (int i = 0; i < num_stations; i++)
            cout << stations[i].name << " ";
        cout << endl;
    }
};

class Temp
{
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

Station *GetStation(string name,Company &com)
{
    for (int i = 0; i < com.num_stations; i++)
        if (name == com.stations[i].name)
            return &(com.stations[i]);
    return NULL;
}


Temp Search(Station *begin,Station *start,Station *end,Company *coms,int num_coms)
{ //为了节约内存
    begin->GetAllMidStation(start->name,end->name,coms,num_coms);
    if (begin->midstations.num == 0)
    {
        if (begin->company->name != end->company->name)
            return Temp(false,"",-1);
        else
        {
            string path = "Go by the line of company #" + begin->company->name + " from " + begin->name + " to " + end->name + ".\n";
            return Temp(true,path,abs(begin->index - end->index));
        }

    }
    else
    {

        Temp best(false,"",-1);

        if (begin->company->name != end->company->name)
        {
            for (int i = 0; i < begin->midstations.num; i++)
            {
                Temp temp = Search(begin->midstations.stations[i],start,end,coms,num_coms);
                if (temp.IsExist)
                {
                    string name = begin->midstations.stations[i]->name;
                    int index = begin->GetMidStationIndex(name);
                    int num_pass = temp.num_pass + abs(begin->index - index);
                    string path = "Go by the line of company #" + begin->company->name + " from " + begin->name + " to " + name + ".\n"+temp.path;

                    if (best.IsExist==false)
                    {      
                        best = Temp(true,path,num_pass);
                    }
                    else
                    {
                        if (num_pass <= best.num_pass)
                        {
                            if(num_pass<best.num_pass||path.length()<best.path.length())
                                best = Temp(true,path,num_pass);
                        }
                    }
                }
            }
        }
        else
        {
            string path_direct = "Go by the line of company #" + begin->company->name + " from " + begin->name + " to " + end->name + ".\n";
            best = Temp(true,path_direct,abs(begin->index - end->index));//go directly

            for (int i = 0; i < begin->midstations.num; i++)
            {
                Temp temp = Search(begin->midstations.stations[i],start,end,coms,num_coms);
                if (temp.IsExist)
                {
                    string name = begin->midstations.stations[i]->name;
                    int index = begin->GetMidStationIndex(name);
                    int num_pass = temp.num_pass + abs(begin->index - index);
                    string path = "Go by the line of company #" + begin->company->name + " from " + begin->name + " to " + name + ".\n"+temp.path;

                    if (num_pass <=best.num_pass)
                    {
                        if((num_pass < best.num_pass)||(path.length()<best.path.length()))
                            best = Temp(true,path,num_pass);
                    }
                }
            }
        }
        return best;

    }
}
Station *FindStation(string name,Company &com)
{
    for (int i = 0; i < com.num_stations; i++)
        if (com.stations[i].name == name)
            return &com.stations[i];
    return NULL;
}


/*/debug
Station &FindFirstStation(string name,Company *coms,int num_coms)
{
for (int i = 0; i < num_coms; i++)
{
for (int j = 0; j < coms[i].num_stations; j++)
if (name == coms[i].stations[j].name)
return coms[i].stations[j];
}
}
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
    {
        coms[i].name = num2str(i+1);
        cin >> num_stas;
        coms[i].SetStations(num_stas);
    }

    cin >> num_customers;
    for (int i = 0; i < num_customers; i++)
    { 
        cin >> start >> end;  //给string，自动忽略空格,\n,缓存等 
        Station *a=NULL,*b=NULL;
        Temp best(false,"",-1);
        for (int j = 0; j < num_coms; j++)
        {
            a = FindStation(start,coms[j]);
            if (a != NULL)
            {
                for (int k = 0; k < num_coms; k++)
                {
                    b = FindStation(end,coms[k]);
                    if (b != NULL)
                    {
                        Temp temp = Search(a,a,b,coms,num_coms);
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

void Station::GetAllMidStation(string start,string end,Company *coms,int num_coms)
{//不能回走，不能选择目标做中转站
    this->midstations.num = 0;
    Company *com = this->company;
    int num_stations = com->num_stations;
    Station *no = this->midstations.parent;
    for (int i = 0; i < num_stations; i++)
    {
        if (com->stations[i].name != start && com->stations[i].name != end && com->stations[i].name != this->name)
        {
            for (int j = 0; j < num_coms; j++)
            {
                if ( coms[j].name != com->name)
                {
                    Station *staion = GetStation(com->stations[i].name,coms[j]);
                    if (staion != NULL)
                    {
                        no = this->midstations.parent;
                        while (no!=NULL)
                        {//不能死循环了
                            if (no->name == staion->name && no->company->name == staion->company->name)
                                break;
                            no = no->midstations.parent;
                        }
                        if (no == NULL)
                        {
                            staion->midstations.parent = this;
                            this->midstations.stations[this->midstations.num] = staion;
                            this->midstations.num++;
                        }
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
