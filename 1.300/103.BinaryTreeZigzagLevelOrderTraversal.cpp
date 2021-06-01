#include <iostream>
#include <queue>
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

//103. 二叉树的锯齿形层序遍历
class BinaryTreeZigzagLevelOrderTraversal {
    /*给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
    */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //广度优先遍历
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool left = true;
        while (!q.empty()) {
            int size = q.size();
            vector<int> tmp;    //先用临时vector存放结果
            for (int i = 0;i < size;++i) {
                TreeNode* node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            //根据需求 将结果加入
            if (left) {
                ans.emplace_back(tmp.begin(), tmp.end());
                left = false;
            }
            else {
                ans.emplace_back(tmp.rbegin(), tmp.rend());
                left = true;
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
    BinaryTreeZigzagLevelOrderTraversal cls;

    TreeNode* head = new TreeNode(3);
    head->left = new TreeNode(9);
    head->right = new TreeNode(20);
    head->right->left = new TreeNode(15);
    head->right->right = new TreeNode(7);
    auto& ret = cls.zigzagLevelOrder(head);
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
