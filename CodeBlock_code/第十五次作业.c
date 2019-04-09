/**1.一个数组中只有两个数字是出现一次，
其他所有数字都出现了两次。
找出这两个数字，编程实现。


2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
给20元，可以多少汽水。
编程实现。

3.模拟实现strcpy
4.模拟实现strcat
*/
#include<stdio.h>

void two_number();


int main(){
    two_number();
 return 0;
}
void two_number(){
        int ans[2];
        int count=0;
        int number[]={1,2,3,2,3,4,5,5,6,6};
        for(int i=0;i<(sizeof(number)/sizeof(number[0]));i++){
            int j=0;
                for(;j<(sizeof(number)/sizeof(number[0]));j++){
                    if(number[i]==number[j])
                    break;
                }
                if(j==(sizeof(number)/sizeof(number[0]))){
                    ans[count++]=number[i];
                    if(count>=3)
                        break;
                }
            }

            for(int i=0;i<(sizeof(ans)/sizeof(ans[0]));i++{
                printf("%3d",ans[i]);
            }
            printf("\n");
}
