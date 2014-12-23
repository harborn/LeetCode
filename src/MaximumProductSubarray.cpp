
#include <iostream>
using namespace std;

int maxProduct(int A[], int n) {

	long long max = A[0], min = A[0];
	int res = 0;
	for (int i = 1; i < n; i++) {
		if (A[i] < 0) {
			
			
		}
		else if (A[i] > 0) {

			
		}
		else if (i < n - 1) {
			i++;
			max = A[i];
			min = A[i];
		}

		if (max > res) res = max;
	}

	return res;
}

int main(void) {

	int A[] = { 2, 3, -2, 4 };
	int n = sizeof(A) / sizeof(int);

	int res = maxProduct(A, n);


	return 0;
}