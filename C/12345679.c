#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<graphics.h>  //????
#include<time.h>

#define SCREEN_WIDTH 1366
#define SCREEN_HEIGHT 768
#define DEF_RAIN_NUM 91

int g_nRainPos[DEF_RAIN_NUM]={0}; //��ʼ��λ��
char g_strRain[DEF_RAIN_NUM][10]={0}; //�ַ���
char CreateRandomNum(){
char nRandomNum=0;
while(1)
    {nRandowNum=rand()%123;//�������0~122��һ���ַ�
      if((nRandomNum>=65&&nRandomNum<=90)||nRandomNum>=97)
      {
          return nRandomNum;
      }
    }
    void InitPos()
    {
        for(int i=0;i<DEF_RAIN_NUM;i++)
        {
            for(int j=0;j<10;j++)
            {
                outtextxy(i*15,g_nRainPos[i]-15*j,g_strRain[i][j]);
                settextcolor(RGB(0,255,-28*j,0));
            }
        }
        for(int i=0;i<DEF_RAIN_NUM,i++)
        {
            g_nRainPos[i]+=15;//��Ļˢ�º����λ���½�15
        }
        for(int i=0;i<DEF_RAIN_NUM;i++)
        {
            if(g_nRainPos[i]-10*15>=SCREEN_HEIGHT)
            {
                g_nRainPos[i]=0;
            }
        }
    }
    int main()
    {
        srand((unsigned)time(NULL));
        initgraph(SCREEN_WIDTH,SCREEN_HEIGHT);
        InitPos();
        InitNumRain();
        BeginBatchiDraw();
        while(1)
        {
            InitNumRain();
            ShowNumRain();
            FlushBatchDraw();
            Sleep(100);  //��ʱ0.1��
            cleardevice(); //������Ļ
        }
        EndBatchDraw();
        closegragh();
        return 0;
    }
