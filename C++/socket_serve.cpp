#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include<cstdio> //for printf
#include<winsock2.h>
#pragma comment(lib,"ws2_32")
#define PORT 2333
#define IP "192.168.43.96"
int main()
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	SOCKET sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.S_un.S_addr = inet_addr(IP);
	server_addr.sin_port = htons(PORT);
	//服务端
	bind(sockfd, (SOCKADDR*)&server_addr, sizeof(SOCKADDR));
	listen(sockfd, 5);	//数据队列的长度，一般为0~20
	while (true)	//只能主动关闭服务器
	{
		SOCKADDR_IN client_addr;
		int csize = sizeof(SOCKADDR);
		SOCKET sockcl = accept(sockfd, (SOCKADDR*)&client_addr, &csize); //自动睡眠直到连接

		const char* msg = "Don't Stave Together";
		int msglen = lstrlenA(msg), sendlen = 0;
		while (sendlen < msglen)
		{
			int sn = send(sockcl, msg + sendlen, msglen - sendlen, 0);  //send返回实际发送的len
			if (sn > 0) { sendlen += sn; }
		}

		char cmsg[1024] = "";
		recv(sockcl, cmsg, sizeof(cmsg), 0);
		printf("接收到了客户端发来的消息：\n%s\n", cmsg);
		closesocket(sockcl);
	}
	system("pause");
	closesocket(sockfd);
	WSACleanup();
	return 0;
}