#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//236. 二叉树的最近公共祖先
class LowestCommonAncestorOfABinaryTree {
    /* 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
    */
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ret = nullptr;
        lowest(root, p, q);
        return ret;
    }
private:
    int lowest(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return 0;
        int cnt = 0;
        if (root == p)
            cnt += 1;
        else if (root == q)
            cnt += 2;
        if (cnt == 3) {
            ret = root;
            return cnt;
        }
        cnt += lowest(root->left, p, q);
        if (cnt == 3) {
            if (!ret)
                ret = root;
            return cnt;
        }
        cnt += lowest(root->right, p, q);
        if (cnt == 3 && !ret) {
            ret = root;
        }
        return cnt;
    }
private:
    TreeNode* ret{};
public:
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q || !root)
            return root;
        TreeNode* left = lowestCommonAncestor2(root->left, p, q);
        TreeNode* right = lowestCommonAncestor2(root->right, p, q);
        if (left && right)
            return root;    //说明一个在左边 一个在右边 (root就为所需点)
        return left ? left : right;
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
    LowestCommonAncestorOfABinaryTree cls;

    TreeNode* head = new TreeNode(3);
    head->left = new TreeNode(5);
    head->right = new TreeNode(1);
    head->left->left = new TreeNode(6);
    head->left->right = new TreeNode(2);
    head->left->right->left = new TreeNode(7);
    head->left->right->right = new TreeNode(4);
    head->right->left = new TreeNode(0);
    head->right->right = new TreeNode(8);
    cout << cls.lowestCommonAncestor2(head, head->left, head->right)->val << "->3" << endl;
    cout << cls.lowestCommonAncestor2(head, head->left, head->left->right->right)->val << "->5" << endl;
    Drop(head);
    return 0;
}
