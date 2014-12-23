
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> findSubstring(string S, vector<string> &L) {

	vector<int> res;
	unordered_map<string, int> words;
	unordered_map<string, int> has;
	int lsize = L.size();
	int wlen = L[0].size();
	int send = S.size() - lsize * wlen;
	for (int i = 0; i < lsize; i++) {
		words[L[i]]++;
	}

	unordered_map<string, int> tw;
	for (int i = 0; i < send; i++) {
		;
	}

	return res;
}

size_t stringHash(const string& s)
{
	size_t h = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		h = (s[i] + 31 * h) % 997;
	}
	return h;
}

size_t exponential(unsigned int M)
{
	unsigned int n = 1;
	for (unsigned int i = 0; i < M; ++i)
	{
		n = (31 * n) % 997;
	}
	return n;
}

vector<int> findSubstring2(string S, vector<string> &L) {
	// length of L[i]
	int len = L[0].size();
	int N = L.size();

	// 31 ^ (len - 1) % 997
	size_t power = exponential(len - 1);

	// compute hash sum for L, and hashset for input string O(L.size() * len)
	vector<size_t> hashes;
	hashes.push_back(stringHash(S.substr(0, len)));
	size_t hashSum = 0;
	unordered_set<size_t> strSet;
	for_each(L.begin(), L.end(), [&](const string& s) {
		int hs = stringHash(s);
		strSet.insert(hs);
		hashSum += hs;
	});

	// compute hash for each position (using Rabin-Karp), O(n)
	for (int i = 1; i + len <= S.size(); ++i)
	{
		size_t newHash = 31 *
			(hashes.back() + 997 - power * S[i - 1] % 997) + S[i + len - 1];
		hashes.push_back(newHash % 997);
	}

	// if substring S[i..i+len) is not in L, set hashes[i] to 0, O(n)
	for (int i = 0; i < hashes.size(); ++i)
	{
		if (!strSet.count(hashes[i]))
		{
			hashes[i] = 0;
		}
	}

	// O(n * L.size())
	vector<int> result;
	for (int i = 0; i + (N - 1) * len <= hashes.size(); ++i)
	{
		size_t h = 0;
		for (int j = 0; j < N; ++j)
		{
			h += hashes[i + j * len];
		}
		if (h == hashSum)
		{
			result.push_back(i);
		}
	}
	return result;
}

vector<int> findSubstring3(string S, const vector<string> &L) {
	vector<int> re;
	if (S.size() == 0 || L.size() == 0) return re;
	unordered_map<string, int> total;
	unordered_map<string, int> has;
	int wordNum = L.size();
	int wordLen = L[0].size();
	int searchEnd = S.size() - wordLen * wordNum;

	for (int i = 0; i < wordNum; ++i)
	{
		total[L[i]]++;
	}
	for (int i = 0; i <= searchEnd; ++i)
	{
		int j = i;
		has.clear();
		int iword = 0;
		for (; iword < wordNum; ++iword)
		{
			string sub = S.substr(j, wordLen);
			//not in L
			if (total[sub] == 0)
				break;
			//in L, but redundancy
			if (++has[sub] > total[sub])
				break;
			j += wordLen;
		}
		if (iword == wordNum)
		{
			re.push_back(i);
		}
	}
	return re;
}

vector<int> findSubstring4(string S, vector<string> &L)
{
	vector<int> res;
	map<string, int> cntL;
	map<string, int> cn;
	int n;

	res.clear();
	cntL.clear();
	cn.clear();

	n = S.length();
	int e = L.size();
	int t = L[0].length();
	int k = 0;

	for (int i = 0; i < e; i++)
	{
		if (cn.count(L[i]) == 0)
		{
			cn[L[i]] = 1;
			k++;
		}
		else
		{
			cn[L[i]] += 1;
			k++;
		}
	}

	string tr, du;
	int r = 0;
	int st = 0;

	for (int j = 0; j < t; j++)
	{
		r = 0; st = j;
		for (int i = j; i < n; i += t)
		{
			tr = S.substr(i, t);
			if (cn.count(tr) == 0 || cn[tr] == 0)
			{
				cntL.clear();
				r = 0;
				st = i + t;
			}
			else if (cntL[tr] < cn[tr])
			{
				cntL[tr] += 1;
				r++;
			}
			else
			{
				du = S.substr(st, t);
				while (du != tr)
				{
					cntL[du]--;
					r--;
					st += t;
					du = S.substr(st, t);
				}
				st += t;
			}

			if (r == k)
			{
				res.push_back(st);
				du = S.substr(st, t);
				cntL[du]--;
				r--;
				st += t;
			}
		}
		cntL.clear();
	}
	sort(res.begin(), res.end());
	return res;
}


int main(void) {

	//string S = "barfoothefoobarman";
	//vector<string> L;
	//L.push_back("foo");
	//L.push_back("bar");

	string S = "abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababab";
	string LA[] = { "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba", "ab", "ba" };
	int Ln = 200;
	vector<string> L;
	L.insert(L.begin(), LA, LA + Ln);

	vector<int> res = findSubstring4(S, L);

	return 0;
}