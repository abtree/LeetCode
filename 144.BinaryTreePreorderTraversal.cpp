#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//144. 二叉树的前序遍历
class BinaryTreePreorderTraversal
{
    /*给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
    */
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (!root)
            return ret;
        preorder(root, ret);
        return ret;
    }
private:
    void preorder(TreeNode* root, vector<int>& ret) {
        ret.push_back(root->val);
        if (root->left)
            preorder(root->left, ret);
        if (root->right)
            preorder(root->right, ret);
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
    void Print(vector<int>& ret) {
        cout << "[";
        for (int i : ret) {
            cout << i << ",";
        }
        cout << "]" << endl;
    }
};

int main(int argc, char const* argv[])
{
    BinaryTreePreorderTraversal cls;

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    cls.Print(cls.preorderTraversal(root));
    cls.DropTree(root);

    cls.Print(cls.preorderTraversal(nullptr));

    root = new TreeNode(1);
    root->right = new TreeNode(2);
    cls.Print(cls.preorderTraversal(root));
    cls.DropTree(root);

    root = new TreeNode(1);
    root->left = new TreeNode(2);
    cls.Print(cls.preorderTraversal(root));
    cls.DropTree(root);

    root = new TreeNode(1);
    cls.Print(cls.preorderTraversal(root));
    cls.DropTree(root);
    return 0;
}
