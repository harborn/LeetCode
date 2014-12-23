
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int numDistinct(string S, string T) {
	int size1 = S.size();
	int size2 = T.size();
	if (size2 == 0) return 1;
	if (size1 == 0) return 0;
	int res = 0;
	for (int i = 0; i < size1; i++) {
		if (S[i] == T[0]) {
			res += numDistinct(S.substr(i + 1, size1 - i - 1), T.substr(1, size2 - 1));
		}
	}
	return res;
}

int numDistinct2(string S, string T) {
	int size1 = S.size();
	int size2 = T.size();
	if (size1 < size2) return 0;
	vector<vector<int>> dp(size2 + 1, vector<int>(size1 + 1, 0));
	for (int j = 0; j <= size1; j++)
		dp[0][j] = 1;

	for (int i = 1; i <= size2; i++) {
		for (int j = 1; j <= size1; j++) {
			dp[i][j] = dp[i][j - 1];
			if (T[i - 1] == S[j - 1]) {
				dp[i][j] += dp[i - 1][j - 1];
			}
		}
	}

	return dp[size2][size1];
}

int numDistinct3(string S, string T) {
	int match[200];
	if (S.size() < T.size()) return 0;
	match[0] = 1;
	for (int i = 1; i <= T.size(); i++)
		match[i] = 0;
	for (int i = 1; i <= S.size(); i++)
		for (int j = T.size(); j >= 1; j--)
			if (S[i - 1] == T[j - 1])
				match[j] += match[j - 1];
	return match[T.size()];
}

int main(void)
{
	// res = 10582116
	string S = "aabdbaabeeadcbbdedacbbeecbabebaeeecaeabaedadcbdbcdaabebdadbbaeabdadeaabbabbecebbebcaddaacccebeaeedababedeacdeaaaeeaecbe";
	string T = "bddabdcae";

	// res = 3
	//string S = "rabbbit";
	//string T = "rabbit";

	// res = 1
	//string S = "ABCDE";
	//string T = "ACE";

	int res = numDistinct2(S, T);


	return 0;
}