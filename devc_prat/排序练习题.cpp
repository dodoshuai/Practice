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
	//堆排序
	/**
	*建堆，最后一行的非叶子节点为父节点开始向下调整，父节点不断向上移动，直到以根节点为父节点调整完毕 
	**/ 
	//一次调整_大堆 
	void adjust(int k,int m){
		int f=k;
		int c=2*k+1;
		while(c<=m){
			//确保数组下表不越界，并比较左右子节点的大小 
			if(c<m&&nums[c]<nums[c+1]){
				c+=1;
			}
			if(nums[f]>nums[c]){
				break;
			}else{
				Swap(nums[f],nums[c]);
				f=c;
				c=2*f+1;
			}
		}
	}
	void smalljust(int k,int m){
		int f=k;
		int c=2*k+1;
		while(c<=m){
			//确保数组下表不越界，并比较左右子节点的大小 
			if(c<m&&nums[c]>nums[c+1]){
				c+=1;
			}
			if(nums[f]<nums[c]){
				break;
			}else{
				Swap(nums[f],nums[c]);
				f=c;
				c=2*f+1;
			}
		}
	}
	void  a_b_heapsort(){
		int len=nums.size();
		for(int i=len/2-1;i>=0;i--){
			//大堆 
			//adjust(i,len-1);
			//小堆
			smalljust(i,len-1); 
		}
		print();
		cout<<"-------------------"<<endl;
		for(int i=len-1;i>0;i--){
			Swap(nums[0],nums[i]);
			//adjust(0,i-1);
			smalljust(0,i-1);
			cout<<"-------------------"<<endl;
			print();
		}
		
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
	//q.cpsort();
	q.a_b_heapsort();
	q.print();
	return 0;
} 
