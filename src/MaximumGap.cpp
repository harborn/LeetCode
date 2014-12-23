

#include <iostream>
#include <vector>

using namespace std;

//Give an unsorted array, find the maximum difference between the successive elements in its sorted form.
//Try to solve it in linear time/space.
//Return 0 if the array contains less 2 elements.
//You may assume all elements in the array are non-negetive integers and fit in the 32-bit singed integer range.

// Õ∞≈≈–Ú

int maximumGap(vector<int> &num){
	int size = num.size();
	if (size < 2) return 0;

	int min = num[0], max = num[0];
	for (int i = 1; i < size; i++) {
		if (num[i] > max) max = num[i];
		if (num[i] < min) min = num[i];
	}

	int gap = (max - min) / (size - 1) + 1;
	vector<vector<int>> temp(size);
	for (int i = 0; i < size; i++) {
		int index = (num[i] - min) / gap;
		cout << index << endl;
		if (temp[index].empty()) {
			temp[index].push_back(num[i]);
		}
		else if (temp[index].size() == 1) {
			if (num[i] < temp[index][0]) {
				temp[index].push_back(temp[index][0]);
				temp[index][0] = num[i];
			}
			else
				temp[index].push_back(num[i]);
		}
		else {
			if (num[i] < temp[index][0])
				temp[index][0] = num[i];
			if (num[i] > temp[index][1])
				temp[index][1] = num[i];
		}
	}

	int ret = INT_MIN;
	vector<int> pre = temp[0];
	for (int i = 1; i < temp.size(); i++) {
		if (temp[i].empty()) continue;
		if (pre.size() == 1) {
			if (temp[i][0] - pre[0] > ret)
				ret = temp[i][0] - pre[0];
		}
		else {
			if (temp[i][0] - pre[1] > ret)
				ret = temp[i][0] - pre[1];
		}
		pre = temp[i];
	}

	return ret;
}

int main(void)
{
	//int d[] = { 1, 5, 6, 7, 66 };
	int d[] = { 1, 2, 66 };

	vector<int> num;
	num.insert(num.begin(), d, d + sizeof(d) / sizeof(d[0]));

	int res = maximumGap(num);

	return 0;
}