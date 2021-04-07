#include <iostream>
#include <vector>
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

//102. 二叉树的层序遍历
class BinaryTreeLevelOrderTraversal {
    /* 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
    */
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        //递归实现层序遍历
        if (!root)
            return {};
        vector<vector<int>> ans;
        int lv = 0;
        ans.push_back(vector<int>{root->val});
        order(root->left, ans, lv + 1);
        order(root->right, ans, lv + 1);
        return ans;
    }
private:
    void order(TreeNode* root, vector<vector<int>>& ans, int lv) {
        if (!root)
            return;
        if (ans.size() <= lv)
            ans.push_back(vector<int>{});
        ans[lv].push_back(root->val);
        order(root->left, ans, lv + 1);
        order(root->right, ans, lv + 1);
    }
public:
    vector<vector<int>> levelOrder2(TreeNode* root) {
        //广度优先遍历
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();    //需要在这里获取当前队列长度（很重要）
            ans.push_back(vector<int>{});
            for (int i = 0; i < size;++i) {
                TreeNode* node = q.front();
                q.pop();
                ans.back().push_back(node->val);
                if (node->left)
                    q.push(node->left); //这里便是为什么需要用队列
                if (node->right)
                    q.push(node->right);
            }
        }
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
    BinaryTreeLevelOrderTraversal cls;

    TreeNode* head = new TreeNode(3);
    head->left = new TreeNode(9);
    head->right = new TreeNode(20);
    head->right->left = new TreeNode(15);
    head->right->right = new TreeNode(7);
    auto& ret = cls.levelOrder2(head);
    cout << "[";
    for (auto& it : ret) {
        cout << "[";
        for (auto i : it) {
            cout << i << ",";
        }
        cout << "]";
    }
    cout << "]" << endl;
    cls.DropTree(head);
    return 0;
}
