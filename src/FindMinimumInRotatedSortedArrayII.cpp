
#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int> &num) {
	int s = 0, e = num.size() - 1;
	int min = num[0];
	while (s <= e) {
		int m = (s + e) / 2;
		if (num[m] < min) min = num[m];
		if (m > s && num[s] == num[m]) {
			int k = s + 1;
			while (k < m && num[k] == num[m]) k++;
			if (k == m) s = m + 1;
			else e = m - 1;
		}
		else if (e > m && num[m] == num[e]) {
			int k = m + 1;
			while (k < e && num[k] == num[e]) k++;
			if (k == e) e = m - 1;
			else s = m + 1;
		}
		else {
			if (num[s] <= num[m]) {
				if (num[s] < min) min = num[s];
				s = m + 1;
			}
			else {
				e = m - 1;
			}
		}
	}
	return min;
}

int main(void) {


	return 0;
}