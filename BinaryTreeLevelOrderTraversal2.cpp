#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//107. 二叉树的层序遍历 II
class BinaryTreeLevelOrderTravelsal2 {
    /*给定一个二叉树，返回其节点值自底向上的层序遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
    */
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        //与102一样 只是最后反转一下链表
        if (!root) {
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            ans.emplace_back(vector<int>{});
            for (int i = 0;i < size;++i) {
                TreeNode* cur = q.front();
                q.pop();
                ans.back().push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
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
    BinaryTreeLevelOrderTravelsal2 cls;

    TreeNode* head = new TreeNode(3);
    head->left = new TreeNode(9);
    head->right = new TreeNode(20);
    head->right->left = new TreeNode(15);
    head->right->right = new TreeNode(7);
    auto& ret = cls.levelOrderBottom(head);
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
    return 0;
}
