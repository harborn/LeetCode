

#include <iostream>

void helper(int d[], int s, int m, int e) {
	int i = s, j = m;
	int t;
	while (i < m && j < e) {
		if (d[i] > d[j]) {
			t = d[i];
			d[i] = d[j];
			d[j] = t;
		}
		else if (d[i] < d[j]) {
		
		}
		i++;
	}
}


void MergeSort(int d[], int n) {

}

//int main(void) {
//
//	return 0;
//}