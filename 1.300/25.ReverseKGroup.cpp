#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//25. K 个一组翻转链表
class CReverseKGroup {
	/*
	给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
	k 是一个正整数，它的值小于或等于链表的长度。
	如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

	 示例：
	 给你这个链表：1->2->3->4->5
	 当 k = 2 时，应当返回: 2->1->4->3->5
	 当 k = 3 时，应当返回: 3->2->1->4->5

	  说明：
	  你的算法只能使用常数的额外空间。
	  你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
	*/
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		/*
		冒泡法
		p 1 2 3 4 5
		p 1	3 2 4 5
		p 3 1 2 4 5
		p 3 2 1 4 5
		*/
		if (k < 2)
			return head;
		if (!head)
			return head;

		auto end = new ListNode(0);
		end->next = head;
		auto tail = end;
		auto np = head;
		while (np) {
			//先确定分组的起始位置和结束位置
			auto p = np;
			for (int i = 1; i < k; ++i) {	//这里是故意少走一步的(后面会补上)
				np = np->next;
				if (!np)
					break;
			}
			if (!np)
				break;
			
			auto nt = p;	//下一组的tail
			np = np->next;	//下一组的起始位置
			reverseFromTo(tail, p, np);
			tail = nt;
			tail->next = np;
		}

		tail = end;
		end = end->next;
		delete tail;
		return end;
	}
private:
	void reverseFromTo(ListNode* tail, ListNode* from, ListNode* to) {
		//头插法翻转链表
		while (from != to) {
			auto k = tail->next;
			tail->next = from;
			from = from->next;
			tail->next->next = k;
		}
	}
};

int main(int argc, char const *argv[])
{
	auto h = new ListNode(1);
	auto p = h;
	p->next = new ListNode(2);
	p = p->next;
	p->next = new ListNode(3);
	p = p->next;
	p->next = new ListNode(4);
	p = p->next;
	p->next = new ListNode(5);

	auto h1 = new ListNode(1);
	p = h1;
	p->next = new ListNode(2);
	p = p->next;
	p->next = new ListNode(3);
	p = p->next;
	p->next = new ListNode(4);
	p = p->next;
	p->next = new ListNode(5);
	
	CReverseKGroup cls;
	h = cls.reverseKGroup(h, 2);
	p = h;
	cout << "group: " << 2;
	while (p) {
		h = p;
		p = p->next;
		cout << "-->" << h->val;
		delete h;
	}
	cout << endl;
	
	h1 = cls.reverseKGroup(h1, 3);
	p = h1;
	cout << "group: " << 3;
	while (p) {
		h = p;
		p = p->next;
		cout << "-->" << h->val;
		delete h;
	}
	cout << endl;
	return 0;
}
