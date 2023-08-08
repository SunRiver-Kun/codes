#include<stdlib.h>
#include<time.h>
int getrand(int up,int down)
{
    srand((unsigned)time(NULL));    //以时间作为种子，同一秒结果一样
    return rand()%(up-down+1)+down;  //生产down~up之间的随机数
}
