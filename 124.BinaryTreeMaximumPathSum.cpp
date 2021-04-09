#include <iostream>
#include <vector>
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

//124. 二叉树中的最大路径和
class BinaryTreeMaximumPathSum
{
    /*路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。路径和 是路径中各节点值的总和。给你一个二叉树的根节点 root ，返回其 最大路径和 。
    */
public:
    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;
        //递归
        int sum = 0;
        int half = maxpath(root, sum);
        return max(half, sum);
    }
private:
    //返回值表示 可以连接的最大值
    int maxpath(TreeNode* root, int& sum) {
        if (!root->left && !root->right) {
            sum = INT_MIN;
            return root->val;
        }
        int half = root->val;
        if (root->left && root->right) {
            int tl = 0; //不能与根节点相连的子树的最大值
            int hl = maxpath(root->left, tl);   //能与根节点相连的子树的最大值
            int tr = 0; //不能与根节点相连的子树的最大值
            int hr = maxpath(root->right, tr); //能与根节点相连的子树的最大值
            sum = max(tl, tr);
            sum = max(sum, hl + root->val + hr);
            sum = max(sum, hl);
            sum = max(sum, hr);
            half = max(half, hl + root->val);
            half = max(half, hr + root->val);
            return half;
        }
        //只有一个子节点的情况
        TreeNode* tr = nullptr;
        if (root->right)
            tr = root->right;
        else if (root->left)
            tr = root->left;
        int hl = maxpath(tr, sum);
        sum = max(sum, hl);
        half = max(half, half + hl);
        return half;
    }
public:
    int maxPathSum2(TreeNode* root) {
        //通过计算贡献值的方式递归
        ans = INT_MIN;
        maxpath2(root);
        return ans;
    }
private:
    int maxpath2(TreeNode* root) {
        if (!root)
            return 0;
        int left = max(maxpath2(root->left), 0);    //贡献值如果为负 不计如
        int right = max(maxpath2(root->right), 0);  //
        int price = root->val + left + right;
        ans = max(ans, price);
        return root->val + max(left, right);
    }
private:
    int ans{};
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
    BinaryTreeMaximumPathSum cls;

    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    cout << cls.maxPathSum2(head) << " -> 6" << endl;
    cls.DropTree(head);

    head = new TreeNode(-2);
    head->left = new TreeNode(1);
    cout << cls.maxPathSum2(head) << " -> 1" << endl;
    cls.DropTree(head);

    head = new TreeNode(-10);
    head->left = new TreeNode(9);
    head->right = new TreeNode(20);
    head->right->left = new TreeNode(15);
    head->right->right = new TreeNode(7);
    cout << cls.maxPathSum2(head) << " -> 42" << endl;
    cls.DropTree(head);

    head = new TreeNode(-3);
    cout << cls.maxPathSum2(head) << " -> -3" << endl;
    cls.DropTree(head);

    head = new TreeNode(5);
    head->left = new TreeNode(4);
    head->right = new TreeNode(8);
    head->left->left = new TreeNode(11);
    head->right->left = new TreeNode(13);
    head->right->right = new TreeNode(4);
    head->left->left->left = new TreeNode(7);
    head->left->left->right = new TreeNode(2);
    head->right->right->right = new TreeNode(1);
    cout << cls.maxPathSum2(head) << " -> 48" << endl;
    cls.DropTree(head);
    return 0;
}
