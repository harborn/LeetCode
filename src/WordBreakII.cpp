
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// s = "leetcode";
bool wordBreak2(string s, unordered_set<string> &dict) {
	int size = s.size();
	if (size == 0) return false;
	if (size == 1) {
		if (dict.find(s) != dict.end()) return true;
		else return false;
	}

	vector<bool> dp(size + 1, false);
	dp[0] = true;
	for (int i = 1; i <= size; i++) {
		for (int j = 0; j < i; j++) {
			string ss = s.substr(j, i - j);
			if (dict.find(ss) != dict.end() && dp[j]) {
				dp[i] = true;
				break;
			}
		}
	}

	return dp[size];
}

vector<string> helper(vector<vector<vector<string>>> dps, int pos) {
	vector<string> res;
	if (pos < 0) return res;

	for (int i = 0; i < dps[pos].size(); i++) {
		int l = dps[pos][i][0].size();
		vector<string> sr = helper(dps, l - 1);
		if (sr.empty()) {
			res.push_back(dps[pos][i][1]);
		}
		else {
			for (int k = 0; k < sr.size(); k++) {
				res.push_back(sr[k] + " " + dps[pos][i][1]);
			}
		}
	}

	return res;
}

// s = "catsanddog";
// dict = ["cat", "cats", "and", "sand", "dog"]
// res = ["cats and dog", "cat sand dog"]
vector<string> wordBreak(string s, unordered_set<string> &dict) {
	vector<string> res;
	int size = s.size();
	if (size == 0) return res;

	vector<vector<vector<string>>> dps;
	vector<bool> dp(size + 1, false);
	dp[0] = true;

	for (int i = 1; i <= size; i++) {
		vector<vector<string>> words;
		for (int j = 0; j < i; j++) {
			string ss = s.substr(j, i - j);
			if (dict.find(ss) != dict.end() && dp[j]) {
				dp[i] = true;
				vector<string> vs;
				vs.push_back(s.substr(0, j));
				vs.push_back(ss);
				words.push_back(vs);
			}
		}
		dps.push_back(words);
	}

	res = helper(dps, size - 1);

	return res;
}

int main(void) {

	string s = "catsanddog";
	unordered_set<string> dict;
	dict.insert("cat"); dict.insert("cats"); dict.insert("and"); dict.insert("sand");
	dict.insert("dog");



	vector<string> res = wordBreak(s, dict);

	return 0;
}