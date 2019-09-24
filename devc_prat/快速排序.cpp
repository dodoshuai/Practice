#include<iostream>
#include<vector>
using namespace std;
class sy{
	public:
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
		void Swap(int &a,int &b){
		int tmp=a;
		a=b;
		b=tmp;
	}
/*	void quicksort(int left,int right){		
		if(left<right){
			int i=left,j=right,t=nums[left];
			while(i<j){
				while(i<j&&nums[i]<=t){
					i++;
				}
				while(i<j&&nums[j]>=t){
					j--;
				}
				if(i<j){
					Swap(nums[i],nums[j]);
				}
			}
			
			quicksort(left,i-1);
			quicksort(i+1,right);			
		}
	}
	*/
	void qs(int l,int r){
		if(l<r){
			int i=l,j=r,t=nums[l];
			while(i<j){
				while(i<j&&nums[j]>=t){
					j--;
				}
				while(i<j&&nums[i]<=t){
					i++;
				}
				if(i<j){
					Swap(nums[i],nums[j]);
				}
			}
			nums[l]=nums[i];
			nums[i]=t;
			qs(l,i-1);
				qs(i+1,r);
			
		}
	}
	void dd(int k,int m){
		int f=k;
		int c=f*2+1;
		while(c<m){
			if(c<m-1&&nums[c]<nums[c+1]){//m-1 È·±£c+1³¬½ç 
				c++;
			}
			if(c<m&&nums[c]<=nums[f]){
				break;
			}else{
				Swap(nums[c],nums[f]);
				f=c;
				c=f*2+1;
			}
		}
	}
	void create_head(){
		int len=nums.size();
		for(int i=len/2-1;i>=0;i--){
			dd(i,len);
		}
	}
	void head(){
		int len=nums.size();
		create_head();
		for(int i=len;i>1;i--){
			Swap(nums[i-1],nums[0]);
			dd(0,i-1);
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
	//q.a_b_heapsort();
	//q.qs(0,a.size()-1); 
	q.head();
	q.print();
	return 0;
}  
