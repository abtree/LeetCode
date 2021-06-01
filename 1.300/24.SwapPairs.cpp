#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

//24 两两交换链表中的节点
class CSwapPairs {
	/*
	给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
	你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

	 示例:
	 给定 1->2->3->4, 你应该返回 2->1->4->3.
	*/
public:
	ListNode* swapPairs(ListNode* head) {
		/*
			顺序交换就可以了
			就是写起来有点绕
		*/
		auto p = new ListNode(0);
		p->next = head;
		head = p;
		auto q = p->next;
		while (q && q->next) {	//这两个是需要交换的
			p->next = q->next;
			q->next = q->next->next;
			p->next->next = q;
			p = q;
			q = p->next;
		}
		p = head;
		head = p->next;
		delete p;
		return head;
	}
};

int main(int argc, char const* argv[])
{
	auto h = new ListNode(1);
	auto p = h;
	p->next = new ListNode(2);
	p = p->next;
	p->next = new ListNode(3);
	p = p->next;
	p->next = new ListNode(4);

	CSwapPairs cls;
	h = cls.swapPairs(h);
	p = h;
	while (p) {
		h = p;
		p = p->next;
		cout << "->" << h->val;
		delete h;
	}
	cout << endl;
	return 0;
}
