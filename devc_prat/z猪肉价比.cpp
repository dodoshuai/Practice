#include<iostream>
using namespace std;
int main(){
int n;
while(cin>>n&&n!=0){
int q=0;
while(n>1){
if(n%3!=0){
n=n/3+1;}else{
n=n/3;
} 
q++;
} 
cout<<q<<endl;
} 
return 0;
}
