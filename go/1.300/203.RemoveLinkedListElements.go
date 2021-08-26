package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func removeElements(head *ListNode, val int) *ListNode {
	newHead := &ListNode{}
	p := newHead
	for head != nil {
		if head.Val == val {
			head = head.Next
		} else {
			p.Next = head
			head = head.Next
			p = p.Next
			p.Next = nil
		}
	}
	return newHead.Next
}

func main() {
	head := &ListNode{Val: 1}
	p := head
	p.Next = &ListNode{Val: 2}
	p = p.Next
	p.Next = &ListNode{Val: 6}
	p = p.Next
	p.Next = &ListNode{Val: 3}
	p = p.Next
	p.Next = &ListNode{Val: 4}
	p = p.Next
	p.Next = &ListNode{Val: 5}
	p = p.Next
	p.Next = &ListNode{Val: 6}
	head = removeElements(head, 6)
	fmt.Printf("[")
	for head != nil {
		fmt.Printf("%d, ", head.Val)
		head = head.Next
	}
	fmt.Printf("] \n")

	head = &ListNode{Val: 7}
	p = head
	p.Next = &ListNode{Val: 7}
	p = p.Next
	p.Next = &ListNode{Val: 7}
	p = p.Next
	p.Next = &ListNode{Val: 7}
	head = removeElements(head, 7)
	fmt.Printf("[")
	for head != nil {
		fmt.Printf("%d, ", head.Val)
		head = head.Next
	}
	fmt.Printf("] \n")
}
