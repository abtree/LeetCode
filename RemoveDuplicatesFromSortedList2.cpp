#pragma once

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//82. 删除排序链表中的重复元素 II
class RemoveDuplicatesFromSortedList2 {
    /*
    给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

    示例 1:
    输入: 1->2->3->3->4->4->5
    输出: 1->2->5

    示例 2:
    输入: 1->1->1->2->3
    输出: 2->3
    */
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        ListNode* q = nullptr;
        ListNode* l = nullptr;
        bool de = false;
        while (p) {
            if (p->next == nullptr) {
                if (de) {
                    if (l)
                        l->next = nullptr;
                    else
                        head = nullptr;
                    delete p;
                }
                return head;
            }
            if (p->val == p->next->val) {
                q = p->next;
                p->next = p->next->next;
                delete q;
                de = true;
                continue;
            }
            else {
                if (de) {
                    q = p;
                    if (!l)
                        head = p->next;
                    else
                        l->next = p->next;
                    p = p->next;
                    delete q;
                    de = false;
                }
                else {
                    l = p;
                    p = p->next;
                }
            }
        }
    }
};

int main() {
    RemoveDuplicatesFromSortedList2 cls;
    ListNode* pHead = new ListNode(1);
    ListNode* p = pHead;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(5);
    pHead = cls.deleteDuplicates(pHead);
    while (pHead) {
        ListNode* p = pHead;
        pHead = p->next;
        cout << p->val << "->";
        delete p;
    }
    cout << endl;

    pHead = new ListNode(1);
    p = pHead;
    p->next = new ListNode(1);
    p = p->next;
    p->next = new ListNode(1);
    p = p->next;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(3);
    pHead = cls.deleteDuplicates(pHead);
    while (pHead) {
        ListNode* p = pHead;
        pHead = p->next;
        cout << p->val << "->";
        delete p;
    }
    cout << endl;

    pHead = new ListNode(1);
    p = pHead;
    p->next = new ListNode(1);
    pHead = cls.deleteDuplicates(pHead);
    while (pHead) {
        ListNode* p = pHead;
        pHead = p->next;
        cout << p->val << "->";
        delete p;
    }
    cout << endl;
    return 0;
}