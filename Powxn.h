#pragma once

//50. Pow(x, n)
class CPowxn {
    /*
        实现 pow(x, n) ，即计算 x 的 n 次幂函数。

    示例 1:
        输入: 2.00000, 10
        输出: 1024.00000

    示例 2:
        输入: 2.10000, 3
        输出: 9.26100

    示例 3:
        输入: 2.00000, -2
        输出: 0.25000
        解释: 2-2 = 1/22 = 1/4 = 0.25
    说明:
        -100.0 < x < 100.0
        n 是 32 位有符号整数，其数值范围是 [−2^31, 2^31 − 1] 。
    */
public:
    double myPow(double x, int n) {
        if (x == 0)
            return 0;
        if (n == INT_MIN) {
            x = 1 / x;
            x *= x;
            n = INT_MAX;
        }
        else if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        return pown(x, n);
    }
private:
    double pown(double x, int n) {
        //递归倒着算 设n=77
        //需要求77，可以用 38 + 38 + 1
        if (n <= 0)
            return 1.0;
        auto y = pown(x, n / 2);    //求出38的值
        y *= y; //38 * 38 就是 76 次的值
        if (n % 2 > 0)
            y *= x; //在乘以1次 就是77次的值
        return y;
    }
public:
    double myPow2(double x, int n) {
        if (x == 0)
            return 0;
        double ret = 1;
        if (n == INT_MIN) {
            x = 1 / x;
            ret *= x;
            n = INT_MAX;
        }
        else if (n < 0) {
            x = 1 / x;
            n = -n;
        }

        //正向指数增长法 1 2 4 8 ...
        while (n > 0) {
            double y = x;
            n = pown2(y, n);
            ret *= y;
        }
        return ret;
    }
private:
    int pown2(double& x, int n) {
        if (n == 1)
            return 0;
        unsigned int i = 1;
        while (i <= n) {
            if (i * 2 > n)
                return n - i;
            x *= x;
            i *= 2;
        }
        return 0;
    }
public:
    static void Test() {
        CPowxn cls;
        cout << cls.myPow2(1.0, INT_MIN) << " -> 1.0" << endl;
        cout << cls.myPow2(2.0, 10) << " -> 1024.0" << endl;
        cout << cls.myPow2(2.1, 3) << " -> 9.261" << endl;
        cout << cls.myPow2(2.0, -2) << " -> 0.25" << endl;
    }
};