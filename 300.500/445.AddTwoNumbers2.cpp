#include <iostream>
using namespace std;

struct ListNode {
    int val{};
    ListNode* next{};
    ListNode() {}
    ListNode(int x) : val(x) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class AddTwoNumbers2
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode* head = new ListNode();
        ListNode* p = head;
        int add = 0;
        while (l1 || l2) {
            if (l1 && l2) {
                add += l1->val + l2->val;
                p->next = l1;
                l1 = l1->next;
                ListNode* q = l2;
                l2 = l2->next;
                p = p->next;
                p->next = nullptr;
                p->val = add % 10;
                add = add / 10;
                delete q;
            }
            else if (l1) {
                add += l1->val;
                p->next = l1;
                l1 = l1->next;
                p = p->next;
                p->next = nullptr;
                p->val = add % 10;
                add = add / 10;
            }else if (l2) {
                add += l2->val;
                p->next = l2;
                l2 = l2->next;
                p = p->next;
                p->next = nullptr;
                p->val = add % 10;
                add = add / 10;
            }
        }
        if (add > 0) {
            p->next = new ListNode(add);
        }
        p = head->next;
        delete head;
        head = reverseList(p);
        return head;
    }
private:
    ListNode* reverseList(ListNode* li) {
        ListNode* q = nullptr;
        while (li) {
            ListNode* p = li->next;
            li->next = q;
            q = li;
            li = p;
        }
        return q;
    }
};

void Print(ListNode* li) {
    cout << "[";
    while (li){
        cout << li->val << ", ";
        ListNode* p = li;
        li = li->next;
        delete p;
    }
    cout << "]" << endl;
}

int main(int argc, char const *argv[])
{
    AddTwoNumbers2 cls;
    ListNode* head = new ListNode(7);
    head->next = new ListNode(2);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(3);
    ListNode* head1 = new ListNode(5);
    head1->next = new ListNode(6);
    head1->next->next = new ListNode(4);
    head = cls.addTwoNumbers(head, head1);
    Print(head);

    head = new ListNode(2);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head1 = new ListNode(5);
    head1->next = new ListNode(6);
    head1->next->next = new ListNode(4);
    head = cls.addTwoNumbers(head, head1);
    Print(head);

    head = new ListNode(0);
    head1 = new ListNode(0);
    head = cls.addTwoNumbers(head, head1);
    Print(head);
    return 0;
}
