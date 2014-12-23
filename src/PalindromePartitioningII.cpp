
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

int minCut(string s) {
	int size = s.size();
	if (size <= 1) return 1;
	vector<int> dp(size, 0);
	for (int i = 1; i < size; i++) {
		if (isPalindrome(s.substr(0, i + 1)))
		{
			dp[i] = 0;
		}
		else
		{
			int min = i;
			int part = 0;
			for (int j = 1; j <= i; j++) {
				part = dp[j - 1];
				string sub = s.substr(j, i - j + 1);
				if (!isPalindrome(sub)) {
					part += i - j;
				}
				part += 1;
				if (part < min) min = part;
			}
			dp[i] = min;
		}
	}

	return dp[size - 1];
}

bool isPalindrome2(string &s, int start, int end)
{
	while (start< end)
	{
		if (s[start] != s[end])
			return false;
		start++; end--;
	}
	return true;
}

void dfs(string &s, int start, int depth, int &min) {
	if (start == s.size()) {
		if (min > depth - 1)
			min = depth - 1;
		return;
	}
	for (int i = s.size() - 1; i >= start; i--) {
		if (isPalindrome2(s, start, i)) {
			dfs(s, i + 1, depth + 1, min);
		}
	}
}

int minCut2(string s) {
	int min = INT_MAX;
	dfs(s, 0, 0, min);
	return min;
}


int minCut3(string s) {
	int size = s.size();
	if (size <= 1) return 0;
	
	vector<int> d(size + 1, 0);
	vector<vector<bool>> p(size, vector<bool>(size, false));

	for (int i = 0; i <= size; i++) {
		d[i] = size - i;
	}

	for (int i = size - 1; i >= 0; i--) {
		for (int j = i; j < size; j++) {
			if (s[i] == s[j] && ((j - i) < 2 || p[i + 1][j - 1])) {
				p[i][j] = true;
				d[i] = std::min(d[i], d[j + 1] + 1);
			}
		}
	}
	return d[0] - 1;
}


int main(void) {
	//string s = "aaba";
	//string s = "abcdcba";
	string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	string s2 = "ababababababababababababcbabababababababababababa";
	
	//string s = "aababa";


	//int res = minCut(s);

	int res2 = minCut3(s);

	return 0;
}