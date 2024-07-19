#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val{};
    TreeNode *left{};
    TreeNode *right{};
    TreeNode() {}
    TreeNode(int x) : val(x) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindModeInBinarySearchTree
{
public:
    vector<int> findMode(TreeNode *root)
    {
        unordered_map<int, int> dp;
        if (root)
        {
            dfs(dp, root);
        }
        if (dp.empty())
        {
            return {};
        }
        int m = 0;
        for (auto &x : dp)
        {
            m = max(m, x.second);
        }
        vector<int> ret;
        for (auto &x : dp)
        {
            if (x.second == m)
            {
                ret.push_back(x.first);
            }
        }
        return ret;
    }

private:
    void dfs(unordered_map<int, int> &dp, TreeNode *root)
    {
        dp[root->val] += 1;
        if (root->left)
        {
            dfs(dp, root->left);
        }
        if (root->right)
        {
            dfs(dp, root->right);
        }
    }

public:
    // 空间优化版本
    // 因为搜索树中序遍历会得到一个单调不减队列
    // 可以利用这个特性实现不需要额外空间的遍历
    vector<int> findMode1(TreeNode *root)
    {
        ans.clear();
        base = count = maxCount = 0;
        dfs(root);
        return ans;
    }

private:
    void update(int val)
    {
        if (val == base)
        {
            ++count;
        }
        else
        {
            count = 1;
            base = val;
        }
        if (count == maxCount)
        {
            ans.push_back(val);
        }
        else if (count > maxCount)
        {
            ans = vector<int>{val};
            maxCount = count;
        }
    }
    void dfs(TreeNode *r)
    {
        if (!r)
        {
            return;
        }
        dfs(r->left);
        update(r->val);
        dfs(r->right);
    }

private:
    vector<int> ans;
    int base{};
    int count{};
    int maxCount{};
};

void print(const vector<int> &ret)
{
    cout << "[";
    for (int x : ret)
    {
        cout << x << ",";
    }
    cout << "]" << endl;
}

void del(TreeNode *root)
{
    if (root->left)
    {
        del(root->left);
    }
    if (root->right)
    {
        del(root->right);
    }
    delete root;
}

int main(int argc, char const *argv[])
{
    FindModeInBinarySearchTree cls;
    TreeNode *head = new TreeNode(1);
    head->right = new TreeNode(2);
    head->right->left = new TreeNode(2);
    print(cls.findMode1(head));
    del(head);

    head = new TreeNode(0);
    print(cls.findMode1(head));
    del(head);
    return 0;
}
