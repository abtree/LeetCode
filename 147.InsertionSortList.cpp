#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//147. 对链表进行插入排序
class InsertionSortList
{
    /* 对链表进行插入排序。*/
public:
    ListNode* insertionSortList(ListNode* head) {
        /* 对链表进行插入排序。 */
        if (!head)
            return head;
        ListNode* cur = head->next;
        head->next = nullptr;
        while (cur) {
            //遍历位置
            ListNode* p = head;
            ListNode* end = cur;
            cur = cur->next;
            end->next = nullptr;
            while (p) {
                if (p->val > end->val) {  //改变头指针
                    end->next = p;
                    head = end;
                    break;
                }
                if (p->next) {
                    if (p->next->val > end->val) {
                        end->next = p->next;
                        p->next = end;
                        break;
                    }
                    else {
                        p = p->next;
                    }
                }
                else {
                    p->next = end;
                    break;
                }
            }
        }
        return head;
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
    InsertionSortList cls;

    ListNode* head = new ListNode(4);
    ListNode* p = head;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(1);
    p = p->next;
    p->next = new ListNode(3);
    head = cls.insertionSortList(head);
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
    head = cls.insertionSortList(head);
    cls.Drop(head);

    return 0;
}
