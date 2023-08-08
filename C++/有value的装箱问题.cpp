#include<iostream>
using namespace std;
typedef struct
{//all >=0  
    unsigned int value;
    unsigned int weight;
}Object;
int GetMaxValue(const Object objs[], const size_t size_objs, const int maxweight, int index = 0)
{
    if (index > (size_objs - 1)) { return 0; }
    if (objs[index].weight > maxweight)
        return GetMaxValue(objs, size_objs, maxweight, index + 1);
    else
    {
        int temp1 = objs[index].value + GetMaxValue(objs, size_objs,maxweight - objs[index].weight, index + 1);
        int temp2 = GetMaxValue(objs, size_objs, maxweight, index + 1);
        return temp1 > temp2 ? temp1 : temp2;
    }
}

int main()
{
    while(1)
    {
        int count,maxweight;
        cout << "请输入个数和背包承重的最大值：" << endl;
        cin >> count>>maxweight;

        if (count <= 0 || maxweight <= 0)return -1;

        cout << "请输入每个价值和重量：" << endl;
        Object *objs = new Object[count];
        for (int i = 0; i < count; ++i)
        {
            cin >> objs[i].value >> objs[i].weight;
        }
        cout << GetMaxValue(objs, count, maxweight) << endl;
    }

}