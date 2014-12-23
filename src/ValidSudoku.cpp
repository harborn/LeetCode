
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool isValidSudoku(vector<vector<char> > &board) {
	for (int i = 0; i < 9; i++) {
		unordered_set<char> row;
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == '.') continue;
			if (row.find(board[i][j]) != row.end())
				return false;
			row.insert(board[i][j]);
		}
	}

	for (int j = 0; j < 9; j++) {
		unordered_set<char> col;
		for (int i = 0; i < 9; i++) {
			if (board[i][j] == '.') continue;
			if (col.find(board[i][j]) != col.end())
				return false;
			col.insert(board[i][j]);
		}
	}

	for (int i = 0; i < 9; i++) {
		unordered_set<char> block;
		for (int j = 0; j < 9; j++) {
			int r = i / 3 * 3 + j / 3;
			int c = i % 3 * 3 + j % 3;
			if (board[r][c] == '.') continue;
			if (block.find(board[r][c]) != block.end())
				return false;
			block.insert(board[r][c]);
		}
	}

	return true;
}

bool checkValid(int vec[], int val)
{
	if (vec[val] == 1)return false;
	vec[val] = 1;
	return true;
}

bool isValidSudoku2(vector<vector<char> > &board) {
	int rowValid[10] = { 0 }; //用于判断某一行是否合法，对于行来说这个数组可以重复使用
	int columnValid[9][10] = { 0 }; //用于判断某一列是否合法
	int subBoardValid[9][10] = { 0 }; //用于判断某一个九宫格是否合法
	for (int i = 0; i < 9; i++)
	{
		memset(rowValid, 0, sizeof(rowValid));
		for (int j = 0; j < 9; j++)
			if (board[i][j] != '.')
			{
			if (!checkValid(rowValid, board[i][j] - '0') ||
				!checkValid(columnValid[j], board[i][j] - '0') ||
				!checkValid(subBoardValid[i / 3 * 3 + j / 3], board[i][j] - '0'))
				return false;
			}
	}
	return true;
}


int main(void) {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int r = i / 3 * 3 + j / 3;
			int c = i % 3 * 3 + j % 3;
			cout << r << ", " << c << endl;
		}
		cout << endl;
	}

	return 0;
}