#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//206. 反转链表
class RecerseLinkedList
{
    /* 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
    */
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = new ListNode();
        while (head) {
            ListNode* q = newHead->next;
            newHead->next = head;
            head = head->next;
            newHead->next->next = q;
        }
        ListNode* p = newHead->next;
        delete newHead;
        return p;
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
    RecerseLinkedList cls;
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(5);
    head = cls.reverseList(head);
    cls.Drop(head);

    head = new ListNode(1);
    p = head;
    p->next = new ListNode(2);
    head = cls.reverseList(head);
    cls.Drop(head);

    head = cls.reverseList(nullptr);
    cls.Drop(head);
    return 0;
}
