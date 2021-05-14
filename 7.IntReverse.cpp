#include <iostream>
#include <string>

using namespace std;

//7 整数反转
class IntReverse {
	/*
	给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

	示例 1:
	输入: 123
	输出: 321

	示例 2:
	输入: -123
	输出: -321

	示例 3:
	输入: 120
	输出: 21
	注意:
	假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
	*/
public:
	int reverse(int x) {
		/*
			通过逐位取和放 实现反转 （需要注意越界问题）
		*/
		const int max = INT_MAX / 10;
		int pop = 0;
		int ret = 0;
		while (x != 0)
		{
			pop = x % 10;
			x /= 10;
			if (ret > max || (ret == max && pop > 7))
				return 0;
			if (ret < -1 * max || (ret == -1 * max && pop < -8))
				return 0;
			ret = ret * 10 + pop;
		}
		return ret;
	}

	int reverse2(int x) {
		/*
		通过字符串实现反转
		*/
		bool fs = false;
		if (x < 0) {
			fs = true;
			x *= -1;
		}

		string s1 = to_string(x);
		if (s1.size() < 10) {
			s1.reserve();
			int ret = atoi(s1.c_str());
			return fs ? (-1 * ret) : ret;
		}
		if (s1.size() > 10)
			return 0;
		char last = s1[9];
		s1[9] = 'x';
		int ret = atoi(s1.c_str());
		if (ret > INT_MAX / 10)
			return 0;
		if (ret == INT_MAX / 10) {
			if (fs) {
				if (last > '8')
					return 0;
				return -1 * (ret * 10 + (last - '0'));
			}
			else {
				if (last > '7')
					return 0;
				return ret * 10 + (last - '0');
			}
		}
		return fs ? (-1 * (ret * 10 + (last - '0'))) : (ret * 10 + (last - '0'));
	}
};

int main(int argc, char const *argv[])
{
	IntReverse ir;
	cout << ir.reverse(123) << " -> 321" << endl;
	cout << ir.reverse(-123) << " -> -321" << endl;
	cout << ir.reverse(120) << " -> 21" << endl;
	cout << ir.reverse(-1200000) << " -> -21" << endl;
	return 0;
}
