#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

//138. 复制带随机指针的链表
class CopyListWithRandomPointer
{
    /*给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。构造这个链表的 深拷贝。返回复制链表的头节点。
    */
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, int> src;  //原链表
        unordered_map<int, Node*> dst;  //新链表
        unordered_map<Node*, Node*> tmp;    //临时表
        Node* nh = new Node(0);
        Node* cur = nh;
        int i = 0;
        while (head) {
            Node* p = head;
            head = head->next;
            cur->next = new Node(p->val);
            cur = cur->next;
            src[p] = i;
            dst[i] = cur;
            if (p->random) {
                auto it = src.find(p->random);
                if (it != src.end()) {
                    cur->random = dst[it->second];
                }
                else {
                    tmp[p] = cur;
                }
            }
            ++i;
        }
        for (auto& it : tmp) {
            auto ps = src.find(it.first->random);
            it.second->random = dst[ps->second];
        }
        cur = nh->next;
        delete nh;
        return cur;
    }
public:
    void Drop(Node* head) {
        while (head) {
            Node* p = head;
            head = head->next;
            delete p;
        }
    }
};

int main(int argc, char const* argv[])
{
    CopyListWithRandomPointer cls;

    Node* head = new Node(7);
    Node* p = head;
    p->next = new Node(13);
    p = p->next;
    p->random = head;
    p->next = new Node(11);
    p = p->next;
    Node* q = p;
    p->next = new Node(10);
    p = p->next;
    p->random = q;
    p->next = new Node(1);
    q->random = p->next;
    p->next->random = head;
    Node* ret = cls.copyRandomList(head);
    cls.Drop(head);
    cls.Drop(ret);

    head = new Node(1);
    p = head;
    p->next = new Node(2);
    p = p->next;
    head->random = p;
    p->random = p;
    ret = cls.copyRandomList(head);
    cls.Drop(head);
    cls.Drop(ret);

    head = new Node(3);
    p = new Node(3);
    q = new Node(3);
    head->next = p;
    p->next = q;
    p->random = head;
    ret = cls.copyRandomList(head);
    cls.Drop(head);
    cls.Drop(ret);
    return 0;
}
