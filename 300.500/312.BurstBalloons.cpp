#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//312. 戳气球
class BurstBalloons {
    /* 有 n 个气球，编号为0 到 n - 1，每个气球上都标有一个数字，这些数字存在数组 nums 中。现在要求你戳破所有的气球。戳破第 i 个气球，你可以获得 nums[i - 1] * nums[i] * nums[i + 1] 枚硬币。 这里的 i - 1 和 i + 1 代表和 i 相邻的两个气球的序号。如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球。求所能获得硬币的最大数量。
    */
public:
    int maxCoins(vector<int>& nums) {
        //分治 i..j = when k=i+1..j-1 => max(i..k + k..j + i*k*j)
        vals.resize(nums.size() + 2, 1);    //这里增加边界 并且边界不能被戳破(实现上就不用考虑边界问题了，也就是不用考虑只剩2个或以下元素的情况)
        for (int i = 0; i < nums.size();++i) {
            vals[i + 1] = nums[i];
        }
        ret.resize(nums.size() + 2, vector<int>(nums.size() + 2, -1));
        return solve(0, nums.size() + 1);
    }
private:
    int solve(int start, int end) {
        if (start >= end - 1)    //由于我们增加了边界 所以不用考虑只有两个数的情况
            return 0;
        if (ret[start][end] != -1) {  //已经计算过了
            return ret[start][end];
        }
        for (int k = start + 1; k < end; ++k) {
            //遍历k 找到最大结果
            int sum = vals[start] * vals[k] * vals[end];
            sum += solve(start, k);
            sum += solve(k, end);
            ret[start][end] = max(ret[start][end], sum);
        }
        return ret[start][end];
    }
private:
    vector<int> vals;
    vector<vector<int>> ret;
public:
    int maxCoins1(vector<int>& nums) {
        //动态规划 与分治思想一样 实现方法不同
        int n = nums.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        vector<int> vals(n+2, 1);
        for(int i=0;i<n;++i){
            vals[i+1] = nums[i];
        }
        for(int i = n-1;i>=0;--i){ //注意这里i倒着算 是为了保证区间由小到大
            for(int j = i+2;j<=n+1;++j){    //此时i..j的区间由小到大 才能计算
                for(int k = i+1;k<j;++k){
                    int sum = vals[i]*vals[k]*vals[j];
                    sum += dp[i][k];
                    sum += dp[k][j];
                    dp[i][j] = max(dp[i][j], sum);
                }
            }
        }
        return dp[0][n+1];
    }
};

int main(int argc, char const *argv[]){
    BurstBalloons cls;
    cout << cls.maxCoins(vector<int>{3,1,5,8}) << " : " << cls.maxCoins1(vector<int>{3,1,5,8}) << " -> 167" << endl;
    cout << cls.maxCoins(vector<int>{1,5}) << " : " << cls.maxCoins1(vector<int>{1,5}) << " -> 10" << endl;
    return 0;
}
