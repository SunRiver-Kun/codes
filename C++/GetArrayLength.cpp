#include<iostream>

#define ArrayLength(array,len){len = (sizeof(array)/sizeof(array[0]));}

using namespace std;

//char a[]="abc" ,return 4(contact '\0')
template<typename T>
int GetArrayLength(T &array)
{
    return sizeof(array) / sizeof(array[0]);
}
//��main�п���
/*
��using namespaceʱ��std::��ʡ
    std::end(array)-std::begin(array);

*/

