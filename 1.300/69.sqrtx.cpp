#include <iostream>
using namespace std;

//69. x 的平方根
class SqrtX {
    /*
    实现 int sqrt(int x) 函数。
    计算并返回 x 的平方根，其中 x 是非负整数。
    由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

    示例 1:
    输入: 4
    输出: 2

    示例 2:
    输入: 8
    输出: 2
    说明: 8 的平方根是 2.82842...,
         由于返回类型是整数，小数部分将被舍去。
    */
public:
    int mySqrt(int x) {
        //二分法
        int ans = 0;
        int l = 0, r = x;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if ((long long)mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
public:
    int mySqrt2(int x) {
        //换算法( sqrt(x)=x^1/2=e^(1/2lnx))
        if (x == 0) {
            return 0;
        }
        int ans = exp(0.5 * log(x));
        if ((long long)(ans + 1) * (ans + 1) <= x)
            return ans + 1;
        return ans;
    }
};

int main() {
    SqrtX cls;
    cout << cls.mySqrt(4) << " --> 2" << endl;
    cout << cls.mySqrt(8) << " --> 2" << endl;
    return 0;
}