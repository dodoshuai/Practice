/**1.һ��������ֻ�����������ǳ���һ�Σ�
�����������ֶ����������Ρ�
�ҳ����������֣����ʵ�֡�


2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
��20Ԫ�����Զ�����ˮ��
���ʵ�֡�

3.ģ��ʵ��strcpy
4.ģ��ʵ��strcat
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
