#include<iostream>

using namespace std;

int main() {
	int l;
	int r;
	cin >> l >> r;
	int num = (l / 4) * (r / 4) * 8;
		num += (l % 4 * (r / 4) * 2);
		num += (r % 4 * (l / 4) * 2);
		if (l % 4 >2) {
			if (r % 4 > 2) {
				num += 5;
			}
			else {
				num += (r % 4 * 2);
			}
		}
		else {
			if (r % 4 < 2)
			{
				num += ((l % 4) * (r % 4));
			}
			else {
				num += (2 * (l % 4));
			}
		}
		cout << num << endl;
	return 0;
}