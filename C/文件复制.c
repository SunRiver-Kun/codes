#include<stdio.h>
void copy_file(char *filename,char *newfilename)
{
    FILE *p1,*p2;
    char ch;
    if((p1=fopen(filename,"rb"))==NULL)  //�򿪱����Ƶ��ļ�
	{
		printf("ERROR");
		exit(0);
	}
	if((p2=fopen(newfilename,"wb"))==NULL) //д��Ҫ���Ƶ��ļ���
	{
		printf("ERROR");
		exit(0);
	}
	while(!feof(p1))    //��һ������ļ��Ƿ�����ĺ������ж�
	{
		ch=fgetc(p1);   //����ÿһ��p1ָ����ļ��е��ֽڣ���chд�뵽p2ָ����ļ���ȥ�����û��p2�ļ�����Ὠ��һ����filename1�ַ������������ļ�

		fputc(ch,p2);
	}

	printf("���Ƴɹ�");

	fclose(p1);   //����֮��Ϊ�˱��ⲻ��Ҫ�Ĳ������Ŷ�д��Ҫ�ر��ļ������ϵ��ļ�ָ�����ļ�����ϵ
	fclose(p2);

}
int main()
{
    printf("�����ļ��������ļ�����\n");
    char p1[50],p2[50];
    gets(p1);
    gets(p2);
    copy_file(p1,p2);
}
