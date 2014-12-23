#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//
//There are N children standing in a line. Each child is assigned a rating value.
//
//You are giving candies to these children subjected to the following requirements:
//
//Each child must have at least one candy.
//Children with a higher rating get more candies than their neighbors.
//What is the minimum candies you must give?


int candy(vector<int> &ratings) {
	int res = 0, size = ratings.size();
	if (size == 0) return 0;
	if (size == 1) return 1;
	int i = 1, ord, c;
	int st = 0, stv;
	if (ratings[0] > ratings[1]) { c = 2; ord = -1; stv = 2; }
	else if (ratings[0] < ratings[1]) { c = 1; ord = 1; stv = 1; }
	else { c = 1; ord = 0; stv = 1; }
	res += c;
	while (i < size) {
		if (ratings[i] > ratings[i - 1]) {
			if (ord == 0) c = 1;
			else if (ord == -1) {
				res -= (i - st) * (c - 1);
				c = 1;
			}
			c++;
			if (ord == -1) {
				st = i - 1;
				stv = c;
			}
			ord = 1;
		}
		else if (ratings[i] < ratings[i - 1]) {
			c--;
			if (ord == 0) { // 4,4,3
				st = i - 1;
			}
			else if (ord == 1) { // 1,2,3,4,1
				st = i - 1; // 1,2,3,4,1,2,3,4,1
				stv = c;
			}
			ord = -1;
		}
		else {
			ord = 0;
			st = i;
			stv = c;
		}
		res += c;
		i++;
	}
	if (ord != 1 && c != 1) {
		res -= (i - st) * (c - 1);
	}
	return res;
}

int candy2(vector<int> &ratings) {
	int res = 0, size = ratings.size();
	if (size == 0) return 0;
	if (size == 1) return 1;
	int i = 1, ord, c, st;
	if (ratings[0] > ratings[1]) { c = 2; ord = -1; st = 0; }
	else if (ratings[0] < ratings[1]) { c = 1; ord = 1; st = 0; }
	else { c = 1; ord = 0; st = 0; }
	res = c;
	ratings.push_back(ratings.back());
	size++;
	while (i < size) {
		if (ratings[i] > ratings[i - 1]) {
			if (ord == -1) {
				res -= (i - st) * (c - 1);
				c = 1;
				st = i;
			}
			else if (ord == 0) {
				res -= (i - st) * (c - 1);
				c = 1;
				st = i;
			}
			c++;
			ord = 1;
		}
		else if (ratings[i] < ratings[i - 1]) {
			if (ord == 0) {

			}
			else if (ord == 1) {

			}
			c--;
			ord = -1;
		}
		else {
			if (ord == -1) {

				st = i;
			}
			else if (ord == 1) {
				st = i;
			}
			c = 1;
			ord = 0;
		}
		i++;
		res += c;
	}
	res--;
	ratings.pop_back();

	return res;
}

void adjust(vector<int> &ratings, vector<int> &candies, int start, int end) {
	if (start > end) return;
	int c = 1;
	for (int i = end; i >= start; i--) {
		candies[i] = c;
		c++;
	}
	if (start > 0 && ratings[start] > ratings[start - 1]) {
		if (candies[start] == candies[start - 1]) candies[start] = candies[start - 1] + 1;
		else if (candies[start] < candies[start-1]) candies[start] = candies[start - 1] + 1;
	}
}

int candy3(vector<int> &ratings) {
	int size = ratings.size();
	if (size < 2) return size;
	vector<int> candies(size, 0);
	int c;
	if (ratings[0] > ratings[1]) c = 2;
	else c = 1;
	int i = 1, s = 0;
	candies[0] = c;
	while (i < size) {
		while (i < size && ratings[i] > ratings[i - 1]) {
			c++;
			candies[i] = c;
			i++;
		}
		s = i;
		while (i < size && ratings[i] < ratings[i - 1]) {
			c--;
			candies[i] = c;
			i++;
		}
		adjust(ratings, candies, s - 1, i - 1);
		c = 1;
		while (i < size && ratings[i] == ratings[i - 1]) {
			candies[i] = c;
			i++;
		}
	}
	int res = 0;
	for (int i = 0; i < size; i++) {
		res += candies[i];
	}
	return res;
}

void ReAdjustCandy(vector<int>& ratings, vector<int>& candy, int startIndex)
{
	int k = startIndex;
	int diff = 1 - candy[k];
	while (k > 0 && ratings[k - 1] > ratings[k])
	{
		candy[k] = candy[k] + diff;
		k--;
	}
	if (diff > 0) candy[k] += diff;
}

