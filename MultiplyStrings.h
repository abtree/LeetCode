#pragma once

//43. 字符串相乘
class CMultiplyStrings {
	/*
	给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

	输入: num1 = "2", num2 = "3"
	输出: "6"

	输入: num1 = "123", num2 = "456"
	输出: "56088"

	1, num1 和 num2 的长度小于110。
	2, num1 和 num2 只包含数字 0-9。
	3, num1 和 num2 均不以零开头，除非是数字 0 本身。
	4, 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
	*/
public:
	string multiply(string num1, string num2) {
		//竖乘法
		if (num1 == "0" || num2 == "0")
			return "0";
		//先翻转 好处理
		std::reverse(num1.begin(), num1.end());
		std::reverse(num2.begin(), num2.end());

		string ret(num1.size() + num2.size(), '0');
		int i = 0;
		for (char c : num2) {
			int up = 0;
			int pos = i;
			int b = c - '0';
			string cell(num1.size() + i + 1, '0');
			for (char d : num1) {
				int r = (d - '0')*b + up;
				up = r / 10;
				cell[pos] = r % 10 + '0';
				++pos;
			}
			//处理进位
			if (up > 0) {
				cell[pos] = up + '0';
				up = 0;
			}
			//加回结果
			for (int j = 0; j < cell.size(); ++j) {
				int r = ret[j] - '0' + cell[j] - '0' + up;
				up = r / 10;
				ret[j] = r % 10 + '0';
			}
			if (up > 0) {
				ret[cell.size()] = up + '0';
			}
			++i;
		}
		//最后处理
		if (*ret.rbegin() == '0')
			ret.pop_back();
		std::reverse(ret.begin(), ret.end());
		return ret;
	}

	string multiply2(string num1, string num2) {
		//竖乘法的优化版本
		int n1 = num1.length();
		int n2 = num2.length();
		string result(n1 + n2, '0');

		for (int i = n1 - 1; i >= 0; i--) {
			for (int j = n2 - 1; j >= 0; j--) {
				int sum = (result[i + j + 1] - '0') + (num1[i] - '0')*(num2[j] - '0');
				result[i + j + 1] = (sum % 10) + '0';
				result[i + j] += sum / 10;
			}
		}

		for (int i = 0; i < result.length(); i++) { // int->string
			if (result[i] != '0' || i == result.length() - 1) { // 初始化时result全为0，需要从第一个不为0开始返回string，或者个位为0
				return result.substr(i); // 0-ith pos
			}
		}
		return "0";
	}
public:
	static void Test() {
		CMultiplyStrings cls;
		string ret = cls.multiply("2", "3");
		cout << ret.c_str() << " --> 6" << endl;
		ret = cls.multiply("123", "456");
		cout << ret.c_str() << " --> 56088" << endl;
	}
};