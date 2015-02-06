
#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int> &num) {
	int n = num[0], i = 1, cnt = 1;;
	while (i < num.size()) {
		if (num[i] == n) {
			cnt++;
		}
		else {
			cnt--;
			if (cnt <= 0) {
				cnt = 1;
				n = num[i];
			}
		}
		i++;
	}
	return n;
}

int main(void) {
	int d[] = {3,1,3,2,3,2,3,3,2};
	vector<int> num;
	num.insert(num.begin(), d, d + sizeof(d) / sizeof(d[0]));

	int res = majorityElement(num);

	return 0;
}