/*
#include<stdio.h>
int main()
{
	char ch;//���Ǵ洢�� 
	int cout=0;//����һ�������� 
	while(ch=getchar()!=EOF)
	{
		if(ch=='{')
		{
		cout+=1;
		}
		if(ch=='}'&&cout==0)
		{
			printf("��ƥ�䣡\n");
			return 0;
		}
		if(ch=='}')
		
	}
	return 0;
} 
*/
#include <stdio.h>
int main()
{
int ch;
int count = 0;//����һ��������count

while((ch = getchar()) != EOF)//ѭ�����룬EOF����
{
if(ch == '{')
{
count ++;
}
                       //������{ʱ��������+1

if(ch == '}' && count == 0)

{
printf("��ƥ��\n");
return 0;
}                      

                           //������}��������Ϊ0�ˣ������ƥ�䣬��Ϊ}��{ǰ��

if(ch == '}' && count !=0)
{
count --;
}

                              //������}�Ҽ�������Ϊ0ʱ��������-1

}

if(count == 0)
{
printf("ƥ��!\n");
}
else
{
printf("��ƥ��!\n");
}//�жϼ�����count


return 0;
}

