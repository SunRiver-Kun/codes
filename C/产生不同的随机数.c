#include<stdlib.h>
#include<time.h>
int getrand(int up,int down)
{
    srand((unsigned)time(NULL));    //��ʱ����Ϊ���ӣ�ͬһ����һ��
    return rand()%(up-down+1)+down;  //����down~up֮��������
}
