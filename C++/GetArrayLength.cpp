#include<iostream>

#define ArrayLength(array,len){len = (sizeof(array)/sizeof(array[0]));}

using namespace std;

//char a[]="abc" ,return 4(contact '\0')
template<typename T>
int GetArrayLength(T &array)
{
    return sizeof(array) / sizeof(array[0]);
}
//在main中可用
/*
当using namespace时，std::可省
    std::end(array)-std::begin(array);

*/

