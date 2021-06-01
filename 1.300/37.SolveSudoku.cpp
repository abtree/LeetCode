#include <vector>
#include <set>
#include <iostream>
#include <stack>
#include <array>
using namespace std;

//37. 解数独
class SolveSudoku {
	/*
	编写一个程序，通过填充空格来解决数独问题。
	一个数独的解法需遵循如下规则：

	数字 1-9 在每一行只能出现一次。
	数字 1-9 在每一列只能出现一次。
	数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
	空白格用 '.' 表示。

	提示：
	给定的数独序列只包含数字 1-9 和字符 '.' 。
	你可以假设给定的数独只有唯一解。
	给定数独永远是 9x9 形式的。
	*/
private:
	struct SudokuMaybe
	{
		vector<vector<char>> lastBoard;
		int i{};
		int j{};
		set<char> poss;
	};
public:
	void solveSudoku(vector<vector<char>>& board) {
		//先直接解一次
		if(correctSet(board)){
			//cout << " correct" << endl;
			return;
		}
		//解不出来就猜
		while (true) {
			if (mError) {
				mError = false;
				if (!back(board))
					return;
				if (correctSet(board)) {
					return;
				}
			}
			else {
				if(!guess(board))
					continue;
				if (correctSet(board)) {
					return;
				}
			}
		}
	}
private:
	bool guess(vector<vector<char>>& board) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if(board[i][j] != '.')
					continue;
				SudokuMaybe mb;
				mb.lastBoard = board;
				mb.i = i;
				mb.j = j;
				mb.poss = set<char>{ '1','2','3','4' ,'5' ,'6' ,'7' ,'8' ,'9' };
				auto it = mb.poss.begin();
				while (it != mb.poss.end()) {
					if (IsColValid(i, j, *it, board) == false) {
						it = mb.poss.erase(it);
						continue;
					}
					if (IsRowValid(i, j, *it, board) == false) {
						it = mb.poss.erase(it);
						continue;
					}
					if (IsBoxValid(i, j, *it, board) == false) {
						it = mb.poss.erase(it);
						continue;
					}
					++it;
				}
				if (mb.poss.empty()) {
					mError = true;
					return false;
				}
				//推测
				board[i][j] = *mb.poss.begin();
				mb.poss.erase(mb.poss.begin());
				mMaybes.push(mb);
				return true;
			}
		}
		return true;
	}
	bool back(vector<vector<char>>& board) {
		while (!mMaybes.empty()) {
			SudokuMaybe& mb = mMaybes.top();
			if (mb.poss.empty()) {
				mMaybes.pop();
				continue;	//需要继续向上还原
			}
			board = mb.lastBoard;	//还原
			board[mb.i][mb.j] = *mb.poss.begin();
			mb.poss.erase(mb.poss.begin());
			return true;
		}
		return false;
	}
private:
	//下面是推测的结果
	stack<SudokuMaybe> mMaybes;
	bool mError{};	//是否冲突
