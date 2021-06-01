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

//129. 求根节点到叶节点数字之和
class SumRootToLeafNumbers
{
    /*给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。每条从根节点到叶节点的路径都代表一个数字：
    例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。计算从根节点到叶节点生成的 所有数字之和 。叶节点 是指没有子节点的节点。
    */
public:
    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;

        //深度优先遍历
        int sum = 0;
        ret = 0;
        sumnums(root, sum);
        return ret;
    }
private:
    void sumnums(TreeNode* root, int sum) {
        sum = sum * 10 + root->val;
        if (!root->left && !root->right) {
            ret += sum;
        }
        else {
            if (root->left)
                sumnums(root->left, sum);
            if (root->right)
                sumnums(root->right, sum);
        }
    }
private:
    int ret{};
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
    SumRootToLeafNumbers cls;

    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    cout << cls.sumNumbers(head) << " -> 25" << endl;
    cls.DropTree(head);

    head = new TreeNode(4);
    head->left = new TreeNode(9);
    head->right = new TreeNode(0);
    head->left->left = new TreeNode(5);
    head->left->right = new TreeNode(1);
    cout << cls.sumNumbers(head) << " -> 1026" << endl;
    cls.DropTree(head);
    
    return 0;
}
