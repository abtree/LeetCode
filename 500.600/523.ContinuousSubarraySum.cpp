#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class tree
{
public:
    tree(int n) : size(n + 1)
    {
        for (int i = 0; i < size; ++i)
        {
            Tree.push_back(0);
        }
    }
    int lowbit(int x)
    {
        return x & (-x);
    }
    void add(int k, int v)
    {
        while (k <= size)
        {
            Tree[k] += v;
            k += lowbit(k);
        }
    }
    int sum(int x)
    {
        int ans = 0;
        while (x > 0)
        {
            ans += Tree[x];
            x -= lowbit(x);
        }
        return ans;
    }

private:
    vector<int> Tree{};
    int size{};
};

class ContinuousSubarraySum
{
public:
    // 暴力求解
    bool checkSubarraySum(const vector<int> &nums, int k)
    {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum = nums[i];
            for (int j = i + 1; j < n; ++j)
            {
                sum += nums[j];
                if (sum % k == 0)
                {
                    return true;
                }
            }
        }
        return false;
    }

public:
    // 树状数组
    bool checkSubarraySum1(const vector<int> &nums, int k)
    {
        int n = nums.size();
        tree t(n);
        for (int i = 0; i < n; ++i)
        {
            t.add(i + 1, nums[i]);
        }
        for (int i = 2; i <= n; ++i)
        {
            int sum = t.sum(i);
            if (sum % k == 0)
            {
                return true;
            }
            for (int j = i - 2; j > 0; --j)
            {
                int ns = sum - t.sum(j);
                if (ns % k == 0)
                {
                    return true;
                }
            }
        }
        return false;
    }

public:
    // 前缀和(只需要判断 preSum[j] % k == preSum[i] % k)
    // 另外特殊处理只有preSum[j]的情况(添加i=-1,余数为0的项),从第一个元素到第j+1个元素和
    bool checkSubarraySum2(const vector<int> &nums, int k)
    {
        unordered_map<int, int> dp{{0, -1}};
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            int rem = sum % k;
            auto it = dp.find(rem);
            if (it != dp.end())
            {
                if (i - it->second > 1)
                {
                    return true;
                }
            }
            else
            {
                dp.insert({rem, i});
            }
        }
        return false;
    }
};

int main()
{
    ContinuousSubarraySum cls;
    cout << boolalpha << cls.checkSubarraySum2(vector<int>{23, 2, 6, 4, 7}, 13) << false << endl;
    cout << boolalpha << cls.checkSubarraySum2(vector<int>{23, 2, 4, 6, 7}, 6) << true << endl;
    cout << boolalpha << cls.checkSubarraySum2(vector<int>{23, 2, 6, 4, 7}, 6) << true << endl;
    return 0;
}
