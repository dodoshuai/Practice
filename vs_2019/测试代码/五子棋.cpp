#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define N 20
int a[][2] = { {0, 1}, {0, -1}, {1, 0}, { -1, 0}, {1, 1}, {1, -1}, { -1, 1}, { -1, -1} };
bool check(vector<vector<char>>& map) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '*' || map[i][j] == '+') {
				for (int k = 0; k < 8; k++) {
					int count = 1;
					int x = i + a[k][0];
					int y = j + a[k][1];
					while (x >= 0&& x < N && y >= 0 && y < 20 && map[x][y] == map[i][j]) {
						count++;
						x += a[k][0];
						y += a[k][1];
					}
					if (count == 5) {
						return true;
					}
				}
			}
		}
	}
	return false;
}
int main() {
//	string str;
	char q;
	vector<vector<char>> map(20);
	for (int i = 0; i < 20; i++) {
		vector<char> a(20);
		map[i] = a;
	}
	int x = 0;
	int y = 0;
	int count = 0;
	while (cin>>q) {
		map[x][y] = q;
		count++;
		y++;
		if (y == 20) {
			x++;
			y = 0;
		}
		if (x == 20) {
			if (check(map)) cout << "Yes" << endl;
			else cout << "No" << endl;
			x = 0;
			y = 0;
		}

	/*	vector<vector<char>> map(20);
		for (int i = 0; i < N; i++) {
			vector<char> a(20);
			for (int j = 0; j < N; j++) {
				cin >> a[j];
			}
			map[i] = a;
		}*/
	//	int flag = false;

	
	}
/*	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j]; 
		}
		cout << endl;
	}
*/
	return 0;
}
/*
....................
....................
....................
....................
......* .............
.......*............
........*...........
....++++.*..........
..........*.........
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
.......*............
...... + *++ + .........
.......*............
.......*............
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
*/