#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 235. 二叉搜索树的最近公共祖先
class LowestCommonAncestorOfaBST {
    /* 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
    */
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;
        if (p->val > q->val) {
            TreeNode* t = p;
            p = q;
            q = t;
        }
        while (root) {
            if (root->val < p->val)
                root = root->right;
            else if (root->val > q->val)
                root = root->left;
            else
                return root;
        }
        return nullptr;
    }
};

void Drop(TreeNode* head) {
    if (!head)
        return;
    Drop(head->left);
    Drop(head->right);
    delete head;
}

int main(int argc, char const* argv[])
{
    LowestCommonAncestorOfaBST cls;

    TreeNode* head = new TreeNode(6);
    head->left = new TreeNode(2);
    head->right = new TreeNode(8);
    head->left->left = new TreeNode(0);
    head->left->right = new TreeNode(4);
    head->left->right->left = new TreeNode(3);
    head->left->right->right = new TreeNode(5);
    head->right->left = new TreeNode(7);
    head->right->right = new TreeNode(9);
    cout << cls.lowestCommonAncestor(head, head->left, head->right)->val << "->6" << endl;
    cout << cls.lowestCommonAncestor(head, head->left, head->left->right)->val << "->2" << endl;
    cout << cls.lowestCommonAncestor(head, head->left->right->left, head->left->right->right)->val << "->4" << endl;
    Drop(head);
    return 0;
}
