#include <iostream>
#include <string>

using namespace std;

//44. 通配符匹配
class WildcardMatch {
	/*
	给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
	'?' 可以匹配任何单个字符。
	'*' 可以匹配任意字符串（包括空字符串）。
	两个字符串完全匹配才算匹配成功。

	说明:
	s 可能为空，且只包含从 a-z 的小写字母。
	p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。

	输入:
	s = "aa"
	p = "a"
	输出: false
	解释: "a" 无法匹配 "aa" 整个字符串。

	输入:
	s = "aa"
	p = "*"
	输出: true
	解释: '*' 可以匹配任意字符串。

	输入:
	s = "cb"
	p = "?a"
	输出: false
	解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。

	输入:
	s = "adceb"
	p = "*a*b"
	输出: true
	解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".

	输入:
	s = "acdcb"
	p = "a*c?b"
	输出: false
	*/
public:
	bool isMatch(string s, string p) {
		//先去头去尾
		int size = p.size();
		int start = 0;
		int end = size - 1;
		int last = s.size() - 1;
		while (start < size) {
			if (p[start] == '*')
				break;
			if (start > last)
				return false;
			if (p[start] == '?') {
				++start;
				continue;
			}
			if (p[start] != s[start])
				return false;	//一定匹配不上
			++start;
		}
		if (start > end) {
			if (end == last)
				return true;	//已经匹配上了
			return false;
		}

		while (end > start) {
			if (p[end] == '*')
				break;
			if (p[end] == '?') {
				--end;
				--last;
				if (last < start - 1)
					return false;
				continue;
			}
			if (p[end] != s[last])
				return false;
			--end;
			--last;
		}
		//再贪心匹配
		int first = start;
		while (start < end) {
			if (p[start] == '*') {
				++start;
				continue;
			}
			if (first > last)
				return false;
			while (first <= last) {
				if (p[start] != '?' && s[first] != p[start]) {
					++first;
					continue;
				}
				if (childStart(s, p, start, end, first, last))
					break;
				++first;
			}
		}
		return true;
	}
private:
	bool childStart(string& s, string& p, int& start, int end, int& first, int last) {
		int olds = start;
		int oldf = first;
		while (start <= end && first <= last) {
			if (p[start] == '?') {
				++start;
				++first;
				continue;
			}
			if (p[start] == '*')
				return true;
			if (p[start] != s[first]) {
				start = olds;
				first = oldf;
				return false;
			}
			++start;
			++first;
		}
		if (p[start] == '*')
			return true;
		start = olds;
		first = oldf;
		return false;
	}
public:
	bool isMatch2(string s, string p) {
		//贪心算法的优化版
		int i = 0, j = 0;	//记录当前值
		int i_recall = 0, j_recall = 0;	//记录回退值
		while (s[i] != '\0') {
			if (s[i] == p[j] || p[j] == '?') {
				++i, ++j;
			}
			else if (p[j] == '*') {
				i_recall = i;
				j_recall = ++j;
			}
			else if (j_recall) {
				i = i_recall++;
				j = j_recall;
			}
			else {
				return false;
			}
		}
		while (p[j] == '*') ++j;
		return p[j] == '\0';
	}
public:
	bool isMatch3(string s, string p) {
		string textChars = s;
		string patternChars = p;
		//双指针，从右到左
		int sRight = textChars.size();
		int pRight = patternChars.size();
		//逆序比对文本串和模式串，就要判则要求s和p字符一致 遇到模式串中* 或者s、p有一个到达开头位置，则结束尾部比对
		while (sRight > 0 && pRight > 0 && patternChars[pRight - 1] != '*') {
			//两字符相同 或者 模式串中字符为? ，匹配成功，双指针左移一位
			if ((textChars[sRight - 1] == patternChars[pRight - 1]) || patternChars[pRight - 1] == '?') {
				sRight--;
				pRight--;
			}
			else { //不匹配 尾部匹配结束
				return false;
			}
		}
		//如果p到达起始位置，则只有s也到达起始位置匹配成功，否则匹配失败
		if (pRight == 0) {
			return sRight == 0;
		}

		//双指针，正序遍历文本串和模式串
		int sLeft = 0, pLeft = 0;//分别记录s、p当前比对的字符的索引
		int sRecord = -1, pRecord = -1;//遇到模式串中出现*时，正在比对的双指针s、p下标位置

									   //正序比对文本串和模式串，结束为止为尾部比对后的双指针位置
		while (sLeft < sRight && pLeft < pRight) {
			if (patternChars[pLeft] == '*') {
				pLeft++;//模式串指针右移（相当于* 匹配空字符)，如果多个连续的*则贪心的找最后一个
				sRecord = sLeft;//遇到* 记录当前s的当前位置
				pRecord = pLeft;//遇到* 记录p中*的 下一个当前位置
			}
			else if ((textChars[sLeft] == patternChars[pLeft]) || patternChars[pLeft] == '?') {
				//模式串中当前位置不是*，则判断文本串和模式串字符是否匹配（相等或者模式串中字符为？),匹配成功双指针右移
				sLeft++;
				pLeft++;
			}
			else if (sRecord != -1 && sRecord + 1 < sRight) {
				//不匹配的时候按照最近的一个*位置进行回溯
				sRecord++;//每次贪心的将*多匹配一个s
				sLeft = sRecord;//s在上次尝试的基础上，多走一个字符
				pLeft = pRecord;//p回溯到* 的下一个位置
			}
			else {
				return false;
			}
		}
		//验证p是否还有剩余字符，如果有剩余字符必须全为 *才满足
		for (int i = pLeft; i < pRight; i++) {
			if (patternChars[i] != '*') {
				return false;
			}
		}
		return true;
	}
};

