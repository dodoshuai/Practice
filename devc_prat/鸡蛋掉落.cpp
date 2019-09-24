#include<iostream>
#include<vector>
using namespace std;
int superEggDrop(int K, int N) {
       vector<int>record(K+1,1);//包含0个鸡蛋的情况，所以需要申请K+1个空间。只尝试一次的时候，无论多少个鸡蛋，最高都只能测1层
    record[0]=0;//0个鸡蛋的情况特殊化处理，为0
    int move=2;//如果尝试2次
    while(record[K]<N)//当record[K]大于等于N的时候就退出循环
    {
        for(int i=K;i>=1;i--)//从vector的后面开始更新，这样不影响其他位置的vector元素的更新
            record[i]=record[i]+record[i-1]+1;
        move++;//move+1，再尝试一次
    }
        
    return move-1;//返回需要的尝试次数
    }

int main(){
	int k;
	int n;
	cin>>k>>n;
	cout<<superEggDrop(k,n)<<endl;
	return 0;
	
} 
