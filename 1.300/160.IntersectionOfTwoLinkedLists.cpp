#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class IntersectionOfTwoLinkedLists
{
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        //dp查询
        unordered_set<ListNode*> dp;
        while (headA) {
            dp.insert(headA);
            headA = headA->next;
        }
        while (headB) {
            if (dp.find(headB) != dp.end())
                return headB;
            headB = headB->next;
        }
        return nullptr;
    }
public:
    ListNode* getIntersectionNode2(ListNode* headA, ListNode* headB) {
        //绕两圈法
        if (!headA || !headB)
            return nullptr;
        ListNode* a = headA;
        ListNode* b = headB;
        int cnt = 0; //防止两个链表不相交时出现死循环
        while (a != b) {
            if (a->next)
                a = a->next;
            else {
                a = headB;
                ++cnt;
            }
            if (b->next) {
                b = b->next;
            }
            else {
                b = headA;
                ++cnt;
            }
            if (cnt > 2) {
                return nullptr;
            }
        }
        return a;
    }
public:
    void Drop(ListNode* h, ListNode* h2, ListNode* p) {
        while (h != p) {
            ListNode* q = h;
            h = h->next;
            delete q;
        }
        while (h2 != p) {
            ListNode* q = h2;
            h2 = h2->next;
            delete q;
        }
        while (p) {
            ListNode* q = p;
            p = p->next;
            delete q;
        }
    }
};

int main(int argc, char const* argv[])
{
    IntersectionOfTwoLinkedLists cls;

    ListNode* head = new ListNode(4);
    ListNode* p = head;
    p->next = new ListNode(1);
    p = p->next;
    p->next = new ListNode(8);
    p = p->next;
    ListNode* head2 = new ListNode(5);
    ListNode* q = head2;
    q->next = new ListNode(0);
    q = q->next;
    q->next = new ListNode(1);
    q = q->next;
    q->next = p;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(5);
    p = cls.getIntersectionNode2(head, head2);
    cout << p->val << endl;
    cls.Drop(head, head2, p);

    head = new ListNode(2);
    p = head;
    p->next = new ListNode(6);
    p = p->next;
    p->next = new ListNode(4);
    head2 = new ListNode(1);
    q = head2;
    q->next = new ListNode(5);
    p = cls.getIntersectionNode2(head, head2);
    cls.Drop(head, head2, p);

    return 0;
}
