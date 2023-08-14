#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class NAryTreeLevelOrderTraversal{
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        if (!root)
            return ret;
        queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            ret.resize(ret.size() + 1);
            for (int i = 0; i < size;++i) {
                Node* c = q.front();
                q.pop();
                ret.back().push_back(c->val);
                for (auto* n : c->children) {
                    q.push(n);
                }
            }
        }
        
        return ret;
    }
};

void Delete(Node* head) {
    if (head->children.size() > 0) {
        for (auto* c : head->children) {
            Delete(c);
        }
    }
    delete head;
}

void Print(vector<vector<int>>& ret) {
    cout << "[";
    for (auto& cs : ret) {
        cout << "[";
        for (int c : cs) {
            cout << c << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;
}

int main(int argc, char const* argv[]) {
    NAryTreeLevelOrderTraversal cls;
    Node* head = new Node(1);
    head->children.push_back(new Node(3));
    head->children.push_back(new Node(2));
    head->children.push_back(new Node(4));
    head->children[0]->children.push_back(new Node(5));
    head->children[0]->children.push_back(new Node(6));
    auto& ret = cls.levelOrder(head);
    Print(ret);
    Delete(head);
    
    head = new Node(1);
    head->children.push_back(new Node(2));
    head->children.push_back(new Node(3));
    head->children.push_back(new Node(4));
    head->children.push_back(new Node(5));
    head->children[1]->children.push_back(new Node(6));
    head->children[1]->children.push_back(new Node(7));
    head->children[2]->children.push_back(new Node(8));
    head->children[3]->children.push_back(new Node(9));
    head->children[3]->children.push_back(new Node(10));
    head->children[1]->children[1]->children.push_back(new Node(11));
    head->children[2]->children[0]->children.push_back(new Node(12));
    head->children[3]->children[0]->children.push_back(new Node(13));
    head->children[1]->children[1]->children[0]->children.push_back(new Node(14));
    auto& ret1 = cls.levelOrder(head);
    Print(ret1);
    Delete(head);
    return 0;
}
