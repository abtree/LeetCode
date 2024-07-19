#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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

class FindLargestValueInEachTreeRow
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> rets;
        if (!root)
        {
            return rets;
        }
        queue<TreeNode *> qu;
        qu.push(root);
        while (!qu.empty())
        {
            int mx = INT_MIN;
            int size = qu.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *curr = qu.front();
                qu.pop();
                mx = max(mx, curr->val);
                if (curr->left)
                {
                    qu.push(curr->left);
                }
                if (curr->right)
                {
                    qu.push(curr->right);
                }
            }
            rets.push_back(mx);
        }
        return rets;
    }
};

void print(const vector<int> &ret)
{
    cout << "[";
    for (int x : ret)
    {
        cout << x << ",";
    }
    cout << "]" << endl;
}

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
    FindLargestValueInEachTreeRow cls;
    TreeNode *head = new TreeNode(1);
    head->left = new TreeNode(3);
    head->left->left = new TreeNode(5);
    head->left->right = new TreeNode(3);
    head->right = new TreeNode(2);
    head->right->right = new TreeNode(9);
    //[1,3,9]
    print(cls.largestValues(head));
    del(head);

    head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    //[1,3]
    print(cls.largestValues(head));
    del(head);
    return 0;
}
