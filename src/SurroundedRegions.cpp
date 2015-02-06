
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

void helper(vector<vector<char>> &board, vector<vector<char>> &visited, int row, int col, int x, int y) {
	struct point {
		int r;
		int c;
		point(int i, int j) : r(i), c(j) {}
	};

	int surrouned = 1;
	vector<point> q;
	q.push_back(point(x, y));
	int start = 0;
	while (start < q.size()) {
		int n = q.size() - start;
		for (int i = start; i < start + n; i++) {
			int r = q[i].r;
			int c = q[i].c;
			visited[r][c] = 1;
			if (r == 0 || r == row-1 || c == 0 || c == col-1)
				surrouned = 0;
			if (r > 0 && !visited[r-1][c] && board[r-1][c] == 'O') // up
				q.push_back(point(r-1, c));
			if (c < col - 1 && !visited[r][c+1] && board[r][c+1] == 'O') // right
				q.push_back(point(r, c+1));
			if (r < row - 1 && !visited[r+1][c] && board[r+1][c] == 'O') // down
				q.push_back(point(r+1, c));
			if (c > 0 && !visited[r][c-1] && board[r][c-1] == 'O') // left
				q.push_back(point(r, c-1));
		}
		start += n;
	}
	if (surrouned) {
		for (int i = 0; i < q.size(); i++) {
			board[q[i].r][q[i].c] = 'X';
		}
	}
}

void solve(vector<vector<char>> &board) {
	if (board.empty()) return;
	int row = board.size();
	int col = board[0].size();

	vector<vector<char>> visited(row, vector<char>(col, 0));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (!visited[i][j] && board[i][j] == 'O') {
				helper(board, visited, row, col, i, j);
			}
		}
	}
}

struct point {
	int r;
	int c;
	point(int i, int j) : r(i), c(j) {}
};

void helper2(vector<vector<char>> &board, vector<point> &q, int row, int col, int x, int y) {
	q.push_back(point(x, y));
	int i = 0;
	while (i < q.size()) {
		int r = q[i].r;
		int c = q[i].c;
		board[r][c] = 'Y';
		if (r > 0 && board[r-1][c] == 'O') { q.push_back(point(r-1, c)); /*cout << r-1 << ", " << c << endl; */}
		if (r < row - 1 && board[r+1][c] == 'O') { q.push_back(point(r+1, c)); /*cout << r+1 << ", " << c << endl; */}
		if (c < col - 1 && board[r][c+1] == 'O') { q.push_back(point(r, c+1)); /*cout << r << ", " << c+1 << endl; */}
		if (c > 0 && board[r][c-1] == 'O') { q.push_back(point(r, c-1)); /*cout << r << ", " << c - 1 << endl; */}
		i++;
	}
	cout << i << endl;
}

void helper3(vector<vector<char>> &board, vector<point> &q, int row, int col) {
	int i = 0;
	while (i < q.size()) {
		int r = q[i].r;
		int c = q[i].c;
		board[r][c] = 'Y';
		if (r > 0 && board[r-1][c] == 'O') { q.push_back(point(r-1, c)); /*cout << r-1 << ", " << c << endl; */}
		if (r < row - 1 && board[r+1][c] == 'O') { q.push_back(point(r+1, c)); /*cout << r+1 << ", " << c << endl; */}
		if (c < col - 1 && board[r][c+1] == 'O') { q.push_back(point(r, c+1)); /*cout << r << ", " << c+1 << endl; */}
		if (c > 0 && board[r][c-1] == 'O') { q.push_back(point(r, c-1)); /*cout << r << ", " << c - 1 << endl; */}
		i++;
	}
	cout << i << endl;
}

