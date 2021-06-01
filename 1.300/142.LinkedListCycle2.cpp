#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

//142. 环形链表 II
class LinkedListCycle2
{
    /*给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。
    说明：不允许修改给定的链表。
    进阶：你是否可以使用 O(1) 空间解决此题？
    */
public:
    ListNode* detectCycle(ListNode* head) {
        //hash表
        unordered_set<ListNode*> tmp;
        while (head) {
            if (tmp.find(head) != tmp.end())
                return head;
            tmp.insert(head);
            head = head->next;
        }
        return nullptr;
    }
public:
    ListNode* detectCycle2(ListNode* head) {
        //快慢指针
        ListNode* slow = head, * fast = head;
        while (fast) {
            slow = slow->next;
            if (!fast->next) {
                return nullptr;
            }
            fast = fast->next->next;
            if (fast == slow) { //当块指针与慢指针相遇 我们在从head出发 每次移动一位 快慢指针相遇时 便是环点
                fast = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
public:
    void Drop(ListNode* head) {
        //hash表
        unordered_set<ListNode*> tmp;
        while (head) {
            if (tmp.find(head) != tmp.end())
                break;
            tmp.insert(head);
            head = head->next;
        }
        for (auto p : tmp) {
            delete p;
        }
    }
};

int main(int argc, char const* argv[])
{
    LinkedListCycle2 cls;

    ListNode* head = new ListNode(3);
    ListNode* p = head;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(0);
    p = p->next;
    p->next = new ListNode(-4);
    p = p->next;
    p->next = head->next;
    p = cls.detectCycle2(head);
    if (p) {
        cout << p->val << " -> 2" << endl;
    }
    else {
        cout << " nullptr" << endl;
    }
    cls.Drop(head);

    head = new ListNode(1);
    p = head;
    p->next = new ListNode(2);
    p = p->next;
    p->next = head;
    p = cls.detectCycle2(head);
    if (p) {
        cout << p->val << " -> 1" << endl;
    }
    else {
        cout << " nullptr" << endl;
    }
    cls.Drop(head);

    head = new ListNode(1);
    p = cls.detectCycle2(head);
    if (p) {
        cout << p->val << " -> 0" << endl;
    }
    else {
        cout << "nullptr" << endl;
    }
    cls.Drop(head);

    return 0;
}
