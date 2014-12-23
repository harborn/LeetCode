
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestConsecutive(vector<int> &num) {

	int size = num.size();
	if (size <= 1) return size;
	vector<vector<int>> arrays;

	for (int i = 0; i < size; i++) {
	
		int as = arrays.size();
		int cnt = 0;
		int a[2] = { -1 };
		for (int j = 0; j < as; j++) {
			if (num[i] == (arrays[j].front() - 1) || num[i] == (arrays[j].back() + 1)) {
				a[cnt++] = j;
			}
			else if (num[i] >= arrays[j].front() && num[i] <= arrays[j].back()) {
				cnt = -1;
				break;
			}
		}
		if (cnt == 0) {
			vector<int> v; 
			v.push_back(num[i]);
			arrays.push_back(v);
		}
		else if (cnt == 1) {
			if (num[i] == (arrays[a[0]].front() - 1)) {
				arrays[a[0]].insert(arrays[a[0]].begin(), num[i]);
			}
			else  {
				arrays[a[0]].push_back(num[i]);
			}
		}
		else if (cnt == 2) {
			if ((arrays[a[0]].front() - 1 == num[i]) && (arrays[a[1]].back() + 1) == num[i]) {
				arrays[a[1]].push_back(num[i]);
				arrays[a[1]].insert(arrays[a[1]].end(), arrays[a[0]].begin(), arrays[a[0]].end());
				arrays.erase(arrays.begin() + a[0]);
			}
			else {
				arrays[a[0]].push_back(num[i]);
				arrays[a[0]].insert(arrays[a[0]].end(), arrays[a[1]].begin(), arrays[a[1]].end());
				arrays.erase(arrays.begin() + a[1]);
			}
		}
	}

	int max = arrays[0].size();
	for (int i = 1; i < arrays.size(); i++) {
		if (arrays[i].size() > max) max = arrays[i].size();
	}

	return max;
}

int longestConsecutive(vector<int> &num) {
	unordered_map<int, int> hashmap;
	for (int i = 0; i< num.size(); i++)
	{
		hashmap[num[i]] = i;
	}
	vector<int> visited(num.size(), 0);
	int maxV = INT_MIN;
	for (int i = 0; i< num.size(); i++)
	{
		if (visited[i] == 1) continue;
		visited[i] = 1;
		int len = 1;
		int index = num[i] - 1;
		while (hashmap.find(index) != hashmap.end())
		{
			visited[hashmap[index]] = 1;
			index--;
			len++;
		}
		index = num[i] + 1;
		while (hashmap.find(index) != hashmap.end())
		{
			visited[hashmap[index]] = 1;
			index++;
			len++;
		}
		if (len > maxV)
			maxV = len;
	}
	return maxV;
}

int main(void)
{
	//int d[] = { 100, 4, 200, 1, 3, 2 };
	int d[] = { 0, 3, 7, 2, 5, 8, 4, 6, 0, 1 };
	int n = sizeof(d) / sizeof(int);
	vector<int> num;
	num.insert(num.end(), d, d + n);

	int res = longestConsecutive(num);

	return 0;
}
