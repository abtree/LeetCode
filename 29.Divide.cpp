#include <iostream>

using namespace std;

//29. 两数相除
class CDivide {
	/*
	给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
	返回被除数 dividend 除以除数 divisor 得到的商。
	整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2

	 示例 1:
	 输入: dividend = 10, divisor = 3
	 输出: 3
	 解释: 10/3 = truncate(3.33333..) = truncate(3) = 3

	 示例 2:
	 输入: dividend = 7, divisor = -3
	 输出: -2
	 解释: 7/-3 = truncate(-2.33333..) = -2

	  提示：
	  被除数和除数均为 32 位有符号整数。
	  除数不为 0。
	  假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。
	*/
public:
	int divide(int dividend, int divisor) {
		//暴力法 (这种解法在leetcode上会超时)
		if (divisor == 0)
			return 0;
		if (dividend > INT_MAX || dividend < INT_MIN)
			return INT_MAX;
		if(dividend == INT_MIN && divisor == -1)
			return INT_MAX; //这种会越界
		if (divisor == 1)	//如果被除数为1 返回原数
			return dividend;
		if (divisor == -1)	//如果被除数为-1 除了越界的情况 转换为负数
			return 0 - dividend;
		
		int ret = 0;
		//判断符号
		bool underZero = false;
		if (dividend > 0 && divisor < 0)
			underZero = true;
		else if (dividend < 0 && divisor > 0)
			underZero = true;

		//转成负数
		if (dividend > 0)
			dividend = 0 - dividend;	
		if (divisor > 0)
			divisor = 0 - divisor;

		while (dividend <= divisor) {
			dividend -= divisor;
			if (underZero)
				--ret;
			else
				++ret;
		}

		return ret;
	}
public:
	int divide2(int dividend, int divisor) {
		/*
		倍数增长发(先圈定范围，再具体求值)
		[例]10 / 3
		首先 10 > 3 => {min >= 1, max ? }
		首先 10 > 6 => {min >= 2, max ? }
		首先 10 < 12 => {min >= 2, max <= 4 } //这时范围就出来了
		
		此时我们可以知道最终的结果会是 2 + (10 - 6) / 3
		2 + 后面的部分 又可以用上面的方法计算
		*/
		//几种特殊情况
		if (divisor == 0)
			return 0;
		if (dividend > INT_MAX || dividend < INT_MIN)
			return INT_MAX;
		if (divisor == 1)	//如果被除数为1 返回原数
			return dividend;
		if (divisor == -1) {
			if (dividend == INT_MIN) return INT_MAX;	//这种会越界
			return 0 - dividend;
		}

		//判断符号
		bool underZero = false;
		if (dividend > 0 && divisor < 0)
			underZero = true;
		else if (dividend < 0 && divisor > 0)
			underZero = true;

		//转成负数
		if (dividend > 0)
			dividend = 0 - dividend;
		if (divisor > 0)
			divisor = 0 - divisor;
		//修正符号
		int ret = divide(dividend, divisor, 0);
		if (underZero)
			return -ret;
		return ret;
	}
private:
	int divide(int dividend, int divisor, int add) {
		if (dividend > divisor)
			return add;	//此时已经不能再整除了
		int next = divisor;	//这里需要保存一份
		int ret = 1;
		while (true) {
			if (INT_MIN - divisor > divisor)	//这里是越界检查
				break;
			if (dividend > divisor + divisor)
				break;
			divisor += divisor;
			ret += ret;
		}
		return divide(dividend - divisor, next, add + ret);
	}
};

int main(int argc, char const *argv[])
{
	CDivide cls;
	cout << cls.divide2(2147483647, 3) << " --> 715827882" << endl;
	cout << cls.divide2(-2147483648, -1) << " --> 2147483647" << endl;
	cout << cls.divide2(-2147483648, 1) << " --> -2147483648" << endl;
	cout << cls.divide2(10, 3) << " --> 3" << endl;
	cout << cls.divide2(7, -3) << " --> -2" << endl;
	return 0;
}
