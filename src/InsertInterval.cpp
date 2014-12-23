
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

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
	vector<Interval> res;

	int size = intervals.size();
	if (size == 0) {
		res.push_back(newInterval);
		return res;
	}

	if (newInterval.end < intervals.front().start) {
		res.push_back(newInterval);
		res.insert(res.end(), intervals.begin(), intervals.end());
	}
	else if (newInterval.start > intervals.back().end) {
		res.insert(res.begin(), intervals.begin(), intervals.end());
		res.push_back(newInterval);
	}
	else {
		int end = INT_MIN;
		for (int i = 0; i < size; i++) {
			if (intervals[i].start <= end) {
				if (res.back().end < intervals[i].end) {
					res.back().end = intervals[i].end;
					end = intervals[i].end;
				}
			}
			else if (newInterval.start <= intervals[i].end &&
				newInterval.end >= intervals[i].end) {
				Interval interval(intervals[i].start, newInterval.end);
				res.push_back(interval);
				end = interval.end;
			}
			else if (newInterval.start <= intervals[i].start &&
				newInterval.end >= intervals[i].start) {
				Interval interval(newInterval.start, newInterval.end);
				res.push_back(interval);
				end = interval.end;
				i--;
			}
			else {
				res.push_back(intervals[i]);
			}
		}
	}

	return res;
}

vector<Interval> insert2(vector<Interval> &v, Interval nv)
{
	vector<Interval> res;
	int sta = nv.start, end = nv.end;
	int i = 0;

	//注意：找到第一个起点的条件  
	for (; i<v.size() && sta > v[i].end; i++)
	{
		res.push_back(v[i]);
	}

	//注意：为空或过了结尾点  
	if (i < v.size())
		sta = min(sta, v[i].start);

	//注意：找到结束点的条件  
	for (; i < v.size() && end >= v[i].start; i++)
		end = max(end, v[i].end);

	res.push_back(Interval(sta, end));

	res.insert(res.end(), v.begin() + i, v.end());

	return res;
}

vector<Interval> insert3(vector<Interval> &intervals, Interval newInterval) {
	vector<Interval> res;
	int size = intervals.size();
	int start = newInterval.start, end = newInterval.end;
	int i = 0;
	while (i < size) {
		if (end < intervals[i].start) {
			res.push_back(Interval(start, end));
			break;
		}
		else if (start > intervals[i].end) {
			res.push_back(intervals[i]);
			i++;
		}
		else {
			start = min(start, intervals[i].start);
			end = max(end, intervals[i].end);
			i++;
		}
	}

	if (i < size) {
		for (; i < size; i++) {
			res.push_back(intervals[i]);
		}
	}
	else {
		res.push_back(Interval(start, end));
	}

	return res;
}

vector<Interval> insert4(vector<Interval> &intervals, Interval newInterval) {
	vector<Interval> result;
	int i = 0;
	while (i < intervals.size() && intervals[i].end < newInterval.start)
		result.push_back(intervals[i++]);
	while (i < intervals.size() && intervals[i].start <= newInterval.end){
		if (intervals[i].start < newInterval.start)
			newInterval.start = intervals[i].start;
		if (intervals[i].end > newInterval.end)
			newInterval.end = intervals[i].end;
		i++;
	}
	result.push_back(newInterval);

	while (i < intervals.size() && intervals[i].start > newInterval.end)
		result.push_back(intervals[i++]);
	return result;
}

int main(void)
{
	vector<Interval> intervals;
	Interval i1(1, 5);
	//Interval i2(2, 7);
	intervals.push_back(i1);
	
	Interval ii(6, 8);

	//vector<Interval> res = insert(intervals, i2);
	//vector<Interval> res2 = insert2(intervals, i2);
	vector<Interval> res3 = insert3(intervals, ii);

	return 0;
}