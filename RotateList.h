#pragma once

//61. 旋转链表
class RotateList {
    /*
    给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

    示例 1:
        输入: 1->2->3->4->5->NULL, k = 2
        输出: 4->5->1->2->3->NULL
        解释:
        向右旋转 1 步: 5->1->2->3->4->NULL
        向右旋转 2 步: 4->5->1->2->3->NULL
    示例 2:
        输入: 0->1->2->NULL, k = 4
        输出: 2->0->1->NULL
        解释:
        向右旋转 1 步: 2->0->1->NULL
        向右旋转 2 步: 1->2->0->NULL
        向右旋转 3 步: 0->1->2->NULL
        向右旋转 4 步: 2->0->1->NULL

    */
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
        //计算旋转后的链表的断点位置
        //将链表闭环
        //再在断点位置打开
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