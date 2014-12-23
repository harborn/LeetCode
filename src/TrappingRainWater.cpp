
#include <iostream>
#include <algorithm>
using namespace std;

int GetWater(int A[], int r, int l) {
	if (l <= r + 1) return 0;
	int min = A[r] <= A[l] ? A[r] : A[l];
	int sum = 0;
	int i = r + 1;
	while (i < l) {
		if (min > A[i])
			sum += min - A[i];
		i++;
	}
	return sum;
}

int trap(int A[], int n) {
	int i = 0;
	while (A[i] == 0) i++;
	int res = 0;
	while (i < n) {
		int a = A[i];
		int j = i + 1;
		int p = j;
		int m = 0;
		while (j < n) {
			if (A[j] >= a) {
				p = j;
				break;
			}
			else if (A[j] > m) {
				p = j;
				m = A[j];
			}
			j++;
		}
		if (p < n)
			res += GetWater(A, i, p);
		i = p;
	}
	return res;
}

int trap2(int A[], int n) {
	if (n<2) return 0;
	int *maxL = new int[n], *maxR = new int[n];
	int max = A[0];
	maxL[0] = 0;
	for (int i = 1; i<n - 1; i++)
	{
		maxL[i] = max;
		if (max < A[i])
			max = A[i];
	}
	max = A[n - 1];
	maxR[n - 1] = 0;
	int ctrap, ttrap = 0;
	for (int i = n - 2; i>0; i--)
	{
		maxR[i] = max;
		ctrap = min(maxL[i], maxR[i]) - A[i];
		if (ctrap>0)
			ttrap += ctrap;
		if (max<A[i])
			max = A[i];
	}
	delete maxL, maxR;
	return ttrap;
}

int main(void)
{
	int A[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	//int A[] = { 5, 4, 1, 2 };
	//int A[] = { 5, 2, 1, 2, 1, 5 };
	int n = sizeof(A) / sizeof(int);

	//int w = GetWater(A, 0, 5);

	int res = trap2(A, n);

	return 0;
}