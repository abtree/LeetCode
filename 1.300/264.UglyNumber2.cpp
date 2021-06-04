#include <iostream>
#include <queue>
#include <unordered_set>
#include <functional>
#include <array>
#include <algorithm>

using namespace std;

// 264. 丑数 II
class UglyNumber2 {
    /* 给你一个整数 n ，请你找出并返回第 n 个 丑数 。丑数 就是只包含质因数 2、3 和/或 5 的正整数。
    */
public:
    int nthUglyNumber(int n) {
        //倒叙的优先队 (实际是将丑数依次算出 并取出第n个)
        unordered_set<long long> repeat;
        priority_queue<long long, vector<long long>, greater<long long>> q;   //实际上是取q中第n小的元素 q类似一个窗口动态向后滑动
        q.push(1);
        array<int, 3> facts{ 2,3,5 };
        long long ugly = 0;
        while (n > 0) {
            ugly = q.top();
            q.pop();    //出一个
            for (int f : facts) { //进3个
                auto u = ugly * f;
                if (repeat.find(u) == repeat.end()) {
                    q.push(u);
                    repeat.insert(u);
                }
            }
            --n;
        }
        return (int)ugly;
    }
public:
    int nthUglyNumber2(int n) {
        /*  动态规划 dp[n]表示第n个丑数
            初始条件 dp[1] = 1
            指针 p2 p3 p5 分别表示 因数 2 3 5 指向的上一个丑数
            当 2 <= i <= n时, dp[i] = min(dp[p2]*2, dp[p3]*3, dp[p5]*5),
            同时:被dp[i]选中的值，需要移动到下一个值,即：如果 dp[i] 与 dp[p2],dp[p3],dp[p5]相等，相应指针加1
        */
        vector<int> dp(n);
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0; //初始都指向第一个丑数
        for (int i = 1; i < n;++i) {
            int n2 = dp[p2] * 2;
            int n3 = dp[p3] * 3;
            int n5 = dp[p5] * 5;
            dp[i] = min(n2, min(n3, n5));
            if (dp[i] == n2) {
                ++p2;
            }
            if (dp[i] == n3) {
                ++p3;
            }
            if (dp[i] == n5) {
                ++p5;
            }
        }
        return dp[n-1];
    }
};

int main(int argc, char const* argv[])
{
    UglyNumber2 cls;
    cout << cls.nthUglyNumber2(10) << "->12" << endl;
    cout << cls.nthUglyNumber2(1) << "->1" << endl;
    cout << cls.nthUglyNumber2(1407) << "->536870912" << endl;
    return 0;
}
