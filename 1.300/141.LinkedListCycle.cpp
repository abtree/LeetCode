#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

//141. 环形链表
class LinkedListCycle
{
    /*
    给定一个链表，判断链表中是否有环。如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。如果链表中存在环，则返回 true 。 否则，返回 false 。
    */
public:
    bool hasCycle(ListNode* head) {
        //快慢指针
        ListNode* once = head;
        ListNode* twice = head;
        while (twice && twice->next) {
            twice = twice->next->next;
            once = once->next;
            if (twice == once)
                return true;
        }
        return false;
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
    LinkedListCycle cls;

    ListNode* head = new ListNode(3);
    ListNode* p = head;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(0);
    p = p->next;
    p->next = new ListNode(-4);
    p = p->next;
    p->next = head->next;
    cout << boolalpha << cls.hasCycle(head) << " -> true" << endl;
    cls.Drop(head);

    head = new ListNode(1);
    p = head;
    p->next = new ListNode(2);
    p = p->next;
    p->next = head;
    cout << boolalpha << cls.hasCycle(head) << " -> true" << endl;
    cls.Drop(head);

    head = new ListNode(1);
    cout << boolalpha << cls.hasCycle(head) << " -> false" << endl;
    cls.Drop(head);

    return 0;
}
