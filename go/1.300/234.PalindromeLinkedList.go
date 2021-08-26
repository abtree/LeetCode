package main

import (
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func isPalindrome(head *ListNode) bool {
	p := head
	q := head
	stack := []int{head.Val}
	for q.Next != nil && q.Next.Next != nil {
		p = p.Next
		q = q.Next.Next
		stack = append(stack, p.Val)
	}
	size := len(stack) - 1
	if q.Next == nil {
		size--
	}

	for p.Next != nil {
		p = p.Next
		if p.Val != stack[size] {
			return false
		}
		size--
	}
	return true
}

func main() {
	head := &ListNode{Val: 1}
	head.Next = &ListNode{Val: 2}
	head.Next.Next = &ListNode{Val: 1}
	fmt.Println(isPalindrome(head), true)

	head = &ListNode{Val: 1}
	head.Next = &ListNode{Val: 2}
	head.Next.Next = &ListNode{Val: 2}
	head.Next.Next.Next = &ListNode{Val: 1}
	fmt.Println(isPalindrome(head), true)
}
