#pragma once

//6 Z 字形变换
class Convert {
	/*
	将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
	比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
	L   C   I   R
	E T O E S I I G
	E   D   H   N
	之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
	请你实现这个将字符串进行指定行数变换的函数：
	string convert(string s, int numRows);
	示例 1:
	输入: s = "LEETCODEISHIRING", numRows = 3
	输出: "LCIRETOESIIGEDHN"
	示例 2:
	输入: s = "LEETCODEISHIRING", numRows = 4
	输出: "LDREOEIIECIHNTSG"
	解释:
	L     D     R
	E   O E   I I
	E C   I H   N
	T     S     G
	*/
public:
	string convert(string s, int numRows) {
		/*
			该题其实很有规律 假如列数为 r
			首先我们第一排位 我们需要计算两个值
			第0排为： p = 2r - 1*2; q = 0 + 0*2; pos = r; => foreach(i = 0 -> n) if(i is even) pos += q; else pos += p; 
			第1排为： p = 2r - 2*2; q = 0 + 1*2; pos = r; => foreach(i = 0 -> n) if(i is even) pos += q; else pos += p;
			第n排为： p = 2r - (n + 1)*2; q = 0 + n*2; pos = r; => foreach(i = 0 -> n) if(i is even) pos += q; else pos += p;
		*/
		if (s.empty())
			return "";
		if (numRows < 2)
			return s;
		int n = s.size();
		string ret(n, 'x');
		int p = 0, q = 0, c = 0;
		int pos = 0; 
		bool isEven = false;
		for (int r = 0; r < numRows; ++r) {
			p = numRows * 2 - (r + 1) * 2;
			q = r * 2;
			pos = r;
			isEven = false;
			while (pos < n) {
				ret[c] = s[pos];
				++c;

				if (isEven) {
					if (q > 0) {
						pos += q;
						isEven = false;
						continue;	//是偶数时 如果q大于0 加上q
					}
					isEven = false;	//是偶数时 如果q == 0 跳过偶数阶段
				}

				if (p > 0) {	//是基数时 如果p > 0 加上p
					pos += p;
				}
				else {
					pos += q;
					isEven = true;
				}
				isEven = !isEven;	//跳过该阶段
			}
		}
		return ret;
	}

	string convert1(string s, int numRows) {
		/*
			和上面原理相同 只是用循环实现
		*/
		if (s.empty())
			return "";
		if (numRows < 2)
			return s;
		int n = s.size();
		string ret(n, s[0]);
		int p = 0, q = 0, c = 0;
		int pos = 0;
		for (int r = 0; r < numRows; ++r) {
			p = numRows * 2 - (r + 1) * 2;
			q = r * 2;
			pos = r;
			ret[c] = s[pos];
			++c;
			for (int i = 0; ; ++i) {
				if (i % 2 == 0) {
					if(p == 0)
						continue;
					pos += p;
				}
				else {
					if (q == 0)
						continue;
					pos += q;
				}
				if (pos >= n)
					break;
				ret[c] = s[pos];
				++c;
			}
		}
		return ret;
	}
public:
	static void Test() {
		string s = "LEETCODEISHIRING";
		Convert c;
		cout << c.convert1(s, 3) << " -> LCIRETOESIIGEDHN" << endl;
		cout << c.convert1(s, 4) << " -> LDREOEIIECIHNTSG" << endl;
	}
};