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

//101. 对称二叉树
class SymmetricTree {
    /*给定一个二叉树，检查它是否是镜像对称的。
    例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
    但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
    */
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return symmetric(root->left, root->right);
    }
private:
    bool symmetric(TreeNode* left, TreeNode* right) {
        if (!left && !right)
            return true;
        if (!left || !right)
            return false;
        if (left->val != right->val)
            return false;
        if (!symmetric(left->left, right->right))
            return false;
        if (!symmetric(left->right, right->left))
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
    SymmetricTree cls;

    TreeNode* head = new TreeNode(1);
    TreeNode* p = head;
    p->left = new TreeNode(2);
    p->right = new TreeNode(2);
    p->left->left = new TreeNode(3);
    p->left->right = new TreeNode(4);
    p->right->left = new TreeNode(4);
    p->right->right = new TreeNode(3);
    cout << boolalpha << cls.isSymmetric(head) << " -> true" << endl;
    cls.DropTree(head);

    head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(2);
    head->left->right = new TreeNode(3);
    head->right->right = new TreeNode(3);
    cout << boolalpha << cls.isSymmetric(head) << " -> false" << endl;
    cls.DropTree(head);

    return 0;
}
