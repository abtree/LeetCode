#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class MinimumDepthOfBinaryTree {
public:
    int minDepth(TreeNode* root) {
        return depth(root, 0);
    }
private:
    int depth(TreeNode* root, int lv) {
        if (!root)
            return lv;

        if (!root->left)
            return depth(root->right, lv + 1);
        if (!root->right)
            return depth(root->left, lv + 1);
        return std::min(depth(root->left, lv + 1), depth(root->right, lv + 1));
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
    MinimumDepthOfBinaryTree cls;

    TreeNode* head = new TreeNode(3);
    head->left = new TreeNode(9);
    head->right = new TreeNode(20);
    head->right->left = new TreeNode(15);
    head->right->right = new TreeNode(7);
    cout << cls.minDepth(head) << " -> 2" << endl;
    cls.DropTree(head);

    head = new TreeNode(2);
    head->right = new TreeNode(3);
    head->right->right = new TreeNode(4);
    head->right->right->right = new TreeNode(5);
    head->right->right->right->right = new TreeNode(6);
    cout << cls.minDepth(head) << " -> 5" << endl;
    cls.DropTree(head);
    return 0;
}
