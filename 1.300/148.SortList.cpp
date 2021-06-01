#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//148. 排序链表
class SortList
{
    /* 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
    进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗
    */
public:
    ListNode* sortList(ListNode* head) {
        //归并排序
        return sort(head, nullptr);
    }
private:
    ListNode* sort(ListNode* head, ListNode* tail) {
        if (!head)
            return head;
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        ListNode* once = head;
        ListNode* twice = head;
        while (twice != tail) {
            once = once->next;
            twice = twice->next;
            if (twice != tail) {
                twice = twice->next;
            }
        }
        return merge(sort(once, tail), sort(head, once));
    }
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* head = nullptr;
        if (left->val > right->val) {
            head = right;
            right = right->next;
        }
        else {
            head = left;
            left = left->next;
        }
        ListNode* ret = head;
        while (left && right) {
            if (left->val > right->val) {
                head->next = right;
                head = right;
                right = right->next;
            }
            else {
                head->next = left;
                head = left;
                left = left->next;
            }
        }
        if (left) {
            head->next = left;
        }
        if (right) {
            head->next = right;
        }
        return ret;
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
    SortList cls;

    ListNode* head = new ListNode(4);
    ListNode* p = head;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(1);
    p = p->next;
    p->next = new ListNode(3);
    head = cls.sortList(head);
    cls.Drop(head);

    head = new ListNode(-1);
    p = head;
    p->next = new ListNode(5);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(0);
    head = cls.sortList(head);
    cls.Drop(head);

    head = cls.sortList(nullptr);
    cls.Drop(head);

    return 0;
}
