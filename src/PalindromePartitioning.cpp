
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(string s) {
	if (s.empty()) return false;
	int i = 0, j = s.size() - 1;
	while (i < j) {
		if (s[i] != s[j])
			return false;
		i++; j--;
	}
	return true;
}

vector<vector<string>> partition(string s) {
	vector<vector<string>> res;
	int size = s.size();
	if (size == 0) return res;
	if (size == 1) {
		vector<string> p;
		p.push_back(s);
		res.push_back(p);
		return res;
	}

	int p = 0; 
	int i = 0;
	while (i < size) {
		i++;
		string s1 = s.substr(0, i);
		string s2 = s.substr(i, size - i);
		if (isPalindrome(s1)) {
			vector<vector<string>> sub = partition(s2);
			for (int j = 0; j < sub.size(); j++) {
				sub[j].insert(sub[j].begin(), s1);
				res.push_back(sub[j]);
			}
			if (s2.empty()) {
				vector<string> q;
				q.push_back(s1);
				res.push_back(q);
			}
		}
	}
	return res;
}

int main(void)
{
	string s = "bb";

	vector<vector<string>> res = partition(s);

	return 0;
}
