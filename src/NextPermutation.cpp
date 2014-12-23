
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

void nextPermutation(vector<int> &num) {
	int size = num.size();
	if (size < 2) return;
	int i = size-1;
	int j, t;

	while (i > 0 && num[i - 1] >= num[i]) i--;

	if (i == size - 1) {
		t = num[size - 1];
		num[size - 1] = num[i - 1];
		num[i - 1] = t;
		return;
	}
	else if (i == 0) {
		j = size - 1;
		while (i < j) {
			t = num[j];
			num[j] = num[i];
			num[i] = t;
			i++;
			j--;
		}
		return;
	}
	else {
		i--;
		j = size - 1;
		while (j > i && num[j] <= num[i]) j--;
		t = num[j];
		num[j] = num[i];
		num[i] = t;

		i++;
		j = size - 1;
		while (i < j) {
			t = num[j];
			num[j] = num[i];
			num[i] = t;
			i++;
			j--;
		}
	}
}

void nextPermutation3(vector<int> &num) {
	assert(num.size() >0);
	int vioIndex = num.size() - 1;
	while (vioIndex >0)
	{
		if (num[vioIndex - 1] < num[vioIndex])
			break;
		vioIndex--;
	}
	if (vioIndex >0)
	{
		vioIndex--;
		int rightIndex = num.size() - 1;
		while (rightIndex >= 0 && num[rightIndex] <= num[vioIndex])
		{
			rightIndex--;
		}
		int swap = num[vioIndex];
		num[vioIndex] = num[rightIndex];
		num[rightIndex] = swap;
		vioIndex++;
	}
	int end = num.size() - 1;
	while (end > vioIndex)
	{
		int swap = num[vioIndex];
		num[vioIndex] = num[end];
		num[end] = swap;
		end--;
		vioIndex++;
	}
}

void nextPermutation2(vector<int> &num) {
	next_permutation(num.begin(), num.end());
}

void printPermutation(vector<int> num) {
	for (int i = 0; i < num.size(); i++) {
		cout << num[i] << ", ";
	}
}

int main(void)
{
	//int A[] = { 1, 5, 1 };
	//int A[] = { 5, 1, 1 };
	int A[] = { 1, 2, 3 };
	//int A[] = { 7,6,5,4,3,2,1 };
	//int A[] = { 1, 2, 3, 4, 5, 7, 6 };
	int n = sizeof(A) / sizeof(int);

	vector<int> num;
	num.insert(num.end(), A, A + n);

	//nextPermutation2(num); printPermutation(num);
	//nextPermutation2(num); printPermutation(num);
	//nextPermutation2(num); printPermutation(num);
	//nextPermutation2(num); printPermutation(num);
	//nextPermutation2(num); printPermutation(num);
	//nextPermutation2(num); printPermutation(num);
	//nextPermutation2(num); printPermutation(num);
	//nextPermutation2(num); printPermutation(num);
	//nextPermutation2(num); printPermutation(num);
	//nextPermutation2(num); printPermutation(num);
	//nextPermutation2(num); printPermutation(num);
	//nextPermutation2(num); printPermutation(num);
	//nextPermutation2(num); printPermutation(num);

	for (int i = 0; i < 20; i++) {
		printPermutation(num);
		nextPermutation(num);
		cout << "    ->     ";
		printPermutation(num);
		cout << endl;
	}

	return 0;
}