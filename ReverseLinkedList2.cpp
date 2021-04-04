#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//92.反转链表 II
class ReverseLinkList2 {
    /*
    给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。

    示例 1：
    输入：head = [1,2,3,4,5], left = 2, right = 4
    输出：[1,4,3,2,5]

    示例 2：
    输入：head = [5], left = 1, right = 1
    输出：[5]
    */
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left >= right)
            return head;
        ListNode* p = new ListNode(0, head);
        head = p;
        ListNode* cur = head;
        for(int i =0; i < left;++i){
            p = cur;
            cur = cur->next;
        }
        ListNode* e = cur;
        ListNode* r=new ListNode(0);
        ListNode* t = nullptr;
        for(int i = left; i<= right;++i){
            t = cur->next;
            if(r->next){
                cur->next = r->next;
            }
            r->next = cur;
            cur = t;
        }
        p->next = r->next;
        e->next = cur;
        delete r;
        p = head->next;
        delete head;
        return p;
    }
};

int main(int argc, char const* argv[])
{
    ReverseLinkList2 cls;

    ListNode* head = new ListNode(1);
    ListNode* p = head;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(5);
    head = cls.reverseBetween(head, 2, 4);
    cout << "[";
    while(head){
        p = head;
        head = head->next;
        cout << p->val << ",";
        delete p;
    }
    cout << "]" << endl;

    head = new ListNode(5);
    head = cls.reverseBetween(head, 1, 1);
    cout << "[";
    while(head){
        p = head;
        head = head->next;
        cout << p->val << ",";
    }
    cout << "]" << endl;

    head = new ListNode(3);
    head->next = new ListNode(5);
    head = cls.reverseBetween(head, 1, 2);
    cout << "[";
    while(head){
        p = head;
        head = head->next;
        cout << p->val << ",";
    }
    cout << "]" << endl;
    return 0;
}
