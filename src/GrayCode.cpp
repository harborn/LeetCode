
#include <iostream>
#include <vector>

using std::vector;
using std::cout;

vector<int> grayCode(int n) {
        
	vector<int> ret;
	
	if (n <= 0) return ret;

	ret.push_back(0);
	ret.push_back(1);

	int k = 1;
	int m = 1;
	while (k < n) {
		int l = ret.size() - 1;
		m <<= 1;
		while (l >= 0) {
			ret.push_back(m + ret[l]);
			l--;
		}
		k++;
	}
	return ret;
}

int main(void)
{
	vector<int> res = grayCode(4);

	return 0;
}