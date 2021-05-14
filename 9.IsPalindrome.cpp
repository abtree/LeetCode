#include <iostream>
#include <string>
using namespace std;

//9 回文数
class IsPalindrome {
	/*
	判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

	示例 1:
	输入: 121
	输出: true

	示例 2:
	输入: -121
	输出: false
	解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

	示例 3:
	输入: 10
	输出: false
	解释: 从右向左读, 为 01 。因此它不是一个回文数。

	进阶:
	你能不将整数转为字符串来解决这个问题吗？
	*/
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;	//负数一定不是

		/*
			转换为string方法
		*/
		string str = to_string(x);
		int n = str.size() - 1;
		for (int i = 0; i < n; ++i, --n) {
			if (str[i] != str[n])
				return false;
		}
		return true;
	}
	bool isPalindrome2(int x) {
		if (x < 0 || (x != 0 && x % 10 == 0))
			return false;	//负数一定不是 末尾为0的大于0的数一定不是
		if (x < 10)
			return true;	//0一定是

		/*
			翻转一半 与剩余的一半比较 应该相等
		*/
		int y = 0;
		while (x > y) {
			int z = x % 10;
			x = x / 10;
			if (x == y)
				return true;	//除去中间位 相等
			y = y * 10 + z;
			if (x == y)
				return true;
		}
		return false;
	}
};

int main(int argc, char const *argv[])
{
	IsPalindrome c;
	cout << boolalpha << c.isPalindrome2(121) << " -> true" << endl;
	cout << boolalpha << c.isPalindrome2(-121) << " -> false" << endl;
	cout << boolalpha << c.isPalindrome2(10) << " -> false" << endl;
	cout << boolalpha << c.isPalindrome2(11) << " -> true" << endl;
	return 0;
}
