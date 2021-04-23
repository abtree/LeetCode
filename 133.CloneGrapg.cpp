#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

//133. 克隆图
class CloneGrapg
{
    /*给你无向 连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）。图中的每个节点都包含它的值 val（int） 和其邻居的列表（list[Node]）。
    测试用例格式：
    简单起见，每个节点的值都和它的索引相同。例如，第一个节点值为 1（val = 1），第二个节点值为 2（val = 2），以此类推。该图在测试用例中使用邻接列表表示。邻接列表 是用于表示有限图的无序列表的集合。每个列表都描述了图中节点的邻居集。给定节点将始终是图中的第一个节点（值为 1）。你必须将 给定节点的拷贝 作为对克隆图的引用返回。
    */
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        unordered_map<int, Node*> tmp;
        queue<Node*> q;
        q.push(node);
        Node* ret = new Node(node->val);
        tmp[node->val] = ret;
        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();
            for (auto n : cur->neighbors) {
                if (tmp.find(n->val) == tmp.end()) {
                    tmp[n->val] = new Node(n->val);
                    q.push(n);
                }
                tmp[cur->val]->neighbors.push_back(tmp[n->val]);
            }
        }
        return ret;
    }
public:
    void Drop(Node* node) {
        unordered_map<int, Node*> tmp;
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* c = q.front();
            q.pop();
            tmp[c->val] = c;
            for (auto n : c->neighbors) {
                if (tmp.find(n->val) == tmp.end()) {
                    q.push(n);
                }
            }
        }
        for (auto& it : tmp) {
            delete it.second;
        }
    }
};

int main(int argc, char const* argv[])
{
    CloneGrapg cls;

    Node* head = new Node(1);
    Node* h2 = new Node(2);
    Node* h3 = new Node(3);
    Node* h4 = new Node(4);
    head->neighbors.push_back(h2);
    head->neighbors.push_back(h4);
    h2->neighbors.push_back(head);
    h2->neighbors.push_back(h3);
    h3->neighbors.push_back(h2);
    h3->neighbors.push_back(h4);
    h4->neighbors.push_back(head);
    h4->neighbors.push_back(h3);
    Node* ret = cls.cloneGraph(head);
    cls.Drop(head);
    cls.Drop(ret);
    return 0;
}
