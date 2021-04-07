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

//105. 从前序与中序遍历序列构造二叉树
class ConstructBinaryTreeFromPreorderAndInorderTraversal {
    /*根据一棵树的前序遍历与中序遍历构造二叉树。
    注意:你可以假设树中没有重复的元素。
    */
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        /*先找到根节点，再递归根节点的左子树和右子树，在将左子树，右子树加到根节点上
        前序变量第一个元素就是根节点
        */
       //先构造kv表
       mKV.clear();
       int n = inorder.size();
       for(int i = 0;i < n;++i){
           mKV[inorder[i]] = i;
       }
       return build(preorder, inorder, 0, n-1, 0, n-1);
    }
private:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
        if(ps > pe)
            return nullptr;
        int pos = mKV[preorder[ps]];
        int len = pos - is;
        TreeNode* head = new TreeNode(preorder[ps]);
        head->left = build(preorder, inorder, ps+1, ps+len, is, pos-1);
        head->right = build(preorder, inorder, ps+len+1, pe, pos+1, ie);
        return head;
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
    ConstructBinaryTreeFromPreorderAndInorderTraversal cls;

    TreeNode* head = cls.buildTree(vector<int>{3,9,20,15,7}, vector<int>{9,3,15,20,7});
    cout << "[";
    cls.DropTree(head);
    cout << "]" << endl;
    return 0;
}
