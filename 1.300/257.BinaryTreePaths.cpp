#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// 257. 二叉树的所有路径
class BinaryTreePaths {
    /* 给定一个二叉树，返回所有从根节点到叶子节点的路径。说明: 叶子节点是指没有子节点的节点。
    */
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> ret;
        ans.clear();
        dfs(root, ret);
        return ans;
    }
private:
    void dfs(TreeNode* root, vector<int>& ret) {
        if (!root)
            return;
        ret.push_back(root->val);
        if (!root->left && !root->right) {
            string str = "";
            for (int i = 0; i < ret.size() - 1; ++i) {
                str += to_string(ret[i]) + "->";
            }
            str += to_string(ret.back());
            ans.push_back(str);
        }
        else {
            dfs(root->left, ret);
            dfs(root->right, ret);
        }
        ret.pop_back();
    }
private:
    vector<string> ans;
};

void Drop(TreeNode* head) {
    if (head->left)
        Drop(head->left);
    if (head->right)
        Drop(head->right);
    delete head;
}

int main(int argc, char const* argv[]) {
    BinaryTreePaths cls;
    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->right = new TreeNode(5);
    const auto& ret = cls.binaryTreePaths(head);
    cout << "[";
    for (auto& it : ret) {
        cout << it.c_str() << ",";
    }
    cout << "]" << endl;
    Drop(head);
    return 0;
}
