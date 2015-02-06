
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

bool wordBreak(string s, unordered_set<string> &dict) {
	int size = s.size();
	vector<int> dp(size, 0);
	dp[0] = (dict.find(s.substr(0,1)) != dict.end());
	for (int i = 1; i < size; i++) {
		for (int j = 0; j <= i; j++) {
			
		}
	}

	return dp[size-1];
}

int main(void)
{


	return 0;
}