private:
	//下面是确定的计算
	bool correctSet(vector<vector<char>>& board) {
		init(board);
		for (int c = 8; c > 0; --c) {
			if (ColCheck(c, board)) {
				c = 9;
				if (IsEnd())
					return true;
				else
					continue;
			}
			else if (mError) {
				return false;
			}
			if (RowCheck(c, board)) {
				c = 9;
				if (IsEnd())
					return true;
				else
					continue;
			}
			else if (mError) {
				return false;
			}
			if (BoxCheck(c, board)) {
				c = 9;
				if (IsEnd())
					return true;
				else
					continue;
			}
			else if (mError) {
				return false;
			}
		}
		return false;
	}
	bool ColCheck(int c, vector<vector<char>>& board) {
		for (int k = 0; k < 9; ++k) {
			if(mColsCount[k] != c)
				continue;
			//先找出空位 和 为使用的字符
			int i = k;
			set<char> cs{ '1','2','3','4' ,'5' ,'6' ,'7' ,'8' ,'9' };
			vector<int> poss;
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.') {
					poss.push_back(j);
					continue;
				}
				cs.erase(board[i][j]);
			}
			//根据剩余的符号 找 对应的格子
			if (cs.size() == 1) {
				SetChar(i, poss[0], *cs.begin(), board);
				return true;
			}

			for (int m = 0; m < poss.size(); ++m) {
				if (cs.empty())
					return true;
				if (poss[m] == -1)
					continue;
				set<char> tmp = cs;
				auto it = tmp.begin();
				while (it != tmp.end()) {
					if (IsRowValid(i, poss[m], *it, board) == false) {
						it = tmp.erase(it);
						continue;
					}
					if (IsBoxValid(i, poss[m], *it, board) == false) {
						it = tmp.erase(it);
						continue;
					}
					++it;
				}
				if (tmp.empty()) {
					//发生冲突
					mError = true;
					return false;
				}
				if (tmp.size() == 1) {
					SetChar(i, poss[m], *tmp.begin(), board);
					cs.erase(*tmp.begin());
					poss[m] = -1;
					m = 0;
				}
			}
		}
		return false;
	}
	bool RowCheck(int c, vector<vector<char>>& board) {
		for (int k = 0; k < 9; ++k) {
			if (mRowsCount[k] != c)
				continue;
			//先找出空位 和 为使用的字符
			int j = k;
			set<char> cs{ '1','2','3','4' ,'5' ,'6' ,'7' ,'8' ,'9' };
			vector<int> poss;
			for (int i = 0; i < 9; ++i) {
				if (board[i][j] == '.') {
					poss.push_back(i);
					continue;
				}
				cs.erase(board[i][j]);
			}
			//根据剩余的符号 找 对应的格子
			if (cs.size() == 1) {
				SetChar(poss[0], j, *cs.begin(), board);
				return true;
			}

			for (int m = 0; m < poss.size(); ++m) {
				if (cs.empty())
					return true;
				if (poss[m] == -1)
					continue;
				set<char> tmp = cs;
				auto it = tmp.begin();
				while (it != tmp.end()) {	//去除不合法的值
					if (IsColValid(poss[m], j, *it, board) == false) {
						it = tmp.erase(it);
						continue;
					}
					if (IsBoxValid(poss[m], j, *it, board) == false) {
						it = tmp.erase(it);
						continue;
					}
					++it;
				}
				if (tmp.empty()) {
					//发生冲突
					mError = true;
					return false;
				}
				if (tmp.size() == 1) {	//如果只剩唯一合法值
					SetChar(poss[m], j, *tmp.begin(), board);
					cs.erase(*tmp.begin());
					poss[m] = -1;
					m = -1;
				}
			}
		}
		return false;
	}
	bool BoxCheck(int c, vector<vector<char>>& board) {
		for (int k = 0; k < 9; ++k) {
			if (mBoxsCount[k] != c)
				continue;
			//先找出空位 和 为使用的字符
			set<char> cs{ '1','2','3','4' ,'5' ,'6' ,'7' ,'8' ,'9' };
			vector<pair<int, int>> poss;
			int p1 = k / 3;
			int p2 = p1 + 3;
			int q1 = k % 3 * 3;
			int q2 = q1 + 3;
			while (p1 < p2) {
				while (q1 < q2) {
					if (board[p1][q1] == '.') {
						poss.push_back(make_pair(p1, q1));
					}
					else {
						cs.erase(board[p1][q1]);
					}
					++q1;
				}
				++p1;
			}
			//根据剩余的符号 找 对应的格子
			if (cs.size() == 1) {
				SetChar(poss[0].first, poss[0].second, *cs.begin(), board);
				return true;
			}

			for (int m = 0; m < poss.size(); ++m) {
				if (cs.empty())
					return true;
				if (poss[m].first == -1)
					continue;
				set<char> tmp = cs;
				auto it = tmp.begin();
				while (it != tmp.end()) {	//去除不合法的值
					if (IsColValid(poss[m].first, poss[m].second, *it, board) == false) {
						it = tmp.erase(it);
						continue;
					}
					if (IsRowValid(poss[m].first, poss[m].second, *it, board) == false) {
						it = tmp.erase(it);
						continue;
					}
					++it;
				}
				if (tmp.empty()) {
					//发生冲突
					mError = true;
					return false;
				}
				if (tmp.size() == 1) {	//如果只剩唯一合法值
					SetChar(poss[m].first, poss[m].second, *tmp.begin(), board);
					cs.erase(*tmp.begin());
					poss[m] = make_pair(-1, -1);
					m = 0;
				}
			}
		}
		return false;
	}
	//是否已经完成数独
	bool IsEnd() {
		for (int i = 0; i < 9; ++i) {
			if (mColsCount[i] < 9)
				return false;
		}
		//cout << "solve end" << endl;
		return true;
	}
	//初始化个数
	void init(vector<vector<char>>& board) {
		mColsCount.fill(0);
		mRowsCount.fill(0);
		mBoxsCount.fill(0);
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.') {
					continue;
				}
				mColsCount[i]+=1;
				mRowsCount[j]+=1;
				mBoxsCount[i / 3 * 3 + j / 3]+=1;
			}
		}
	}
	//该位置插入的该值在列上是否合法
	bool IsRowValid(int i, int j, char value, vector<vector<char>>& board) {
		for (int k = 0; k < 9; ++k) {
			if (k == i)
				continue;
			if (board[k][j] == value)
				return false;
		}
		return true;
	}
	//该位置插入的该值在行上是否合法
	bool IsColValid(int i, int j, char value, vector<vector<char>>& board) {
		for (int k = 0; k < 9; ++k) {
			if (k == j)
				continue;
			if (board[i][k] == value)
				return false;
		}
		return true;
	}
	//该位置插入的该值在区域上是否合法
	bool IsBoxValid(int i, int j, char value, vector<vector<char>>& board) {
		int p1 = i / 3 * 3;
		int p2 = p1 + 3;
		int q1 = j / 3 * 3;
		int q2 = q1 + 3;
		while (p1 < p2) {
			for (int m = q1; m < q2; ++m) {
				if (p1 == i && m == j)
					continue;
				if (board[p1][m] == value)
					return false;
			}
			++p1;
		}
		return true;
	}
	void SetChar(int i, int j, char c, vector<vector<char>>& board) {
		//cout << "pos [" << i << "," << j << "] =>" << c << endl;
		board[i][j] = c;
		mColsCount[i] += 1;
		mRowsCount[j] += 1;
		mBoxsCount[i / 3 * 3 + j / 3] += 1;
	}
