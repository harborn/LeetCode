
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
	vector<vector<string>> res;
	res.push_back(vector<string>(1, start));
	int find = 0;
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
					}
					else if (dict.find(str) != dict.end()) {
						vector<string> path(res[n]);
						path.push_back(str);
						res.push_back(path);
						//dict.erase(str);
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

	return res2;
}


class Solution {
public:
	vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		pathes.clear();
		dict.insert(start);
		dict.insert(end);
		vector<string> prev;
		unordered_map<string, vector<string> > traces;
		for (unordered_set<string>::const_iterator citr = dict.begin();
			citr != dict.end(); citr++) {
			traces[*citr] = prev;
		}

		vector<unordered_set<string> > layers(2);
		int cur = 0;
		int pre = 1;
		layers[cur].insert(start);
		int level = 0;
		while (true) {
			cur = !cur;
			pre = !pre;
			for (unordered_set<string>::const_iterator citr = layers[pre].begin();
				citr != layers[pre].end(); citr++)
				dict.erase(*citr);
			layers[cur].clear();
			for (unordered_set<string>::const_iterator citr = layers[pre].begin();
				citr != layers[pre].end(); citr++) {
				for (int n = 0; n<(*citr).size(); n++) {
					string word = *citr;
					int stop = word[n] - 'a';
					for (int i = (stop + 1) % 26; i != stop; i = (i + 1) % 26) {
						word[n] = 'a' + i;
						if (dict.find(word) != dict.end()) {
							traces[word].push_back(*citr);
							layers[cur].insert(word);
						}
					}
				}
			}
			level++;
			if (layers[cur].size() == 0)
				return pathes;
			if (layers[cur].count(end))
				break;
		}
		vector<string> path;
		buildPath(traces, path, end);

		return pathes;
	}

private:
	void buildPath(unordered_map<string, vector<string> > &traces,
		vector<string> &path, const string &word) {
		if (traces[word].size() == 0) {
			path.push_back(word);
			vector<string> curPath = path;
			reverse(curPath.begin(), curPath.end());
			pathes.push_back(curPath);
			path.pop_back();
			return;
		}

		const vector<string> &prevs = traces[word];
		path.push_back(word);
		for (vector<string>::const_iterator citr = prevs.begin();
			citr != prevs.end(); citr++) {
			buildPath(traces, path, *citr);
		}
		path.pop_back();
	}

	vector<vector<string> > pathes;
};


int main(void) {

	string words[] = { "si", "go", "se", "cm", "so", "ph", "mt", "db", "mb", "sb", "kr", "ln", "tm", "le", "av", "sm", "ar", "ci", "ca", "br", "ti", "ba", "to", "ra", "fa", "yo", "ow", "sn", "ya", "cr", "po", "fe", "ho", "ma", "re", "or", "rn", "au", "ur", "rh", "sr", "tc", "lt", "lo", "as", "fr", "nb", "yb", "if", "pb", "ge", "th", "pm", "rb", "sh", "co", "ga", "li", "ha", "hz", "no", "bi", "di", "hi", "qa", "pi", "os", "uh", "wm", "an", "me", "mo", "na", "la", "st", "er", "sc", "ne", "mn", "mi", "am", "ex", "pt", "io", "be", "fm", "ta", "tb", "ni", "mr", "pa", "he", "lr", "sq", "ye" };
	string start = "qa";
	string end = "sq";
	int n = 95;

	unordered_set<string> dict;
	for (int i = 0; i < n; i++) 
		dict.insert(words[i]);

	vector<vector<string>> res;
	vector<vector<string>> res2;

	res = findLadders(start, end, dict);

	// recreate dictionary.
	dict.clear();
	for (int i = 0; i < n; i++)
		dict.insert(words[i]);

	Solution sol;
	res2 = sol.findLadders(start, end, dict);

	cout << "res: " << endl;
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << ", ";
		}
		cout << endl;
	}

	cout << "res2: " << endl;
	for (int i = 0; i < res2.size(); i++) {
		for (int j = 0; j < res2[i].size(); j++) {
			cout << res2[i][j] << ", ";
		}
		cout << endl;
	}


	return 0;
}