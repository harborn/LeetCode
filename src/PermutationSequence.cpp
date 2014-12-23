
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string getPermutation(int n, int k) {
	string res(n, ' ');

	long long num = 1;
	for (int i = 2; i <= n; i++) num *= i;

	for (int i = n; i > 0; i--) {
		int t = num, j = i;
		while (k < t && j > 0) {
			t /= j; j--;
		}
		k -= t/j;
		num /= i;
		res[n-i] = '0' + j;
	}

	return res;
}

string getPermutation2(int n, int k) {
	vector<int> nums(n);
	int permCount = 1;
	for (int i = 0; i< n; i++)
	{
		nums[i] = i + 1;
		permCount *= (i + 1);
	}
	// change K from (1,n) to (0, n-1) to accord to index  
	k--;
	string targetNum;
	for (int i = 0; i< n; i++)
	{
		permCount = permCount / (n - i);
		int choosed = k / permCount;
		targetNum.push_back(nums[choosed] + '0');
		//restruct nums since one num has been picked  
		for (int j = choosed; j< n - i; j++)
		{
			nums[j] = nums[j + 1];
		}
		k = k%permCount;
	}
	return targetNum;
}

string getPermutation(int n, int k) {
	vector<int> num(n, 0);
	int perm_sum = 1;
	for (size_t i = 0; i < n; ++i)
	{
		num[i] = i + 1;
		perm_sum *= (i + 1);
	}
	string ret;
	//因为数组是从0到n-1的 所以基数从 0到k-1  
	--k;
	for (size_t i = 0; i < n; ++i)
	{
		perm_sum = perm_sum / (n - i);
		int selected = k / perm_sum;
		ret.push_back(num[selected] + '0');
		//选择一个数后重新构造剩下的数组  
		for (size_t j = selected; j < n - i - 1; ++j)
			num[j] = num[j + 1];
		k = k % perm_sum;
	}
	return ret;
}

int main(void) {

	int n = 3;

	cout << getPermutation(n, 1) << endl;

	for (int i = 1; i <= 6; i++) {
		cout << getPermutation(n, i + 1) << endl;
	}

	return 0;
}
