#include<iostream>
#include<vector>
using namespace std;
#define N 10
int res;
int dfs(vector<vector<char>>& map,int x,int y,vector<vector<int>> &q,int num) {
	if (x < 0 || x >= N || y < 0 || y >= N||q[x][y]==1) {
		return INT_MAX;
	}
	if (x == 9 && y == 8)
		return num;
	q[x][y] = 1;
	int d1=dfs(map,x + 1, y,q,num+1);
	int d2=dfs(map,x - 1, y,q,num+1);
	int d3=dfs(map,x, y + 1,q,num+1);
	int d4=dfs(map, x, y - 1,q,num+1);
	int min = d1 > d2 ? d2 : d1;
	min = min > d3 ? d3 : min;
	min = min > d4 ? d4 : min;
	q[x][y] = 0;
	return min;
	
}
int main() {
	vector<vector<int>> aa(N);
	vector<vector<char>> map(N);
	for (int i = 0; i < N; i++) {
		vector<char> a(N);
		vector<int> b(N);
			aa[i] = b;
		map[i] = a;
	}
	char c;
	int x = 0;
	int y = 0;
	while (cin >> c) {
		
			map[x][y] = c;
			if (c == '#') {
				aa[x][y] = 1;
			}
			else if(c=='.'){
				aa[x][y] = 0;
			}
			y++;
			if (y == N) {
				x++;
				y = 0;
			}
		if(x!=N){

		}
		else {
		/*	for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
				//	cout << map[i][j]<<" ";
					cout << aa[i][j] << " ";
				}
				cout << endl;
			}
			*/
		int count=	dfs(map, 0, 1,aa,0);
		cout << count << endl;
	/*	cout << INT_MAX << endl;
		cout << map[9][8] << endl;
		cout << aa[9][8] << endl;
		*/
			x = 0;
			y = 0;
		}
	}

	return 0;
}
/*
#.########
#........#
#........#
#........#
#........#
#........#
#........#
#........#
#........#
########.#
#.########
#........#
########.#
#........#
#.########
#........#
########.#
#........#
#.######.#
########.#
*/

/*
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <exception>
#include <iomanip>
#include <memory>
#include <sstream>

using namespace std;

bool check(int x, int y, int m, int n, vector<vector<char>>& room)
{
	return x >= 0 && x < m && y >= 0 && y < n && room[x][y] == '.';
}

int main(int argc, char** argv)
{
	//freopen("in.txt", "r", stdin);
	int m = 10, n = 10;
	string row;
	while (cin >> row)
	{
		vector<vector<char>> room(m, vector<char>(n));
		for (int i = 0; i < m; ++i)
		{
			if (i > 0) cin >> row;
			for (int j = 0; j < n; ++j)
			{
				room[i][j] = row[j];
			}
		}

		int sx = 0, sy = 1;
		int ex = 9, ey = 8;
		vector<pair<int, int>> cur;
		cur.emplace_back(sx, sy);
		room[sx][sy] = ' ';
		int step = 0;
		bool reach = false;
		while (!cur.empty())
		{
			vector<pair<int, int>> next;
			for (auto& pr : cur)
			{
				if (pr.first == ex && pr.second == ey)
				{
					reach = true;
					break;
				}
				int x = pr.first, y = pr.second;
				if (check(x - 1, y, m, n, room))
				{
					room[x - 1][y] = ' ';
					next.emplace_back(x - 1, y);
				}
				if (check(x + 1, y, m, n, room))
				{
					room[x + 1][y] = ' ';
					next.emplace_back(x + 1, y);
				}
				if (check(x, y - 1, m, n, room))
				{
					room[x][y - 1] = ' ';
					next.emplace_back(x, y - 1);
				}
				if (check(x, y + 1, m, n, room))
				{
					room[x][y + 1] = ' ';
					next.emplace_back(x, y + 1);
				}
			}
			if(reach) break;
			++step;
			cur = next;
		}

		cout << step << endl;
	}

	return 0;
}

*/