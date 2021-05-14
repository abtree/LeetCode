#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//3 无重复字符的最长子串
class CSubString {
	/*
	给定一个字符串，请你找出其中不含有重复字符的最长子串的长度。

	示例 1:

	输入: "abcabcbb"
	输出: 3
	解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
	*/
public:
	int lengthOfLongestSubstring(string s) {
		/*
		该题的解题思路基本上都会采用滑动窗口
		在这里需要采用unordered_map来存储string中遇到的每个字符的最后位置
		（由于c++的char只包含128个字符 所有用数组也可以实现，不过map的扩展性会更好）
		用map记录每个字符最后出现的位置的好处是 左指针p能清楚的知道下一步该跳到哪里，而
		不用一步一步的走
		*/
		if (s.empty())
			return 0;	//空字符串特殊处理

		unordered_map<char, int> c_pos;
		int start = 1, max = 0, cur = 0, i = 0;
		for (; s[i] != '\0'; ++i) {
			auto& pos = c_pos[s[i]];
			if (pos >= start) {
				//找到重复的字符
				//记录当前子串的长度
				//并将start指针 移到重复字符的下个字符
				cur = i - start + 1;
				if (cur > max)
					max = cur;
				start = c_pos[s[i]] + 1;
			}
			pos = i + 1;
		}
		cur = i - start + 1;
		return cur > max ? cur : max;
	}

	int lengthOfLongestSubstring2(string s) {
		/*
		原理同上
		用unordered_set实现
		需要删除不再需要的项
		好处是更节约空间
		*/
		unordered_set<char> c_substr;
		int i = 0, j = 0, cur = 0, max = 0;
		for (; s[j] != '\0'; ++j) {
			if (c_substr.count(s[j]) > 0) {
				//发现重复的字符
				cur = j - i;
				if (cur > max)
					max = cur;
				//删除多余的项  直到重复项
				while (s[i] != s[j]) {
					c_substr.erase(s[i]);
					++i;
				}
				c_substr.erase(s[i]);
				++i;
			}
			c_substr.insert(s[j]);
		}
		cur = j - i;
		return cur > max ? cur : max;
	}
};

int main(int argc, char const *argv[])
{
	int typ = 1;
	string str = "abcabcbb";
	CSubString css;
	if (typ == 1) {
		cout << css.lengthOfLongestSubstring(str) << endl;
	}
	else {
		cout << css.lengthOfLongestSubstring2(str) << endl;
	}
	
	str = "pwwkew";
	if (typ == 1) {
		cout << css.lengthOfLongestSubstring(str) << endl;
	}
	else {
		cout << css.lengthOfLongestSubstring2(str) << endl;
	}
	return 0;
}