void solve2(vector<vector<char>> &board) {
	if (board.empty()) return;
	int row = board.size();
	int col = board[0].size();

	vector<point> q;

	for (int j = 0; j < col; j++) {
		if (board[0][j] == 'O') {
			q.push_back(point(0, j));
		}
	}

	for (int j = 0; j < col; j++) {
		if (board[row-1][j] == 'O')  {
			q.push_back(point(row-1, j));
		}
	}

	for (int i = 0; i < row; i++) {
		if (board[i][0] == 'O') {
			q.push_back(point(i, 0));
		}
	}

	for (int i = 0; i < row; i++) {
		if (board[i][col-1] == 'O') {
			q.push_back(point(i, col-1));
		}
	}

	helper3(board, q, row, col);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			board[i][j] = (board[i][j] == 'Y' ? 'O' : 'X');
		}
	}
}

vector<int> xIndex;  
vector<int> yIndex;  
void solve3(vector<vector<char>> &board) {  
	int row = board.size();  
	if(row == 0) return;  
	int col = board[0].size();  
	xIndex.clear();  
	yIndex.clear();            
	for(int i =0; i< row; i++)  
	{  
		if(board[i][0] == 'O')  
		{  
			xIndex.push_back(i);  
			yIndex.push_back(0);  
		}  
		if(board[i][col-1] == 'O')  
		{  
			xIndex.push_back(i);  
			yIndex.push_back(col-1);  
		}  
	}  
	for(int i =0; i< col; i++)  
	{  
		if(board[0][i] == 'O')  
		{  
			xIndex.push_back(0);  
			yIndex.push_back(i);  
		}  
		if(board[row-1][i] == 'O')  
		{  
			xIndex.push_back(row-1);  
			yIndex.push_back(i);  
		}  
	}            
	int k =0;  
	while(k<xIndex.size())  
	{  
		int x = xIndex[k];  
		int y = yIndex[k];     
		board[x][y] = 'Y';  
		if(x>0 && board[x-1][y] == 'O' ) {xIndex.push_back(x-1); yIndex.push_back(y);}  
		if(x<row-1 && board[x+1][y] == 'O' ) {xIndex.push_back(x+1); yIndex.push_back(y);}                 
		if(y>0 && board[x][y-1] == 'O' ) {xIndex.push_back(x); yIndex.push_back(y-1);}  
		if(y<col-1 && board[x][y+1] == 'O' ) {xIndex.push_back(x); yIndex.push_back(y+1);}  
		k++;  
	}  
	cout << k << endl;
	for(int i =0; i< row; i++)  
	{  
		for(int j =0; j< col; j++)  
		{  
			if(board[i][j] =='O') board[i][j] = 'X';  
			if(board[i][j] == 'Y') board[i][j] = 'O';  
		}  
	}            
}    

int main(void) {

	string lines[] = {"XOOOOOOOOOOOOOOOOOOO","OXOOOOXOOOOOOOOOOOXX","OOOOOOOOXOOOOOOOOOOX","OOXOOOOOOOOOOOOOOOXO","OOOOOXOOOOXOOOOOXOOX","XOOOXOOOOOXOXOXOXOXO","OOOOXOOXOOOOOXOOXOOO","XOOOXXXOXOOOOXXOXOOO","OOOOOXXXXOOOOXOOXOOO","XOOOOXOOOOOOXXOOXOOX","OOOOOOOOOOXOOXOOOXOX","OOOOXOXOOXXOOOOOXOOO","XXOOOOOXOOOOOOOOOOOO","OXOXOOOXOXOOOXOXOXOO","OOXOOOOOOOXOOOOOXOXO","XXOOOOOOOOXOXXOOOXOO","OOXOOOOOOOXOOXOXOXOO","OOOXOOOOOXXXOOXOOOXO","OOOOOOOOOOOOOOOOOOOO","XOOOOXOOOXXOOXOXOXOO"};

	vector<vector<char>> board;
	for (int i = 0; i < 20; i++) {
		cout << lines[i] << endl;
		board.push_back(vector<char>(lines[i].begin(), lines[i].begin() + 20));
	}

	clock_t tStart = clock();

	solve2(board);

	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

	return 0;
}