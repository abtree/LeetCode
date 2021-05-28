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

// 222. 完全二叉树的节点个数
class CountCompleteTreeNodes {
    /* 给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。
    */
public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int layer = 0;
        int point = 1;
        bool ret = false;
        while (q.size()) {
            int n = q.size();
            ++layer;
            point += 1 << layer;
            for (int i = 0; i < n; ++i) {
                TreeNode* c = q.front();
                q.pop();
                if (c->right) {
                    if (ret)
                        return point;
                    q.push(c->right);
                }
                else {
                    point -= 1;
                    ret = true;
                }
                if (c->left) {
                    if (ret)
                        return point;
                    q.push(c->left);
                }
                else {
                    point -= 1;
                }
            }
        }
        return point;
    }
public:
    int countNodes2(TreeNode* root) {
        //2分查找法
        if (!root)
            return 0;
        //找到树的最大层数
        int lv = 0;
        TreeNode* node = root;
        while (node->left) {
            ++lv;
            node = node->left;
        }
        int low = 1 << lv;   //最小节点数(其实应该大于这个值)
        int high = (1 << (lv + 1)) - 1; //最大节点数
        while (low < high) {    //2分查找
            int mid = (high - low + 1) / 2 + low;
            if (exists(root, lv, mid)) {
                low = mid;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
private:
    bool exists(TreeNode* root, int lv, int mid) {
        int bits = 1 << (lv - 1);
        while (root && bits > 0) {
            if (bits & mid) {
                root = root->right;
            }
            else {
                root = root->left;
            }
            bits >>= 1;
        }
        return root != nullptr;
    }
public:
    void drop(TreeNode* root) {
        if (root->right)
            drop(root->right);
        if (root->left)
            drop(root->left);
        delete root;
    }
};

int main(int argc, char const* argv[]) {
    CountCompleteTreeNodes cls;
    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->left = new TreeNode(4);
    head->left->right = new TreeNode(5);
    head->right->left = new TreeNode(6);
    cout << cls.countNodes2(head) << " -> 6" << endl;
    cls.drop(head);

    cout << cls.countNodes2(nullptr) << " -> 0" << endl;

    head = new TreeNode(1);
    cout << cls.countNodes2(head) << " -> 1" << endl;
    cls.drop(head);

    return 0;
}
