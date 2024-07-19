#include <iostream>
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

class DiameterOfBinaryTree
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        mlen = 0;
        dfs(root);
        return mlen;
    }

private:
    int dfs(TreeNode *n)
    {
        int l = 0, r = 0;
        if (n->left)
        {
            l = dfs(n->left) + 1;
        }
        if (n->right)
        {
            r = dfs(n->right) + 1;
        }
        mlen = max(mlen, l + r);
        return max(l, r);
    }

private:
    int mlen{};
};

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

int main()
{
    DiameterOfBinaryTree cls;
    TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->left->left = new TreeNode(4);
    head->left->right = new TreeNode(5);
    head->right = new TreeNode(3);
    cout << cls.diameterOfBinaryTree(head) << " -> 3" << endl;
    del(head);

    head = new TreeNode(1);
    head->left = new TreeNode(2);
    cout << cls.diameterOfBinaryTree(head) << " -> 1" << endl;
    del(head);
    return 0;
}
