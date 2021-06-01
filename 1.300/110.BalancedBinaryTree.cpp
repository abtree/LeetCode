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

//110. 平衡二叉树
class BalancedBinaryTree {
    /*给定一个二叉树，判断它是否是高度平衡的二叉树。
    本题中，一棵高度平衡二叉树定义为：一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
    */
public:
    bool isBalanced(TreeNode* root) {
        //从叶子到根 后序检查所有子树
        return height(root) >= 0;
    }
private:
    int height(TreeNode* root) {
        if (!root)
            return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        if (lh < 0 || rh < 0 || abs(lh - rh)>1)
            return -1;
        return max(lh, rh) + 1;
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
    BalancedBinaryTree cls;

    TreeNode* head = new TreeNode(3);
    head->left = new TreeNode(9);
    head->right = new TreeNode(20);
    head->right->left = new TreeNode(15);
    head->right->right = new TreeNode(7);
    cout << boolalpha << cls.isBalanced(head) << " -> true" << endl;
    cls.DropTree(head);

    head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(2);
    head->left->left = new TreeNode(3);
    head->left->right = new TreeNode(3);
    head->left->left->left = new TreeNode(4);
    head->left->left->right = new TreeNode(4);
    cout << boolalpha << cls.isBalanced(head) << " -> false" << endl;
    cls.DropTree(head);

    cout << boolalpha << cls.isBalanced(nullptr) << " -> true" << endl;
    return 0;
}
