#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
ll rzdg(ll a,ll b){
	return b==0?abs(a):rzdg(b,a%b);
}
ll ret_jj(ll a,ll b){
	ll l00l=rzdg(a,b);
	a/=l00l;
	b/=l00l;
	ll ret=a*b;
	return ret;
}

int main(){	
	ll a1,a2,b1,b2;
	scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2);
	cout<<ret_jj(a1,b1)<<endl;
	cout<<ret_jj(a2,b2)<<endl;
	return 0;
}

/*
#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}
struct Fraction{
	ll up,down;
};
Fraction reduction(Fraction result)
{
	if(result.down<0)
	{
		result.down =-result.down;
		result.up=-result.up;
	}
	if(result.up==0)
	{
		result.down=1;
	}
	else
	{
		ll d=gcd(abs(result.up),abs(result.down));
		result.up=result.up/d;
		result.down=result.down/d;
	}
	return result;
}
Fraction add(Fraction a,Fraction b)
{
	Fraction result;
	result.up=a.up*b.down+a.down*b.up;
	result.down=a.down*b.down;
	return  reduction(result);
}
Fraction minu(Fraction a,Fraction b)
{
	Fraction result;
	result.up=a.up*b.down-a.down*b.up;
	result.down=a.down*b.down;
	return  reduction(result);
}
Fraction multi(Fraction a,Fraction b)
{
	Fraction result;
	result.up=a.up*b.up;
	result.down=a.down*b.down;
	return  reduction(result);
}
Fraction divide(Fraction a,Fraction b)
{
	Fraction result;
	result.up=a.up*b.down;
	result.down=a.down*b.up;
	return  reduction(result);
}
void prin(Fraction a)
{
	a=reduction(a);
	if(a.up<0) printf("(");
	if(a.down==1)
	{
		printf("%lld",a.up);
	}
	else if(abs(a.up)>abs(a.down))
	{
		printf("%lld %lld/%lld",a.up/a.down,abs(a.up)%a.down,a.down);
	}
	else
	{
		printf("%lld/%lld",a.up,a.down);
	}
	if(a.up<0) printf(")");
}
Fraction choose(Fraction a,Fraction b,char c)
{
	if(c=='+')
	{
	    return 	add(a,b);
	}
	else if(c=='-')
	{
		return minu(a,b);
	}
	else if(c=='*')
	{
		return multi(a,b);
	 } 
 } 
int main()
{
	Fraction temp1,temp2;
	scanf("%lld/%lld %lld/%lld",&temp1.up,&temp1.down,&temp2.up,&temp2.down);
	temp1=reduction(temp1);
	temp2=reduction(temp2);
	char str[4]={'+','-','*','/'};
	for(int i=0;i<3;i++)
	{
		prin(temp1);
		printf(" %c ",str[i]);
		prin(temp2);
		printf(" = ");
		prin(choose(temp1,temp2,str[i]));
		printf("\n");
	}
	prin(temp1);
	printf(" %c ",str[3]);
	prin(temp2);
	printf(" = ");
	if(temp2.up==0) printf("Inf");
	else prin(divide(temp1,temp2));
	printf("\n");
	return 0;
}
*/
