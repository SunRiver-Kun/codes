#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<winsock.h>
#define SERVPORT 2333  //服务器监听端口
#define BACKLOG 10  //最大同时连接请求数
#define ASSEST(msg,bool) if((bool)==-1){printf(msg);exit(-1);}
int main()
{
    int sockfd,client_fd; //监听，传输
    struct sockaddr_in my_addr; //本机地址信息
    struct sockaddr_in remote_addr;  //客户端地址信息
    char* msg = "You are welcome!\n";
    my_addr.sin_family=AF_INET;
    my_addr.sin_port=htons(SERVPORT);
    my_addr.sin_addr.s_addr=INADDR_ANY;

    ASSEST("socket",sockfd=socket(AF_INET,SOCK_STREAM,0))
    ASSEST("listen",listen(sockfd,BACKLOG))
    while(1)
    {
        int sin_size = sizeof(struct sockaddr_in);

    }
}
