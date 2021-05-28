#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

	//manacher算法
	string longestPalindrome3(string s) {
		int start = 0, end = -1;	//这里记录找到的最长回文串
		/*	为了将偶数型回文串转化为基数型 这里插入'#'
			如 aa -> #a#a# ; aba -> #a#b#a#
		*/
		string t = s;
		s = "#";
		for (char c : t) {
			s += c;
			s += '#';
		}
		/* 这里声明一个容器记录已经查找过的点的臂长
		   如：baaabaaa 位置为 0 1 2 3 4 5 6 7
		   此时 中心点 j = 4; 我们要判断 位置 i = 6 的点为中心能形成的最长回文串
		   我们先找到 i 关于 j的对称点 i1 = j - (i - j) = 2j - i = 2; 此时我们已经知道 i1 = 2所形成的最大臂长为2
		   我们可以知道j向左延伸的臂长能到位置1的点(即第一个a，我们记作jleft)；而i1的臂长能延伸到位置为0的点
		   此时：我们可以知道i的臂长最小应该为 min(i1的臂长，i1-jleft) = min(2, 2 - 1);
		   而 i1-jleft = jright-i (jright为j的右臂长能延伸到的点，即位置7)
		*/
		vector<int> armLen(s.size(), 0);
		int jright = -1;	//右臂长所到的点
		int j = -1;		//相等i的中心点j(j臂长为覆盖i的范围最大的点,这样可以保证i跳过匹配的臂长最大)
		for (int i = 0; i < s.size(); ++i) {
			int curArmLen;
			if (jright >= i) {	//右臂长覆盖了i点 说明i有可能可以跳过部分匹配
				int iSym = j * 2 - i;	//找到i的对称点
				int minArmLen = min(armLen[iSym], jright - i);	//这里请看上面注释
				curArmLen = armlens(s, i - minArmLen, i + minArmLen);
			}else{
				curArmLen = armlens(s, i, i);	//以i为中心完整匹配
			}
			armLen[i] = curArmLen;	//记录该点的臂长
			if(i+curArmLen>jright){	//这里计算中心点j是否需要移动，以保证j点臂长始终是覆盖i点最大范围的点
				j = i;
				jright = i + curArmLen;
			}
			if(curArmLen*2+1 > end-start){	//这里是保存查找到的最大回文子串的开始结束位置
				start = i - curArmLen;
				end = i + curArmLen;
			}
		}
		//将最大回文串取出来， 并去掉插入的'#'
		t = "";
		while(start <= end){
			if(s[start] != '#')
				t += s[start];
			++start;
		}
		return t;
	}
private:
	int armlens(string& s, int i, int j) {
		while (i >= 0 && j < s.size() && s[i] == s[j]) {	//中心扩散发
			--i;
			++j;
		}
		return (j - i - 2) / 2;	//这里是因为插入了'#'
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
	cout << handle.longestPalindrome3(str1).c_str() << " -> ababa" << endl;
	cout << handle.longestPalindrome3(str2).c_str() << " -> baab" << endl;
	cout << handle.longestPalindrome3(str3).c_str() << " -> aa" << endl;
	cout << handle.longestPalindrome3(str4).c_str() << " -> abaaba" << endl;
	cout << handle.longestPalindrome3(str5).c_str() << " -> aba" << endl;
	return 0;
}
