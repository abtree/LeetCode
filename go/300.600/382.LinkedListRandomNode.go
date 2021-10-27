package main

import (
	"fmt"
	"math/rand"
	"time"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

type Solution struct {
	Data []*ListNode
}

/** @param head The linked list's head.
  Note that the head is guaranteed to be not null, so it contains at least one node. */
func Constructor(head *ListNode) Solution {
	rand.Seed(time.Now().UnixNano())
	ret := Solution{
		Data: []*ListNode{},
	}
	for head != nil {
		ret.Data = append(ret.Data, head)
		head = head.Next
	}
	return ret
}

/** Returns a random node's value. */
func (this *Solution) GetRandom() int {
	pos := rand.Intn(len(this.Data))
	return this.Data[pos].Val
}

func main() {
	head := &ListNode{Val: 1}
	head.Next = &ListNode{Val: 2}
	head.Next.Next = &ListNode{Val: 3}
	cls := Constructor(head)
	fmt.Println(cls.GetRandom())
	fmt.Println(cls.GetRandom())
	fmt.Println(cls.GetRandom())
}
