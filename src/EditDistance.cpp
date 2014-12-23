
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// dp[i][j] = dp[i-1][j-1], if (word1[i] == word2[j])
//            min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1, if (word1[i] != word2[j])
// dp[0][j] = j;
// dp[i][0] = i;
int minDistance(string word1, string word2) {
	int size1 = word1.size();
	int size2 = word2.size();

	vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));

	for (int i = 0; i <= size1; i++) dp[i][0] = i;
	for (int j = 0; j <= size2; j++) dp[0][j] = j;

	for (int i = 1; i <= size1; i++) {
		for (int j = 1; j <= size2; j++) {
			if (word1[i - 1] == word2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
			}
		}
	}
	return dp[size1][size2];
}

int minDistance2(string word1, string word2) {
	if (word1.size() < word2.size())
		word1.swap(word2);
	string& bigStr = word1;
	string& smallStr = word2;
	int * matchUp = new int[20000];
	int* matchDown = new int[20000];
	for (int i = 0; i <= smallStr.size(); i++)
	{
		matchUp[i] = 0;
		matchDown[i] = i;
	}
	for (int i = 1; i <= bigStr.size(); i++)
	{
		matchUp[0] = i;
		for (int j = 1; j <= smallStr.size(); j++)
		{
			if (bigStr[i - 1] == smallStr[j - 1])
			{
				matchUp[j] = matchDown[j - 1];
			}
			else
			{
				matchUp[j] = min(matchDown[j], matchDown[j - 1]);
				matchUp[j] = min(matchUp[j], matchUp[j - 1]) + 1;
			}
		}
		int* temp = matchUp;
		matchUp = matchDown;
		matchDown = temp;
	}
	return matchDown[smallStr.size()];
}

int main(void)
{
	//string s1 = "ykyyyab";
	//string s2 = "abxxxxx";
	//string s1 = "sea";
	//string s2 = "eat";

	string s1 = "afbc";
	string s2 = "abcdefgh";

	int res = minDistance(s1, s2);
	int res2 = minDistance2(s1, s2);

	return 0;
}