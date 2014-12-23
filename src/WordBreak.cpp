
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;


bool wordBreak(string s, unordered_set<string> &dict) {

	int size = s.size();
	if (size == 0) return false;
	if (size == 1) {
		if (dict.find(s) != dict.end()) return true;
		else false;
	}
	bool ret = false;
	int i = 0;
	while (i < size) {
		string s1 = s.substr(0, i);
		string s2 = s.substr(i, size - i);
		ret = false;
		if (dict.find(s1) != dict.end()) {
			if (s2.empty()) {
				return true;
			} else {
				bool sub = wordBreak(s2, dict);
				if (sub) return true;
				else return false;
			}
		}
		i++;
	}

	return ret;
}

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


int main(void)
{
	string s = "acaaaaabbbdbcccdcdaadcdccacbcccabbbbcdaaaaaadb";
	//string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	//string s = "ab";
	//string s = "a";
	//string s = "leetcode";
	// ["abbcbda", "cbdaaa", "b", "dadaaad", "dccbbbc", "dccadd", 
	// "ccbdbc", "bbca", "bacbcdd", "a", "bacb", "cbc", "adc", "c",
	// "cbdbcad","cdbab","db","abbcdbd","bcb","bbdab","aa","bcadb",
	// "bacbcb","ca","dbdabdb","ccd","acbb","bdc","acbccd","d",
	// "cccdcda","dcbd","cbccacd","ac","cca","aaddc","dccac","ccdc",
	// "bbbbcda","ba","adbcadb","dca","abd","bdbb","ddadbad","badb",
	// "ab","aaaaa","acba","abbb"]
	unordered_set<string> dict;
	dict.insert("abbcbda"); dict.insert("cbdaaa"); dict.insert("b"); dict.insert("dadaaad"); dict.insert("dccbbbc"); dict.insert("dccadd");
	dict.insert("ccbdbc"); dict.insert("bbca"); dict.insert("bacbcdd"); dict.insert("a"); dict.insert("bacb"); dict.insert("cbc"); dict.insert("adc"); dict.insert("c");
	dict.insert("cbdbcad"); dict.insert("cdbab"); dict.insert("db"); dict.insert("abbcdbd"); dict.insert("bcb"); dict.insert("bbdab"); dict.insert("aa"); dict.insert("bcadb");
	dict.insert("bacbcb"); dict.insert("ca"); dict.insert("dbdabdb"); dict.insert("ccd"); dict.insert("acbb"); dict.insert("bdc"); dict.insert("acbccd"); dict.insert("d");
	dict.insert("cccdcda"); dict.insert("dcbd"); dict.insert("cbccacd"); dict.insert("ac"); dict.insert("cca"); dict.insert("aaddc"); dict.insert("dccac"); dict.insert("ccdc");
	dict.insert("bbbbcda"); dict.insert("ba"); dict.insert("adbcadb"); dict.insert("dca"); dict.insert("abd"); dict.insert("bdbb"); dict.insert("ddadbad"); dict.insert("badb");
	dict.insert("ab"); dict.insert("aaaaa"); dict.insert("acba"); dict.insert("abbb");

	//dict.insert("a"); "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"]
	//dict.insert("a"); dict.insert("aa"); dict.insert("aaa"); dict.insert("aaaa"); dict.insert("aaaaa");
	//dict.insert("aaaaaa"); dict.insert("aaaaaaa"); dict.insert("aaaaaaaa"); dict.insert("aaaaaaaaa"); dict.insert("aaaaaaaaaab");
	
	//"a","abc","b","cd"
	//dict.insert("a"); dict.insert("abc"); dict.insert("b"); dict.insert("cd");
	//dict.insert("leet"); dict.insert("code");

	bool res = wordBreak2(s, dict);
	return 0;
}