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
	//�ͻ���
	while ((connect(sockfd, (SOCKADDR*)&server_addr, sizeof(SOCKADDR)) == -1)); //һֱ����ֱ�����Ϸ�����
	const char* msg = "�����ǿͻ��ˣ���÷���ˣ���������" __TIME__;   //"123" "456",�м��и��ո���Զ�����
	int msglen = lstrlenA(msg), sendlen = 0;
	while (sendlen < msglen)
	{
		int sn = send(sockfd, msg + sendlen, msglen - sendlen, 0);  //send����ʵ�ʷ��͵�len
		if (sn > 0) { sendlen += sn; }
	}

	char buf[1024] = "";
	recv(sockfd, buf, sizeof(buf), 0);
	printf("���յ�����˵���Ϣ��\n%s\n", buf);

	system("pause");
	closesocket(sockfd);
	WSACleanup();
	return 0;
}