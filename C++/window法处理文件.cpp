//#include <stdlib.h>
//#include <stdio.h>
#include <iostream>
#include <windows.h>
//#include <memory.h>
//#include <string.h>
int WriteFile();

int main(int argc, char* argv[])
{
	//获取系统temp目录
	WCHAR strTmpPath[MAX_PATH];
	GetTempPath(sizeof(strTmpPath), strTmpPath);
	printf("获取系统temp目录：%s\n", strTmpPath);

	// 获取自身的绝对路径
	WCHAR	strSelf[MAX_PATH];
	memset(strSelf, 0, sizeof(strSelf));
	GetModuleFileName(NULL, strSelf, sizeof(strSelf));
	printf("获取自身的绝对路径：%s\n", strSelf);

	//获取当前进程号
	printf("获取当前进程号：%d\n", GetCurrentThreadId());

	// 获取系统目录
	WCHAR strSysDir[100];
	GetSystemDirectory(strSysDir, sizeof(strSysDir));
	// char *bin = "%SystemRoot%\\System32\\svchost.exe -k netsvcs";
	printf("系统目录：%s\n", strSysDir);

	//采用：CreateFile、ReadFile、WriteFile读写文件
	WriteFile();
	//采用fread、fwrite
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
		//GetFileSizeEx(hFile,&lFileSize);//若文件长度超过0xFFFFFFFF，使用GetFileSizeEx。
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
		printf("总共读取的文件大小:%d\n:", dwReadTotal);
	}

	hFile = CreateFile(L"E:\\方式一.txt", GENERIC_WRITE, 0, NULL,
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