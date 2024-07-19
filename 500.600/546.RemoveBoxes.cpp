#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class RemoveBoxes
{
public:
    int removeBoxes(const vector<int> &boxes)
    {
        dp = vector<vector<vector<int>>>(100, vector<vector<int>>(100, vector<int>(100, 0)));
        return calculatePoints1(boxes, 0, boxes.size() - 1, 0);
    }

private:
    // 计算 区间[l, r+]最优解; r+表示需要考虑[r, n)区间内值为boxes[r]的所有元素
    // [l, r] 标识区间 k表示 [r, n)区间内值为boxes[r]的元素个数
    int calculatePoints(const vector<int> &boxes, int l, int r, int k)
    {
        if (l > r)
        {
            return 0;
        }
        if (dp[l][r][k] == 0)
        {
            // 移除区间最后一个元素,包含其后所有值为boxes[r]的元素
            dp[l][r][k] = calculatePoints(boxes, l, r - 1, 0) + (k + 1) * (k + 1);
            // 计算[l, r]中值为boxes[r]的元素，此时可能不优先移除最后一个元素
            // 如 [5,3,5] 应该先移除3,而不是最后一个5
            for (int i = l; i < r; ++i)
            {
                if (boxes[i] == boxes[r])
                    dp[l][r][k] = max(dp[l][r][k], calculatePoints(boxes, l, i, k + 1) + calculatePoints(boxes, i + 1, r - 1, 0));
            }
        }
        return dp[l][r][k];
    }
    // 针对 boxes[r] == boxes[r-1]时,可进行一点优化
    // 即只需要将k+1,r-1即可
    int calculatePoints1(const vector<int> &boxes, int l, int r, int k)
    {
        if (l > r)
        {
            return 0;
        }
        if (dp[l][r][k] == 0)
        {
            int r1 = r, k1 = k;
            while (r1 > l && boxes[r1] == boxes[r1 - 1])
            {
                r1--;
                k1++;
            }

            // 移除区间最后一个元素,包含其后所有值为boxes[r]的元素
            dp[l][r][k] = calculatePoints1(boxes, l, r1 - 1, 0) + (k1 + 1) * (k1 + 1);
            // 计算[l, r]中值为boxes[r]的元素，此时可能不优先移除最后一个元素
            // 如 [5,3,5] 应该先移除3,而不是最后一个5
            for (int i = l; i < r1; ++i)
            {
                if (boxes[i] == boxes[r1])
                    dp[l][r][k] = max(dp[l][r][k], calculatePoints1(boxes, l, i, k1 + 1) + calculatePoints1(boxes, i + 1, r1 - 1, 0));
            }
        }
        return dp[l][r][k];
    }

private:
    vector<vector<vector<int>>> dp;
};

int main()
{
    RemoveBoxes cls;
    cout << cls.removeBoxes(vector<int>{1, 3, 2, 2, 2, 3, 4, 3, 1}) << " -> 23" << endl;
    cout << cls.removeBoxes(vector<int>{1, 1, 1}) << " -> 9" << endl;
    cout << cls.removeBoxes(vector<int>{1}) << " -> 1" << endl;
    return 0;
}
