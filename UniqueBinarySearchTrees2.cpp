#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//95. 不同的二叉搜索树 II
class UniqueBinarySearchTree2{
    /*
    给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。
    */
public:
    vector<TreeNode*> generateTrees(int n) {
        //递归回溯 不断缩小范围
        //root节点为i时，left为start...i-1组成的数，right为i+1...end组成的树
        if(n <= 0)
            return vector<TreeNode*>{};
        return generate(1, n);
    }
private:
    vector<TreeNode*> generate(int start, int end){
        if(start > end){
            return {nullptr};   //这里不能返回空vector，后面遍历需要
        }
        vector<TreeNode*> ret;
        for(int i = start; i <= end; ++i){
            auto &left = generate(start, i-1);
            auto &right = generate(i+1, end);
            for(auto il : left){
                for(auto ir : right){
                    TreeNode* tn = new TreeNode(i); //这里必须在这里定义， 由于使用的指针,不能提到外面
                    tn->left = il;
                    tn->right = ir;
                    ret.emplace_back(tn);
                }
            }
        }
        return ret;
    }
public:
    void PrintTree(TreeNode* root){
        if(root){
            cout << root->val << ",";
            if(root->left)
                PrintTree(root->left);
            if(root->right)
                PrintTree(root->right);
        }
    }
};

int main(int argc, char const *argv[])
{
    UniqueBinarySearchTree2 cls;
    auto &ret = cls.generateTrees(3);
    for(auto it : ret){
        cout << "[";
        cls.PrintTree(it);
        cout << "]" << endl;
    }
    return 0;
}
