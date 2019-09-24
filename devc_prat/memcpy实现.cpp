#include<stdio.h>
#include <stddef.h>
#include<iostream>
using namespace std;
void * memcpy(void * destination,const void * source, size_t num){
	char *s1=(char *)destination;
	const char *s2=(const char *)source;
	while(num--){
		*s1++=*s2++;
	}
	return destination;
}
void * memmove(void *destination,const void * source,size_t num){
	char *s1=(char *)destination;
	const char *s2=(const char *)source;
	if((s2+num)>s1){
		cout<<"s2+num="<<s2+num<<endl;
		cout<<"s1="<<s1<<endl;
		while(num--){
			s1[num]=s2[num];
		}
		cout<<"bb--------"<<endl;
	}else{
		/*printf("s1=%p\n",s1);
		printf("s2+num=%p\n",s2+num);
		printf("s2+num=%p\n",s2+num);	
		*/
		//验证地址 
		while(num--){
		*s1++=*s2++;
	}
	}
}
/*
由验证结果可知cpy是不会正确处理拷贝资源重叠的情况的 
*/
int main(){
	int a[10]={1,2,3,4,5,6,7};
	int b[10];
	for(int i=0;i<10;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	memmove((void*)&a[3],(void *)&a[0],20);
	for(int i=0;i<10;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
		memcpy((void*)&a[3],(void *)&a[0],20);
	for(int i=0;i<10;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
