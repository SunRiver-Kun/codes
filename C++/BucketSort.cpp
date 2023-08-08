#include<iostream>
using namespace std;

//move all target to the end of str
void BucketSort(char *str, int length,const char target)
{
    length--; //no change the '\0'
    int i = 0, j = 0;  // 
    for (i; i < length; ++i)  //�൱���½�һ�����鿽����target�����ݣ�Ȼ���������ԭstr
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