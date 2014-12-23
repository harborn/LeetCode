
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

int gcd(int a, int b)
{
	if (a == 0) return b;
	return gcd(b%a, a);
}

int maxPoints(vector<Point> &points) {

	int size = points.size();
	if (size <= 2) return size;

	int res = 2;

	// inclined line
	// dx, dy, x0, y0, p.x, p.y, count
	unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int, int>>>>>> linePoint;
	// vertical line
	// x, p.x, p.y, count
	unordered_map<int, unordered_map<int, unordered_map<int, int>>> vlPoint;
	// horizontal
	// y, p.x, p.y, count
	unordered_map<int, unordered_map<int, unordered_map<int, int>>> hlPoint;

	for (int i = 0; i < size - 1; i++) {
		int x0 = points[i].x;
		int y0 = points[i].y;
		for (int j = i + 1; j < size; j++) {
			int x1 = points[j].x;
			int y1 = points[j].y;
			int dx = x0 - x1;
			int dy = y0 - y1;

			if (dx == 0) { // vectical line
				if (vlPoint.find(x0) != vlPoint.end() &&
					vlPoint[x0].find(x1) != vlPoint[x0].end() &&
					vlPoint[x0][x1].find(y1) != vlPoint[x0][x1].end()) {
					vlPoint[x0][x1][y1]++;
					vlPoint[x0][x1][y1]++;
				}
				else {
					vlPoint[x0][x1][y1] = 2;
				}
			}
			else if (dy == 0) { // horizontal line
				if (hlPoint.find(y0) != hlPoint.end() &&
					hlPoint[y0].find(x1) != hlPoint[y0].end() &&
					hlPoint[y0][x1].find(y1) != hlPoint[y0][x1].end()) {
					hlPoint[y0][x1][y1]++;
				}
				else {
					hlPoint[y0][x1][y1] = 2;
				}
			}
			else {
				int g = gcd(abs(dx), abs(dy));
				dx /= g;
				dy /= g;

				if (dx < 0) {
					dx = 0 - dx;
					dy = 0 - dy;
				}

				if (linePoint.find(dx) != linePoint.end() &&
					linePoint[dx].find(dy) != linePoint[dx].end() &&
					linePoint[dx][dy].find(x0) != linePoint[dx][dy].end() &&
					linePoint[dx][dy][x0].find(y0) != linePoint[dx][dy][x0].end() &&
					linePoint[dx][dy][x0][y0].find(x1) != linePoint[dx][dy][x0][y0].end() &&
					linePoint[dx][dy][x0][y0][x1].find(y1) != linePoint[dx][dy][x0][y0][x1].end()) {
					linePoint[dx][dy][x0][y0][x1][y1]++;
				}
				else {
					linePoint[dx][dy][x0][y0][x1][y1] = 2;
				}
			}
		}
	}

	unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int, int>>>>>>::iterator k6;
	unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int, int>>>>>::iterator k5;
	unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int, int>>>>::iterator k4;
	unordered_map<int, unordered_map<int, unordered_map<int, int>>>::iterator k3;
	unordered_map<int, unordered_map<int, int>>::iterator k2;
	unordered_map<int, int>::iterator k1;
	for (k3 = vlPoint.begin(); k3 != vlPoint.end(); k3++) {
		int num = 0;
		for (k2 = k3->second.begin(); k2 != k3->second.end(); k2++) {
			for (k1 = k2->second.begin(); k1 != k2->second.end(); k1++) {
				num += k1->second;
			}
		}
		if (num > res) res = num;
	}

	for (k3 = hlPoint.begin(); k3 != hlPoint.end(); k3++) {
		int num = 0;
		for (k2 = k3->second.begin(); k2 != k3->second.end(); k2++) {
			for (k1 = k2->second.begin(); k1 != k2->second.end(); k1++) {
				num += k1->second;
			}
		}
		if (num > res) res = num;
	}

	return res;
}

int maxPoints2(vector<Point> &points) {
	unordered_map<float, int> mp;
	int maxNum = 0;
	for (int i = 0; i < points.size(); i++)
	{
		mp.clear();
		//mp[INT_MIN] = 0;
		int duplicate = 1;
		for (int j = 0; j < points.size(); j++)
		{
			if (j == i) continue;
			if (points[i].x == points[j].x && points[i].y == points[j].y)
			{
				duplicate++;
				continue;
			}
			float k = points[i].x == points[j].x ? INT_MAX : (float)(points[j].y - points[i].y) / (points[j].x - points[i].x);
			mp[k]++;
		}
		unordered_map<float, int>::iterator it = mp.begin();
		for (; it != mp.end(); it++)
			if (it->second + duplicate > maxNum)
				maxNum = it->second + duplicate;
	}
	return maxNum;
}

int maxPoints3(vector<Point> &points) {
	int i, j;
	double alpha;
	int max = 0;
	int num;
	int overlap;
	if (points.size() < 2)return points.size();
	unordered_map<double, int> temp;
	for (i = 0; i != points.size() - 1; i++) {
		overlap = 0;
		num = 1;
		for (j = i + 1; j != points.size(); j++) {
			if (points[j].x == points[i].x && points[j].y == points[i].y) {
				overlap++;
			}
			else {
				alpha = atan2((points[j].y - points[i].y), (points[j].x - points[i].x));
				if (alpha <= 0)alpha = atan2((points[i].y - points[j].y), (points[i].x - points[j].x));
				temp[alpha]++;
				num = temp[alpha] + 1 > num ? temp[alpha] + 1 : num;
			}
		}
		if (overlap > 0) num += overlap;
		if (num > max) max = num;
		temp.clear();
	}
	return max;
}

int maxPoints4(vector<Point> &points) {
	int size = points.size();
	if (size <= 2) return size;
	unordered_map<float, int> mp;
	int res = 0;
	for (int i = 0; i < size - 1; i++){
		mp.clear();
		int same = 0;
		int num = 1;
		for (int j = i + 1; j < size; j++) {
			if (points[i].x == points[j].x && points[i].y == points[j].y) {
				same++;
			}
			else
			{
				float k = points[i].x == points[j].x ? INT_MAX : (float)(points[j].y - points[i].y) / (points[j].x - points[i].x);
				mp[k]++;
				num = mp[k] + 1 > num ? mp[k] + 1 : num;
			}
		}
		num += same;
		if (num > res) res = num;
	}

	return res;
}

int main(void) {

	unordered_map<int, int> tm;

	tm[0]++;
	tm[0]++;
	tm[0]++;
	tm[0]++;
	tm[0]++;

	tm[1]++;

	vector<Point> points;
	points.push_back(Point(0, 0));
	points.push_back(Point(0, 0));
	points.push_back(Point(0, 0));
	//points.push_back(Point(1, 1));
	//points.push_back(Point(2, 2));

	int res = maxPoints2(points);
	cout << res << endl;

	return 0;
}