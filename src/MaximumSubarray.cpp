
#include <iostream>


int maxSubArray(int A[], int n) {

	int i = 1;
	int sum = A[0];
	int max = A[0];
	while (i < n) {
		if (A[i] > 0) {
			if (sum <= 0) sum = A[i];
			else sum += A[i];
		} else {
			if (sum > max) max = sum;
			if (sum < 0) sum = A[i];
			else sum += A[i];
		}
		i++;
	}
	if (sum > max) max = sum;
	return max;
}

int maxSubArray2(int A[], int n) {  
	int sum = 0;
	int max = INT_MIN;
	int i = 0;
	while (i < n) {  
		sum += A[i];        
		if(sum > max)
			max = sum;  
		if(sum < 0)  
			sum = 0;  
		i++;
	}
	return max;  
}  

int main(void)
{
	int A[] = {-2,-1};
	//int A[] = {-2,1};
	//int A[] = {-2,-3};
	//int A[] = {-2,3};
	//int A[] = {2,3};
	//int A[] = {-2,1,-3,4,-1,2,1,-5,4}; // max subarray sum is 6
	int n = sizeof(A) / sizeof(int);

	int res = maxSubArray2(A, n);

	return 0;
}