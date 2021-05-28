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

// 226. 翻转二叉树
class InvertBinaryTree
{
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return root;
        auto* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
public:
    void Drop(TreeNode* head) {
        if (!head)
            return;
        Drop(head->left);
        cout << head->val << ",";
        Drop(head->right);
    }
};

int main(int argc, char const* argv[])
{
    InvertBinaryTree cls;

    TreeNode* head = new TreeNode(4);
    head->left = new TreeNode(2);
    head->right = new TreeNode(7);
    head->left->left = new TreeNode(1);
    head->left->right = new TreeNode(3);
    head->right->left = new TreeNode(6);
    head->right->right = new TreeNode(9);
    head = cls.invertTree(head);
    cout << "[";
    cls.Drop(head);
    cout << "]" << endl;
    return 0;
}
