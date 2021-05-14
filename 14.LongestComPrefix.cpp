#include <iostream>
#include <vector>
#include <string>

using namespace std;

//14 最长公共前缀
class CLongestComPrefix {
	/*
	编写一个函数来查找字符串数组中的最长公共前缀。
	如果不存在公共前缀，返回空字符串 ""。

	示例 1:
	输入: ["flower","flow","flight"]
	输出: "fl"

	示例 2:
	输入: ["dog","racecar","car"]
	输出: ""
	解释: 输入不存在公共前缀。
	*/
public:
	string longestCommonPrefix(vector<string>& strs) {
		//遍历逐个比较法
		if (strs.empty())
			return "";
		if (strs.size() < 2)
			return strs[0];
		int p = strs[0].size();
		for (int i = 1; i < strs.size(); ++i) {
			int m = 0, n = 0;
			while (m < p) {
				if (strs[i][n] != strs[0][m]) {
					p = m;
					break;
				}
				else {
					++m;
					++n;
				}
				if (n >= strs[i].size()) {
					p = m;
					break;
				}
			}
			if (p <= 0)
				break;
		}
		return strs[0].substr(0, p);
	}

	string longestCommonPrefix2(vector<string>& strs) {
		//逐位比较法
		if (strs.empty())
			return "";
		if (strs.size() < 2)
			return strs[0];

		int pos = 0;
		while (true) {
			for (auto& str : strs) {
				if (pos >= str.size())
					return strs[0].substr(0, pos);
				if (str[pos] != strs[0][pos])
					return strs[0].substr(0, pos);
			}
			++pos;
		}
		return strs[0].substr(0, pos);
	}
};

int main(int argc, char const* argv[])
{
	CLongestComPrefix cls;
	cout << cls.longestCommonPrefix2(vector<string>{"aa", "a"}).c_str() << " -> a" << endl;
	cout << cls.longestCommonPrefix2(vector<string>{"flower", "flow", "flight"}).c_str() << " -> fl" << endl;
	cout << cls.longestCommonPrefix2(vector<string>{"dog", "racecar", "car"}).c_str() << " -> " << endl;
	return 0;
}
