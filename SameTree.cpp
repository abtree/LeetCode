#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//100. 相同的树
class SameTree {
    /*
    给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
    如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
    */
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        if (p->val != q->val)
            return false;

        if (!isSameTree(p->left, q->left))
            return false;

        if (!isSameTree(p->right, q->right))
            return false;

        return true;
    }
public:
    void DropTree(TreeNode* root) {
        //删除树
        if (root->left)
            DropTree(root->left);
        if (root->right)
            DropTree(root->right);
        delete root;
    }
};

int main(int argc, char const* argv[])
{
    SameTree cls;

    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);
    cout << boolalpha << cls.isSameTree(p, q) << " -> true" << endl;
    cls.DropTree(p);
    cls.DropTree(q);

    p = new TreeNode(1);
    p->left = new TreeNode(2);
    q = new TreeNode(1);
    q->right = new TreeNode(2);
    cout << boolalpha << cls.isSameTree(p, q) << " -> false" << endl;
    cls.DropTree(p);
    cls.DropTree(q);

    p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(1);
    q = new TreeNode(1);
    q->left = new TreeNode(1);
    q->right = new TreeNode(2);
    cout << boolalpha << cls.isSameTree(p, q) << " -> false" << endl;
    cls.DropTree(p);
    cls.DropTree(q);

    return 0;
}
