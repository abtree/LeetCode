#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// 337. 打家劫舍 III
class HouseRobber3 {
private:
    struct Sel {
        int Seled{};
        int NonSeled{};
    };
public:
    int rob(TreeNode* root) {
        auto sel = dfs(root);
        return max(sel.Seled, sel.NonSeled);
    }
private:
    Sel dfs(TreeNode* root) {
        if (!root) {
            return Sel{};
        }
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        Sel sel;
        sel.Seled = l.NonSeled + r.NonSeled + root->val;
        sel.NonSeled = max(l.Seled, l.NonSeled) + max(r.Seled, r.NonSeled);
        return sel;
    }
public:
    int rob1(TreeNode* root) {
        auto dfs = [](auto&& dfs, TreeNode* root) {
            if (!root) {
                return make_pair(0, 0);
            }
            //这段代码需要 c++20才能支持
            auto [l_nosel, l_sel] = dfs(dfs, root->left);
            auto [r_nosel, r_sel] = dfs(dfs, root->right);
            auto nsel = max(l_sel, l_nosel) + max(r_sel, r_nosel);
            auto sel = l_nosel + r_nosel + root->val;

            //// c++11 需要返回 pair
            // auto& lp = dfs(dfs, root->left);
            // auto& rp = dfs(dfs, root->right);
            // auto nsel = max(lp.first, lp.second) + max(rp.first, rp.second);
            // auto sel = lp.first + rp.first + root->val;
            return make_pair(nsel, sel);
        };
        auto [n, s] = dfs(dfs, root);
        return max(n, s);
        //auto& par = dfs(dfs, root);
        //return max(par.first, par.second);
    }
};

void Drop(TreeNode* head) {
    if (!head)
        return;
    Drop(head->left);
    Drop(head->right);
    delete head;
}

int main(int argc, char const* argv[]) {
    HouseRobber3 cls;

    TreeNode* head = new TreeNode(3);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->right = new TreeNode(3);
    head->right->right = new TreeNode(1);
    cout << cls.rob1(head) << " -> 7" << endl;
    Drop(head);

    head = new TreeNode(3);
    head->left = new TreeNode(4);
    head->right = new TreeNode(5);
    head->left->left = new TreeNode(1);
    head->left->right = new TreeNode(3);
    head->right->right = new TreeNode(1);
    cout << cls.rob1(head) << " -> 9" << endl;
    Drop(head);

    return 0;
}
