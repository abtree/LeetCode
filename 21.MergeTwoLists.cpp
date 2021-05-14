#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//21 合并两个有序链表
class CMergeTwoLists {
	/*
	将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

	 示例：
	 输入：1->2->4, 1->3->4
	 输出：1->1->2->3->4->4
	*/
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		//这两个可以不判断
		if (!l1)
			return l2;
		if (!l2)
			return l1;

		ListNode* ret = new ListNode();	//增加一个无用的节点 减少代码复杂度
		ListNode* p = ret;

		while (l1 && l2)
		{
			if (l1->val <= l2->val) {
				p->next = l1;
				l1 = l1->next;
			}
			else {
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}
		if (l1)
			p->next = l1;
		else if (l2)
			p->next = l2;
		p = ret->next;
		delete ret;
		return p;
	}
};

int main(int argc, char const* argv[])
{
	CMergeTwoLists cls;
	ListNode* l1 = new ListNode(1);
	ListNode* p = l1;
	p->next = new ListNode(2);
	p = p->next;
	p->next = new ListNode(4);

	ListNode* l2 = new ListNode(1);
	p = l2;
	p->next = new ListNode(3);
	p = p->next;
	p->next = new ListNode(4);

	p = cls.mergeTwoLists(l1, l2);
	while (p) {
		l1 = p;
		p = p->next;
		cout << l1->val << " -> ";
		delete l1;
	}
	cout << endl;
	return 0;
}
