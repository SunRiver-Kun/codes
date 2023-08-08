#include<stdio.h>
void copy_file(char *filename,char *newfilename)
{
    FILE *p1,*p2;
    char ch;
    if((p1=fopen(filename,"rb"))==NULL)  //打开被复制的文件
	{
		printf("ERROR");
		exit(0);
	}
	if((p2=fopen(newfilename,"wb"))==NULL) //写入要复制的文件名
	{
		printf("ERROR");
		exit(0);
	}
	while(!feof(p1))    //用一个检查文件是否结束的函数来判断
	{
		ch=fgetc(p1);   //读出每一个p1指向的文件中的字节，把ch写入到p2指向的文件中去，如果没有p2文件，则会建立一个以filename1字符数组命名的文件

		fputc(ch,p2);
	}

	printf("复制成功");

	fclose(p1);   //用完之后，为了避免不必要的操作干扰读写，要关闭文件，即断掉文件指针与文件的联系
	fclose(p2);

}
int main()
{
    printf("输入文件名和新文件名：\n");
    char p1[50],p2[50];
    gets(p1);
    gets(p2);
    copy_file(p1,p2);
}
