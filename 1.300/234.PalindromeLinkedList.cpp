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

//234. 回文链表
class PalindromeLinkedList {
    /* 请判断一个链表是否为回文链表。
    */
public:
    bool isPalindrome(ListNode* head) {
        stack<int> pre;
        pre.push(head->val);
        ListNode* p = head;
        ListNode* q = head;
        bool single = true;
        while (q->next) {
            q = q->next;
            if (q->next) {
                q = q->next;
            }
            else {
                single = false;
                break;
            }
            p = p->next;
            pre.push(p->val);
        }
        if (single) {
            pre.pop();
        }
        while (p->next) {
            p = p->next;
            if (p->val != pre.top())
                return false;
            pre.pop();
        }
        return true;
    }
public:
    bool isPalindrome2(ListNode* head) {
        //翻转后半段链表
        ListNode* firstMid = endOfMid(head);
        ListNode* secondStart = reverseList(firstMid->next);
        ListNode* p1 = head;
        ListNode* p2 = secondStart;
        bool ret = true;
        while (p2) {
            if (p1->val != p2->val) {
                ret = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        firstMid->next = reverseList(secondStart);  //还原链表
        return ret;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur)
        {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
    ListNode* endOfMid(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
public:
    void Drop(ListNode* head) {
        while (head) {
            ListNode* p = head;
            head = head->next;
            delete p;
        }
    }
};

int main(int argc, char const* argv[])
{
    PalindromeLinkedList cls;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    cout << boolalpha << cls.isPalindrome2(head) << "->true" << endl;
    cls.Drop(head);

    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    cout << boolalpha << cls.isPalindrome2(head) << "->true" << endl;
    cls.Drop(head);
    return 0;
}
