
#include <iostream>
#include <string>
#include <vector>

using namespace std;


void helper(vector<vector<string>> &res, vector<string> &sol, int r, int n) {
	if (r == n)
		res.push_back(sol);

	// create a line
	string line(n, '.');
	string line2(n, '.');
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < r; j++) {
			if (sol[j][i] == 'Q') {
				line[i] = 'Q';
				break;
			}
			else if ((i - r + j >= 0 && sol[j][i - r + j] == 'Q') ||
				(i + r - j) < n && sol[j][i + r - j] == 'Q') {
				line[i] = 'N';
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (line[i] == '.') {
			line2[i] = 'Q';
			sol.push_back(line2);
			helper(res, sol, r + 1, n);
			sol.pop_back();
			line2[i] = '.';
		}
	}
}


void printSolutions(vector<vector<string>> res) {
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << endl;
		}
		cout << "--------------------------" << endl;
	}
}



// very fast solution!!!!!
class Solution {

	struct Node {

		int _pos;
		const int _num;
		const int _level;
		const Node* _prev;

		Node(int num, int level) : _pos(0),
			_num(num),
			_level(level),
			_prev(NULL) { }

	};

public:

	vector<vector<string> > solveNQueens(int n) {

		vector<vector<string> > results;

		Node node(n, 0);
		_backTrace(results, &node);

		return results;
	}

private:

	void _backTrace(vector<vector<string> >& results, Node *node) {

		for (node->_pos = 0;
			node->_pos < node->_num;
			node->_pos++) {

			// Reject if invalid:
			if (node->_prev) {

				int diag_left = node->_pos;
				int diag_right = node->_pos;

				const Node *ancestor = node->_prev;
				while (ancestor) {

					// No queens upper.
					if (ancestor->_pos == node->_pos) break;

					// No queens in diagonal upper-left.
					--diag_left;
					if (ancestor->_pos == diag_left) break;

					// No queens in diagonal upper-right.
					++diag_right;
					if (ancestor->_pos == diag_right) break;

					ancestor = ancestor->_prev;
				}

				if (ancestor) continue; // Rejected!
			}

			// The solution up to the current level is valid, lets pass to the next.
			int level = node->_level + 1;

			// Accept if is at the last level:
			if (level == node->_num) {

				vector<string> result;
				const Node *out_node = node;
				while (out_node) {

					_outputRow(result,
						out_node->_pos,
						out_node->_num);

					out_node = out_node->_prev;
				}
				reverse(result.begin(), result.end());
				results.push_back(result); // Result collected.
			}

			// Next recursion to a lower level:
			else {

				Node next_node(node->_num, level);
				next_node._prev = node; // Builds a liked list on the stack ;-)
				_backTrace(results, &next_node);
			}

		} // for (pos: 0..num)
	}

	void _outputRow(vector<string>& result,
		int pos,
		int num) {

		string row;
		for (int i = 0; i < num; ++i) {

			if (i == pos) row += 'Q';
			else row += '.';
		}

		result.push_back(row);
	}

};

vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> res;
	if (n <= 0) return res;
	vector<string> sol;
	helper(res, sol, 0, n);
	return res;
}

int main(void) {

	vector<vector<string>> res = solveNQueens(1);

	printSolutions(res);

	return 0;
}