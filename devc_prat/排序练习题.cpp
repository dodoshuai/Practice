/*
�����㷨ʵ�� 
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
	//ֱ�Ӳ������� 
	/*
		�ڴ��㷨����Ϊi֮ǰ�Ķ����ź���ģ����ԴӴ���С��������������Ͳ���
		�ܵ����������
		1.ǰ���ں�   ��ǰһ��ֵ��ֵ����һ��
		2.ǰ���ڻ�С�ں�	����ѭ��
		��ԭ����i����ֵ��ֵ��j+1�� 
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
	void zjpx(){//ѡ������ 
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
	//ϣ������ 
	void xiersort(){
		int x=nums.size()/2;
		while(x){
			
		
		for(int i=x;i<nums.size();++i){
			if(nums[i]<nums[i-x]){
				//��¼�㣬ϣ�������ܽ���ǽ������ȵ����ź��� 
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
	//������
	/**
	*���ѣ����һ�еķ�Ҷ�ӽڵ�Ϊ���ڵ㿪ʼ���µ��������ڵ㲻�������ƶ���ֱ���Ը��ڵ�Ϊ���ڵ������� 
	**/ 
	//һ�ε���_��� 
	void adjust(int k,int m){
		int f=k;
		int c=2*k+1;
		while(c<=m){
			//ȷ�������±�Խ�磬���Ƚ������ӽڵ�Ĵ�С 
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
			//ȷ�������±�Խ�磬���Ƚ������ӽڵ�Ĵ�С 
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
			//��� 
			//adjust(i,len-1);
			//С��
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
