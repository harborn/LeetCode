

#include <iostream>

using namespace std;

double findMedianSortedArrays(int A[], int m, int B[], int n) {
	if (A == NULL || m <= 0) {
		if (B == NULL || n <= 0)
			return 0;
		else{
			if (n % 2) {
				return B[n / 2];
			}
			else {
				return (double)(B[n / 2] + B[n / 2 - 1]) / 2;
			}
		}
	}
	if (B == NULL || n <= 0) {
		if (A == NULL || m <= 0)
			return 0;
		else {
			if (m % 2) {
				return A[m / 2];
			}
			else {
				return (double)(A[m / 2] + A[m / 2 - 1]) / 2;
			}
		}
	}

	int d1 = 0, d2 = 0;
	int i = 0, j = 0;
	int cnt = 0, len = (m + n) / 2;
	while (i < m && j < n && cnt <= len) {
		d1 = d2;
		if (A[i] <= B[j]) {
			d2 = A[i];
			i++;
		}
		else {
			d2 = B[j];
			j++;
		}
		cnt++;
	}
	while (i < m && cnt <= len) {
		d1 = d2;
		d2 = A[i];
		i++;
		cnt++;
	}
	while (j < n && cnt <= len) {
		d1 = d2;
		d2 = B[j];
		j++;
		cnt++;
	}

	if ((m + n) % 2)
		return d2;
	else
		return (double)(d1 + d2) / 2.0;
}

int main(void)
{

	int A[] = { 2,2,2 };
	int B[] = { 2,2,2,2 };

	double res = findMedianSortedArrays(A, 3, B, 4);
	return 0;
}
