#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
using namespace std;
bool bj() {
	string str;
	getline(cin, str);
	char* x[7];
	int y = 0;
	int flag = 0;
	int l = 0;
	int r = 0;
	for (int i = 0; i < str.size(); ++i){
		if (str[i] == '-') {
			flag = 1;
			str[i] = '\0';
		}
		if (str[i] != ' ') {
			x[y++] = &str[i];
			if (flag != 1) {
				l++;
			}
			else {
				r++;
			}
			while (str[i] != ' ' && str[i] != '\0') {
				if (str[i] == '-') {
					str[i] = '\0';
					flag = 1;
					break;
				}
				i++;
			}
		}
		if (str[i] == ' ') {
			str[i] = '\0';
		}
	}
	//cout << "l=" << l << " r=" << r << endl;
	/*
	for (int i = 0; i < 6; ++i) {
		printf("%s\n", x[i]);
	}
	*/
	int a[6] = {0};
	int b[6] = { 0 };
	if (l == 2) {
		if (strlen(x[l - 1]) > 2) {
			a[l] = 1;
		}
		else {
			a[l] = x[l - 1][0];
		}
	}else if (l == 1) {
		if (strlen(x[l - 1]) > 2) {
			a[l] = 114;//¡®r¡¯
		}
		else {
			a[l] = x[l - 1][0];
		}
	}
	else {
		a[l] = x[l - 1][0];
	}
	if (r == 2) {
		if (strlen(x[l+r - 1]) > 2) {
			b[r] = 1;
		}
		else {
			b[r] = x[l+r - 1][0];
		}
	}else if (r == 1) {
		if (strlen(x[l+r - 1]) > 2) {
			b[r] = 114;//¡®r¡¯
		}
		else {
			b[r] = x[l+r - 1][0];
		}
	}
	else {
		b[r] = x[l+r - 1][0];
	}

	if (a[l] == 75)
		a[l] = 85;
	if (a[l] == 65)
		a[l] = 90;
	if (a[l] == 49)
		a[l] = 58;//'9'==57
	if (b[r] == 75)
		b[r] = 85;
	if (b[r] == 65)
		b[r] = 90;
	if (b[r] == 49)
		b[r] = 58;

	for (int i = 0; i < 6; i++) {
		cout <<"l--"<<i<<"--"<< a[i] << endl;
		cout <<"r--"<<i<<"--"<< b[i] << endl;
	}
	
	int ab = 0;
	if (a[2] != 1 && b[2] != 1) {
		if (l == r) {
			ab = a[l] > b[r] ? 1 : 2;
		}
		else if (l != r && (l != 4 && r != 4)) {
			ab = -1;
		}
		else if (l != r) {
			if (l == 4)
			{
				ab = 1;
			}
			else if (r == 4) {
				ab = 2;
			}
		}

	}
	else {
		if (a[2] == 1) {
			ab = 1;
		}
		else if(b[2]==1){
			ab = 2;
		}
	}
	//if(a[1]==10)
//	cout << "ab=" << ab << endl;
	if (ab == 1) {
		for (int i = 0; i < l; ++i) {
			if (i != 0)
				printf(" ");
			printf("%s", x[i]);
		}
	}
	else if (ab == 2) {
		for (int i = l; i < l + r; ++i) {
			if (i != l) {
				printf(" ");
			}
			printf("%s", x[i]);
		}
	}
	else if (ab == -1) {
		printf("ERROR");
	}

	return true;
}
	int main() {
		bj();
	return 0;
}