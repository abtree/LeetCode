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

//114. 二叉树展开为链表
class FlattenBinaryTreeToLinkedList {
    /*
    给你二叉树的根结点 root ，请你将它展开为一个单链表：
    展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
    展开后的单链表应该与二叉树 先序遍历 顺序相同。
    */
public:
    void flatten(TreeNode* root) {
        if (!root)
            return;
        flat(root);
    }
private:
    TreeNode* flat(TreeNode* root) {
        TreeNode* right = root->right;
        if (root->left) {
            root->right = root->left;
            root->left = nullptr;
            root = flat(root->right);
        }
        if (right) {
            root->right = right;
            root = flat(root->right);
        }
        return root;
    }
public:
    void DropTree(TreeNode* root) {
        //删除树
        cout << root->val << ",";
        if (root->left)
            DropTree(root->left);
        if (root->right)
            DropTree(root->right);
        delete root;
    }
};

int main(int argc, char const* argv[])
{
    FlattenBinaryTreeToLinkedList cls;

    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(5);
    head->left->left = new TreeNode(3);
    head->left->right = new TreeNode(4);
    head->right->right = new TreeNode(6);
    cls.flatten(head);
    cout << "[";
    cls.DropTree(head);
    cout << "]" << endl;

    cls.flatten(nullptr);

    head = new TreeNode(0);
    cls.flatten(head);
    cout << "[";
    cls.DropTree(head);
    cout << "]" << endl;

    return 0;
}
