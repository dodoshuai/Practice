#include<iostream>
using namespace std;
int fun(int n)
{
	int cnt=0;
	while(n>1)
	{
		if(n%3!=0)
		  n=n/3+1;
		else
		  n=n/3;
		cnt++;
	}
	return cnt;
}

int main(){
    int n;
    /*while(cin>>n){
    	if(n==0)
    	break;
        int q=1;
        int i;
        for( i=0;i<32;i++){
            if(q>n)
                break;
            q=q<<1;
        }
        cout<<i-1<<endl;
    }
    */
    while(cin>>n&&n!=0){
    	cout<<fun(n)<<endl;
    }
    
    return 0;
}
