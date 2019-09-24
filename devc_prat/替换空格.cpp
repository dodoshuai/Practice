#include<iostream>
#include<stdio.h>
using namespace std;
void replaceSpace(char *str,int length) {
        if(str==NULL||length==0)
            return ;
        int count=0;
        int num=0;
        char *aa=str;
        while((*aa)!='\0'){
        	num++;
            if(*aa++==' ')
                count++;
            }
       int newstring=num+count*2;
       
        if(newstring>length)
            return;
        int pnewlength=newstring;
        int poldlength=num;
        while(poldlength>0)
        {
            if(str[poldlength]==' ')
            {
                str[pnewlength--]='0';
                str[pnewlength--]='2';
                str[pnewlength--]='%';
            }
            else
            {
                str[pnewlength--]=str[poldlength];
            }
            poldlength--;
        }
	}
	int  main(){
		//char str[20] ="hello world";
		char str[20]=" helloworld";
		//getline(str,cin);
		printf("%s\n",str);
		int num=0;
		for(int i=0;str[i]!='\0';i++){
			num++;
		}
		replaceSpace(str,20);
		printf("%s",str);
		return 0;
	}
