#include <iostream>

using namespace std;

struct ListNode {
	int val{};
	ListNode* next{};
	ListNode(int x) : val(x), next(nullptr) {}
};

//19 删除链表的倒数第N个节点
class CRemoveNthFromEnd {
	/*
	给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

	示例：
	给定一个链表: 1->2->3->4->5, 和 n = 2.
	当删除了倒数第二个节点后，链表变为 1->2->3->5.

	说明：给定的 n 保证是有效的。

	进阶：你能尝试使用一趟扫描实现吗？
	*/
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (!head)
			return nullptr;
		ListNode* p = nullptr;
		ListNode* h = head;
		while (h && n > 0) {
			h = h->next;
			--n;
		}
		//特殊处理一个节点的情况
		if (!h) {
			if (n == 0) {	//只有一个元素的情况
				h = head->next;
				delete head;
				return h;
			}
			else {
				return head; //不够 返回原来的
			}
		}

		h = h->next;
		p = head;
		while (h) {
			h = h->next;
			p = p->next;
		}
		auto q = p->next;
		p->next = q->next;
		delete q;
		return head;
	}
};

int main(int argc, char const* argv[])
{
	CRemoveNthFromEnd cls;
	ListNode* head = new ListNode(1);
	ListNode* p = head;
	p->next = new ListNode(2);
	p = p->next;
	p->next = new ListNode(3);
	p = p->next;
	p->next = new ListNode(4);
	p = p->next;
	p->next = new ListNode(5);
	head = cls.removeNthFromEnd(head, 2);
	p = head;
	while (p)
	{
		head = p;
		cout << head->val << ",";
		p = p->next;
		delete head;
	}
	cout << endl;
	return 0;
}
