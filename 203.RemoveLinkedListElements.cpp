#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 203. 移除链表元素
class RemoveLinkedListElements
{
    /* 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
    */
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* nh = new ListNode();
        ListNode* p = nh;
        while (head) {
            if (head->val == val) {
                ListNode* q = head;
                head = head->next;
                delete q;
            }
            else {
                p->next = head;
                head = head->next;
                p = p->next;
                p->next = nullptr;
            }
        }
        p = nh->next;
        delete nh;
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
    RemoveLinkedListElements cls;
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(6);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(5);
    p = p->next;
    p->next = new ListNode(6);
    head = cls.removeElements(head, 6);
    cls.Drop(head);

    cls.removeElements(nullptr, 1);

    head = new ListNode(7);
    p = head;
    p->next = new ListNode(7);
    p = p->next;
    p->next = new ListNode(7);
    p = p->next;
    p->next = new ListNode(7);
    head = cls.removeElements(head, 7);
    cls.Drop(head);
    return 0;
}
