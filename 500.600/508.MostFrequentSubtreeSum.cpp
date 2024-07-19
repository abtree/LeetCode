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

class MostFrequentSubtreeSum
{
public:
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        rets.clear();
        m = 0;
        dfs(root);
        vector<int> ans;
        for (auto &x : rets)
        {
            if (x.second == m)
            {
                ans.push_back(x.first);
            }
        }
        return ans;
    }

private:
    int dfs(TreeNode *root)
    {
        int l = 0, r = 0;
        if (root->left)
            l = dfs(root->left);
        if (root->right)
            r = dfs(root->right);
        int sum = l + r + root->val;
        rets[sum] += 1;
        m = max(m, rets[sum]);
        return sum;
    }

private:
    unordered_map<int, int> rets;
    int m{};
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

void del(TreeNode *head)
{
    if (head->left)
        del(head->left);
    if (head->right)
        del(head->right);
    delete head;
}

int main(int argc, char const *argv[])
{
    MostFrequentSubtreeSum cls;
    TreeNode *head = new TreeNode(5);
    head->left = new TreeNode(2);
    head->right = new TreeNode(-3);
    //[2,-3,4]
    print(cls.findFrequentTreeSum(head));
    del(head);

    head = new TreeNode(5);
    head->left = new TreeNode(2);
    head->right = new TreeNode(-5);
    //[2]
    print(cls.findFrequentTreeSum(head));
    del(head);
    return 0;
}
