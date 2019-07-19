#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<int> r(n+1);
		for (int i = 1; i <= n; i++) {
			cin >> r[i];
		}
		//sort(r.begin(), r.end());
		int k, d;
		int x = 1;
		cin >> k >> d;
		long long a[51][11][2] = { 0 };
		long long ans = 0;

		for (int i = 1; i <= n; i++) {
			a[i][1][0] = a[i][1][1] = r[i];
			for (int j = 2; j <=k; j++) {
				for (int l = i - 1; l >= max(i - d, 1); l--) {
					a[i][j][0] = max(a[i][j][0], max(a[l][j - 1][1] * r[i], a[l][j - 1][0] * r[i]));
					a[i][j][1] = min(a[i][j][1], min(a[l][j - 1][1] * r[i], a[l][j - 1][0] * r[i]));
				}
			}
			ans = max(ans, max(a[i][k][0], a[i][k ][1]));
		}
		

		//cout << ans << endl;
		printf("%lld\n", ans);
	}
}

/*

#include<cstdio>
#include<algorithm>
using namespace std;
long long f[51][51][2];
int a[55];
int main(){
	int n,k,d;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	scanf("%d%d",&k,&d);
	long long ans=0;
	for(int i=1;i<=n;i++){//遍历每一个人人
		f[i][1][0]=f[i][1][1]=a[i];//仅选一个人时，乘积为本身
		for(int j=2;j<=k;j++){
			for(int l=i-1;l>=max(i-d,1);--l){
			//在第i个数之前取一个与目前数乘积最大的 ，且与当前数距离不超过d
				f[i][j][0]=max(f[i][j][0],max(f[l][j-1][1]*a[i],f[l][j-1][0]*a[i]));
				f[i][j][1]=min(f[i][j][1],min(f[l][j-1][1]*a[i],f[l][j-1][0]*a[i]));
			}
		}
		ans=max(ans,max(f[i][k][0],f[i][k][1]));
	}
	printf("%lld\n",ans);
	return 0;
}
*/