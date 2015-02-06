
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string longestPalindrome(string s) {
	int size = s.size();
	vector<vector<int>> dp(size, vector<int>(size, 0));

	for (int i = size-1; i >= 0; i--) {
		for (int j = i; j < size; j++) {
			if (s[i] == s[j]) {
				if (j == i)
					dp[i][j] = 1;
				else if (j == i+1) {
					dp[i][j] = 2;
				}
				else if (dp[i+1][j-1] == j-i-1) {
					dp[i][j] = dp[i+1][j-1] + 2;
				} else {
					dp[i][j] = dp[i+1][j-1];
				}
			}
			else {
				if (j == i + 1)
					dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
				else
					dp[i][j] = max(dp[i+1][j-1], max(dp[i][j-1], dp[i+1][j]));
			}
		}
	}

	string res;
	for (int j = 0; j < size; j++) {
		if (dp[0][j] > res.size()) {
			res = s.substr(j + 1 - dp[0][j], dp[0][j]);
		}
	}

	return res;
}

string longestPalindrome2(string s)
{
	int size = s.size();
	if (size <= 1) return s;
	int j = 0;
	int max = 0;
	string res;
	for (int i = 0; i < size; i++) {
		j = 1;
		for (j = 1; i >= j && (i + j) < size && s[i-j] == s[i+j]; j++);
		if ((j-1) * 2 + 1 > max) {
			max = (j-1) * 2 + 1;
			res = s.substr(i-j+1, max);
		}
		j = 1;
		for (j = 0; i >= j && (i+1+j) < size && s[i-j] == s[i+1+j]; j++);
		if (j*2 > max) {
			max = j*2;
			res = s.substr(i-j+1, max);
		}
	}

	return res;
}

string longestPalindrome3(string s)
{
	int size=s.size(),i;
	char *t=new char[2*size+2],*q=t;
	int *p=new int[2*size+1],mx=0,id=0,MAX=0,center=0;

	for(*q='#',i=0; i<size; ++i, *++q='#')
		*++q = s[i];

	for(*++q = 0, p[0] = i = 1; t[i]; i++) {
		p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
		while (i + p[i] <= 2 * size + 1 && t[i + p[i]] == t[i - p[i]])
			p[i]++;
		if (i + p[i] > mx)
			mx = i + p[i], id = i;
		if (p[i] > MAX) 
			MAX = p[i], center = i;
	}

	delete(p),delete(t);
    return s.substr((center-MAX+1)/2,MAX-1);
}

int main(void)
{

	vector<int> v;
	for (int i = 0; i < 100; i++)
		v.push_back(1);
	//string s = "bb";
	//string s = "abcdcba";
	//string s = "character";
	//string s = "committee";
	//string s = "chineseni";
	string s = "12212321";

	//string res = longestPalindrome(s);
	//string res2 = longestPalindrome2(s);
	string res3 = longestPalindrome3(s);
	return 0;
}