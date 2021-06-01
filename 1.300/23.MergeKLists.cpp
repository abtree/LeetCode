#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val{};
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//23 合并K个升序链表
class CMergeKLists {
	/*
	给你一个链表数组，每个链表都已经按升序排列。请你将所有链表合并到一个升序链表中，返回合并后的链表。

		示例 1：
		输入：lists = [[1, 4, 5], [1, 3, 4], [2, 6]]
		输出：[1, 1, 2, 3, 4, 4, 5, 6]
		解释：链表数组如下：
		[
			1->4->5,
			1->3->4,
			2->6
		]
	将它们合并到一个有序链表中得到。
		1->1->2->3->4->4->5->6

		示例 2：
		输入：lists = []
		输出：[]

		示例 3：
		输入：lists = [[]]
		输出：[]

		提示：
		k == lists.length
		0 <= k <= 10 ^ 4
		0 <= lists[i].length <= 500
		- 10 ^ 4 <= lists[i][j] <= 10 ^ 4
		lists[i] 按 升序 排列
		lists[i].length 的总和不超过 10 ^ 4
		*/
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty())
			return nullptr;
		ListNode* ret = new ListNode(0, lists[0]);
		for (int i = 1; i < lists.size(); ++i) {
			//合并list[0] 和 list[i]
			ListNode* p = ret;
			ListNode* q = lists[i];
			while (q) {
				if (p->next == nullptr) {
					p->next = q;
					break;
				}
				if (q->val < p->next->val) {
					ListNode* k = p->next;
					p->next = q;
					q = q->next;
					p = p->next;
					p->next = k;
				}
				else {
					p = p->next;
				}
			}
		}
		ListNode* p = ret->next;
		delete ret;
		return p;
	}
};

int main(int argc, char const* argv[])
{
	vector<ListNode*> lists;
	ListNode* h = new ListNode(1);
	ListNode* p = h;
	p->next = new ListNode(4);
	p = p->next;
	p->next = new ListNode(5);
	lists.push_back(h);
	h = new ListNode(1);
	p = h;
	p->next = new ListNode(3);
	p = p->next;
	p->next = new ListNode(4);
	lists.push_back(h);
	h = new ListNode(2);
	h->next = new ListNode(6);
	lists.push_back(h);
	CMergeKLists cls;
	h = cls.mergeKLists(lists);
	cout << "[" << endl;
	while (h) {
		p = h;
		h = h->next;
		cout << p->val << " ";
		delete p;
	}
	cout << "]" << endl;
	return 0;
}
