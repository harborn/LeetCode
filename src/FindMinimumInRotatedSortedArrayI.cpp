
#include <iostream>
#include <vector>

using namespace std;

int binarySearch(int A[], int n, int t) {

	int s = 0, e = n - 1;
	
	while (s <= e) {
		int m = (s + e) / 2;
		if (t < A[m]) e = m - 1;
		else if (t > A[m]) s = m + 1;
		else return m;
	}

	return -1;
}

int findMin(vector<int> &num) {
	int s = 0, e = num.size() - 1;
	int min = num[0];
	while (s <= e) {
		int m = (s + e) / 2;
		//cout << num[s] << endl;
		//cout << num[e] << endl;
		if (num[m] < min) min = num[m];
		if (num[s] <= num[m]) {
			if (num[s] < min) min = num[s];
			s = m + 1; 
		} else {
			if (num[e] < min) min = num[e];
			e = m - 1;
		}
	}
	return min;
}

int main(void)
{
	int A[] = { 0, 1, 2, 4, 5, 6, 7 };
	int n = sizeof(A) / sizeof(int);

	int ret = binarySearch(A, n, 0);

	vector<int> num; // 4 5 6 7 0 1 2
	num.push_back(3);
	num.push_back(1);
	num.push_back(2);
	/*num.push_back(6);
	num.push_back(7);
	num.push_back(0);
	num.push_back(1);
	num.push_back(2);*/

	int ret2 = findMin(num);

	return 0;
}