#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//143. 重排链表
class ReorderList
{
    /*给定一个单链表 L：L0→L1→…→Ln-1→Ln ，将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
    你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
    */
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> q;
        ListNode* p = head;
        while (p) {
            q.push(p);
            p = p->next;
        }
        p = head;
        int mid = q.size() / 2;
        for (int i = 0; i < mid; ++i) {
            ListNode* b = q.top();
            q.pop();
            b->next = p->next;
            p->next = b;
            p = b->next;
        }
        p->next = nullptr;
    }
public:
    void Drop(ListNode* head) {
        cout << "[";
        while (head) {
            ListNode* p = head;
            head = head->next;
            cout << p->val << ",";
            delete p;
        }
        cout << "]" << endl;
    }
};

int main(int argc, char const* argv[])
{
    ReorderList cls;

    ListNode* head = new ListNode(1);
    ListNode* p = head;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(4);
    cls.reorderList(head);
    cls.Drop(head);

    head = new ListNode(1);
    p = head;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(5);
    cls.reorderList(head);
    cls.Drop(head);

    return 0;
}
