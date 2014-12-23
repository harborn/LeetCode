
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> fullJustify(vector<string> &words, int L) {
	vector<string> res;
	vector<string> line;
	int i = 0;
	int size = words.size();
	int len = 0;
	while (i < size) {
		int l = words[i].size();
		if (len + l > L) {
			int n = line.size();
			string sl;
			if (n == 1) {
				sl.append(line[0]);
				int sc = L - line[0].size();
				string ss(sc, ' ');
				sl.append(ss);
				res.push_back(sl);
				line.clear();
				len = 0;
				continue;
			}

			int space = L - len + n;
			int per = space / (n - 1);
			int left = space - per * (n - 1);

			for (int j = 0; j < n - 1; j++) {
				sl.append(line[j]);
				int sc = per + (left > 0 ? 1 : 0);
				left--;
				string ss(sc, ' ');
				sl.append(ss);
			}
			sl.append(line.back());
			res.push_back(sl);
			line.clear();
			len = 0;
		}
		else if (len + l == L) {
			line.push_back(words[i]);
			string sl;
			int n = line.size();
			for (int j = 0; j < n - 1; j++) {
				sl.append(line[j]);
				sl.append(" ");
			}
			sl.append(line.back());
			res.push_back(sl);
			line.clear();
			len = 0;
			i++;
		}
		else {
			line.push_back(words[i]);
			len += l + 1;
			i++;
		}
	}

	if (line.size() == 1) {
		string sl;
		sl.append(line[0]);
		int sc = L - line[0].size();
		string ss(sc, ' ');
		sl.append(ss);
		res.push_back(sl);
	}
	else if (line.size() > 1) {
		string sl;
		int n = line.size();
		int space = L - len + n;
		for (int j = 0; j < n; j++) {
			sl.append(line[j]);
			sl.append(" ");
			space--;
		}
		string ss(space, ' ');
		sl.append(ss);
		res.push_back(sl);
	}
	
	return res;
}

int main(void) {

	//string s[] = { "Listen", "to", "many,", "speak", "to", "a", "few." };
	string s[] = { "What", "must", "be", "shall", "be." };
	
	vector<string> words;

	words.insert(words.begin(), s, s + 5);

	//words.push_back("This");
	//words.push_back("is");
	//words.push_back("an");
	//words.push_back("example");
	//words.push_back("of");
	//words.push_back("text");
	//words.push_back("justification.");

	//words.push_back("A"); words.push_back("line"); words.push_back("other");
	//words.push_back("than"); words.push_back("the"); words.push_back("last");
	//words.push_back("line"); words.push_back("might"); words.push_back("contain");
	//words.push_back("only"); words.push_back("one"); words.push_back("word");



	vector<string> res = fullJustify(words, 12);

	return 0;
}