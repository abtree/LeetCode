#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//86. 分隔链表
class PartitionList {
    /*
    给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
    你应当 保留 两个分区中每个节点的初始相对位置。

    示例 1：
    输入：head = [1,4,3,2,5,2], x = 3
    输出：[1,2,2,4,3,5]

    示例 2：
    输入：head = [2,1], x = 2
    输出：[1,2]
    */
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* h = nullptr;  //头指针的位置
        ListNode* le = nullptr; //小于x的最后元素位置
        ListNode* be = nullptr; //大于等于x的最后元素位置
        ListNode* p = head; //当前遍历到的位置
        while(p){
            if(p->val < x){
                if(!le){
                    le = p;
                    h = p;
                }else{
                    le->next = p;
                    le = p;
                }
                if(head == p){
                    head = p->next;
                }else{
                    if(!be){
                        be = head;
                    }
                    be->next = p->next;
                }
                p=p->next;
                le->next = nullptr;
            }else{
                be = p;
                p = p->next;
            }
        }
        if(!le)
            return head;
        le->next = head;
        return h;
    }
public:
    ListNode* partition2(ListNode* head, int x) {
        ListNode *small = new ListNode(-1);
        ListNode *smallPtr = small;
        ListNode *large = new ListNode(-1);
        ListNode *largePtr = large;

        while (head != nullptr) {
            if (head->val < x) {
                smallPtr->next = head;
                smallPtr = smallPtr->next;
            } else {
                largePtr->next = head;
                largePtr = largePtr->next;
            }
            head = head->next;
        }
        largePtr->next = nullptr;
        smallPtr->next = large->next;
        smallPtr = small->next;
        delete large;
        delete small;
        return smallPtr;
    }
};

int main(int argc, char const* argv[])
{
    PartitionList cls;
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    p->next = new ListNode(4);
    p=p->next;
    p->next = new ListNode(3);
    p=p->next;
    p->next = new ListNode(0);
    p=p->next;
    p->next = new ListNode(2);
    p=p->next;
    p->next = new ListNode(5);
    p=p->next;
    p->next = new ListNode(2);
    head = cls.partition2(head, 3);
    while(head){
        p = head;
        head= p->next;
        cout << p->val<<"->";
        delete p;
    }
    cout << endl;

    head = new ListNode(1);
    p = head;
    p->next = new ListNode(4);
    p=p->next;
    p->next = new ListNode(3);
    p=p->next;
    p->next = new ListNode(2);
    p=p->next;
    p->next = new ListNode(5);
    p=p->next;
    p->next = new ListNode(2);
    head = cls.partition2(head, 3);
    while(head){
        p = head;
        head= p->next;
        cout << p->val<<"->";
        delete p;
    }
    cout << endl;

    head = new ListNode(2);
    p = head;
    p->next = new ListNode(1);
    head = cls.partition2(head, 2);
    while(head){
        p = head;
        head= p->next;
        cout << p->val<<"->";
        delete p;
    }
    cout << endl;
    return 0;
}
