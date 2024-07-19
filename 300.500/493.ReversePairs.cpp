#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class BIT
{
private:
    vector<int> tree;
    int n;

public:
    // 注意，树状数组的x是从1开始的,所以开辟n的数组时，需要额外开辟1个空间
    BIT(int _n) : n(_n), tree(_n + 1) {}

    static constexpr int lowbit(int x)
    {
        return x & (-x);
    }

    // 修改树状数组第x个元素的值(增加d)
    void update(int x, int d)
    {
        while (x <= n)
        {
            tree[x] += d;
            x += lowbit(x);
        }
    }

    // 获取前x个元素的值的和
    int query(int x) const
    {
        int ans = 0;
        while (x)
        {
            ans += tree[x];
            x -= lowbit(x);
        }
        return ans;
    }
};

class ReversePairs
{
public:
    // 暴力求解法(会超时)
    int reversePairs(vector<int> nums)
    {
        int ret = 0;
        int size = nums.size();
        for (int j = size - 1; j > 0; --j)
        {
            long long cur = 2ll * nums[j];
            for (int i = j - 1; i >= 0; --i)
            {
                if (nums[i] > cur)
                {
                    ++ret;
                }
            }
        }
        return ret;
    }
    // 递归合并法
    int reversePairs1(vector<int> nums)
    {
        if (nums.size() < 2)
        {
            return 0;
        }
        return reversePair(nums, 0, nums.size() - 1);
    }

private:
    int reversePair(vector<int> &nums, int left, int right)
    {
        if (left >= right)
        {
            return 0;
        }
        int mid = (left + right) / 2;
        int n1 = reversePair(nums, left, mid);
        int n2 = reversePair(nums, mid + 1, right);
        int ret = n1 + n2;
        // 计算两组之间的值
        int i = left;
        int j = mid + 1;
        while (i <= mid)
        {
            while (j <= right && (long long)nums[i] > 2ll * nums[j])
            {
                ++j;
            }
            ret += (j - mid - 1);
            ++i;
        }

        // 合并
        vector<int> sorted(right - left + 1);
        int p1 = left;
        int p2 = mid + 1;
        int p = 0;
        while (p1 <= mid || p2 <= right)
        {
            if (p1 > mid)
            {
                sorted[p] = nums[p2];
                ++p;
                ++p2;
            }
            else if (p2 > right)
            {
                sorted[p] = nums[p1];
                ++p;
                ++p1;
            }
            else
            {
                if (nums[p1] < nums[p2])
                {
                    sorted[p] = nums[p1];
                    ++p;
                    ++p1;
                }
                else
                {
                    sorted[p] = nums[p2];
                    ++p;
                    ++p2;
                }
            }
        }
        for (int i = 0; i < sorted.size(); ++i)
        {
            nums[left + i] = sorted[i];
        }
        return ret;
    }

public:
    // 树化数组
    int reversePairs2(vector<int> nums)
    {
        set<long long> allNums;
        for (int x : nums)
        {
            allNums.insert(x);
            allNums.insert(2ll * x);
        }
        unordered_map<long long, int> values;
        int idx = 0;
        for (auto x : allNums)
        {
            values[x] = ++idx;
        }
        int ret = 0;
        BIT bit(values.size());
        for (int i = 0; i < nums.size(); ++i)
        {
            int left = values[2ll * nums[i]];
            int right = values.size();
            ret += bit.query(right) - bit.query(left);
            bit.update(values[nums[i]], 1);
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    ReversePairs cls;
    cout << cls.reversePairs2(vector<int>{1, 3, 2, 3, 1}) << " -> 2" << endl;
    cout << cls.reversePairs2(vector<int>{2, 4, 3, 5, 1}) << " -> 3" << endl;
    return 0;
}
