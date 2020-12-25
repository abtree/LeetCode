#pragma once

class RotateList {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0)
            return head;
        ListNode* p = head;
        int size = 0;
        for (int i = 1; i < k;++i) {
            p = p->next;
            if (!p) {
                size = i;
                break;
            }
        }
        if (size > 0) {
            //这里计算超过长度的值
            k = k % size;
            if (k == 0)
                return head;
            p = head;
            for (int i = 1; i < k;++i) {
                p = p->next;
            }
        }
        p = p->next;
        if (!p) {
            //刚好转一圈
            return head;
        }
        ListNode* q = head;
        while (p->next != nullptr) {
            q = q->next;
            p = p->next;
        }
        p->next = head;
        head = q->next;
        q->next = nullptr;
        return head;
    }
public:
    static void Test() {
        RotateList cls;
        ListNode* head = new ListNode(1);
        ListNode* p = new ListNode(2);
        head->next = p;
        ListNode* q = p;
        p = new ListNode(3);
        q->next = p;
        q = p;
        p = new ListNode(4);
        q->next = p;
        q = p;
        p = new ListNode(5);
        q->next = p;
        q = p;
        head = cls.rotateRight(head, 2);
        while (head) {
            p = head;
            head = head->next;
            cout << p->val << ",";
            delete p;
        }
        cout << endl;

        head = new ListNode(0);
        p = new ListNode(1);
        head->next = p;
        q = p;
        p = new ListNode(2);
        q->next = p;
        head = cls.rotateRight(head, 4);
        while (head) {
            p = head;
            head = head->next;
            cout << p->val << ",";
            delete p;
        }
        cout << endl;

        head = new ListNode(1);
        p = new ListNode(2);
        head->next = p;
        head = cls.rotateRight(head, 0);
        while (head) {
            p = head;
            head = head->next;
            cout << p->val << ",";
            delete p;
        }
        cout << endl;
    }
};