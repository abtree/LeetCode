#include <iostream>
#include <cmath>
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

class BinaryTreeTilt
{
public:
    int findTilt(TreeNode *root)
    {
        ret = 0;
        dfs(root);
        return ret;
    }

private:
    int dfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int l = dfs(root->left);
        int r = dfs(root->right);
        ret += abs(l - r);
        return l + r + root->val;
    }
    int ret{};
};

void del(TreeNode *head)
{
    if (head->left)
        del(head->left);
    if (head->right)
        del(head->right);
    delete head;
}

int main()
{
    BinaryTreeTilt cls;
    TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    cout << cls.findTilt(head) << " -> 1" << endl;
    del(head);

    head = new TreeNode(4);
    head->left = new TreeNode(2);
    head->right = new TreeNode(9);
    head->left->left = new TreeNode(3);
    head->left->right = new TreeNode(5);
    head->right->right = new TreeNode(7);
    cout << cls.findTilt(head) << " -> 15" << endl;
    del(head);

    head = new TreeNode(21);
    head->left = new TreeNode(7);
    head->right = new TreeNode(14);
    head->left->left = new TreeNode(1);
    head->left->right = new TreeNode(1);
    head->right->left = new TreeNode(2);
    head->right->right = new TreeNode(2);
    head->left->left->left = new TreeNode(3);
    head->left->left->right = new TreeNode(3);
    cout << cls.findTilt(head) << " -> 9" << endl;
    del(head);
    return 0;
}
