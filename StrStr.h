#pragma once

//28. 实现 strStr()
class CStrStr {
	/*
	实现 strStr() 函数。
	给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

	示例 1:
	输入: haystack = "hello", needle = "ll"
	输出: 2

	示例 2:
	输入: haystack = "aaaaa", needle = "bba"
	输出: -1
	*/
public:
	int strStr(string haystack, string needle) {
		//双指针法
		if (needle.empty())
			return 0;
		int L = haystack.size();
		int n = needle.size();
		if (n > L)
			return -1;
		for (int i = 0; i <= L - n; ++i) {
			if(haystack[i] != needle[0])
				continue;
			if (strMatch(haystack, needle, i))
				return i;
		}
		return -1;
	}
private:
	bool strMatch(string& source, string& target, int pos) {
		for (char c : target) {
			if (source[pos] != c)
				return false;
			++pos;
		}
		return true;
	}
public:
	static void Test() {
		CStrStr cls;
		cout << cls.strStr("hello", "ll") << " --> 2" << endl;
		cout << cls.strStr("aaaaa", "bba") << " --> -1" << endl;
	}
};