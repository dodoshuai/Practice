#include<iostream>
#include<vector>
using namespace std;
/*double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
	int m = A.size();
	int n = B.size();
	if (m > n) {
		vector<int> temp = A; A = B; B = temp;
		int tmp = m; m = n; n = tmp;
	}
	int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
	while (iMin <= iMax) {
		int i = (iMin + iMax) / 2;
		int j = halfLen - i;
		if (i<iMax && B[j - 1]>A[i]) {
			iMin = i + 1;
		}
		else if (i > iMin && A[i - 1] > B[j]) {
			iMax = i - 1;
		}
		else {
			int maxLeft = 0;
			if (i == 0) { maxLeft = B[j - 1]; }
			else if (j == 0) { maxLeft = A[i - 1]; }
			else {
				maxLeft = A[i-1]>B[j-1]?A[i - 1]:B[j - 1];
			}
			if ((m + n) % 2 == 1) { return maxLeft; }
			int minRight = 0;
			if (i == m) { minRight = B[j]; }
			else if (j == n) { minRight = A[i]; }
			else { minRight = A[i] > B[j] ? B[j] : A[i]; }
			return (maxLeft + minRight) / 2.0;
			}
		}
	return 0.0;
	}
*/
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	
}
/*double abc(vector<int>& nums1, int a, vector<int>& nums2, int b, int mid) {
	if (a > nums1.size()) return;
	if (b > nums2.size()) return;
	if (mid == 1) return;

}*/
double abc(vector<int>& nums1, vector<int>& nums2) {
	int n = nums1.size();
	int m = nums2.size();
	//int mid1 = (m + n + 1) / 2;
	//int mid2 = (m + n + 2) / 2;
	
	int n1 = 0;
	int m1 = 0;
	int n2 = n-1;
	int m2 = m-1;
	int mid1 = (n2 -n1+1) / 2;
	int mid2 = (m2 -m1+ 1) / 2;
	//先比较中间值
	//再缩小范围
	//继续判断

		if (nums1[mid1] > nums2[mid2]) {
			n2 = mid1-1;
			m1 = mid2+1;
		}
		else if (nums1[mid1] < nums2[mid2]) {
			m2 =mid2-1;
			n1 = mid1+1;
		}
		mid1 = (n2 - n1 + 1) / 2+n1;
		mid2 = (m2 - m1 + 1) / 2+m1;

		
	
}
int main() {
	
	return 0;
}