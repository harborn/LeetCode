#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

#include <fstream>
#include <streambuf>

using namespace std;

int lengthOfLongestSubstring(string s) {

	int size = s.size();

	int i, j, k;
	int r = 0;
	int max = 0;
	for (i = 0; i < size - 1;) {
		r = 0;
		for (j = i + 1; j < size; j++) {
			for (k = i; k < j; k++) {
				if (s[k] == s[j]) {
					r = 1;
					break;
				}
			}
			if (r)
				break;
		}
		if (j - i > max) max = j - i;
		i = k + 1;
	}

	return max;
}

int lengthOfLongestSubstring2(const string s) {
	int idx[256]; // indices of each char.
	memset(idx, -1, sizeof idx);
	int i, j, best = 0, start = 0;
	for (i = 0; i < s.size(); i++) {
		const unsigned char c = (unsigned char)s[i];
		j = idx[c];
		idx[c] = i;
		if (start <= j) {
			start = j + 1;
		}
		best = max(best, i - start + 1);
	}
	return best;
}

int lengthOfLongestSubstring4(string s) {
	vector<int> charIndex(256, -1);
	int longest = 0, m = 0;

	for (int i = 0; i < s.length(); i++) {
		m = max(charIndex[s[i]] + 1, m);    // automatically takes care of -1 case
		charIndex[s[i]] = i;
		longest = max(longest, i - m + 1);
	}

	return longest;
}

int lengthOfLongestSubstring3(string s) {
	unordered_map<char, int> hash;
	int maxlen = 0;
	int index = 0;

	for (int i = 0; i < s.size(); i++)
	{
		if (hash.find(s[i]) != hash.end())
		{
			if (maxlen < hash.size())
			{
				maxlen = hash.size();
			}
			index = hash[s[i]];
			for (auto it = hash.begin(); it != hash.end();)
			{
				if (it->second <= index) {
					it = hash.erase(it);
				}
				else {
					it++;
				}
			}
		}

		hash[s[i]] = i;
	}
	if (maxlen < hash.size()) maxlen = hash.size();

	return maxlen;
}

char FindFirstNotRepeatedChar(char *pstring) {
	if (pstring == NULL)
		return 0;

	//定义并初始化哈希表
	const int hashLength = 256;
	unsigned int hashList[hashLength];
	for (int i = 0; i < hashLength; ++i)
	{
		hashList[i] = 0;
	}

	char *pchar = pstring;
	while (*pchar != '\0')
	{
		hashList[*pchar]++;
		pchar++;
	}

	pchar = pstring;

	while (*pchar != '\0')
	{
		if (hashList[*pchar] == 1)
		{
			return *pchar;
		}

		pchar++;
	}

	return 0;
}

int main(void)
{


	char c = FindFirstNotRepeatedChar("bcdecdea");

	cout << c << endl;


	string s = "abcabcbb";
	//string s = "bbbbbc";
	//string s = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
	//string s = "hnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqcac";
	//string s = "msboaguwnnyqxnzlgdgwpbtrwblnsadeuguumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuu";

	//ifstream f("strings.txt");
	//string s;
	//string t;
	//while (f) {
	//	getline(f, t);
	//	s += t;
	//}

	cout << s << endl;

	int res = lengthOfLongestSubstring(s);
	int res2 = lengthOfLongestSubstring2(s);
	int res3 = lengthOfLongestSubstring3(s);

	cout << res << endl;
	cout << res2 << endl;
	cout << res3 << endl;

	return 0;
}