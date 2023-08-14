#include <iostream>
using namespace std;

class Node {
public:
    int val{};
    Node* prev{};
    Node* next{};
    Node* child{};
    Node(int i) :val(i) {}
};

class FlattenAMultilevelDoublyLinkedList{
public:
    Node* flatten(Node* head) {
        ret = head;
        dfs(head);
        return ret;
    }
private:
    Node* dfs(Node* head) {
        while (head) {
            if (head->child == nullptr) {
                if (head->next)
                    head = head->next;
                else
                    return head;
            }
            else {
                Node* next = head->next;
                head->next = head->child;
                head->child->prev = head;
                head->child = nullptr;
                head = dfs(head->next);
                if (next) {
                    head->next = next;
                    next->prev = head;
                    head = head->next;
                }
            }
        }
        return head;
    }
private:
    Node* ret;
};

void print(Node* head) {
    cout << "[";
    while (head)
    {
        Node* c = head;
        head = head->next;
        cout << c->val << ",";
        delete c;
    }
    cout << "]" << endl; 
}

int main(int argc, char const* argv[]) {
    FlattenAMultilevelDoublyLinkedList cls;
    Node* head = new Node(1);
    Node* h = head;
    head->next = new Node(2);
    head->next->prev = head;
    head = head->next;
    head->next = new Node(3);
    head->next->prev = head;
    head = head->next;
    head->next = new Node(4);
    head->next->prev = head;
    head = head->next;
    head->next = new Node(5);
    head->next->prev = head;
    head = head->next;
    head->next = new Node(6);
    head->next->prev = head;
    head = h->next->next;
    head->child = new Node(7);
    head = head->child;
    head->next = new Node(8);
    head->next->prev = head;
    head = head->next;
    head->next = new Node(9);
    head->next->prev = head;
    head = head->next;
    head->next = new Node(10);
    head->next->prev = head;
    head = h->next->next->child->next;
    head->child = new Node(11);
    head = head->child;
    head->next = new Node(12);
    head->next->prev = head; 
    Node* r = cls.flatten(h);
    print(r);
    return 0;
}
