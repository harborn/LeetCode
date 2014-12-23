
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct pos {
	int x;
	int y;
	pos(int a, int b) : x(a), y(b) {}
};

struct posVal {
	int x;
	int y;
	char val;
	posVal(int a, int b, char c) : x(a), y(b), val(c) {}
};

vector<posVal> getRowColumnBlock(vector<vector<char>> &board) {
	vector<pos> poss;
	string nums;

	for (int i = 0; i < 9; i++) { // row
		string s;
		vector<pos> pt;
		for (int j = 0; j < 9; j++) {
			if (board[i][j] != '.') s.push_back(board[i][j]);
			else pt.push_back(pos(i, j));
		}
		if (s.size() > nums.size() && s.size() != 9) {
			nums = s;
			poss = pt;
		}
	}

	for (int j = 0; j < 9; j++) { // column
		string s;
		vector<pos> pt;
		for (int i = 0; i < 9; i++) {
			if (board[i][j] != '.') s.push_back(board[i][j]);
			else pt.push_back(pos(i, j));
		}
		if (s.size() > nums.size() && s.size() != 9) {
			nums = s;
			poss = pt;
		}
	}

	for (int i = 0; i < 9; i++) { // block
		string s;
		vector<pos> pt;
		for (int j = 0; j < 9; j++) {
			int r = i / 3 * 3 + j / 3;
			int c = i % 3 * 3 + j % 3;
			if (board[r][c] != '.') s.push_back(board[r][c]);
			else pt.push_back(pos(r, c));
		}
		if (s.size() > nums.size() && s.size() != 9) {
			nums = s;
			poss = pt;
		}
	}

	vector<posVal> res;
	if (poss.size() == 0) return res;

	string s = "123456789";
	string s2;
	for (int i = 0; i < s.size(); i++) {
		if (nums.find(s[i]) >= nums.size())
			s2.push_back(s[i]);
	}

	for (int i = 0; i < poss.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			res.push_back(posVal(poss[i].x, poss[i].y, s2[j]));
		}
	}

	return res;

}

bool check(vector<vector<char>> &board, int row, int col) {
	char rlb[10] = { 0 };
	memset(rlb, 0, 10);
	int num;
	for (int j = 0; j < 9; j++) { // check row
		num = board[row][j] - '0';
		if (num > 0 && num <= 9) {
			if (rlb[num] == 0)
				rlb[num] = 1;
			else return false;
		}
	}
	memset(rlb, 0, 10);
	for (int i = 0; i < 9; i++) { // check column
		num = board[i][col] - '0';
		if (num > 0 && num <= 9) {
			if (rlb[num] == 0)
				rlb[num] = 1;
			else return false;
		}
	}
	memset(rlb, 0, 10);
	for (int i = 0; i < 9; i++) { // check block
		int r = row / 3 * 3 + i / 3;
		int c = col / 3 * 3 + i % 3;
		num = board[r][c] - '0';
		if (num > 0 && num <= 9) {
			if (rlb[num] == 0)
				rlb[num] = 1;
			else return false;
		}
	}

	return true;
}

bool helper(vector<vector<char>> &board) {
	vector<posVal> ava = getRowColumnBlock(board);
	cout << "ava.size() = " << ava.size() << endl;

	while (!ava.empty()) {
		for (int i = 0; i < ava.size(); i++) {
			int x = ava[i].x, y = ava[i].y, v = ava[i].val;
			char c = board[x][y];
			board[x][y] = v;
			if (check(board, x, y)) {
				cout << "[" << x << ", " << y << "] = " << v - '0' << ", ";
				bool ret = helper(board);
				if (ret) return true;
				//if (ret) continue;
			}
			else board[x][y] = c;
		}
		ava = getRowColumnBlock(board);
	}
	return true;
}

void solveSudoku(vector<vector<char> > &board) {

	helper(board);
}


struct Position {
	int row;
	int col;
};

