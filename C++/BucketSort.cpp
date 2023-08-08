#include<iostream>
using namespace std;

//move all target to the end of str
void BucketSort(char *str, int length,const char target)
{
    length--; //no change the '\0'
    int i = 0, j = 0;  // 
    for (i; i < length; ++i)  //相当于新建一个数组拷贝非target的数据，然后把它贴回原str
    {
        if (str[i] != target)
            str[j++] = str[i];
    }

    for (j; j < length ; ++j)
        str[j] = target;


}

int main()
{
    char str[] = "dadawwrfdasdcxzcsfafwagjaisdoaihqhourwhdouihdoizshdcoizhocxh";
    cout << "old str = " << endl << str << endl;
    BucketSort(str, sizeof(str),'d'); //sizeof() include '\0'
    cout << "after moving d:  str = " << endl << str << endl;

}