#include <stdio.h>
#include <stdlib.h>    //qsort

int compare (const void * a, const void * b)    //������const void ��ָ��
{
    return ( *(int*)a - *(int*)b );          //b-a��Ϊ����
}

int main()
{

    int i,k[5] = {4, 1, 5, 2, 6};
    qsort(k, 5, sizeof(int), compare);          //��������Ԫ�ظ�����Ԫ�ش�С���ȽϺ���
    for (i = 0; i < 5;i++)
        printf("%d", k[i]);
    return 0;
}
