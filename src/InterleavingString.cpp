#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isInterleave(string s1, string s2, string s3) {
	if (s1.empty()) return !s3.compare(s2);
	if (s2.empty()) return !s3.compare(s1);

	bool res1 = false, res2 = false;

	if (s1[0] == s3[0]) {
		string ts1 = s1, ts3 = s3;;
		ts1.erase(ts1.begin());
		ts3.erase(ts3.begin());
		res1 = isInterleave(ts1, s2, ts3);
	}

	if (s2[0] == s3[0]) {
		string ts2 = s2, ts3 = s3;;
		ts2.erase(ts2.begin());
		ts3.erase(ts3.begin());
		res2 = isInterleave(s1, ts2, ts3);
	}
	return res1 | res2;
}

bool isInterleave2(string s1, string s2, string s3) {
	if (s3.size() != s1.size() + s2.size())
		return false;
	//create indicator
	vector<vector<bool> > match(s1.size() + 1, vector<bool>(s2.size() + 1, false));
	//initialization the first row and the first column
	match[0][0] = true;
	for (int l1 = 1; l1 <= s1.size(); ++l1) {
		char c1 = s1[l1 - 1];
		char c3 = s3[l1 - 1];
		if (c1 == c3) {
			match[l1][0] = true;
		}
		else
			break;
	}
	for (int l2 = 1; l2 <= s2.size(); ++l2) {
		char c2 = s2[l2 - 1];
		char c3 = s3[l2 - 1];
		if (c2 == c3) {
			match[0][l2] = true;
		}
		else
			break;
	}
	//work through the rest of matrix using the formula
	for (int l1 = 1; l1 <= s1.size(); ++l1) {
		char c1 = s1[l1 - 1];
		for (int l2 = 1; l2 <= s2.size(); ++l2) {
			char c2 = s2[l2 - 1];
			int l3 = l1 + l2;
			char c3 = s3[l3 - 1];
			if (c1 == c3) {
				match[l1][l2] = match[l1 - 1][l2] | match[l1][l2];
			}
			if (c2 == c3) {
				match[l1][l2] = match[l1][l2 - 1] | match[l1][l2];
			}
		}
	}
	//the last element is the result
	for (int i = 0; i < match.size(); i++) {
		for (int j = 0; j < match[i].size(); j++) {
			cout << match[i][j] << ", ";
		}
		cout << endl;
	}
	return match[s1.size()][s2.size()];
}

int main(void)
{

	//string s1 = "abbbbbbcabbacaacccababaabcccabcacbcaabbbacccaaaaaababbbacbb";
	//string s2 = "ccaacabbacaccacababbbbabbcacccacccccaabaababacbbacabbbbabc";
	//string s3 = "cacbabbacbbbabcbaacbbaccacaacaacccabababbbababcccbabcabbaccabcccacccaabbcbcaccccaaaaabaaaaababbbbacbbabacbbacabbbbabc";

	string s1 = "ab";
	string s2 = "bc";
	string s3 = "babc";


	bool res = isInterleave2(s1, s2, s3);

	return 0;
}