#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<winsock.h>
#define SERVPORT 2333  //�����������˿�
#define BACKLOG 10  //���ͬʱ����������
#define ASSEST(msg,bool) if((bool)==-1){printf(msg);exit(-1);}
int main()
{
    int sockfd,client_fd; //����������
    struct sockaddr_in my_addr; //������ַ��Ϣ
    struct sockaddr_in remote_addr;  //�ͻ��˵�ַ��Ϣ
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
