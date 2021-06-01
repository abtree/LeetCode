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

//98. 验证二叉搜索树
class ValidateBinarySearchTree {
    /*
    给定一个二叉树，判断其是否是一个有效的二叉搜索树。假设一个二叉搜索树具有如下特征：
    节点的左子树只包含小于当前节点的数。
    节点的右子树只包含大于当前节点的数。
    所有左子树和右子树自身必须也是二叉搜索树。
    */
public:
    bool isValidBST(TreeNode* root) {
        //遍历比对法
        return valid(root, LLONG_MIN, LLONG_MAX);
    }
private:
    bool valid(TreeNode* root, long long min, long long max) {
        if (root->left) {
            if (root->left->val >= root->val)
                return false;
            if (root->left->val <= min)
                return false;
            if (!valid(root->left, min, root->val))
                return false;
        }
        if (root->right) {
            if (root->right->val <= root->val)
                return false;
            if (root->right->val >= max)
                return false;
            if (!valid(root->right, root->val, max))
                return false;
        }
        return true;
    }
public:
    bool isValidBST2(TreeNode* root){
        //中序遍历法：中序遍历得到的结果一定是升序的
        stack<TreeNode*> stack;
        long long inorder = (long long)INT_MIN - 1;

        while (!stack.empty() || root != nullptr) {
            while (root != nullptr) {
                stack.push(root);
                root = root -> left;
            }
            root = stack.top();
            stack.pop();
            // 如果中序遍历得到的节点的值小于等于前一个 inorder，说明不是二叉搜索树
            if (root -> val <= inorder) {
                return false;
            }
            inorder = root -> val;
            root = root -> right;
        }
        return true;
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
    ValidateBinarySearchTree cls;

    TreeNode* head = new TreeNode(2);
    TreeNode* p = head;
    p->left = new TreeNode(1);
    p->right = new TreeNode(3);
    cout << boolalpha << cls.isValidBST(head) << " -> true" << endl;
    cls.DropTree(head);

    head = new TreeNode(5);
    p = head;
    p->left = new TreeNode(1);
    p->right = new TreeNode(4);
    p = p->right;
    p->left = new TreeNode(3);
    p->right = new TreeNode(6);
    cout << boolalpha << cls.isValidBST(head) << " -> false" << endl;
    cls.DropTree(head);

    head = new TreeNode(5);
    p = head;
    p->left = new TreeNode(4);
    p->right = new TreeNode(6);
    p = p->right;
    p->left = new TreeNode(3);
    p->right = new TreeNode(7);
    cout << boolalpha << cls.isValidBST(head) << " -> false" << endl;
    cls.DropTree(head);

    head = new TreeNode(-2147483648);
    p = head;
    p->right = new TreeNode(2147483647);
    cout << boolalpha << cls.isValidBST(head) << " -> true" << endl;
    cls.DropTree(head);

    head = new TreeNode(-2147483648);
    p = head;
    p->right = new TreeNode(2147483647);
    p=p->right;
    p->left = new TreeNode(-2147483648);
    cout << boolalpha << cls.isValidBST(head) << " -> false" << endl;
    cls.DropTree(head);

    return 0;
}
