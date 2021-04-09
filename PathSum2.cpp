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

//113. 路径总和 II
class PathSum2 {
    /*给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。叶子节点 是指没有子节点的节点。
    */
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        mRet.clear();
        if (!root)
            return mRet;

        vector<int> paths;
        path(root, targetSum, paths);
        return mRet;
    }
private:
    void path(TreeNode* root, int targetSum, vector<int>& paths) {
        paths.push_back(root->val);
        targetSum -= root->val;
        if (targetSum == 0 && !root->left && !root->right) {
            mRet.emplace_back(paths.begin(), paths.end());
            paths.pop_back();
            return;
        }
        if (root->left) path(root->left, targetSum, paths);
        if (root->right) path(root->right, targetSum, paths);
        paths.pop_back();
    }
private:
    vector<vector<int>> mRet;
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
    PathSum2 cls;

    TreeNode* head = new TreeNode(5);
    head->left = new TreeNode(4);
    head->right = new TreeNode(8);
    head->left->left = new TreeNode(11);
    head->left->left->left = new TreeNode(7);
    head->left->left->right = new TreeNode(2);
    head->right->left = new TreeNode(13);
    head->right->right = new TreeNode(4);
    head->right->right->left = new TreeNode(5);
    head->right->right->right = new TreeNode(1);
    auto& ret = cls.pathSum(head, 22);
    cout << "[";
    for (auto& it : ret) {
        cout << "[";
        for (auto i : it) {
            cout << i << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;
    cls.DropTree(head);

    head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    auto& ret1 = cls.pathSum(head, 5);
    cout << "[";
    for (auto& it : ret1) {
        cout << "[";
        for (auto i : it) {
            cout << i << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;
    cls.DropTree(head);

    return 0;
}
