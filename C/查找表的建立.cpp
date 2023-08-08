#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <stdlib.h>
#include <direct.h>
#include <string.h>
#include <io.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;
FILE *p;
void md(long long int m)
{
long long int shi,fen,miao,hmiao;
hmiao=m%3600000;
m=m/1000;
if(m/3600<24)
{
shi = m/3600;
fen = m/60%60;
miao = m%60;
cout<<endl<<"换算等于"<<shi<<"时:"<<fen<<"分:"<<miao<<"秒:"<<(hmiao-miao*1000)<<"毫秒"<<endl;
}
else printf("输入数值太大");
}
class CBrowseDir
{
protected:
    char m_szInitDir[_MAX_PATH];
public:
    CBrowseDir();
    bool SetInitDir(const char *dir);
    bool BeginBrowse(const char *filespec);
protected:
    bool BrowseDir(const char *dir,const char *filespec);
    virtual bool ProcessFile(const char *filename);
    virtual void ProcessDir(const char *currentdir,const char *parentdir);
};
CBrowseDir::CBrowseDir()
{
    getcwd(m_szInitDir,_MAX_PATH);
    int len=strlen(m_szInitDir);
    if (m_szInitDir[len-1] != '\\')
        strcat(m_szInitDir,"\\");
}

bool CBrowseDir::SetInitDir(const char *dir)
{
    if (_fullpath(m_szInitDir,dir,_MAX_PATH) == NULL)
        return false;
    if (_chdir(m_szInitDir) != 0)
        return false;
    int len=strlen(m_szInitDir);
    if (m_szInitDir[len-1] != '\\')
        strcat(m_szInitDir,"\\");
    return true;
}
bool CBrowseDir::BeginBrowse(const char *filespec)
{
    ProcessDir(m_szInitDir,NULL);
    return BrowseDir(m_szInitDir,filespec);
}
bool CBrowseDir::BrowseDir(const char *dir,const char *filespec)
{
    _chdir(dir);
    long hFile;
    _finddata_t fileinfo;
    if ((hFile=_findfirst(filespec,&fileinfo)) != -1)
    {
        do
        {
            if (!(fileinfo.attrib & _A_SUBDIR))
            {
                char filename[_MAX_PATH];
                strcpy(filename,dir);
                strcat(filename,fileinfo.name);
                puts(filename);
                fputs(filename,p);
                fprintf(p,"\n");
                if (!ProcessFile(filename))
                    return false;
            }
        } while (_findnext(hFile,&fileinfo) == 0);
        _findclose(hFile);
    }
    _chdir(dir);
    if ((hFile=_findfirst("*.*",&fileinfo)) != -1)
    {
        do
        {
            if ((fileinfo.attrib & _A_SUBDIR))
            {
                if (strcmp(fileinfo.name,".") != 0 && strcmp
                    (fileinfo.name,"..") != 0)
                {
                    char subdir[_MAX_PATH];
                    strcpy(subdir,dir);
                    strcat(subdir,fileinfo.name);
                    strcat(subdir,"\\");
                    ProcessDir(subdir,dir);
                    if (!BrowseDir(subdir,filespec))
                        return false;
                }
            }
        } while (_findnext(hFile,&fileinfo) == 0);
        _findclose(hFile);
    }
    return true;
}

bool CBrowseDir::ProcessFile(const char *filename)
{
    return true;
}

void CBrowseDir::ProcessDir(const char
    *currentdir,const char *parentdir)
{
}

class CStatDir:public CBrowseDir
{
protected:
    long long int m_nFileCount;
    long long int m_nSubdirCount;

public:
    CStatDir()
    {
        m_nFileCount=m_nSubdirCount=0;
    }
    int GetFileCount()
    {
        return m_nFileCount;
    }
    int GetSubdirCount()
    {
        return m_nSubdirCount-1;
    }
protected:
    virtual bool ProcessFile(const char *filename)
    {
        m_nFileCount++;
        return CBrowseDir::ProcessFile(filename);
    }
    virtual void ProcessDir
        (const char *currentdir,const char *parentdir)
    {
        m_nSubdirCount++;
        CBrowseDir::ProcessDir(currentdir,parentdir);
    }
};

