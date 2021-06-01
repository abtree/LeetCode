#include <iostream>
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

//108. 将有序数组转换为二叉搜索树
class ConvertSortedArrayToBinarySearchTree {
    /*给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。
    高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。
    */
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //递归构造树
        return convert(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* convert(vector<int>& nums, int start, int end) {
        if (start > end)
            return nullptr;
        int mid = (end - start) / 2 + start;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = convert(nums, start, mid - 1);
        node->right = convert(nums, mid + 1, end);
        return node;
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
    ConvertSortedArrayToBinarySearchTree cls;
    TreeNode* head = cls.sortedArrayToBST(vector<int>{-10,-3,0,5,9});
    cout << "[";
    cls.DropTree(head);
    cout << "]" << endl;

    head = cls.sortedArrayToBST(vector<int>{1,3});
    cout << "[";
    cls.DropTree(head);
    cout << "]" << endl;
    return 0;
}
