#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val{};
    TreeNode *left{};
    TreeNode *right{};
    TreeNode() {}
    TreeNode(int x) : val(x) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindBottomLeftTreeValue
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
        int ans = 0;
        queue<TreeNode *> qu;
        qu.push(root);
        while (!qu.empty())
        {
            int len = qu.size();
            for (int i = 0; i < len; ++i)
            {
                TreeNode *cu = qu.front();
                qu.pop();
                if (i == 0)
                {
                    ans = cu->val;
                }
                if (cu->left)
                {
                    qu.push(cu->left);
                }
                if (cu->right)
                {
                    qu.push(cu->right);
                }
            }
        }
        return ans;
    }
};

void del(TreeNode *h)
{
    if (h->left)
    {
        del(h->left);
    }
    if (h->right)
    {
        del(h->right);
    }
    delete h;
}

int main(int argc, char const *argv[])
{
    FindBottomLeftTreeValue cls;
    TreeNode *head = new TreeNode(2);
    head->left = new TreeNode(1);
    head->right = new TreeNode(1);
    cout << cls.findBottomLeftValue(head) << " -> 1" << endl;
    del(head);

    head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->left->left = new TreeNode(4);
    head->right = new TreeNode(3);
    head->right->left = new TreeNode(5);
    head->right->left->left = new TreeNode(7);
    head->right->right = new TreeNode(6);
    cout << cls.findBottomLeftValue(head) << " -> 7" << endl;
    del(head);
    return 0;
}