int main()
{
    int DiskCount = 0;
    DWORD DiskInfo = GetLogicalDrives();
    while(DiskInfo)
        {
            if(DiskInfo&1)
                {
                    ++DiskCount;
                }
            DiskInfo = DiskInfo >> 1;
        }
    cout<<"逻辑磁盘数量:"<<DiskCount<<endl;
    int DSLength = GetLogicalDriveStrings(0,NULL);
    char* DStr = new char[DSLength];
    GetLogicalDriveStrings(DSLength,(LPTSTR)DStr);
    int DType;
    int si=0;
    BOOL fResult;
    unsigned long long int i64FreeBytesToCaller;
    unsigned long long intTotalBytes;
    unsigned long long int i64FreeBytes;
    unsigned long long int i64TotalBytes;
    int g=0,k=0;
    char name[100];
    for(int i=0; i<DSLength/4; ++i)
        {
            char dir[5]= {DStr[si],':','\\'};
            cout<<dir;
            DType = GetDriveType(DStr+i*4);
            if(DType == DRIVE_FIXED)
                {
                    cout<<"硬盘";
                    name[k]=DStr[si];
                    k++;
                    g++;
                }
            else if(DType == DRIVE_CDROM)
                {
                    cout<<"光驱";
                }
            else if(DType == DRIVE_REMOVABLE)
                {
                    cout<<"可移动式磁盘";
                }
            else if(DType == DRIVE_REMOTE)
                {
                    cout<<"网络磁盘";
                }
            else if(DType == DRIVE_RAMDISK)
                {
                    cout<<"虚拟RAM磁盘";
                }
            else if (DType == DRIVE_UNKNOWN)
                {
                    cout<<"未知设备";
                }
            fResult = GetDiskFreeSpaceEx (dir,(PULARGE_INTEGER)&i64FreeBytesToCaller,(PULARGE_INTEGER)&i64TotalBytes,(PULARGE_INTEGER)&i64FreeBytes);
            if(fResult)
                {
                    if((i64TotalBytes/1024/1024)>1024)
                      cout<<" 磁盘大小:"<<(float)i64TotalBytes/1024/1024/1024<<" GB";
                     else
                       cout<<" 磁盘大小:"<<(float)i64TotalBytes/1024/1024<<" MB";
                    if((i64FreeBytesToCaller/1024/1024)>1024)
                      cout<<" 剩余空间:"<<(float)i64FreeBytesToCaller/1024/1024/1024<<" GB";
                     else
                       cout<<" 剩余空间:"<<(float)i64FreeBytesToCaller/1024/1024<<" MB";
                }
            else
                {
                    cout<<" 设备未准备好或启用了系统加密！";
                }
            if(!fResult)
              {
                  k--;
              }
            cout<<endl;
            si+=4;
        }
    cout<<"共有硬盘"<<g<<"块"<<endl;
    g=k+1;
    cout<<"共有未加密的硬盘"<<g<<"块"<<endl;
    cout<<"正在启动索引程序"<<endl;
    int i;
    p=fopen("list.txt","a+");
    if(g==1)
      {
          cout<<"您只有一个c盘"<<endl;
          cout<<"检测C盘可能会让程序崩溃"<<endl;
      }
    clock_t start,finish;
    start=clock();
    for(i=1;i<g;i++)
       {
             fprintf(p,"%c盘内的文件如下\n",name[i]);
            char buf[6] = {name[i],':','\\'};
             CStatDir statdir;
            statdir.SetInitDir(buf);
            statdir.BeginBrowse("*.*");
            fprintf(p,"文件总数: %d\n子目录总数:%d\n",statdir.GetFileCount(),statdir.GetSubdirCount());
            printf("文件总数: %d\n子目录总数:%d\n",statdir.GetFileCount(),statdir.GetSubdirCount());
       }
    cout<<"全部完成"<<endl;
    finish=clock();
    cout<<"用时"<<(finish-start)<<"毫秒";
    md(finish-start);
    return 0;
}
