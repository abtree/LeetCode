#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val{};
    TreeNode *left{};
    TreeNode *right{};
    TreeNode(int x) : val(x) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 94. 二叉树的中序遍历
class BinaryTreeInorderTraversal{
    /*
    给定一个二叉树的根节点 root ，返回它的 中序 遍历。
    */
public:
    vector<int> inorderTraversal(TreeNode* root) {
        //递归实现
        vector<int> ans;
        inorder(ans, root);
        return ans;
    }
private:
    void inorder(vector<int>& ans, TreeNode* root){
        if(!root)
            return;
        if(root->left)
            inorder(ans, root->left);
        ans.push_back(root->val);
        if(root->right)
            inorder(ans, root->right);
    }
public:
    vector<int> inorderTraversal2(TreeNode* root) {
        vector<int> ans;
        TreeNode* predecessor = nullptr;
        while(root){
            if(root->left){
                predecessor = root->left;
                while(predecessor->right && predecessor->right != root){
                    predecessor = predecessor->right;   //一直找的最右的节点 并让他指向root
                }
                if(!predecessor->right){
                    predecessor->right = root;
                    root = root->left;
                }else{
                    ans.push_back(root->val);
                    predecessor->right = nullptr;
                    root = root->right;
                }
            }else{
                ans.push_back(root->val);
                root=root->right;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    BinaryTreeInorderTraversal cls;
    TreeNode* head = new TreeNode(1);
    TreeNode* p = head;
    p->right = new TreeNode(2);
    p=p->right;
    p->left = new TreeNode(3);
    auto& ret = cls.inorderTraversal2(head);
    cout << "[";
    for(auto i : ret){
        cout << i << ",";
    }
    cout << "]" << endl;
    
    head = new TreeNode(1);
    auto& ret1 = cls.inorderTraversal2(head);
    cout << "[";
    for(auto i : ret1){
        cout << i << ",";
    }
    cout << "]" << endl;

    head = new TreeNode(1);
    p = head;
    p->left = new TreeNode(2);
    auto& ret2 = cls.inorderTraversal2(head);
    cout << "[";
    for(auto i : ret2){
        cout << i << ",";
    }
    cout << "]" << endl;

    head = new TreeNode(1);
    p = head;
    p->right = new TreeNode(2);
    auto& ret3 = cls.inorderTraversal2(head);
    cout << "[";
    for(auto i : ret3){
        cout << i << ",";
    }
    cout << "]" << endl;
    return 0;
}
