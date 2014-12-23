
#include <iostream>

using namespace std;

int removeDuplicates(int A[], int n) {

	int j = n - 1;
	int i = n - 2;

	int a = A[j];
	int cnt = 1;
	int res = n;
	while (i >= 0) {
		a = A[j];
		cnt = 1;
		while (A[i] == a && i >= 0) {
			cnt++;
			i--;
		}
		if (cnt > 2) {
			int k = j - 1;
			int l = i + 1;
			while (k < res) {
				A[l] = A[k];
				l++; k++;
			}
			res -= (j - i - 2);
		}
		j = i;
		i--;
	}

	return res;
}

int main(void)
{
	int A[] = { 1, 1, 1, 2, 2, 3 };
	int n = sizeof(A) / sizeof(int);

	int res = removeDuplicates(A, n);

	return 0;
}