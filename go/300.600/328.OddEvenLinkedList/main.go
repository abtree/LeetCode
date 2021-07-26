package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func oddEvenList(head *ListNode) *ListNode {
	if head == nil {
		return head
	}
	even := &ListNode{}
	p, q := head, even
	for p.Next != nil {
		q.Next = p.Next
		p.Next = p.Next.Next
		q = q.Next
		q.Next = nil
		if p.Next == nil {
			p.Next = even.Next
			return head
		}
		p = p.Next
	}
	p.Next = even.Next
	return head
}

func print(head *ListNode) {
	fmt.Print("[")
	for head != nil {
		fmt.Print(head.Val, ",")
		head = head.Next
	}
	fmt.Println("]")
}

func main() {
	head := &ListNode{Val: 1}
	p := head
	p.Next = &ListNode{Val: 2}
	p = p.Next
	p.Next = &ListNode{Val: 3}
	p = p.Next
	p.Next = &ListNode{Val: 4}
	p = p.Next
	p.Next = &ListNode{Val: 5}
	head = oddEvenList(head)
	print(head)

	head = &ListNode{Val: 2}
	p = head
	p.Next = &ListNode{Val: 1}
	p = p.Next
	p.Next = &ListNode{Val: 3}
	p = p.Next
	p.Next = &ListNode{Val: 5}
	p = p.Next
	p.Next = &ListNode{Val: 6}
	p = p.Next
	p.Next = &ListNode{Val: 4}
	p = p.Next
	p.Next = &ListNode{Val: 7}
	oddEvenList(head)
	print(head)
}
