
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

// Given a collection of intervals, merge all overlapping intervals.

vector<Interval> merge(vector<Interval> &intervals) {
	vector<Interval> res;
	int size = intervals.size();
	if (size == 0) return res;
	res.push_back(intervals[0]);
	int i = 1, j;
	int start, end;
	while (i < size) {
		start = intervals[i].start;
		end = intervals[i].end;

		int j = 0;
		while (j < res.size()) {
			if (end < res[j].start) {
				res.insert(res.begin() + j, Interval(start, end));
				break;
			}
			else if (start > res[j].end) {
				j++;
			}
			else {
				start = min(start, res[j].start);
				end = max(end, res[j].end);
				res.erase(res.begin() + j);
			}
		}
		if (j == res.size())
			res.push_back(Interval(start, end));

		i++;
	}

	return res;
}

int main(void) {
	vector<Interval> intervals;
	//Interval i1(1, 3);
	//Interval i2(2, 6);
	//Interval i3(8, 10);
	//Interval i4(15, 18);
	//intervals.push_back(i1);
	//intervals.push_back(i2);
	//intervals.push_back(i3);
	//intervals.push_back(i4);

	//Interval i1(1, 4);
	//Interval i2(0, 0);
	//intervals.push_back(i1);
	//intervals.push_back(i2);

	Interval i1(0, 0);
	Interval i2(4, 5);
	Interval i3(5, 6);
	Interval i4(5, 5);
	Interval i5(2, 3);
	Interval i6(5, 7);
	Interval i7(0, 0);
	intervals.push_back(i1);
	intervals.push_back(i2);
	intervals.push_back(i3);
	intervals.push_back(i4);
	intervals.push_back(i5);
	intervals.push_back(i6);
	intervals.push_back(i7);

	vector<Interval> res = merge(intervals);

	return 0;
}

