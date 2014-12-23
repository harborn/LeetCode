class Solution {
public:
    int majorityElement(vector<int> &num) {
        int n = num[0], i = 1, cnt = 1;;
    	while (i < num.size()) {
    		if (num[i] == n) {
    			cnt++;
    		}
    		else {
    			cnt--;
    			if (cnt <= 0) {
    				cnt = 1;
    				n = num[i];
    			}
    		}
    		i++;
    	}
    	return n;
    }
};
