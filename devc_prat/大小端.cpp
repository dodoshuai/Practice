#include<stdio.h>


union myunion{
int a;
char b;
};


int main(void)
{
union myunion s1;//���������
s1.a=0x10000000;
if(s1.b==0x10)
puts("da��ģʽ");
if(s1.b==0x00)
puts("xiao��ģʽ");

int a;
a=0x10000001;//ָ�����
char b=*((char*)(&a));
if(b==0x10)
puts("���ģʽ");
else if(b==0x01)
puts("С��ģʽ");
return 0;
}
//��������������������������������
//��Ȩ����������ΪCSDN������qq_32809273����ԭ�����£���ѭ CC 4.0 BY-SA ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
//ԭ�����ӣ�https://blog.csdn.net/qq_32809273/article/details/53489887
