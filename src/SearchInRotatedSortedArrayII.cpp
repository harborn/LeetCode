
#include <iostream>

using namespace std;

bool search(int A[], int n, int target) {
	int i = 0, j = n - 1;
	while (i <= j) {
		int m = (i + j) / 2;
		if (A[m] == target) return true;
		if (m > i && A[i] == A[m]) {
			int k = i + 1;
			while (A[k] == A[m] && k < m) k++;
			if (k == m) i = m + 1;
			else j = m - 1;
		}
		else if (j > m && A[m] == A[j]) {
			int k = m + 1;
			while (A[k] == A[j] && k < j) k++;
			if (k == j) j = m - 1;
			else i = m + 1;
		}
		else {
			if (A[i] <= A[m]) {
				if (target >= A[i] && target < A[m])
					j = m - 1;
				else
					i = m + 1;
			}
			else {
				if (target > A[m] && target <= A[j])
					i = m + 1;
				else
					j = m - 1;
			}
		}
	}
	return false;
}

int main(void) {

	//int A[] = { 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 1, 1, 1, 1 };
	int A[] = { 3, 1 };
	int n = sizeof(A) / sizeof(int);

	bool ret = search(A, n, 3);
	cout << ret << endl;

	return 0;
}