private:
	array<int, 9> mColsCount{};	//记录每一行的有效个数
	array<int, 9> mRowsCount{};	//记录每一列的有效个数
	array<int, 9> mBoxsCount{};	//记录每一格的有效个数
};

int main(int argc, char const *argv[])
{
	vector<vector<char>> sudoku{
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
	};
	SolveSudoku cls;
	cls.solveSudoku(sudoku);
	for(auto &it : sudoku){
		for(auto c : it){
			cout << c << "\t";
		}
		cout << endl << endl;
	}
	
	vector<vector<char>> sudoku1{
		{'.','.','9','7','4','8','.','.','.'},
		{'7','.','.','.','.','.','.','.','.'},
		{'.','2','.','1','.','9','.','.','.'},
		{'.','.','7','.','.','.','2','4','.'},
		{'.','6','4','.','1','.','5','9','.'},
		{'.','9','8','.','.','.','3','.','.'},
		{'.','.','.','8','.','3','.','2','.'},
		{'.','.','.','.','.','.','.','.','6'},
		{'.','.','.','2','7','5','9','.','.'}
	};
	cls.solveSudoku(sudoku1);
	for(auto &it : sudoku1){
		for(auto c : it){
			cout << c << "\t";
		}
		cout << endl << endl;
	}
	return 0;
}
