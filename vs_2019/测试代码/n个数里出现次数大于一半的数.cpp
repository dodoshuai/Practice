#include<iostream>
#include<vector>
#include<map>
#include<stdio.h>
using namespace std;
int main() {
	int nums[105];
	int c=0;
		while (scanf("%d", &nums[c++]) != EOF);

		map<int, int > nums_map;
		for (int i = 0; i < c; ++i) {
			nums_map[nums[i]] = 0;
		}
	for (int i = 0; i < c; ++i) {
		nums_map[nums[i]]++;
		if (nums_map[nums[i]] >= (c / 2))
		{
			cout << nums[i] << endl;
			break;
		}
	}
	return 0;
}