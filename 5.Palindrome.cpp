#include <iostream>
#include <string>
#include <vector>

using namespace std;

//5 最长回文子串
class CPalindrome {
	/*
		给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
		示例 1：

		输入: "babad"
		输出: "bab"
		注意: "aba" 也是一个有效答案。
		示例 2：

		输入: "cbbd"
		输出: "bb"
	*/
public:
	string longestPalindrome(string s) {
		/*
		假设 s = a b a b a
				 0 1 2 3 4
		我们可以构建这样一张表 length(子串长度) pos(字符下标)
			length 0 1 2 3 4	/子串最长为4 所以此处最大为4/
			pos	0  t f t f t	/子串长度为1时 单个字符 都是回文/
				1  t f t f -	/子串长度为2时 两个字符相等 就是回文/
				2  t f t - -	/子串长度大于2时 s[i] == s[j] && state[i + 1, j - 1] == true 就是回文 /
				3  t f - - -
				4  t - - - -
		*/
		if (s.empty())
			return "";
		int n = s.size();
		//用vector创建二维数组
		vector<vector<bool>> state(n, vector<bool>(n));
		int j = 0;
		int max = 0, start = 0;
		for (int len = 0; len < n; ++len) {
			for (int pos = 0; pos + len < n; ++pos) {
				if (len == 0) {
					state[pos][pos] = true;
					continue;
				}
				j = pos + len;
				if (len == 1) {
					if (s[pos] == s[j]) {
						state[pos][j] = true;
						if (max < len) {
							start = pos;
							max = len;
						}
					}
					else {
						state[pos][j] = false;
					}
					continue;
				}
				if (s[pos] == s[j] && state[pos + 1][j - 1]) {
					state[pos][j] = true;
					if (max < len) {
						start = pos;
						max = len;
					}
				}
				else {
					state[pos][j] = false;
				}
			}
		}
		return s.substr(start, max + 1);
	}

	string longestPalindrome2(string s) {
		/*
			中心扩散法
			s = ababa
			以s中每个元素为中心，查找其最大回文(但要注意两个字符作为中心的情况, 如baab)
		*/
		if (s.empty())
			return "";
		int n = s.size();
		int start = 0, max = 1;
		int i = 0, j = 0;
		for (int pos = 0; pos < n; ++pos) {
			i = pos - 1;
			j = pos + 1;
			//先判断单中心的情况
			for (; i >= 0 && j < n; --i, ++j) {
				if (s[i] != s[j])
					break;
			}
			if (max < j - i - 1) {
				start = i + 1;
				max = j - i - 1;
			}
			//再判断双中心的情况
			j = pos + 1;
			if (j >= n)
				continue;
			if (s[pos] != s[j])
				continue;	//双中心不成立
			i = pos - 1;
			++j;
			for (; i >= 0 && j < n; --i, ++j) {
				if (s[i] != s[j])
					break;
			}
			if (max < j - i - 1) {
				start = i + 1;
				max = j - i - 1;
			}
		}
		return s.substr(start, max);
	}
};

int main(int argc, char const* argv[])
{
	string str1 = "ababa";
	string str2 = "baab";
	string str3 = "caab";
	string str4 = "abaaba";
	string str5 = "abaacba";
	CPalindrome handle;
	cout << handle.longestPalindrome(str1).c_str() << " -> ababa" << endl;
	cout << handle.longestPalindrome(str2).c_str() << " -> baab" << endl;
	cout << handle.longestPalindrome(str3).c_str() << " -> aa" << endl;
	cout << handle.longestPalindrome(str4).c_str() << " -> abaaba" << endl;
	cout << handle.longestPalindrome(str5).c_str() << " -> aba" << endl;
	return 0;
}
