
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > permute(vector<int> &num) {
	int size = num.size();
	vector<vector<int>> ret;
	for (int i = 0; i < size; i++) {
		vector<int> sn(num);
		sn.erase(sn.begin() + i);
		vector<vector<int>> sp = permute(sn);
		ret[i].insert(ret[i].end(), num[i]);
		for (int j = 0; j < sp.size(); j++) {
			ret.insert(ret.end(), sp[i].begin(), sp[i].end());
		}
	}
	return ret;
}

int main(void)
{
	vector<int> num;
	num.push_back(1);
	//num.push_back(2);
	//num.push_back(3);

	vector<vector<int>> ret = permute(num);

	return 0;
}