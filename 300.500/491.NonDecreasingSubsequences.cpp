#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>
using namespace std;

// 暴力遍历法
class NonDecreasingSubsequences
{
public:
    vector<vector<int>> findSubsequences(vector<int> nums)
    {
        ret.clear();
        had.clear();
        int size = nums.size();
        if (size <= 1)
        {
            return ret;
        }
        for (int i = 0; i < size - 1; ++i)
        {
            vector<int> ans;
            ans.push_back(nums[i]);
            dfs(ans, nums, i + 1);
        }
        return ret;
    }

private:
    void dfs(vector<int> &ans, vector<int> &nums, int i)
    {
        while (i < nums.size())
        {
            if (nums[i] >= ans.back())
            {
                ans.push_back(nums[i]);
                push(ans);
                dfs(ans, nums, i + 1);
                ans.pop_back();
            }
            ++i;
        }
    }
    void push(vector<int> &ans)
    {
        string k = move(join(ans));
        if (had.contains(k))
            return;
        ret.push_back(ans);
        had.insert(k);
    }
    string join(vector<int> &ans)
    {
        stringstream ss;
        for (int x : ans)
        {
            ss << x << ",";
        }
        return ss.str();
    }

private:
    vector<vector<int>> ret;
    unordered_set<string> had;
};

// 二进制枚举（暴力遍历的另一种实现）
class NonDecreasingSubsequences1
{
public:
    vector<vector<int>> findSubsequences(vector<int> nums)
    {
        n = nums.size();
        ans.clear();
        s.clear();
        for (int i = 0; i < (1 << n); ++i)
        {
            maskToList(i, nums);
            if (check())
            {
                int hashValue = getHash(263, int(1e9) + 7);
                if (!s.contains(hashValue))
                {
                    ans.push_back(temp);
                    s.insert(hashValue);
                }
            }
        }
        return ans;
    }

private:
    // 根据mask，选出需要的num，mask标记为1的选择，否则不选
    void maskToList(int mask, vector<int> &nums)
    {
        temp.clear();
        for (int i = 0; i < n; ++i)
        {
            if (mask & 1)
            {
                temp.push_back(nums[i]);
            }
            mask >>= 1;
        }
    }
    // 检测当前temp是否单调递增(长度需要>1)
    bool check()
    {
        for (int i = 1; i < temp.size(); ++i)
        {
            if (temp[i] < temp[i - 1])
            {
                return false;
            }
        }
        return temp.size() > 1;
    }
    // 计算一个hash值，用于去重
    int getHash(int base, int mod)
    {
        int hashValue = 0;
        for (int x : temp)
        {
            hashValue = 1ll * hashValue * base % mod + (x + 101);
            hashValue %= mod;
        }
        return hashValue;
    }

private:
    vector<int> temp;
    vector<vector<int>> ans;
    unordered_set<int> s;
    int n{};
};

// 递归
class NonDecreasingSubsequences2
{
public:
    vector<vector<int>> findSubsequences(vector<int> nums)
    {
        ans.clear();
        temp.clear();
        dfs(0, INT_MIN, nums);
        return ans;
    }

private:
    void dfs(int cur, int last, vector<int> &nums)
    {
        if (cur == nums.size())
        {
            if (temp.size() >= 2)
            {
                ans.push_back(temp);
            }
            return;
        }
        if (nums[cur] >= last)
        {
            temp.push_back(nums[cur]);
            dfs(cur + 1, nums[cur], nums);
            temp.pop_back();
        }
        if (nums[cur] != last)
        {
            dfs(cur + 1, last, nums);
        }
    }

private:
    vector<int> temp;
    vector<vector<int>> ans;
};

void print(vector<vector<int>> ret)
{
    cout << "[";
    for (auto &v : ret)
    {
        cout << "[";
        for (int x : v)
        {
            cout << x << ",";
        }
        cout << "], ";
    }
    cout << "]" << endl;
}

int main(int argc, char const *argv[])
{
    NonDecreasingSubsequences2 cls;
    //[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
    print(cls.findSubsequences(vector<int>{4, 6, 7, 7}));
    //[[4,4]]
    print(cls.findSubsequences(vector<int>{4, 4, 3, 2, 1}));
    return 0;
}
