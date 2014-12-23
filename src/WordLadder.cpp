
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

bool checkTwoString(string start, string end) {
	int i = 0, len = start.length();
	while (i < len && start[i] == end[i]) i++;
	i++;
	while (i < len && start[i] == end[i]) i++;
	if (i == len) return true;
	return false;
}

bool checkTwoString2(string start, string end, int pos) {
	if (pos < 0) return false;
	start[pos] = end[pos];
	if (start == end) return true;
	return false;
}

vector<string> changeChar(string s, int i, unordered_set<string> &dict) {
	vector<string> res;
	char t = s[i];
	for (char c = 'a'; c < 'z'; c++) {
		if (t == c) continue;
		s[i] = c;
		if (dict.find(s) != dict.end()) res.push_back(s);
	}
	return res;
}

vector<string> changeChar2(string s, int pos, unordered_set<string> &dict, unordered_set<string> &history) {
	unordered_set<string>::iterator it;
	vector<string> res;
	for (it = dict.begin(); it != dict.end(); it++) {
		if (checkTwoString2(s, *it, pos) && (s != *it) && (history.find(*it) == history.end()))
			res.push_back(*it);
	}
	return res;
}

void printGraph(unordered_set<string> &dict) {
	unordered_set<string>::iterator it, it2;
	for (it = dict.begin(); it != dict.end(); it++) {
		cout << *it << ": ";
		for (it2 = dict.begin(); it2 != dict.end(); it2++) {
			if (*it == *it2) continue;
			if (checkTwoString(*it, *it2)) cout << *it2 << ", ";
		}
		cout << endl;
	}

}


int helper4(string start, string end, unordered_set<string> &dict) {
	cout << start << ", " << end << endl;
	if (start == end) return 1;
	if (checkTwoString(start, end)) return 2;
	if (dict.empty()) return INT_MAX;
	int res = INT_MAX;

	for (int i = 0; i < start.length(); i++) {
		char t = start[i];
		for (char c = 'a'; c <= 'z'; c++) {
			if (t == c) continue;
			start[i] = c;
			if (dict.find(start) != dict.end()) {
				dict.erase(start);
				int sub = helper4(start, end, dict);
				cout << "\tsub = " << sub << endl;
				if (sub < res) res = sub + 1;
				dict.insert(start);
			}
			start[i] = t;
		}
	}

	return res;
}


int ladderLength(string start, string end, unordered_set<string> &dict) {
	if (start == end) return 0;
	int len = start.size();
	int res = helper4(start, end, dict);
	if (res == INT_MAX) return 0;
	return res;
}

int ladderLength3(string start, string end, unordered_set<string> &dict){
	vector<string> q;
	q.push_back(start);
	int n = 0;
	int level = 1;
	while (n < q.size()) {
		int len = q.size();
		while (n < len) {
			string str = q[n];
			for (int i = 0; i < str.length(); i++) {
				char t = str[i];
				for (char c = 'a'; c <= 'z'; c++) {
					if (c == t) continue;
					str[i] = c;
					if (str == end) return level + 1;
					if (dict.find(str) != dict.end()) {
						q.push_back(str);
						dict.erase(str);
					}
				}
				str[i] = t;
			}
			n++;
		}
		level++;
	}
	return 0;
}

vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
	vector<vector<string>> res;
	res.push_back(vector<string>(1, start));
	int find = 0;
	int cnt1 = 0, cnt2 = 0;
	while (!res.empty()) {
		int n = 0;
		int len = res.size();
		while (n < len) {
			string str = res[n].back();
			for (int i = 0; i < str.length(); i++) {
				char t = str[i];
				for (char c = 'a'; c <= 'z'; c++) {
					if (c == t) continue;
					str[i] = c;
					if (str == end) {
						find = 1;
						vector<string> path(res[n]);
						path.push_back(str);
						res.push_back(path);
						cnt1++;
					}
					else if (dict.find(str) != dict.end()) {
						vector<string> path(res[n]);
						path.push_back(str);
						res.push_back(path);
						//dict.erase(str);
						cnt2++;
					}
				}
				str[i] = t;
			}
			n++;
		}
		res.erase(res.begin(), res.begin() + n);
		if (find) {
			break;
		}
	}
	
	vector<vector<string>> res2;
	for (int i = 0; i < res.size(); i++) {
		if (res[i].back() == end)
			res2.push_back(res[i]);
	}

	cout << "cnt1 = " << cnt1 << ", cnt2 = " << cnt2 << endl;

	return res2;
}

