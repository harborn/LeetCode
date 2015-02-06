
#include <string>
#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> &strs) {
    int size = strs.size();
    if (size == 0) return "";
    if (size == 1) return strs[0];
        
    string prefix;
    char c;
    for (int i = 0; i < strs[0].length(); i++) {
		c = strs[0][i];
		prefix.push_back(c);
		for (int j = 1; j < size; j++) {
			if (strs[j][i] != c) {
				prefix.pop_back();
				return prefix;
			}
		}
    }
	return prefix;
}

int main(void)
{
	vector<string> ss;
	ss.push_back("aab");
	ss.push_back("aabb");

	string ret = longestCommonPrefix(ss);

	return 0;
}