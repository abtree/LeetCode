#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//297. 二叉树的序列化与反序列化
class Codec {
    /*  序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
    请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
    */
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        dfs(root, str);
        return str;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int cur = 0;
        return build(data, cur);
    }
private:
    void dfs(TreeNode* root, string& str) {
        if (!root) {
            str += 'e';
            return;
        }
        str += 'a';
        unsigned int v = root->val;
        for (int i = 0;i < 4;++i) {
            str += char(v & bit);
            v >>= 8;
        }
        dfs(root->left, str);
        dfs(root->right, str);
    }
    TreeNode* build(string& str, int& cur) {
        if (cur >= str.size()) {
            return nullptr;
        }
        if (str[cur] == 'e') {
            ++cur;
            return nullptr;
        }
        int val = 0;
        for (int i = cur + 4;i > cur;--i) {
            val = val << 8 | str[i];
        }
        TreeNode* head = new TreeNode(val);
        cur += 5;
        head->left = build(str, cur);
        head->right = build(str, cur);
        return head;
    }
private:
    int bit{ (1 << 9) - 1 };
};

class Codec1 {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        dfs(root, str);
        return str;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int cur = 0;
        return build(data, cur);
    }
private:
    void dfs(TreeNode* root, string& str) {
        if (!root) {
            str += char(0);
            return;
        }
        string add = to_string(root->val);
        str += char(add.size());
        str += add;
        dfs(root->left, str);
        dfs(root->right, str);
    }
    TreeNode* build(string& str, int& cur) {
        if (cur >= str.size()) {
            return nullptr;
        }
        if (str[cur] == 0) {
            ++cur;
            return nullptr;
        }
        int val = atoi(str.substr(cur + 1, str[cur]).c_str());
        TreeNode* head = new TreeNode(val);
        cur += str[cur] + 1;
        head->left = build(str, cur);
        head->right = build(str, cur);
        return head;
    }
};

void Drop(TreeNode* head) {
    if (head->left)
        Drop(head->left);
    if (head->right)
        Drop(head->right);
    delete head;
}

int main(int argc, char const* argv[]) {
    Codec1 cls;
    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->right->left = new TreeNode(4);
    head->right->right = new TreeNode(5);
    string str = cls.serialize(head);
    Drop(head);
    head = cls.deserialize(str);
    Drop(head);

    head = new TreeNode(4);
    head->left = new TreeNode(-7);
    head->left->left = new TreeNode(-3);
    head->left->right = new TreeNode(-9);
    head->left->right->left = new TreeNode(-3);
    head->left->right->left->left = new TreeNode(9);
    head->left->right->left->left->left = new TreeNode(-7);
    head->left->right->left->left->left->left = new TreeNode(-4);
    head->left->right->left->left->left->left->right = new TreeNode(6);
    head->left->right->left->left->left->left->right->right = new TreeNode(-6);
    head->left->right->left->left->left->left->right->right->left = new TreeNode(-6);
    head->left->right->left->left->left->right = new TreeNode(0);
    head->left->right->left->left->left->right->left = new TreeNode(6);
    head->left->right->left->left->left->right->left->left = new TreeNode(5);
    head->left->right->left->left->left->right->left->left->right = new TreeNode(9);
    head->left->right->left->left->left->right->left->right = new TreeNode(-1);
    head->left->right->left->left->left->right->left->right->left = new TreeNode(-4);
    head->left->right->left->left->right = new TreeNode(-2);
    str = cls.serialize(head);
    Drop(head);
    head = cls.deserialize(str);
    Drop(head);
    return 0;
}
