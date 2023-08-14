#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val{};
    TreeNode* left{};
    TreeNode* right{};
    TreeNode() {}
    TreeNode(int x) : val(x) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class PathSum3
{
public:
    int pathSum(TreeNode* root, int targetSum) {
        ret = 0;
        if (!root)
            return ret;
        tar = targetSum;
        pointa(root);
        return ret;
    }
private:
    void pointa(TreeNode* root) {
        sum(root, 0);
        if (root->left) {
            pointa(root->left);
        }
        if (root->right) {
            pointa(root->right);
        }
    }
    void sum(TreeNode* root, long long x) {
        x += root->val;
        if (x == tar) {
            ++ret;
        }
        if (root->left) {
            sum(root->left, x);
        }
        if (root->right) {
            sum(root->right, x);
        }
        x -= root->val;
    }
private:
    int ret{};
    int tar{};
};

void clear(TreeNode* head) {
    if (!head)
        return;
    clear(head->left);
    clear(head->right);
    delete head;
}

class PathSum4 {
    //通过前缀树优化性能
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return 0;
        dp.clear();
        //这里特殊处理 如果sum == targetSum；sum - targetSum = 0 是满足条件的
        dp[0] = 1;
        return dfs(root, 0, targetSum);
    }
private:
    int dfs(TreeNode* root, long long sum, int targetSum) {
        int ret = 0;
        sum += root->val;
        /*这里要注意：
            sum - targetSum = x 等同于 sum - x = targetSum
            即：从当前节点出发，向root倒推，一定有一个区间之和为targetSum
            这个区间为从root出发，到当前节点 减去 从root出发，到x 的区间
        */
        if (dp.count(sum - targetSum)) {
            ret = dp[sum - targetSum];
        }
        dp[sum]++;
        if (root->left)
            ret += dfs(root->left, sum, targetSum);
        if (root->right)
            ret += dfs(root->right, sum, targetSum);
        dp[sum]--;
        return ret;
    }
private:
    unordered_map<long long, int> dp;
};

int main(int argc, char const* argv[])
{
    PathSum4 cls;
    TreeNode* head = new TreeNode(10);
    head->left = new TreeNode(5);
    head->right = new TreeNode(-3);
    head->left->left = new TreeNode(3);
    head->left->right = new TreeNode(2);
    head->left->left->left = new TreeNode(3);
    head->left->left->right = new TreeNode(-2);
    head->left->right->right = new TreeNode(1);
    head->right->right = new TreeNode(11);
    cout << cls.pathSum(head, 8) << " -> 3" << endl;
    clear(head);
    head = new TreeNode(5);
    head->left = new TreeNode(4);
    head->right = new TreeNode(8);
    head->left->left = new TreeNode(11);
    head->left->left->left = new TreeNode(7);
    head->left->left->right = new TreeNode(2);
    head->right->left = new TreeNode(13);
    head->right->right = new TreeNode(4);
    head->right->right->left = new TreeNode(5);
    head->right->right->right = new TreeNode(1);
    cout << cls.pathSum(head, 22) << " -> 3" << endl;
    clear(head);
    return 0;
}