inline bool isValid(vector<vector<char> > &board, Position &p) {
	char val = board[p.row][p.col];
	if (val < '1' || val > '9') return false;
	//cout<<val<<"vT";

	//1.check row
	vector<char> &brow = board[p.row];
	const int width = brow.size();
	for (int ic = 0; ic < width; ++ic) {
		if (ic != p.col
			&& brow[ic] != '.'
			&& brow[ic] == val) {
			//cout<<brow[ic]<<"rF";
			return false;
		}
	}
	//cout<<"rT";

	//2.check column
	const int height = board.size();
	for (int ir = 0; ir < height; ++ir) {
		if (ir != p.row
			&& board[ir][p.col] != '.'
			&& board[ir][p.col] == val)
			return false;
	}

	//3.check 3*3 grid
	const int baseri = p.row / 3 * 3;
	const int baseci = p.col / 3 * 3;
	for (int ir = baseri; ir < baseri + 3; ++ir) {
		for (int ic = baseci; ic < baseci + 3; ++ic) {
			if (ir != p.row && ic != p.col
				&& board[ir][ic] != '.'
				&& board[ir][ic] == val)
				return false;
		}
	}

	//cout<<"T";
	return true;
}
void solveSudoku2(vector<vector<char> > &board) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	static int times = 0;
	//if(times ++ > 0) return;

	vector<Position> pts;//empty positions
	int rows = board.size();
	if (0 == rows) return;
	int cols = board[0].size();
	if (0 == cols) return;

	//1.found all the empties
	for (int ir = 0; ir < rows; ++ir) {
		for (int ic = 0; ic < cols; ++ic) {
			if (board[ir][ic] == '.') {
				Position p;
				p.row = ir;
				p.col = ic;
				pts.push_back(p);
			}
		}
	}
	if (pts.size() == 0) return;//no empty cells

	//2.back tracing to fill the empties
	int curi = 0;
	bool forward = true;
	board[pts[curi].row][pts[curi].col] = '1';
	while (curi >= 0) {
		if (curi >= pts.size()) return;
		Position &curPt = pts[curi];
		if (forward) {
			bool valid = isValid(board, curPt);
			if (valid) {
				++curi;
			}
			else {
				forward = false;
			}
		}
		else {
			char &c = board[curPt.row][curPt.col];
			if (c == '9') {
				//no siblings
				c = '.';
				--curi;
			}
			else {
				c += 1;
				forward = true;
			}
		}
	}
}//end function

// 36ms
class Solution {
public:
	unordered_map<int, int> int2bit;
	unordered_map<int, int> bit2int;
	bool solveSudoku(int n, vector<pair<int, int>> &blank, vector<vector<char>> &board, vector<int>&row, vector<int>&col, vector<int>&cell) {
		if (n == blank.size())
		{
			return true;
		}
		int i = blank[n].first;
		int j = blank[n].second;
		int idx = (i / 3) * 3 + j / 3;
		int pos = row[i] & col[j] & cell[idx];
		while (pos)
		{
			int p = pos & (-pos);
			pos = pos - p;
			board[i][j] = '0' + bit2int[p];
			row[i] &= ~p;
			col[j] &= ~p;
			cell[idx] &= ~p;
			if (solveSudoku(n + 1, blank, board, row, col, cell))
			{
				return true;
			}
			row[i] |= p;
			col[j] |= p;
			cell[idx] |= p;
		}
		return false;
	}
	void solveSudoku(vector<vector<char>> &board) {

		for (int k = 1; k <= 9; k++)
		{
			int2bit[k] = 1 << (k - 1);
			bit2int[1 << (k - 1)] = k;
		}
		int limit = (1 << 9) - 1;
		vector<int> row(9, limit);
		vector<int> col(9, limit);
		vector<int> cell(9, limit);
		vector<pair<int, int> > blank;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] != '.')
				{
					int k = int2bit[board[i][j] - '0'];
					row[i] &= ~k;
					col[j] &= ~k;
					int idx = (i / 3) * 3 + j / 3;
					cell[idx] &= ~k;
				}
				else
				{
					blank.push_back(pair<int, int>(i, j));
				}
			}
		}
		solveSudoku(0, blank, board, row, col, cell);
	}
};

class Solution2 {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
		return true;
	}
	void solveSudoku(vector<vector<char> > &board) {
		util(board, 0);
	}
	bool util(vector<vector<char>>& board, int pos)
	{
		if (pos >= 81)
			return true;
		int i = pos / 9;
		int j = pos % 9;
		if (board[i][j] != '.')
			return util(board, pos + 1);
		else
		{
			for (char c = '1'; c <= '9'; c++)
			{
				if (!isInRow(board, i, c) && !isInCol(board, j, c) && !isInRec(board, i, j, c))
				{
					board[i][j] = c;
					if (util(board, pos + 1))
						return true;
					else
						board[i][j] = '.';
				}
			}
			return false;
		}
	}

	bool isInRow(vector<vector<char>>& board, int i, char c)
	{
		vector<char>& row = board[i];
		for (int k = 0; k < 9; k++)
		{
			if (row[k] == c)
				return true;
		}
		return false;
	}
	bool isInCol(vector<vector<char>>& board, int j, char c)
	{
		for (int k = 0; k < 9; k++)
		{
			if (board[k][j] == c)
				return true;
		}
		return false;
	}
	bool isInRec(vector<vector<char>>& board, int i, int j, char c)
	{
		int bigrow = i / 3, bigcol = j / 3;
		for (int m = 3 * bigrow; m < 3 * (bigrow + 1); m++)
		{
			for (int n = 3 * bigcol; n < 3 * (bigcol + 1); n++)
				if (board[m][n] == c)
					return true;
		}
		return false;
	}
};

int main(void) {

	string lines[] = {
		"53..7....",
		"6..195...",
		".98....6.",
		"8...6...3",
		"4..8.3..1",
		"7...2...6",
		".6....28.",
		"...419..5",
		"....8..79"
	};

	vector<vector<char>> board;
	for (int i = 0; i < 9; i++) {
		vector<char> line(lines[i].begin(), lines[i].end());
		board.push_back(line);
	}

	//vector<posVal> res = getRowColumnBlock(board);

	//solveSudoku2(board);
	Solution sol2;
	sol2.solveSudoku(board);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}

	return 0;
}