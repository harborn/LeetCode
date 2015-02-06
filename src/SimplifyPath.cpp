#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

string simplifyPath(string path) {
	
	int size = path.size();
	string res;
	if (size <= 0) return res;
	if (path[0] != '/') return res;

	stack<string> st;
	st.push("/");

	int i = 1;
	while (i < size) {
		string s1;
		while (i < size && path[i] != '/') {
			s1.push_back(path[i]);
			i++;
		}
		string s2;
		while (i < size && path[i] == '/') {
			s2.push_back('/');
			i++;
		}
		if (!s1.empty()) {
			if (!s1.compare(".")) {
				
			} else if (!s1.compare("..")) {
				if (st.size() > 1) st.pop();
			} else {
				s1.append("/");
				st.push(s1);
			}
		}
	}
	
	if (!st.empty()) {
		string ts = "";
		while (!st.empty()) {
			res = st.top().append(ts);
			ts = res;
			st.pop();
		}
	}
	if (res.size() > 1) res.pop_back();

	return res;
}

int main(void)
{
	vector<string> vs;
	
	vs.push_back("/home");
	vs.push_back("/a/./b/../../c/"); 
	vs.push_back("//////bin");
	vs.push_back("/../bin");
	vs.push_back("/../bin/.");
	vs.push_back("/...");
	vs.push_back("/.../");
	vs.push_back("/../");
	vs.push_back("/home.../");
	vs.push_back("/..hidden");

	
	string res;
	res = simplifyPath("/a/./b/../../c/");
	
	for (int i = 0; i < vs.size(); i++)
	{
		res = simplifyPath(vs[i]);
		cout << res << endl;
	}
	
	return 0;
}