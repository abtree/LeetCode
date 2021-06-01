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

//145. 二叉树的后序遍历
class BinaryTreePostorderTraversal
{
    /* 给定一个二叉树，返回它的 后序 遍历。 */
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (!root)
            return ret;
        postorder(root, ret);
        return ret;
    }
private:
    void postorder(TreeNode* root, vector<int>& ret) {
        if (root->left)
            postorder(root->left, ret);
        if (root->right)
            postorder(root->right, ret);
        ret.push_back(root->val);
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
    BinaryTreePostorderTraversal cls;

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    cls.Print(cls.postorderTraversal(root));
    cls.DropTree(root);
    return 0;
}
