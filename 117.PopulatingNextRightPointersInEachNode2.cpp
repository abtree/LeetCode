#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int val{};
    Node* left{};
    Node* right{};
    Node* next{};
    Node() {}
    Node(int _val) : val(_val) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

//117. 填充每个节点的下一个右侧节点指针 II
class PopulatingNextRightPointersInEachNode {
    /*给定一个二叉树。填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。初始状态下，所有 next 指针都被设置为 NULL。

    进阶：你只能使用常量级额外空间。使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
    */
public:
    Node* connect(Node* root) {
        //层序遍历
        if (!root)
            return root;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            Node* last = nullptr;
            for (int i = 0; i < size;++i) {
                Node* cur = q.front();
                q.pop();
                if (last)
                    last->next = cur;
                last = cur;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return root;
    }
public:
    Node* connect2(Node* root) {
        /*使用next指针， 因为建立next指针后 上层就可以通过next指针访问所有下层节点
        而跟节点的next指针可以直接建立，所以可以由上到下建立每一层的next指针
        */
        Node* leftmost = root;  //记录下一层的第一个节点
        while (leftmost) {
            Node* cur = leftmost; //记录上一层的当前节点
            leftmost = nullptr;
            Node* last = nullptr; //记录当前层的上一个节点
            while (cur) {
                if (!last) {
                    if (cur->left) {
                        last = cur->left;
                        leftmost = last;
                    }
                    else if (cur->right) {
                        last = cur->right;
                        leftmost = last;
                    }
                }
                if (cur->left && cur->left != last) {
                    last->next = cur->left;
                    last = last->next;
                }
                if (cur->right && cur->right != last) {
                    last->next = cur->right;
                    last = last->next;
                }
                cur = cur->next;
            }
        }
        return root;
    }
public:
    void DropTree(Node* root) {
        //删除树
        cout << root->val;
        if (root->next)
            cout << "->" << root->next->val;
        else
            cout << "->null";
        cout << ";";
        if (root->left)
            DropTree(root->left);
        if (root->right)
            DropTree(root->right);
        delete root;
    }
};

int main(int argc, char const* argv[])
{
    PopulatingNextRightPointersInEachNode cls;

    Node* head = new Node(1);
    head->left = new Node(2);
    head->left->left = new Node(4);
    head->left->right = new Node(5);
    head->right = new Node(3);
    head->right->right = new Node(7);
    head = cls.connect2(head);
    cout << "[";
    cls.DropTree(head);
    cout << "]" << endl;
    return 0;
}
