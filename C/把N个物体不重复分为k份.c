/*   
把N个物体分成k份，不能重复（1.2.3与2.1.3等价）"

*/
  #include<stdio.h>
int C(int a,int b)
{   int s=0,i;
    if(b==1)    return 1; //全部给一份  a 0 0 0
    if(a-b==0||a-b==1)  return 1;   //平分，一份2其他平分  1 1 1 1 +多余的 
    if(a==2)    return 1;  
    else
        for(i=1;i<=a-b&&i<=b;i++)  //5个分3份== 2个分1分+2个分2两份，保证不超过剩余的个数与所要求的份数
        s+=C(a-b,i);
    return s;
    // (7,4)->(3,1)+(3,2)+(3,3)
}
int main()
{
    int N,k;
    scanf("%d%d",&N,&k);
    printf("%d",C(N,k));
}



