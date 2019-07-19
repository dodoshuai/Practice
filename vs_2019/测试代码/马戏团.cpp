/*#include<iostream>
#include<vector>
using namespace std;
typedef struct boo {
	int id;
	int weight;
	int tall;
}Boo;
void Swap(Boo& a, Boo& b) {
	Boo temp;
	temp.id = a.id;
	temp.tall = a.tall;
	temp.weight = a.weight;
	a.id = b.id;
	a.tall = b.tall;
	a.weight = b.weight;
	b.id = temp.id;
	b.tall = temp.tall;
	b.weight = temp.weight;
}
int main() {
	int n;
	cin >> n;
	vector<Boo> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i].id >> nums[i].weight >> nums[i].tall;
	}
	int min;
	for (int i = 0; i < nums.size(); ++i) {
		min = i;
		for (int j = i + 1; j < nums.size(); ++j) {
			if (nums[min].tall > nums[j].tall|| nums[min].weight > nums[j].weight) {
				min = j;
			}
		}
		if (min != i) {
			Swap(nums[i], nums[min]);
		}
	}
	int x = 0;
	int y = 1;
	int i;
	for ( i = 0; 1; i++) {
		if (x >= n) break;
		x += i;
	}
	cout << i << endl;
}*/
/*
6
1 65 100
2 75 80
3 80 100
4 60 95
5 82 101
6 81 70
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

struct node {
	int w;
	int h;
	node(int _w, int _h) : w(_w), h(_h) {}
};

bool cmp(node first, node next) {
	if (first.w != next.w) {
		return first.w < next.w;
	}
	else {
		return first.h > next.h;
	}
}

int main() {
	int input;

	while (cin >> input) {
		int num, w, h;
		vector<node> vec;
		for (int i = 0; i < input; ++i) {
			cin >> num >> w >> h;
			node tmp(w, h);
			vec.push_back(tmp);
		}

		stable_sort(vec.begin(), vec.end(), cmp);

		vector<int> dq(input + 1, 0);
		dq[0] = 1;
		for (int i = 0; i < input; ++i) {
			dq[i] = 1;
			for (int j = 0; j < i; ++j) {
				if (vec[j].h <= vec[i].h && dq[j] + 1 >= dq[i]) {
					dq[i] = dq[j] + 1;
				}
			}
		}

		int max = 0;
		for (int i = 0; i < dq.size(); ++i) {
			if (max < dq[i]) max = dq[i];
		}

		cout << max << endl;
	}

	return 0;
}
/*
经过排序，可知
符合叠罗汉要求的序列
需要筛选，
对所选值之前的值进行遍历，符合要求的值就决定了所选值的对应大小
*/
