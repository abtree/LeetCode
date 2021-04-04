#pragma once

//10 正则表达式匹配
class CRegexSimple {
	/*
	给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
	'.' 匹配任意单个字符
	'*' 匹配零个或多个前面的那一个元素
	所谓匹配，是要涵盖整个字符串s的，而不是部分字符串。

	说明:
	s 可能为空，且只包含从 a-z 的小写字母。
	p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。

	示例 1:
	输入:
	s = "aa"
	p = "a"
	输出: false
	解释: "a" 无法匹配 "aa" 整个字符串。

	示例 2:
	输入:
	s = "aa"
	p = "a*"
	输出: true
	解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次

	示例 3:
	输入:
	s = "ab"
	p = ".*"
	输出: true
	解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）

	示例 4:
	输入:
	s = "aab"
	p = "c*a*b"
	输出: true
	解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。

	示例 5:
	输入:
	s = "mississippi"
	p = "mis*is*p*."
	输出: false
	*/
public:
	bool isMatch(string s, string p) {
		/*
			官方解法
		*/
		int m = s.size();
		int n = p.size();

		if (n > 0 && p[0] == '*')
			return false;	//p以*开头一定是错误的

		//i表示s的长度 j表示p的长度 (这里计算下标的时候 需要长度减1)
		auto matches = [&](int i, int j) {
			if (i == 0) {		//这里表示如果s是空字符串 p只有是空字符串或".*"才匹配 
				return false;
			}
			if (p[j - 1] == '.') {	//如果是点号 可以匹配任意字母
				return true;
			}
			return s[i - 1] == p[j - 1];	//只需要最后一个字母相等
		};

		vector<vector<bool>> f(m + 1, vector<bool>(n + 1));	//这里存储当s取前0.1.2...s.size()时 能匹配多长的p 0.1.2...p.size()
		f[0][0] = true;	//两个空字符串一定匹配
		for (int i = 0; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (p[j - 1] == '*') {	//如果当前字符为*号 
					f[i][j] = f[i][j - 2];	//如果丢弃*号和*号前面的字符也匹配 则加上也匹配(这里忘了考虑 p以*号开头的情况)
					if (!f[i][j] && matches(i, j - 1)) {	//如果丢掉*号 两个字符串最后一个字母相等
						f[i][j] = f[i - 1][j];	//只需要s丢掉最后一个字符也匹配
					}
				}
				else {
					if (matches(i, j)) {	//因为最后一个字符相等
						f[i][j] = f[i - 1][j - 1];	//所以只需要s和p都丢掉最后一个字符也匹配
					}
				}
			}
		}
		return f[m][n];
	}

	bool isMatch2(string s, string p) {
		/*
		官方解法 改版
		*/
		int m = s.size();
		int n = p.size();

		if (n > 0 && p[0] == '*')
			return false;	//p以*开头一定是错误的

		vector<vector<bool>> f(m + 1, vector<bool>(n + 1));	//这里存储当s取前0.1.2...s.size()时 能匹配多长的p 0.1.2...p.size()
		f[0][0] = true;	//两个空字符串一定匹配
		for (int i = 0; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (p[j - 1] == '*') {	//如果当前字符为*号 
					f[i][j] = f[i][j - 2];	//如果丢弃*号和*号前面的字符也匹配 则加上也匹配(这里忘了考虑 p以*号开头的情况)
					if (!f[i][j] && (i != 0 && (p[j-2] == '.' || s[i - 1] == p[j - 2]))) {	//如果丢掉*号 两个字符串最后一个字母相等
						f[i][j] = f[i - 1][j];	//只需要s丢掉最后一个字符也匹配
					}
				}
				else {
					if (i != 0 && (p[j - 1] == '.' || s[i - 1] == p[j - 1])) {	//因为最后一个字符相等
						f[i][j] = f[i - 1][j - 1];	//所以只需要s和p都丢掉最后一个字符也匹配
					}
				}
			}
		}
		return f[m][n];
	}
public:
	static void Test() {
		CRegexSimple crs;
		cout << boolalpha << crs.isMatch2("abcde", "ab.*cde") << " true" << endl;
		cout << boolalpha << crs.isMatch2("", ".*") << " true" << endl;
		cout << boolalpha << crs.isMatch2("aa", "a*") << " true" << endl;
		cout << boolalpha << crs.isMatch2("ab", ".*") << " true" << endl;
	}
};