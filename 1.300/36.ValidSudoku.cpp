#include <iostream>
#include <array>
#include <unordered_set>
#include <vector>

using namespace std;

//36 有效的数独
class ValidSudoku {
	/*
	判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。
	1,数字 1-9 在每一行只能出现一次。
	2,数字 1-9 在每一列只能出现一次。
	3,数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。

	数独部分空格内已填入了数字，空白格用 '.' 表示。
	示例 1:
	输入:
	[
	["5","3",".",".","7",".",".",".","."],
	["6",".",".","1","9","5",".",".","."],
	[".","9","8",".",".",".",".","6","."],
	["8",".",".",".","6",".",".",".","3"],
	["4",".",".","8",".","3",".",".","1"],
	["7",".",".",".","2",".",".",".","6"],
	[".","6",".",".",".",".","2","8","."],
	[".",".",".","4","1","9",".",".","5"],
	[".",".",".",".","8",".",".","7","9"]
	]
	输出: true

	示例 2:
	输入:
	[
	  ["8","3",".",".","7",".",".",".","."],
	  ["6",".",".","1","9","5",".",".","."],
	  [".","9","8",".",".",".",".","6","."],
	  ["8",".",".",".","6",".",".",".","3"],
	  ["4",".",".","8",".","3",".",".","1"],
	  ["7",".",".",".","2",".",".",".","6"],
	  [".","6",".",".",".",".","2","8","."],
	  [".",".",".","4","1","9",".",".","5"],
	  [".",".",".",".","8",".",".","7","9"]
	]
	输出: false
	解释: 除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。
		  但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。
	*/
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		unordered_set<char> column{};
		unordered_set<char> rows[9];
		unordered_set<char> boxs[3];
		resetBox(rows, 9);
		for (int i = 0; i < 9; ++i) {
			if (i % 3 == 0) {
				//清空操作
				resetBox(boxs, 3);
			}
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.')
					continue;
				//先判断行重复
				if (column.count(board[i][j]) > 0)
					return false;
				else
					column.insert(board[i][j]);
				//再判断列重复
				if (rows[j].count(board[i][j]) > 0)
					return false;
				else
					rows[j].insert(board[i][j]);
				//再判断box重复
				if (boxs[j / 3].count(board[i][j]) > 0)
					return false;
				else
					boxs[j / 3].insert(board[i][j]);
			}
			column.clear();	//一行后清空
		}
		return true;
	}

	bool isValidSudoku2(vector<vector<char>>& board) {
		std::array<bool, 9> column{};
		array<array<bool, 9>, 9> rows{};
		array<array<bool, 9>, 3> boxs{};
		for (int i = 0; i < 9; ++i) {
			if (i % 3 == 0) {
				boxs.fill(array<bool, 9>{});
			}
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.')
					continue;
				int pos = board[i][j] - '1';
				//先判断行重复
				if (column[pos])
					return false;
				else
					column[pos] = true;
				//再判断列重复
				if (rows[j][pos])
					return false;
				else
					rows[j][pos] = true;
				//再判断box重复
				if (boxs[j / 3][pos])
					return false;
				else
					boxs[j / 3][pos] = true;
			}
			column.fill(false);
		}
		return true;
	}

	bool isValidSudoku3(vector<vector<char>>& board) {
		std::array<bool, 9> column{};
		array<array<bool, 9>, 9> rows{};
		array<array<bool, 9>, 9> boxs{};
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.')
					continue;
				int pos = board[i][j] - '1';
				//先判断行重复
				if (column[pos])
					return false;
				else
					column[pos] = true;
				//再判断列重复
				if (rows[j][pos])
					return false;
				else
					rows[j][pos] = true;
				//再判断box重复
				if (boxs[i / 3 * 3 + j / 3][pos])
					return false;
				else
					boxs[i / 3 * 3 + j / 3][pos] = true;
			}
			column.fill(false);
		}
		return true;
	}
private:
	void resetBox(unordered_set<char> data[], int size) {
		for (int i = 0; i < size; ++i) {
			data[i] = unordered_set<char>{};
		}
	}
};

int main(int argc, char const* argv[])
{
	vector<vector<char>> sudoku{
		{'5','3','.','.','7','.', '.', '.', '.'},
		{'6','.','.', '1','9','5','.','.','.' },
		{ '.', '9', '8','.','.','.','.','6','.' },
		{ '8','.','.','.','6','.','.','.','3' },
		{ '4', '.', '.', '8', '.', '3', '.','.', '1' },
		{ '7','.','.','.','2','.','.','.','6' },
		{ '.', '6','.','.','.','.','2','8','.' },
		{ '.', '.', '.', '4','1','9','.','.','5' },
		{ '.', '.', '.', '.', '8','.','.','7','9' }
	};
	ValidSudoku cls;
	cout << std::boolalpha << cls.isValidSudoku2(sudoku) << " -> true" << endl;
	sudoku[0][0] = '8';
	cout << std::boolalpha << cls.isValidSudoku2(sudoku) << " -> false" << endl;
	return 0;
}
