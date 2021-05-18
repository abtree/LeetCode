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

// 199. 二叉树的右视图
class BinaryTreeRightSideView
{
    /* 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
    */
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return vector<int>{};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ret;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i< size; ++i){
                TreeNode* cur = q.front();
                q.pop();
                if(i == 0){
                    ret.push_back(cur->val);
                }
                if(cur->right)
                    q.push(cur->right);
                if(cur->left)
                    q.push(cur->left);
            }
        }
        return ret;
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
    BinaryTreeRightSideView cls;
    TreeNode* head = new TreeNode(1);
    TreeNode* p = head;
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->left->right = new TreeNode(5);
    p->right->right = new TreeNode(4);
    auto& ret = cls.rightSideView(head);
    cout << "[";
    for(auto a : ret){
        cout << a << ",";
    }
    cout << "]" << endl;
    cls.DropTree(head);
    return 0;
}
