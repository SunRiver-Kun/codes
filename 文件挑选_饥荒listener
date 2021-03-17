#include<iostream>
#include<cstdlib>       //exit()
#include<fstream>
using namespace std;
void GetKeyMessage(char *infilex,char *outfilex,char star,char end=' ',unsigned int size=20)
{
    fstream infile(infilex,ios::in),outfile(outfilex,ios::out);
    if(!(infile.is_open()&&outfile.is_open()))  exit(-1);
    char c[size+1]="";
    while(!infile.eof())
  {
    infile.ignore(100,star);
    infile.ignore(3,' ');   //这个是为了跳过':'和' '
    infile.get(c,size+1,end);
    outfile<<c<<'\n';   //'\r\n','CRLF'??????
  }
  infile.close();
  outfile.close();
}
void GetKeyMessage(char *infilex,char star,char end='\n',unsigned int size=20)
{   fstream infile(infilex,ios::in);
    if(!infile.is_open())  exit(-1);
    char c[size+1]="";
    while(!infile.eof())
  {
    infile.ignore(100,star);
    infile.ignore(3,' ');
    infile.get(c,size+1,end);
    cout<<c<<endl;
  }
  infile.close();
}

int main()
{
    GetKeyMessage("event_listeners.txt","event_listeners_.txt",']','\t',20);
}
