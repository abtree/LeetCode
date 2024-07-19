#include <iostream>
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

class ConvertBstToGreaterTree
{
public:
    TreeNode *convertBST(TreeNode *root)
    {
        if (!root)
        {
            return root;
        }
        num = 0;
        dfs(root);
        return root;
    }

private:
    void dfs(TreeNode *node)
    {
        if (node->right)
        {
            dfs(node->right);
        }
        num += node->val;
        node->val = num;
        if (node->left)
        {
            dfs(node->left);
        }
    }

private:
    int num{};

public:
    TreeNode *convertBST1(TreeNode *root)
    {
        int sum = 0;
        TreeNode *node = root;
        while (node != nullptr)
        {
            if (node->right == nullptr)
            {
                sum += node->val;
                node->val = sum;
                node = node->left;
            }
            else
            {
                TreeNode *succ = getSuccessor(node);
                if (succ->left == nullptr)
                {
                    // 建立新的临时路径
                    succ->left = node;
                    node = node->right;
                }
                else
                {
                    // 删除新建的临时路径
                    succ->left = nullptr;
                    sum += node->val;
                    node->val = sum;
                    node = node->left;
                }
            }
        }
        return root;
    }

private:
    TreeNode *getSuccessor(TreeNode *node)
    {
        TreeNode *succ = node->right;
        while (succ->left != nullptr && succ->left != node)
        {
            succ = succ->left;
        }

        return succ;
    }
};

void printAndDel(TreeNode *node)
{
    if (node->left)
    {
        printAndDel(node->left);
    }
    cout << node->val << ",";
    if (node->right)
    {
        printAndDel(node->right);
    }
    delete node;
}

int main(int argc, char const *argv[])
{
    TreeNode *head = new TreeNode(4);
    head->left = new TreeNode(1);
    head->left->left = new TreeNode(0);
    head->left->right = new TreeNode(2);
    head->left->right->right = new TreeNode(3);
    head->right = new TreeNode(6);
    head->right->left = new TreeNode(5);
    head->right->right = new TreeNode(7);
    head->right->right->right = new TreeNode(8);
    ConvertBstToGreaterTree cls;
    printAndDel(cls.convertBST1(head));
    cout << endl;

    head = new TreeNode(0);
    head->right = new TreeNode(1);
    printAndDel(cls.convertBST(head));
    cout << endl;

    head = new TreeNode(1);
    head->left = new TreeNode(0);
    head->right = new TreeNode(2);
    printAndDel(cls.convertBST(head));
    cout << endl;

    head = new TreeNode(3);
    head->left = new TreeNode(2);
    head->left->left = new TreeNode(1);
    head->right = new TreeNode(4);
    printAndDel(cls.convertBST(head));
    cout << endl;

    return 0;
}
