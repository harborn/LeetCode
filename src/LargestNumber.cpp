
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compareStr(string n1, string n2) {
	return n1 + n2 > n2 + n1;
}

string largestNumber(vector<int> &num) {
	if (num.size() < 1) return "";
	vector<string> ns(num.size(), "");
	for (int i = 0; i < num.size(); i++) ns[i] = to_string(num[i]);
	sort(ns.begin(), ns.end(), compareStr);
	string res;
	for (int i = 0; i < ns.size(); i++) res.append(ns[i]);
	int i = 0;
	while (res[i] == '0' && (i + 1) < res.size()) i++;
	return res.substr(i);
}

int main(void) {

	
	vector<int> num[] = {
		{0, 0},
		{ 3, 30, 34, 5, 9 },
		{ 121, 12 },
		{ 1, 2, 2, 2 },
		{ 0, 9, 8, 7, 6, 5, 4, 3, 2, 1 },
		{ 1, 20, 3 }
	};

	for (int i = 0; i < sizeof(num) / sizeof(num[0]); i++) {
		string res = largestNumber(num[i]);
		cout << res << endl;
	}
	return 0;
}