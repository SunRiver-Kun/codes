//#include <stdlib.h>
//#include <stdio.h>
#include <iostream>
#include <windows.h>
//#include <memory.h>
//#include <string.h>
int WriteFile();

int main(int argc, char* argv[])
{
	//��ȡϵͳtempĿ¼
	WCHAR strTmpPath[MAX_PATH];
	GetTempPath(sizeof(strTmpPath), strTmpPath);
	printf("��ȡϵͳtempĿ¼��%s\n", strTmpPath);

	// ��ȡ����ľ���·��
	WCHAR	strSelf[MAX_PATH];
	memset(strSelf, 0, sizeof(strSelf));
	GetModuleFileName(NULL, strSelf, sizeof(strSelf));
	printf("��ȡ����ľ���·����%s\n", strSelf);

	//��ȡ��ǰ���̺�
	printf("��ȡ��ǰ���̺ţ�%d\n", GetCurrentThreadId());

	// ��ȡϵͳĿ¼
	WCHAR strSysDir[100];
	GetSystemDirectory(strSysDir, sizeof(strSysDir));
	// char *bin = "%SystemRoot%\\System32\\svchost.exe -k netsvcs";
	printf("ϵͳĿ¼��%s\n", strSysDir);

	//���ã�CreateFile��ReadFile��WriteFile��д�ļ�
	WriteFile();
	//����fread��fwrite
	system("pause");
	return 0;
}

int WriteFile()
{
	DWORD dwFileSize = 0;

	BYTE* buffer = NULL;

	HANDLE hFile = INVALID_HANDLE_VALUE;

	hFile = CreateFile(L"E:\\123.txt", GENERIC_READ,
		FILE_SHARE_READ, NULL, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		CloseHandle(hFile);

		printf("Create File Failed !\n");
		return 0;
	}
	else
	{
		dwFileSize = GetFileSize(hFile, NULL);
		//LARGE_INTEGER lFileSize;
		//GetFileSizeEx(hFile,&lFileSize);//���ļ����ȳ���0xFFFFFFFF��ʹ��GetFileSizeEx��
		printf("%d\n", dwFileSize);

		buffer = new BYTE[dwFileSize];
		if (buffer == NULL)
		{
			printf("Create buffer error !\n");
			return 0;
		}
		ZeroMemory(buffer, dwFileSize);

		DWORD dwReadSize = 0, dwReadTotal = 0;

		while (dwReadTotal < dwFileSize)
		{
			ReadFile(hFile, buffer + dwReadTotal, dwFileSize - dwReadSize, &dwReadSize, NULL);
			dwReadTotal += dwReadSize;
		}
		printf("�ܹ���ȡ���ļ���С:%d\n:", dwReadTotal);
	}

	hFile = CreateFile(L"E:\\��ʽһ.txt", GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		CloseHandle(hFile);
		printf("Create File Failed -2 !\n");
		delete[]buffer;
		buffer = NULL;
		return 0;
	}
	else
	{
		DWORD dwWriteTotal = 0, dwWriteSize = 0;
		while (dwWriteTotal < dwFileSize)
		{
			WriteFile(hFile, buffer + dwWriteTotal, dwFileSize, &dwWriteSize, NULL);
			dwWriteTotal += dwWriteSize;
		}
	}
	delete[]buffer;
	buffer = NULL;
	CloseHandle(hFile);
}