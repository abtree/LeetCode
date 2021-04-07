#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class ConstructBinaryTreeFromInorderAndPostorderTraversal {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        /*和前序与中序基本一样
        */
        mKV.clear();
        int n = inorder.size();
        for (int i = 0;i < n;++i) {
            mKV[inorder[i]] = i;
        }
        return build(inorder, postorder, 0, n - 1, 0, n - 1);
    }
private:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int ps, int pe, int is, int ie) {
        if (ps > pe)
            return nullptr;
        int pos = mKV[postorder[pe]];
        int len = pos - is;
        TreeNode* root = new TreeNode(postorder[pe]);
        root->left = build(inorder, postorder, ps, ps + len - 1, is, pos - 1);
        root->right = build(inorder, postorder, ps + len, pe - 1, pos + 1, ie);
        return root;
    }
private:
    unordered_map<int, int> mKV;    //中序遍历节点和对应的下标(因为没有重复节点，所以可以如此处理)
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
    ConstructBinaryTreeFromInorderAndPostorderTraversal cls;
    TreeNode* head = cls.buildTree(vector<int>{9, 3, 15, 20, 7}, vector<int>{9, 15, 7, 20, 3});
    cout << "[";
    cls.DropTree(head);
    cout << "]" << endl;
    return 0;
}
