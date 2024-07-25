#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val{};
    TreeNode *left{};
    TreeNode *right{};
    TreeNode(){}
    TreeNode(int x) : val(x) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class SubtreeOfAnotherTree
{
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root->val == subRoot->val){
            if (checksub(root, subRoot)){
                return true;
            }
        }
        if (root->left){
           if (isSubtree(root->left, subRoot)){
                return true;
           }
        }
        if (root->right){
           if (isSubtree(root->right, subRoot)){
                return true;
           }
        }
        return false;
    }
private:
    bool checksub(TreeNode* root, TreeNode* subRoot){
        if (root == nullptr && subRoot == nullptr){
            return true;
        }
        if (root == nullptr || subRoot == nullptr) {
            return false;
        }
        if (root->val != subRoot->val){
            return false;
        }
        if (checksub(root->left, subRoot->left) && checksub(root->right ,subRoot->right)){
            return true;
        }
        return false;
    }
};

void drop(TreeNode* root){
    if (root){
        drop(root->left);
        drop(root->right);
    }
    delete root;
}

int main(int argc, char const *argv[])
{
    SubtreeOfAnotherTree cls;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    cout << boolalpha << cls.isSubtree(root, root->left) << " -> true" << endl;

    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(4);
    root1->right = new TreeNode(5);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(2);
    root1->left->right->left = new TreeNode(0);
    cout << boolalpha << cls.isSubtree(root1, root->left) << " -> false" << endl;

    drop(root);
    drop(root1);
    return 0;
}
