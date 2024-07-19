#include <iostream>
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

class MinimumAbsoluteDifferenceInBst
{
public:
    int getMinimumDifference(TreeNode *root)
    {
        ans = INT_MAX;
        last = -10e5;
        dfs(root);
        return ans;
    }

private:
    void dfs(TreeNode *root)
    {
        if (root->left)
        {
            dfs(root->left);
        }
        ans = min(ans, root->val - last);
        last = root->val;
        if (root->right)
        {
            dfs(root->right);
        }
    }

private:
    int ans{};
    int last{};
};

void del(TreeNode *root)
{
    if (root->left)
        del(root->left);
    if (root->right)
        del(root->right);
    delete root;
}

int main()
{
    MinimumAbsoluteDifferenceInBst cls;
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(6);
    cout << cls.getMinimumDifference(root) << " -> 1" << endl;
    del(root);

    root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(48);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(49);
    cout << cls.getMinimumDifference(root) << " -> 1" << endl;
    del(root);
    return 0;
}
