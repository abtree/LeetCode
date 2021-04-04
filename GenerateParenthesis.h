#pragma once

//22 括号生成
class CGenerateParenthesis {
	/*
	数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

	 示例：
	 输入：n = 3
	 输出：[
	 "((()))",
	 "(()())",
	 "(())()",
	 "()(())",
	 "()()()"
	 ]
	*/
public:
	vector<string> ret;
	vector<string> generateParenthesis(int n) {
		if (n < 1)
			return ret;
		generate(2 * n - 1, 1, "(");
		return ret;
	}

	void generate(int n, int p, string s) {
		if (n <= 0) {
			if (p == 0)
				ret.push_back(s);
			return;
		}
		if (p < 0) {
			return;	//后面不可能匹配了
		}
		if (p > n) {
			return;	//')'不够用了 
		}
		generate(n - 1, p + 1, s + "(");
		generate(n - 1, p - 1, s + ")");
	}
public:
	vector<string> generateParenthesis2(int n) {
		vector<string> result;
		generate2("", result, n, n);
		return result;
	}

	//left  -- 还可以放入左括号的数量
	//right -- 还可以放入右括号的数量
	void generate2(string item, vector<string> &result, int left, int right) {
		if (left == 0 && right == 0) {
			result.push_back(item);
			return;
		}

		if (left > 0) {
			generate2(item + "(", result, left - 1, right);
		}
		if (right > 0 && right > left) {
			generate2(item + ")", result, left, right - 1);
		}
	}
public:
	static void Test() {
		CGenerateParenthesis cls;
		auto ret = cls.generateParenthesis(3);
		cout << "[" << endl;
		for (auto &it : ret) {
			cout << it.c_str() << endl;
		}
		cout << "]" << endl;
	}
};