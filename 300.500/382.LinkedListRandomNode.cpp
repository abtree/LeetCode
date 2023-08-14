#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LinkedListRandomNode{
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    LinkedListRandomNode(ListNode* head) {
        while(head){
            data.push_back(head);
            head = head->next;
        }
        srand(time(nullptr));
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int pos = rand()%data.size();
        return data[pos]->val;
    }
private:
    vector<ListNode*> data;
};

class LinkedListRandomNode1{
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    LinkedListRandomNode1(ListNode* head) {
        mHead = head;
        srand(time(nullptr));
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        /* 蓄水池算法(这道题其实并不适用)
        第一个数保留的概率为 1/1
        第二个数保留的概率为 1/2
        ...
        第n个数保留的概率为 1/n
        这样算下来每个数最终被保留的概率都为 1/n
        1/x * x/(x+1) * (x+1)/(x+2) * ... * (n-1)/n = 1/n
        */
        int ret = mHead->val;
        int cnt = 2;
        ListNode* p = mHead->next;
        while(p){
            int x = rand()%cnt+1;
            if(x == cnt){
                ret = p->val;
            }
            p = p->next;
        }
        return ret;
    }
private:
    ListNode* mHead{};
};

void Drop(ListNode* head){
    auto* p = head;
    while (p){
        head = head->next;
        delete p;
        p = head;
    }
}

int main(int argc, char const *argv[]){
    
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    LinkedListRandomNode cls(head);
    cout <<cls.getRandom()<<endl;
    cout <<cls.getRandom()<<endl;
    cout <<cls.getRandom()<<endl;
    Drop(head);
    return 0;
}