int candy4(vector<int> &ratings) {
	vector<int> candy(ratings.size());
	candy[0] = 1;
	int i = 1;
	for (; i < ratings.size(); ++i)
	{
		if (ratings[i] > ratings[i - 1]) //µÝÔö  
		{
			candy[i] = candy[i - 1] + 1;
		}
		if (ratings[i] == ratings[i - 1]) //Æ½ÐÐ  
		{
			candy[i] = 1;
		}
		if (ratings[i] < ratings[i - 1]) //µÝ¼õ  
		{
			candy[i] = candy[i - 1] - 1;
		}
		if (i<ratings.size() - 1 && ratings[i] < ratings[i - 1] && ratings[i] <= ratings[i + 1])
			ReAdjustCandy(ratings, candy, i);
	}
	if (ratings[i - 1] < ratings[i - 2])
		ReAdjustCandy(ratings, candy, ratings.size() - 1);
	int total = 0;
	std::for_each(candy.begin(), candy.end(), [&](int n){
		total += n;
	});
	return total;
}


int main(void) {

	int A1[] = { 2, 2 }; vector<int> r1(A1, A1 + sizeof(A1) / sizeof(int)); // Expected 2; [1,1]
	int A2[] = { 1, 2, 2 }; vector<int> r2(A2, A2 + sizeof(A2) / sizeof(int)); // Expected 4; [1,2,1]
	int A3[] = { 1, 1, 2 }; vector<int> r3(A3, A3 + sizeof(A3) / sizeof(int));// Expected 4; [1,1,2]
	int A4[] = { 1, 1, 1 }; vector<int> r4(A4, A4 + sizeof(A4) / sizeof(int));// Expected 3; [1,1,1]
	int A5[] = { 2, 1 }; vector<int> r5(A5, A5 + sizeof(A5) / sizeof(int));// Expected 3; [2,1]
	int A6[] = { 3, 2, 1 }; vector<int> r6(A6, A6 + sizeof(A6) / sizeof(int));// Expected 6; [3,2,1]
	int A7[] = { 1, 2, 4, 4, 3 }; vector<int> r7(A7, A7 + sizeof(A7) / sizeof(int));// Expected 9; [1,2,3,2,1]
	int A8[] = { 1, 2, 4, 4, 3, 2, 1 }; vector<int> r8(A8, A8 + sizeof(A8) / sizeof(int));// Excpeted 16; [1,2,3,4,3,2,1]
	int A9[] = { 4, 2, 3, 4, 1 }; vector<int> r9(A9, A9 + sizeof(A9) / sizeof(int));// Expected 9; [2,1,2,3,1]
	int A10[] = { 1, 3, 4, 3, 2, 1 }; vector<int> r10(A10, A10 + sizeof(A10) / sizeof(int));// Expected 13; [1,2,4,3,2,1]
	int A11[] = { 1, 3, 4, 4, 4, 4, 3, 2, 1 }; vector<int> r11(A11, A11 + sizeof(A11) / sizeof(int));// Expected 18; [1,2,3,1,1,4,3,2,1]
	int A12[] = { 4, 3, 2, 1, 2, 3, 4, 5, 1 }; vector<int> r12(A12, A12 + sizeof(A12) / sizeof(int));// Expected 25; [4,3,2,1,2,3,4,5,1]
	int A13[] = { 1, 2, 3, 4, 1, 2, 3, 4, 1 }; vector<int> r13(A13, A13 + sizeof(A13) / sizeof(int));// Ecpected 21; [1,2,3,4,1,2,3,4,1]

	vector<vector<int>> ratings;
	ratings.push_back(r12);
	ratings.push_back(r1);
	ratings.push_back(r2);
	ratings.push_back(r3);
	ratings.push_back(r4);
	ratings.push_back(r5);
	ratings.push_back(r6);
	ratings.push_back(r7);
	ratings.push_back(r8);
	ratings.push_back(r9);
	ratings.push_back(r10);
	ratings.push_back(r11);
	ratings.push_back(r12);
	ratings.push_back(r13);

	for (int i = 0; i < ratings.size(); i++){
		int res = candy3(ratings[i]);
		for (int j = 0; j < ratings[i].size(); j++)
			cout << ratings[i][j] << ", ";
		cout << "          = " << res << endl;
	}

	return 0;
}
