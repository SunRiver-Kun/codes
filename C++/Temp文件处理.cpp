#include<iostream>
//#include<cstdlib>
//#include<fstream>

#include<string>
#include<xstring>  // std::wstring
#include<cstdio>
const char* FilePrefix = "SUNRIVER";
std::string GetTempFileName()  //no return the char* , will lose name!!
{  // cstdio
	char name[L_tmpnam] = {};
	tmpnam_s(name); // stdio.h
	return name;
}
FILE* GetTempFile()
{ // return a random name file point to read and write (binary), auto delete, only us can use it!
	FILE *fp;
	tmpfile_s(&fp); // stdio.h
	return fp;
}

std::wstring GetWTempFileName()
{
	wchar_t name[] = L"SUNRIVER-XXXXXX"; // must use [] , XXXXXX is used to random ,must be six X
	if (!_wmktemp_s(name)) // return 0 is right. will change the name
		return name;
	return L"";

	//return	_wtempnam(L"C:\\Users\\Administrator\\Desktop", L"SUNRIVER-"); // directory 目录，当temp用不了是才会用这个
}

int main()
{
	using namespace std;
	cout << GetTempFileName() << endl;
	wcout << GetWTempFileName() << endl;
	system("pause");
}