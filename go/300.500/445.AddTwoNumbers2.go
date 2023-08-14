package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	l1 = reverse(l1)
	l2 = reverse(l2)
	head := &ListNode{}
	p := head
	add := 0
	for l1 != nil || l2 != nil {
		if l1 != nil && l2 != nil {
			add += l1.Val + l2.Val
			p.Next = l1
			l1 = l1.Next
			l2 = l2.Next
			p = p.Next
			p.Next = nil
			p.Val = add % 10
			add /= 10
		} else if l1 != nil {
			add += l1.Val
			p.Next = l1
			l1 = l1.Next
			p = p.Next
			p.Next = nil
			p.Val = add % 10
			add /= 10
		} else if l2 != nil {
			add += l2.Val
			p.Next = l2
			l2 = l2.Next
			p = p.Next
			p.Next = nil
			p.Val = add % 10
			add /= 10
		}
	}
	if add > 0 {
		p.Next = &ListNode{Val: add}
	}
	head = reverse(head.Next)
	return head
}

func reverse(li *ListNode) *ListNode {
	var p *ListNode
	for li != nil {
		q := li
		li = li.Next
		q.Next = p
		p = q
	}
	return p
}

func print(l1 *ListNode) {
	fmt.Print("[")
	for l1 != nil {
		fmt.Printf("%d, ", l1.Val)
		l1 = l1.Next
	}
	fmt.Println("]")
}

func main() {
	head := &ListNode{Val: 7}
	head.Next = &ListNode{Val: 2}
	head.Next.Next = &ListNode{Val: 4}
	head.Next.Next.Next = &ListNode{Val: 3}
	head1 := &ListNode{Val: 5}
	head1.Next = &ListNode{Val: 6}
	head1.Next.Next = &ListNode{Val: 4}
	head = addTwoNumbers(head, head1)
	print(head)

	head = &ListNode{Val: 2}
	head.Next = &ListNode{Val: 4}
	head.Next.Next = &ListNode{Val: 3}
	head1 = &ListNode{Val: 5}
	head1.Next = &ListNode{Val: 6}
	head1.Next.Next = &ListNode{Val: 4}
	head = addTwoNumbers(head, head1)
	print(head)

	head = &ListNode{Val: 0}
	head1 = &ListNode{Val: 0}
	head = addTwoNumbers(head, head1)
	print(head)
}
