
#include <iostream>

using namespace std;

int firstMissingPositive(int A[], int n) {
	for (int i = 0; i < n; i++) {
		int d = A[i];
		while (d > 0 && d <= n && A[d-1] != d) {
			int t = A[d-1];
			A[d-1] = d;
			d = t;
		}
	}
	for (int i = 0; i < n; i++) {
		if (A[i] != i+1) 
			return i+1;
	}
	return n+1;
}

int main(void)
{
	//int A[] = {1,2,0};
	//int A[] = {1,2,3};
	//int A[] = {-2,-1,0};
	int A[] = {3,4,-1,1};
	int n = sizeof(A) / sizeof(int);

	int res = firstMissingPositive(A, n);


	return 0;
}