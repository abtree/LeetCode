#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class BSTIterator {
    /* 中序遍历入队法
    */
public:
    BSTIterator(TreeNode* root) {
        if (root)
            build(root);
    }

    int next() {
        auto* cur = que.front();
        que.pop();
        return cur->val;
    }

    bool hasNext() {
        return !que.empty();
    }
private:
    void build(TreeNode* root) {
        if (root->left)
            build(root->left);
        que.push(root);
        if (root->right)
            build(root->right);
    }
private:
    queue<TreeNode*> que;
};

class BSTIterator2 {
    /* 中序遍历入栈法 保留中序遍历的中间过程
    */
public:
    BSTIterator2(TreeNode* root) :cur(root) {

    }

    int next() {
        while (cur) {
            stk.push(cur);
            cur = cur->left;
        }
        cur = stk.top();
        stk.pop();
        int ret = cur->val;
        cur = cur->right;
        return ret;
    }

    bool hasNext() {
        return cur || !stk.empty();
    }
private:
    TreeNode* cur{};
    stack<TreeNode*> stk;
};

void DropTree(TreeNode* root) {
    //删除树
    if (root->left)
        DropTree(root->left);
    if (root->right)
        DropTree(root->right);
    delete root;
}

int main(int argc, char const* argv[])
{
    TreeNode* head = new TreeNode(7);
    TreeNode* p = head;
    p->left = new TreeNode(3);
    p->right = new TreeNode(15);
    p = p->right;
    p->left = new TreeNode(9);
    p->right = new TreeNode(20);
    BSTIterator2* it = new BSTIterator2(head);
    while (it->hasNext())
    {
        cout << it->next() << endl;
    }
    delete it;
    DropTree(head);
    return 0;
}
