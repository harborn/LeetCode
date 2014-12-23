

#include <iostream>

int removeDuplicates(int A[], int n) {
	if (n <= 1) return n;
	int f = A[0] - 1;
	int i = 0, c, j;
	while (i < n) {
		c = A[i];
		i++;
		while (i < n && c == A[i]) {
			A[i] = f;
			i++;
		}
	}
	
	int len = 1;
	i = 1;
	while (i < n && A[i] != f) {
		i++; len++;
	}
	j = i + 1;
	while (j < n) {
		while (j < n && A[j] == f) j++;
		while (j < n && A[j] != f) {
			A[i] = A[j];
			i++; j++;
			len++;
		}
	}
	return len;
}

int removeElement(int A[], int n, int elem) {
	if (n <= 0) return 0;

	int m = A[0];
	int i = 1;
	while (i < n) {
		if (A[i] < m) m = A[i];
		i++;
	}

	int f = m - 1;
	int rc = 0;
	i = 0; 
	while (i < n) {
		if (A[i] == elem) {
			A[i] = f;
			rc++;
		}
		i++;
	}
	i = 0;
	while (i < n && A[i] != f) {
		i++;
	}
	int j = i;
	while (j < n) {
		while (j < n && A[j] == f) j++;
		while (j < n && A[j] != f) {
			A[i] = A[j];
			i++; j++;
		}
	}
	return n - rc;
}


int main(void)
{
	int A[] = { 1 };
	int n = sizeof(A) / sizeof(int);
	//int res = removeDuplicates(A, n);
	int res = removeElement(A, 1, 1);

	return 0;
}