#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<graphics.h>  //????
#include<time.h>

#define SCREEN_WIDTH 1366
#define SCREEN_HEIGHT 768
#define DEF_RAIN_NUM 91

int g_nRainPos[DEF_RAIN_NUM]={0}; //开始的位置
char g_strRain[DEF_RAIN_NUM][10]={0}; //字符串
char CreateRandomNum(){
char nRandomNum=0;
while(1)
    {nRandowNum=rand()%123;//随机产生0~122的一个字符
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
            g_nRainPos[i]+=15;//屏幕刷新后雨的位置下降15
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
            Sleep(100);  //延时0.1秒
            cleardevice(); //清理屏幕
        }
        EndBatchDraw();
        closegragh();
        return 0;
    }
