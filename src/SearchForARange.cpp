
#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(int A[], int n, int target) {
	
	int min = -1;
	int max = -1;

	vector<int> res;

	int i = 0, j = n - 1;
	int f = 0, m = 0;
	while (1) {
		if (!f) {
			m = (i + j) / 2;
			if (target == A[m])
			{
				min = m;
				max = m;
				f = 1;
			}
			else if (target > A[m]) {
				i = m + 1; 
			}
			else {
				j = m - 1;
			}

			if (i > j) break;
		}
		else {
			// find the last num < target in [i, m-1]
			// find the first num > target in [m+1, j]
			int li = i, lj = m - 1;
			while (li <= lj) {
				int lm = (li + lj) / 2;
				if (A[lm] >= target) lj = lm - 1;
				else li = lm + 1;
			}
			int lmin = min;
			if (A[lj] < target) lmin = lj + 1;
			else if (lj >= 0) lmin = lj;
			if (lmin < min) min = lmin;

			int ri = m + 1, rj = j;
			while (ri <= rj) {
				int rm = (ri + rj) / 2;
				if (A[rm] <= target) ri = rm + 1;
				else rj = rm - 1;
			}
			int rmax = max;
			if (A[rj] > target) rmax = rj - 1;
			else if (rj < n) rmax = rj;
			if (rmax > max) max = rmax;

			break;
		}
	}
	
	
	res.push_back(min);
	res.push_back(max);
	return res;
}

int search(int A[], int n, int target, int st, int ed, bool left){
	if (st>ed){
		return -1;
	}
	else{
		int mid = st + (ed - st) / 2;
		if (A[mid] == target){
			if (left){
				if (mid == 0 || A[mid - 1]<A[mid]){ return mid; }
				else{ return search(A, n, target, st, mid - 1, left); }
			}
			if (!left){
				if (mid == n - 1 || A[mid + 1]>A[mid]){ return mid; }
				else{ return search(A, n, target, mid + 1, ed, left); }
			}
		}
		if (A[mid]<target){
			return search(A, n, target, mid + 1, ed, left);
		}
		if (A[mid]>target){
			return search(A, n, target, st, mid - 1, left);
		}
	}
}

vector<int> searchRange2(int A[], int n, int target) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	vector<int> res(2, -1);
	res[0] = search(A, n, target, 0, n - 1, true);
	res[1] = search(A, n, target, 0, n - 1, false);
	return res;
}


int main(void)
{
	int A[] = { 1, 1, 2 };
	//int A[] = { 2, 2 };
	//int A[] = { 5, 7, 7, 8, 8, 10 };
	//int A[] = { 1, 2, 3, 8, 8, 8, 8, 8, 8, 10, 10, 11, 12, 12, };
	int n = sizeof(A) / sizeof(int);

	vector<int> res = searchRange2(A, n, 3);

	return 0;
}