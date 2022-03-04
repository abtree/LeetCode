#include <iostream>
using namespace std;

struct TreeNode {
    int val{};
    TreeNode* left{};
    TreeNode* right{};
    TreeNode() {}
    TreeNode(int x) : val(x) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class SumOfLeftLeaves {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        ret = 0;
        if (root)
            dfs(root, false);
        return ret;
    }
private:
    void dfs(TreeNode* root, bool left) {
        if (root->left == nullptr && root->right == nullptr) {
            if (left)
                ret += root->val;
            return;
        }
        if (root->left)
            dfs(root->left, true);
        if (root->right)
            dfs(root->right, false);
    }
private:
    int ret{};
};

void drop(TreeNode* root) {
    if (!root)
        return;
    drop(root->left);
    drop(root->right);
    delete root;
}

int main(int argc, char const* argv[]) {
    SumOfLeftLeaves cls;
    TreeNode* head = new TreeNode(3);
    head->left = new TreeNode(9);
    head->right = new TreeNode(20);
    head->right->left = new TreeNode(15);
    head->right->right = new TreeNode(7);
    cout << cls.sumOfLeftLeaves(head) << " -> 24" << endl;
    drop(head);
    return 0;
}
