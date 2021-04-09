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

//112. 路径总和
class PathSum {
    /*给你二叉树的根节点 root 和一个表示目标和的整数 targetSum ，判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。叶子节点 是指没有子节点的节点。
    */
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        
        targetSum -= root->val;
        if(targetSum == 0 && !root->left && !root->right){
            return true;
        }
        return hasPathSum(root->right, targetSum) || hasPathSum(root->left, targetSum);
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
    PathSum cls;

    TreeNode* head = new TreeNode(5);
    head->left = new TreeNode(4);
    head->right = new TreeNode(8);
    head->left->left = new TreeNode(11);
    head->left->left->left = new TreeNode(7);
    head->left->left->right = new TreeNode(2);
    head->right->left = new TreeNode(13);
    head->right->right = new TreeNode(4);
    head->right->right->right = new TreeNode(1);
    cout << boolalpha << cls.hasPathSum(head, 22)<<" -> true" << endl;
    cls.DropTree(head);

    head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    cout << boolalpha << cls.hasPathSum(head, 5)<<" -> false" << endl;
    cls.DropTree(head);

    head = new TreeNode(1);
    head->left = new TreeNode(2);
    cout << boolalpha << cls.hasPathSum(head, 0)<<" -> false" << endl;
    cls.DropTree(head);

    head = new TreeNode(-2);
    head->right = new TreeNode(-3);
    cout << boolalpha << cls.hasPathSum(head, -5)<<" -> true" << endl;
    cls.DropTree(head);

    return 0;
}
