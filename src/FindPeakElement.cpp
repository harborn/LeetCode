
#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(const vector<int> &num) {
	int size = num.size();
	if (size <= 1) return 0;
	if (num[0] > num[1]) return 0;
	if (num[size - 1] > num[size - 2]) return size - 1;
	int i = 1, j = size - 2;
	while (i < j) {
		int m = (i + j) / 2;
		if (num[m] > num[m - 1] && num[m] > num[m + 1])
			return m;
		else if (num[m] > num[m + 1])
			j = m - 1;
		else
			i = m + 1;
	}

	return i;
}

int main(void) {

	int A[] = { 1, 2, 3, 1 };
	int n = sizeof(A) / sizeof(A[0]);

	vector<int> num;
	num.insert(num.begin(), A, A + n);

	int res = findPeakElement(num);

	return 0;
}