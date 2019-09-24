#include<stdio.h>
int main()
{
    int a[] = { 1, 2, 3, 4 };
    printf("%d\n", sizeof(a));//16-->sizeof(a)表示整个数组，计算整个数组大小，单位字节，这里a是整型数组，有四个元素，因此是16
    printf("%d\n", sizeof(a + 0));//4-->a+0表示数组首元素的地址，即“1”的地址
    printf("%d\n", sizeof(*a));//4-->a代表数组首元素的大小，对a解引用，就是首元素的大小
    printf("%d\n", sizeof(a + 1));//4-->类似于上述的a+0，这里代表的是“2”的地址
    printf("%d\n", sizeof(a[1]));//4-->相当于上述的a+1，代表的是“2”的地址
    printf("%d\n", sizeof(&a));//4-->&a表示整个数组的地址，在32位平台下，一个地址的大小为4
    printf("%p\n",&a);
    printf("%d\n", sizeof(*&a));//16-->&a表示整个数组的地址，解引用表示整个数组的大小
    printf("%d\n", sizeof(&a + 1));//4-->&a表示整个数组，再加一表示跳过整个数组后的下一个元素地址，虽然不存在，求地址仍然是合法的，访问就不合法了
    printf("%p\n",&a+1);
	printf("%d\n", sizeof(&a[0]));//4-->首元素的地址
    printf("%p\n",&a[0]);
    printf("%d\n", sizeof(&a[0] + 1));//4-->首元素地址加一，即就是第二个元素“2”的地址
     printf("%p\n",&a[0]+1);

    return 0;
} 
