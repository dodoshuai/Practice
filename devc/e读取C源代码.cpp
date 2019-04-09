/*
#include<stdio.h>
int main()
{
	char ch;//这是存储器 
	int cout=0;//定义一个计数器 
	while(ch=getchar()!=EOF)
	{
		if(ch=='{')
		{
		cout+=1;
		}
		if(ch=='}'&&cout==0)
		{
			printf("不匹配！\n");
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
int count = 0;//定义一个计数器count

while((ch = getchar()) != EOF)//循环输入，EOF结束
{
if(ch == '{')
{
count ++;
}
                       //当遇到{时，计数器+1

if(ch == '}' && count == 0)

{
printf("不匹配\n");
return 0;
}                      

                           //当遇到}但计数器为0了，输出不匹配，即为}在{前边

if(ch == '}' && count !=0)
{
count --;
}

                              //当遇到}且计数器不为0时，计数器-1

}

if(count == 0)
{
printf("匹配!\n");
}
else
{
printf("不匹配!\n");
}//判断计数器count


return 0;
}

