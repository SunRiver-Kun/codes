#include <stdio.h>
#include <stdlib.h>    //qsort

int compare (const void * a, const void * b)    //必须是const void 型指针
{
    return ( *(int*)a - *(int*)b );          //b-a即为降序
}

int main()
{

    int i,k[5] = {4, 1, 5, 2, 6};
    qsort(k, 5, sizeof(int), compare);          //数组名，元素个数，元素大小，比较函数
    for (i = 0; i < 5;i++)
        printf("%d", k[i]);
    return 0;
}
