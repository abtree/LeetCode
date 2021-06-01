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

// 230. 二叉搜索树中第K小的元素
class KthSmallestElementInABst {
    /* 给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。
    */
public:
    int kthSmallest(TreeNode* root, int k) {
        kth = k;
        bsf(root, 0);
        return ret;
    }
private:
    int bsf(TreeNode* root, int cnt) {
        if (!root)
            return cnt;
        cnt = bsf(root->left, cnt);
        if (cnt > kth)
            return cnt;
        ++cnt;
        if (cnt == kth) {
            ret = root->val;
            return cnt + 1;
        }
        if (cnt > kth)
            return cnt;
        return bsf(root->right, cnt);
    }
private:
    int kth{};
    int ret{};
public:
    void Drop(TreeNode* head) {
        if (head->left)
            Drop(head->left);
        if (head->right)
            Drop(head->right);
        delete head;
    }
};

int main(int argc, char const* argv[]) {
    KthSmallestElementInABst cls;

    TreeNode* head = new TreeNode(3);
    head->left = new TreeNode(1);
    head->left->right = new TreeNode(2);
    head->right = new TreeNode(4);
    cout << cls.kthSmallest(head, 1) << "->1" << endl;
    cls.Drop(head);

    head = new TreeNode(5);
    head->left = new TreeNode(3);
    head->right = new TreeNode(6);
    head->left->left = new TreeNode(2);
    head->left->right = new TreeNode(4);
    head->left->left->left = new TreeNode(1);
    cout << cls.kthSmallest(head, 3) << "->3" << endl;
    cls.Drop(head);
    return 0;
}
