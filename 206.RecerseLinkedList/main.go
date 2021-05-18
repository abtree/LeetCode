package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseList(head *ListNode) *ListNode {
	newHead := &ListNode{}
	for head != nil {
		q := newHead.Next
		newHead.Next = head
		head = head.Next
		newHead.Next.Next = q
	}
	return newHead.Next
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
	head = reverseList(head)
	fmt.Printf("[")
	for head != nil {
		fmt.Printf("%d, ", head.Val)
		head = head.Next
	}
	fmt.Println("]")

	head = &ListNode{Val: 1}
	p = head
	p.Next = &ListNode{Val: 2}
	head = reverseList(head)
	fmt.Printf("[")
	for head != nil {
		fmt.Printf("%d, ", head.Val)
		head = head.Next
	}
	fmt.Println("]")

	head = reverseList(nil)
	fmt.Printf("[")
	for head != nil {
		fmt.Printf("%d, ", head.Val)
		head = head.Next
	}
	fmt.Println("]")
}
