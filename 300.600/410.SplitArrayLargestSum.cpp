#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SplitArrayLargestSum
{
public:
    int splitArray1(vector<int>& nums, int m) {
        //动态规划
        /*
            以 7 2 5 10 8为例：
            f[i][1] 即为前i个元素分割为1段的情况：如下
            f[1][1] = [7] = 7;
            f[2][1] = [7 2] = 9;
            f[3][1] = [7 2 5] = 14;
            f[4][1] = [7 2 5 10] = 24;
            f[5][1] = [7 2 5 10 8] = 32;
            再考虑前i个元素分割2段的情况
            f[2][2] = [7 | 2] = 7
            f[3][2] = [7 | 2 5] 或者 [7 2 | 5] = 7
            f[4][2] = [7 | 2 5 10] 或者 [7 2 | 5 10] 或者 [7 2 5 | 10] = 14
            ... 以此类推 ...
            最终求出 f[n][m]
        */
        int n = nums.size();
        vector<vector<long long>> f(n + 1, vector<long long>(m + 1, LLONG_MAX));
        vector<long long> sub(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sub[i + 1] = sub[i] + nums[i];
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, m); j++) {
                for (int k = 0; k < i; k++) {
                    f[i][j] = min(f[i][j], max(f[k][j - 1], sub[i] - sub[k]));
                }
            }
        }
        return (int)f[n][m];
    }
public:
    int splitArray2(vector<int>& nums, int m) {
        //二分法
        int right = 0;
        int left = 0;
        for (auto x : nums) {
            right += x;
            if (left < x)
                left = x;
        }
        if (m == 1)
            return right;   //只分一组时 就是所有元素之和
        while (left < right) {
            int mid = (left + right) / 2;
            int cur = 0;
            int cnt = 1;
            for (auto x : nums) {
                cur += x;
                if (cur <= mid)
                    continue;
                cur = x;
                ++cnt;
            }
            //分组数量不够时 需要调整
            if (cnt <= m) {  //分组过多 需要加大中位值以减少分组
                right = mid;
            }
            else {  //分组过少 需要减小中位值以增加分组
                left = mid + 1;
            }
        }
        return left;
    }
};

int main(int argc, char const* argv[]) {
    SplitArrayLargestSum cls;
    cout << cls.splitArray1(vector<int>{7,2,5,10,8}, 2) << " -> 18" << endl;
    cout << cls.splitArray1(vector<int>{1,2,3,4,5}, 2) << " -> 9" << endl;
    cout << cls.splitArray1(vector<int>{1,4,4}, 3) << " -> 4" << endl;
    return 0;
}