int main(int argc, char const* argv[])
{
	WildcardMatch cls;
	cout << boolalpha << cls.isMatch2("b", "*a*") << " --> false" << endl;
	cout << boolalpha << cls.isMatch2("b", "*?*?") << " --> false" << endl;
	cout << boolalpha << cls.isMatch2("bba", "*a**") << " --> true" << endl;
	cout << boolalpha << cls.isMatch2("aa", "aa") << " --> true" << endl;
	cout << boolalpha << cls.isMatch2("abc", "abc?*") << " --> false" << endl;
	cout << boolalpha << cls.isMatch2("abce", "abc*?") << " --> true" << endl;
	cout << boolalpha << cls.isMatch2("abce", "abc*??") << " --> false" << endl;
	cout << boolalpha << cls.isMatch2("c", "*?*") << " --> true" << endl;
	cout << boolalpha << cls.isMatch2("", "******") << " --> true" << endl;
	cout << boolalpha << cls.isMatch2("b", "?*?") << " --> false" << endl;
	cout << boolalpha << cls.isMatch2("", "?") << " --> false" << endl;
	cout << boolalpha << cls.isMatch2("abcabczzzde", "*abc???de*") << " --> true" << endl;
	cout << boolalpha << cls.isMatch2("mississippi", "m??*ss*?i*pi") << " --> false" << endl;
	cout << boolalpha << cls.isMatch2("aa", "a") << " --> false" << endl;
	cout << boolalpha << cls.isMatch2("aa", "*") << " --> true" << endl;
	cout << boolalpha << cls.isMatch2("cb", "?a") << " --> false" << endl;
	cout << boolalpha << cls.isMatch2("adceb", "*a*b") << " --> true" << endl;
	cout << boolalpha << cls.isMatch2("acdcb", "a*c?b") << " --> false" << endl;
	cout << boolalpha << cls.isMatch2("xxxabcdefxxx", "xxx*abc*def*xxx") << " --> true" << endl;
	cout << boolalpha << cls.isMatch2("xxxabcyyydefxxx", "x?x*abc*def*x?x") << " --> true" << endl;
	cout << boolalpha << cls.isMatch2("xxxabcyyydefxxx", "x?x*a?c*d?f*x?x") << " --> true" << endl;
	return 0;
}
