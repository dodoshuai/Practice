#include<stdio.h>
void SelectSort(int* arr, int size)//选择排序  
{  
    for (int i = 1; i < size; ++i)  
    {  
        int j = i;  
        int temp = arr[i];
	//	printf("%d\n",arr[i]) ;
        while (j>0 && temp < arr[j - 1])  
        {  printf("%d %d\n",arr[j],arr[j-1]) ; 
            arr[j] = arr[j - 1]; 
				
				printf("%d %d\n\n",j,j-1);
            j--;  
        }  
        //printf("111\n");
        arr[j] = temp;  
    }  
  
}  
void InsertSort(int* arr,int size)  
{  
    if (arr == NULL || size == 0)  
        return;  
    for (int i = 1; i < size; ++i)  //保证第一个位置是正确的  
    {  
        int j = i;  
        int temp = arr[i];  
        while (j>0 && temp < arr[j - 1])  
        {  printf("%d %d\n",arr[j],arr[j-1]) ; 
            arr[j] = arr[j - 1];  
            printf("%d %d\n\n",j,j-1);
            j--;  
        }  
        arr[j] = temp;  //插入  
    }  
}  
void ShellSort(int* arr, int size)  
{  
    int tag = size / 2;  
    while (tag >= 1)  
    {  
        for (size_t i = 0; i < size - tag; ++i)  
        {  
            int end = i;  
            int tmp = arr[i + tag];  
            while (end >= 0)     //从后向前进行循环  
            {  //printf("%d %d\n",arr[end],arr[]) ; 
                if (arr[end] > tmp)  
                    arr[end + tag] = arr[end];  //向后挪动  
                else  
                    break;  
  
                end -= tag;  
            }  
            arr[end + tag] = tmp;  
        }  
        tag/= 2;  
    }  
      
}  



int  main()
{
	int i;
int A[9]={5,9,7,4,2,1,6,8,3};
//SelectSort(A,9);
//InsertSort(A,9);
ShellSort(A,9);
for(i=0;i<9;i++)
printf("%d",A[i]);	
	return 0;
}
