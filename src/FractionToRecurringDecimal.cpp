class Solution {
public:
    string fractionToDecimal(int64_t ln, int64_t ld) {
    	if (ln == 0) return "0";
    	if (ld == 0) return "";
    	string res;
    	if ((ln < 0) ^ (ld < 0)) res.push_back('-');
    	ln = abs(ln);
    	ld = abs(ld);
    
    	//long long *d = new long long[denominator];
    	//long long *r = new long long[denominator];
    	vector<long long> d;
    	vector<long long> r;
    	
    	res += to_string(ln / ld);
    	if (ln % ld == 0) {
    		return res;
    	}
    
    	int j;
    	long long t = ln % ld, td, tr;
    	res.push_back('.');
    	int pl = res.size();
    	t *= 10;
    	for (int i = 0; i < ld; i++) {
    		td = t / ld;
    		tr = t % ld;
    		for (j = 0; j < i; j++) {
    			if (td == d[j] && tr == r[j]) break;
    		}
    		if (j < i) {
    			res.insert(res.begin() + pl + j, '(');
    			res.push_back(')');
    			break;
    		}
    		d.push_back(td); //d[i] = td; //d.push_back(td); 
    		r.push_back(tr); //r[i] = tr; //r.push_back(tr); 
    		res.push_back('0' + td);
    		if (tr == 0) break;
    		t = tr * 10;
    	}
    	return res;
    }
};
