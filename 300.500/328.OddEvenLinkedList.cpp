#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class OddEvenLinkedList {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head)
            return head;
        ListNode* even = new ListNode();
        ListNode* p = head;
        ListNode* q = even;
        while (p->next) {
            q->next = p->next;
            q = q->next;
            p->next = p->next->next;
            q->next = nullptr;

            if (p->next == nullptr) {
                p->next = even->next;
                delete even;
                return head;
            }
            p = p->next;
        }
        p->next = even->next;
        delete even;
        return head;
    }
};

void Drop(ListNode* head) {
    cout << "[";
    ListNode* p;
    while (head) {
        p = head;
        head = head->next;
        cout << p->val << " -> ";
        delete p;
    }
    cout << "]" << endl;
}

int main(int argc, char const* argv[]) {
    OddEvenLinkedList cls;

    ListNode* head = new ListNode(1);
    ListNode* p = head;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(5);
    head = cls.oddEvenList(head);
    Drop(head);

    head = new ListNode(2);
    p = head;
    p->next = new ListNode(1);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(5);
    p = p->next;
    p->next = new ListNode(6);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(7);
    head = cls.oddEvenList(head);
    Drop(head);

    return 0;
}
