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

class DeleteNodeInABst{
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        //root为空 不需要处理
        if (!root)
            return nullptr;
        //如果root的值大于key 则key在左子树
        if(root->val > key){
            root->left = deleteNode(root->left, key);
            return root;
        }
        //如果root的值小于key 则key在右子树
        if(root->val < key){
            root->right = deleteNode(root->right, key);
            return root;
        }
        //如果root的值等于key 需要删除该节点 此时可分4总情况
        if(root->val == key){
            //如果root为叶子节点 可直接删除
            if(!root->left && !root->right){
                delete root;
                return nullptr;
            }
            //如果root只有左节点 左节点替代root
            if(!root->right){
                auto *p = root->left;
                delete root;
                return p;
            }
            //同理 如果root只有右节点 右节点替代root
            if(!root->left){
                auto *p = root->right;
                delete root;
                return p;
            }
            //如果root既有左节点也有右节点 可用左节点的最大值或右节点的最小值替换root
            auto* p = root->right;
            while (p->left){    //一直找到右节点的最小值(该节点一定是叶子节点)
                p = p->left;
            }
            //替换root为p
            root->val = p->val;
            root->right = deleteNode(root->right, p->val);
            return root;
        }
        return root;
    }

};

void Delete(TreeNode* head) {
    if (head->left)
        Delete(head->left);
    if (head->right)
        Delete(head->right);
    cout << head->val << ",";
    delete head;
}

int main(int argc, char const* argv[]) {
    DeleteNodeInABst cls;
    TreeNode* head = new TreeNode(5);
    head->left = new TreeNode(3);
    head->right = new TreeNode(6);
    head->left->left = new TreeNode(2);
    head->left->right = new TreeNode(4);
    head->right->right = new TreeNode(7);
    head = cls.deleteNode(head, 3);
    Delete(head);
    head = new TreeNode(5);
    head->left = new TreeNode(2);
    head->left->right = new TreeNode(4);
    head->right = new TreeNode(6);
    head->right->right = new TreeNode(7);
    head = cls.deleteNode(head, 0);
    Delete(head);
    return 0;
}
