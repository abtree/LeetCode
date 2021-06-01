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

//83. 删除排序链表中的重复元素
class RemoveDuplicatesFromSortedList {
    /*
    给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

    示例 1:
    输入: 1->1->2
    输出: 1->2

    示例 2:
    输入: 1->1->2->3->3
    输出: 1->2->3
    */
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        ListNode* q = nullptr;
        while (p && p->next) {
            if (p->val == p->next->val) {
                q = p->next;
                p->next = q->next;
                delete q;
                continue;
            }
            p = p->next;
        }
        return head;
    }
};

int main() {
    RemoveDuplicatesFromSortedList cls;
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    p->next = new ListNode(1);
    p = p->next;
    p->next = new ListNode(2);

    head = cls.deleteDuplicates(head);
    while (head) {
        p = head;
        head = head->next;
        cout << p->val << "->";
        delete p;
    }
    cout << endl;

    head = new ListNode(1);
    p = head;
    p->next = new ListNode(1);
    p = p->next;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(3);

    head = cls.deleteDuplicates(head);
    while (head) {
        p = head;
        head = head->next;
        cout << p->val << "->";
        delete p;
    }
    cout << endl;
    return 0;
}