#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int val{};
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

void del(Node *head)
{
    for (auto *c : head->children)
    {
        del(c);
    }
    delete head;
}

class MaximumDepthOfNAryTree
{
public:
    int maxDepth(Node *root)
    {
        if (!root)
        {
            return 0;
        }
        queue<Node *> qu;
        qu.push(root);
        int depth = 0;
        while (!qu.empty())
        {
            ++depth;
            int size = qu.size();
            for (int i = 0; i < size; ++i)
            {
                Node *cur = qu.front();
                qu.pop();
                for (auto *c : cur->children)
                {
                    qu.push(c);
                }
            }
        }
        return depth;
    }
};

int main()
{
    MaximumDepthOfNAryTree cls;
    Node *head = new Node(1);
    head->children.push_back(new Node(3, vector<Node *>{new Node(5), new Node(6)}));
    head->children.push_back(new Node(2));
    head->children.push_back(new Node(4));
    cout << cls.maxDepth(head) << " -> 3" << endl;
    del(head);

    head = new Node(1, vector<Node *>{
                           new Node(2),
                           new Node(3, vector<Node *>{
                                           new Node(6),
                                           new Node(7, vector<Node *>{new Node(11, vector<Node *>{new Node(14)})})}),
                           new Node(4, vector<Node *>{new Node(8, vector<Node *>{new Node(12)})}), new Node(5, vector<Node *>{new Node(9, vector<Node *>{new Node(13)}), new Node(10)})});
    cout << cls.maxDepth(head) << " -> 5" << endl;
    del(head);
    return 0;
}
