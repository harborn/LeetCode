

int searchInsert(int A[], int n, int target) {
	int s = 0;
	int e = n - 1;
	if (n <= 0) { return 0; }
	if (n == 1) { if (target > A[0]) return 1; else return 0; }

	int m;
	while (s <= e) {
		m = (s + e) / 2;
		if (target < A[m]) e = m - 1;
		else if (target > A[m]) s = m + 1;
		else return m;
	}
	m = (s + e) / 2;
	if (target < A[m]) return s;
	else return e + 1;
}

int main(void)
{

	int A[] = { 1, 3 };
	int n = sizeof(A) / sizeof(int);
	
	int ret = searchInsert(A, 2, 2);

	return 0;
}