#include<stdio.h>


union myunion{
int a;
char b;
};


int main(void)
{
union myunion s1;//共用体测试
s1.a=0x10000000;
if(s1.b==0x10)
puts("da端模式");
if(s1.b==0x00)
puts("xiao端模式");

int a;
a=0x10000001;//指针测试
char b=*((char*)(&a));
if(b==0x10)
puts("大端模式");
else if(b==0x01)
puts("小端模式");
return 0;
}
//————————————————
//版权声明：本文为CSDN博主「qq_32809273」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
//原文链接：https://blog.csdn.net/qq_32809273/article/details/53489887
