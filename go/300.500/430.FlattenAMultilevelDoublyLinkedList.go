package main

import "fmt"

type Node struct {
	Val   int
	Prev  *Node
	Next  *Node
	Child *Node
}

func flatten(root *Node) *Node {
	ret := root
	var dfs func(root *Node) *Node
	dfs = func(root *Node) *Node {
		for root != nil {
			if root.Child == nil {
				if root.Next == nil {
					return root
				} else {
					root = root.Next
				}
			} else {
				next := root.Next
				root.Next = root.Child
				root.Child.Prev = root
				root.Child = nil
				root = dfs(root.Next)
				if next != nil {
					root.Next = next
					next.Prev = root
					root = next
				}
			}
		}
		return root
	}
	dfs(root)
	return ret
}

func print(root *Node) {
	for root != nil {
		c := root
		root = root.Next
		fmt.Printf("%d,", c.Val)
	}
	fmt.Println()
}

func main() {
	head := &Node{Val: 1}
	h := head
	head.Next = &Node{Val: 2}
	head.Next.Prev = head
	head = head.Next
	head.Next = &Node{Val: 3}
	head.Next.Prev = head
	head = head.Next
	head.Next = &Node{Val: 4}
	head.Next.Prev = head
	head = head.Next
	head.Next = &Node{Val: 5}
	head.Next.Prev = head
	head = head.Next
	head.Next = &Node{Val: 6}
	head.Next.Prev = head
	head = h.Next.Next
	head.Child = &Node{Val: 7}
	head = head.Child
	head.Next = &Node{Val: 8}
	head.Next.Prev = head
	head = head.Next
	head.Next = &Node{Val: 9}
	head.Next.Prev = head
	head = head.Next
	head.Next = &Node{Val: 10}
	head.Next.Prev = head
	head = h.Next.Next.Child.Next
	head.Child = &Node{Val: 11}
	head = head.Child
	head.Next = &Node{Val: 12}
	head.Next.Prev = head
	ret := flatten(h)
	print(ret)
}
