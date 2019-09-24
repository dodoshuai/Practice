#include<stdio.h>
#include<iostream>
using namespace std;
 
char *Strcat(char* dest,const char *src);//��src���ַ���׷�ӵ�dest����

int Strcmp(const char*str1,const char * str2);//�����ַ����Ƚ�
 
char *Strcpy(char *dest,const char *src);//�����ַ������ݵ�Ŀ�Ĵ�
 
unsigned Strlen_1(const char *str);//�����ַ����ĳ���--������'\0'
  
char *Strchr(char* str,char c);//����str���״γ���c��λ�ã����򷵻�NULL�����򷵻س���λ��
  
char *Strrchr(char *str,char c);//����str�����һ�γ��ֵ�λ�ã�����У��򷵻س���λ�ã����򷵻�NULL;

char *Strrev(char *str);//��ת�ַ����������ַ���ָ�롣

const char *Strstr(const char *str1,const char *str2);//�����ַ���str2��str1�г��ֵ�λ�ã��ҵ��򷵻�λ�ã����򷵻�NULL

int main(){
	char a[10]="abcd";
	char b[10]="efaafg";
	char dd[]="abcdefghijklmnopqrstuvwxyz";
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<Strcat(a,b)<<endl;
	cout<<Strcmp(a,b)<<endl;
	cout<<Strcpy(a,b)<<endl;
	cout<<Strlen_1(a)<<endl;
	cout<<Strlen_1(b)<<endl;
	char a3='f';
	cout<<"1="<<Strchr(a,a3)<<endl;
	cout<<"2="<<Strrchr(a,a3)<<endl;
	cout<<Strrev(a)<<endl;
	cout<<Strrev(dd)<<endl;
	char a4[]="gfe";
	cout<<"3="<<Strstr(dd,a4)<<endl;
//	printf("%p\n",Strchr(a,'c'));
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<dd<<endl;
	return 0;
}
char *Strcat(char* dest,const char *src)//��src���ַ���׷�ӵ�dest����
{
	if(NULL==src){
		return dest;
	}
	char *s1=dest;
	while(*s1){	
		s1++;//
	}	
	while(*src){
		*s1++=*src++;
	}
	*s1='\0';
	return dest;
}
int Strcmp(const char*str1,const char * str2)//�����ַ����Ƚ�
{
	const char *s1=str1;
	const char *s2=str2;
	while(*s1==*s2){
		if(*s1=='\0'){//�ж�ֹͣ 
			return 0;
		}
		s1++;
		s2++;
	}
	return (*s1-*s2); 
}
char *Strcpy(char *dest,const char *src)//�����ַ������ݵ�Ŀ�Ĵ�
 {
 	if(src==NULL){
 		return NULL;
 	}
 	char * s1=dest;
 	while(*src){
 		*s1++=*src++;
 	}
 	*s1='\0';
 	return dest;
 }
unsigned Strlen_1(const char *str)//�����ַ����ĳ���--������'\0'
{
	unsigned count=0;
	while(*str++){
		//str++;
		count++;
	}
	return count;
} 
char* Strchr(char* str,char c)//����str���״γ���c��λ�ã����򷵻�NULL�����򷵻س���λ��
{
	if(str==NULL){
		return NULL;
	}

	while(*str!=c){
		if(*str=='\0'){
				return NULL;
		}
		str++;
	}
	
	return str;
}  
char *Strrchr(char *str,char c)//����str�����һ�γ��ֵ�λ�ã�����У��򷵻س���λ�ã����򷵻�NULL;
{
		if(str==NULL){
		return NULL;
	}
	size_t len=Strlen_1(str);
	char * s1=str+len-1;
	while(*s1!=c){
		if(s1==str){
			return NULL;
		}
		s1--;
	}	
	return s1;
}

char *Strrev(char *str)//��ת�ַ����������ַ���ָ�롣
{
	if(NULL==str){
		return NULL;
	}
	size_t len=Strlen_1(str);
	char * s1=str;
	char * s2=str+len-1;
	while(s2>s1){
		char c=*s2;
		*s2=*s1;
		*s1=c;
		s2--;
		s1++;
	}
	return str;
}
const char *Strstr(const char *str1,const char *str2)//�����ַ���str2��str1�г��ֵ�λ�ã��ҵ��򷵻�λ�ã����򷵻�NULL
{
	if(str1==NULL||str2==NULL){
		return NULL;
	}	
	while(*str1){
		const char *ret=str1;
		const char *s1=str1;
		const char *s2=str2;
		while(*s2){
			if(*s2!=*s1){
				break;
			}
			s1++;
			s2++;
		}
		if(*s2=='\0'){
			return ret;
		}
		str1++;
	}
	return NULL;
}

  
 
