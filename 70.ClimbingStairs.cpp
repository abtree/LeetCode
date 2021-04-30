#include <iostream>
#include<vector>
using namespace std;

//70. 爬楼梯
class ClimbStairs {
    /*
    假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
    每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
    注意：给定 n 是一个正整数。

    示例 1：
    输入： 2
    输出： 2
    解释： 有两种方法可以爬到楼顶。
    1.  1 阶 + 1 阶
    2.  2 阶

    示例 2：
    输入： 3
    输出： 3
    解释： 有三种方法可以爬到楼顶。
    1.  1 阶 + 1 阶 + 1 阶
    2.  1 阶 + 2 阶
    3.  2 阶 + 1 阶
    */
public:
    int climbStairs(int n) {
        //到达第n阶楼梯的方法=到达n-1阶的方法+到达n-2阶楼梯的方法
        //f(n)=f(n-1)+f(n-2)
        if (n == 1)
            return 1;
        int dp1 = 1;
        int dp2 = 2;
        for (int i = 2;i < n;++i) {
            int t = dp2;
            dp2 += dp1;
            dp1 = t;
        }
        return dp2;
    }
public:
    int climbStairs2(int n) {
        //由于斐波那契数列可以用矩阵幂运算计算求出通用公式：f(x)=1/sqrt(5)[((1+sqrt(5))/2)^n-((1-sqrt(5))/2)^n]
        double sqrt5 = Math.sqrt(5);
        double fibn = Math.pow((1 + sqrt5) / 2, n + 1) - Math.pow((1 - sqrt5) / 2, n + 1);
        return (int)Math.round(fibn / sqrt5);
    }
};

int main() {
    ClimbStairs cls;
    cout << cls.climbStairs(2) << " -> 2" << endl;
    cout << cls.climbStairs(3) << " -> 3" << endl;
    return 0;
}