#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

// 279. 完全平方数
class PerfectSquares {
    /*  给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
    给你一个整数 n ，返回和为 n 的完全平方数的 最少数量 。
    完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。
    */
public:
    int numSquares(int n) {
        //暴力法 计算较大值会严重超时
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        int x = (int)pow(n, 0.5);
        int low = n;
        for(int i = x; i > 0; --i){
            low = min(low, numSquares(n - i*i));
        }
        return low+1;
    }
public:
    int numSquares2(int n) {
        //动态规划
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        int x = (int)pow(n, 0.5);
        vector<int> sqrtnums(x);
        for(int i = 1; i<=x;++i){
            sqrtnums[i-1] = i*i;
        }
        for(int i =1; i<=n;++i){
            for(int j =0; j < x;++j){
                if(i < sqrtnums[j])
                    break;
                dp[i] = min(dp[i], dp[i - sqrtnums[j]] + 1);
            }
        }
        return dp[n];
    }
public:
    int numSquares3(int n) {
        //贪心枚举[深度优先]（性能极好）
        int x = (int)pow(n, 0.5);
        unordered_set<int> sqrtnums;
        for(int i = 1; i<=x;++i){
            sqrtnums.insert(i*i);
        }
        for(int count = 1; count < n; ++count){
            if(isDividedBy(n, count, sqrtnums)){
                return count;
            }
        }
        return n;
    }
    bool isDividedBy(int n, int count, unordered_set<int>& sqrtnums){
        if(count == 1){
            return sqrtnums.find(n) != sqrtnums.end();
        }
        for(int i : sqrtnums){
            if(isDividedBy(n -i, count - 1, sqrtnums))
                return true;
        }
        return false;
    }
public:
    int numSquares4(int n) {
        //贪心算法[广度优先]
        int x = (int)pow(n, 0.5);
        vector<int> sqrtnums(x);
        for(int i = 1; i<=x;++i){
            sqrtnums[i-1] = i*i;
        }
        queue<int> q;
        q.push(n);
        int level = 0;
        while(!q.empty()){
            ++level;
            int size = q.size();
            for(int i = 0; i< size;++i){
                int c = q.front();
                q.pop();
                for(int j = 0; j<x;++j){
                    if (sqrtnums[j] == c){
                        return level;
                    }else if(c < sqrtnums[j]){
                        break;
                    }else{
                        q.push(c- sqrtnums[j]);
                    }
                }
            }
        }
        return level;
    }
public:
    int numSquares5(int n) {
        /* 数学公式
            拉格朗日公式：任何数都可以表示4数和(可包含0)
            满足公式：n = 4^k(8m+7)的数 只能表示为4个不为0的数的完全平方和
        */
        int x = n;
        while(x % 4 == 0){
            x/=4;
        }
        if(x % 8 == 7)
            return 4;
        x = (int)pow(n, 0.5);
        if(x*x == n)
            return 1;
        vector<int> sqrtnums(x);
        for(int i = 1; i<=x;++i){
            sqrtnums[i-1] = i*i;
        }
        for(int i = 0; i<x;++i){
            for (int j = i; j< x;++j){
                if(sqrtnums[i] + sqrtnums[j] == n)
                    return 2;
                else if(sqrtnums[i] + sqrtnums[j] > n){
                    break;
                }
            }
        }
        return 3;
    }
};

int main(int argc, char const *argv[]){
    PerfectSquares cls;
    cout << cls.numSquares5(2) << " -> 2" << endl;
    cout << cls.numSquares5(1) << " -> 1" << endl;
    cout << cls.numSquares5(12) << " -> 3" << endl;
    cout << cls.numSquares5(13) << " -> 2" << endl;
    cout << cls.numSquares5(999) << " -> 4" << endl;
    return 0;
}
