#include <iostream>
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

//99. 恢复二叉搜索树
class RecoverBinarySearchTree {
    /*
    给你二叉搜索树的根节点 root ，该树中的两个节点被错误地交换。请在不改变其结构的情况下，恢复这棵树。
    进阶：使用 O(n) 空间复杂度的解法很容易实现。你能想出一个只使用常数空间的解决方案吗？
    */
public:
    void recoverTree(TreeNode* root) {
        /* 此题需要充分利用搜索树中序遍历后得到递增数列的特性
        */
       stack<TreeNode*> stk;
       TreeNode* x = nullptr,*y = nullptr,*p = nullptr;
       while(!stk.empty() || root != nullptr){
            while(root){
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if(p && root->val < p->val){
                y = root;
                if(!x){
                    x = p;
                }
            }
            p = root;
            root = root->right;
       }
       std::swap(x->val, y->val);
    }
public:
    void DropTree(TreeNode* root) {
        //删除树
        if (root->left)
            DropTree(root->left);
        if (root->right)
            DropTree(root->right);
        cout << root->val << ",";
        delete root;
    }
};

int main(int argc, char const* argv[])
{
    RecoverBinarySearchTree cls;

    TreeNode* head = new TreeNode(1);
    TreeNode* p = head;
    p->left = new TreeNode(3);
    p= p->left;
    p->right = new TreeNode(2);
    cls.recoverTree(head);
    cout << "[";
    cls.DropTree(head);
    cout << "]" << endl;

    head = new TreeNode(3);
    p = head;
    p->left = new TreeNode(1);
    p->right = new TreeNode(4);
    p= p->right;
    p->left = new TreeNode(2);
    cls.recoverTree(head);
    cout << "[";
    cls.DropTree(head);
    cout << "]" << endl;

    return 0;
}
