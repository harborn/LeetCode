
#include <iostream>

int search(int A[], int n, int target) {

	int i = 0, j = n - 1;
	while (i <= j) {
		int m = (i + j) / 2;

		if (A[m] == target) return m;
		else if (A[m] < target) {
			if (A[i] <= A[m]) i = m + 1;
			else {
				if (A[j] >= target) i = m + 1;
				else return -1;
			}
		}
		else {

			if (A[m] <= A[j]) j = m - 1;
			else i = m + 1;

			if (A[i] <= A[m]) j = m - 1;
			else i = m + 1;

		}
	}
	
	return -1;
}

int search(int A[], int n, int target) {
	int l = 0, r = n - 1;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (A[m] == target) return m;
		if (A[m] >= A[l])
		{
			if (A[l] <= target && target< A[m])
				r = m - 1;
			else
				l = m + 1;
		}
		else
		{
			if (A[m]< target && target <= A[r])
				l = m + 1;
			else
				r = m - 1;
		}
	}
	return -1;
}


int main(void)
{
	int A[] = {3 ,5, 1 };
	int n = sizeof(A) / sizeof(int);
	int ret = search(A, n, 1);

	return 0;
}