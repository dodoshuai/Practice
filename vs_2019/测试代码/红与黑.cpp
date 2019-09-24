#include<iostream>
#include<vector>
using namespace std;
int n, m;
int nums = 0;
void dfs(int a, int b,vector<vector<int>>& res) {
	if ( a >= n || a < 0 || b<0 || b>=m||res[a][b]) {
		return;
	}
	nums++;
	res[a][b] = 1;
	dfs(a - 1, b,res);
	dfs(a, b - 1,res);
	dfs(a + 1, b,res);
	dfs(a, b + 1,res);
//	return nums;
}

int main() {
	//int n, m;
	int p,q;
	while (cin >> n >> m) {
		vector<vector<int>> res;

		for (int i = 0; i < n; i++) {
			vector<int> temp;
			for (int j = 0; j < m; j++) {
				char a;
				cin >> a;
				int x = 0;
				if (a == '#') {
					x = 1;
				}
				else {
					if (a == '@') {
						p = i;
						q = j;
					}
				}
				temp.push_back(x);
			}
			res.push_back(temp);
		}
		/*
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << " " << res[i][j];
			}
			cout << endl;
		}*/
		nums = 0;
		dfs(p, q, res);
		cout << nums << endl;
	}
	return 0;
}
/*链接：https://www.nowcoder.com/questionTerminal/5017fd2fc5c84f78bbaed4777996213a
来源：牛客网

#include<iostream>
#include<string.h>
using namespace std;
int a[20][20] = {0},res = 0,m,n;//注意是全局变量，多组数据时要在最后初始化
void dfs(int x,int y)
{
    if(a[x][y]==1||x<0||x>=m||y<0||y>=n)//递归的边界条件
        return ;
    res++;    //结果增加1
    a[x][y] = 1;//置1代表已经走过
    dfs(x-1,y);//分别对应上
    dfs(x+1,y);//下
    dfs(x,y-1);//左
    dfs(x,y+1);//右相邻格子
     
}
int main()
{
    while(~scanf("%d %d",&m,&n))
    {
        getchar();//为什么要getchar()?因为第一行9 6后面还有一个换行符
        int x,y;
        char c;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%c",&c);
                if(c=='@')
                {
                    x = i;
                    y = j;
                }else{
                    if(c=='#')
                        a[i][j] = 1;
                }
            }
            getchar();//同样的，吃掉每行最后一个换行符
        }
        dfs(x,y);
        printf("%d\n",res);
        res = 0;
        memset(a,0,sizeof(a));//全局变量初始化
    }
 
    return 0;
}
*/