int ladderLength2(string start, string end, unordered_set<string> &dict) {
	int level = 1;
	unordered_set<string> qs;
	qs.insert(start);

	while (!qs.empty()) {
		unordered_set<string> nextlevel;
		for (auto it = qs.begin(); it != qs.end(); it++) {
			string temp = *it;
			for (int i = 0; i < temp.size(); i++) {
				char tempchar = temp[i];
				for (int c = 0; c < 26; c++) {
					if (tempchar != c + 'a') {
						temp[i] = c + 'a';
						if (temp == end) {
							return level + 1;
						}
						if (dict.find(temp) != dict.end()) {
							nextlevel.insert(temp);
							dict.erase(temp);
						}
					}
				}
				temp[i] = tempchar;
			}
		}
		qs = nextlevel;
		level++;

	}
	return 0;
}

double diffclock(clock_t clock1, clock_t clock2)
{
	double diffticks = clock1 - clock2;
	double diffms = (diffticks * 1000) / CLOCKS_PER_SEC;
	return diffms;
}

int main(void) {

	//string words[] = { "ted", "tex", "red", "tax", "tad", "den", "rex", "pee" };
	//string start = "red";
	//string end = "tax";
	//int n = 8;

	//string words[] = { "a", "b", "c" };
	//string start = "a";
	//string end = "c";
	//int n = 3;

	//string words[] = { "hot","cog","dog","tot","hog","hop","pot","dot" };
	//string start = "hot";
	//string end = "dog";
	//int n = 8;

	//string words[] = { "hot", "dot", "dog", "lot", "log" };
	//string start = "hit";
	//string end = "cog";
	//int n = 5;

	string words[] = { "si", "go", "se", "cm", "so", "ph", "mt", "db", "mb", "sb", "kr", "ln", "tm", "le", "av", "sm", "ar", "ci", "ca", "br", "ti", "ba", "to", "ra", "fa", "yo", "ow", "sn", "ya", "cr", "po", "fe", "ho", "ma", "re", "or", "rn", "au", "ur", "rh", "sr", "tc", "lt", "lo", "as", "fr", "nb", "yb", "if", "pb", "ge", "th", "pm", "rb", "sh", "co", "ga", "li", "ha", "hz", "no", "bi", "di", "hi", "qa", "pi", "os", "uh", "wm", "an", "me", "mo", "na", "la", "st", "er", "sc", "ne", "mn", "mi", "am", "ex", "pt", "io", "be", "fm", "ta", "tb", "ni", "mr", "pa", "he", "lr", "sq", "ye" };
	string start = "qa";
	string end = "sq";
	int n = 95;

	unordered_set<string> dict;
	for (int i = 0; i < n; i++)
		dict.insert(words[i]);

	//printGraph(dict);



	int res;
	vector<vector<string>> res2;

	clock_t t1, t2;
	//t1 = clock();
	//res = ladderLength3(start, end, dict);
	//t2 = clock();
	//cout << "output: " << res << ", Time elapsed: " << diffclock(t2, t1) << " ms" << endl;

	//t1 = clock();
	//res = ladderLength2(start, end, dict);
	//t2 = clock();
	//cout << "output: " << res << ", Time elapsed: " << diffclock(t2, t1) << " ms" << endl;

	t1 = clock();
	res2 = findLadders(start, end, dict);
	t2 = clock();
	cout << "Time elapsed: " << diffclock(t2, t1) << " ms" << endl;

	for (int i = 0; i < res2.size(); i++) {
		for (int j = 0; j < res2[i].size(); j++) {
			cout << res2[i][j] << ", ";
		}
		cout << endl;
	}

	return 0;
}
