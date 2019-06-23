/*
排序算法实现 
*/
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

class sy{
	public:sy(){
		
	}
	sy(vector<int> &a){
		for(int i=0;i<a.size();++i){
			nums.push_back(a[i]);
		}
	}
	void print(){
		cout<<"---------------------"<<endl;
		for(int i=0;i<nums.size();++i){
			cout<<i<<"="<<nums[i]<<endl;
		}
		cout<<"---------------------"<<endl;
	}
	//直接插入排序 
	/*
		在此算法中因为i之前的都是排好序的，所以从大向小如果不符合条件就插入
		总的情况有两种
		1.前大于后   将前一个值赋值给后一个
		2.前等于或小于后	跳出循环
		将原本的i处的值赋值给j+1处 
	*/ 
	void cpsort(){
		for(int i=1;i<nums.size();++i){
			int qq=nums[i];
			int j=0;
			for(j=i-1;j>=0;--j){
				if(nums[j]>qq){
					nums[j+1]=nums[j];
				}else{
					break;
				}
			}
				nums[j+1]=qq; 
			
		}
	}
	void zjpx(){//选择排序 
		int min;
		for(int i=0;i<nums.size();++i){
			min=i;
			for(int j=i+1;j<nums.size();++j){
				if(nums[min]>nums[j]){
					min=j;
				}
			}
			if(min!=i){
				Swap(nums[i],nums[min]);
			}
		}
	}
	//希尔排序 
	void xiersort(){
		int x=nums.size()/2;
		while(x){
			
		
		for(int i=x;i<nums.size();++i){
			if(nums[i]<nums[i-x]){
				//记录点，希尔排序，总结就是将间隔相等的先排好序 
				int q=i-x;
				int p=nums[i];
				nums[i]=nums[i-x];
				while(q>=0&&p<nums[q]){
					nums[q+x]=nums[q];
					q-=x;
				}
				nums[q+x]=p;
			}
		}
		print();
		x/=2;
		}
	}
	void Swap(int &a,int &b){
		int tmp=a;
		a=b;
		b=tmp;
	}
	private:
		vector<int> nums;
};


int main(){

	int n;
	cin>>n;	
	vector<int> a(n,0);
	for(int i=0;i<a.size();++i){
		cin>>a[i];
	}
	sy q(a);
	q.print();
	//q.zjpx();
	//q.xiersort();
	q.cpsort();
	q.print();
	return 0;
} 
