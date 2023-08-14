package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func deleteNode(root *TreeNode, key int) *TreeNode {
	if root == nil {
		return nil
	}
	if root.Val > key {
		root.Left = deleteNode(root.Left, key)
		return root
	}
	if root.Val < key {
		root.Right = deleteNode(root.Right, key)
		return root
	}
	if root.Val == key {
		if root.Left == nil && root.Right == nil {
			return nil
		}
		if root.Right == nil {
			return root.Left
		}
		if root.Left == nil {
			return root.Right
		}
		p := root.Right
		for p.Left != nil {
			p = p.Left
		}
		root.Val = p.Val
		root.Right = deleteNode(root.Right, p.Val)
		return root
	}
	return root
}

func print(root *TreeNode) {
	if root.Left != nil {
		print(root.Left)
	}
	if root.Right != nil {
		print(root.Right)
	}
	fmt.Printf("%d ,", root.Val)
}

func main() {
	head := &TreeNode{Val: 5}
	head.Left = &TreeNode{Val: 3}
	head.Left.Left = &TreeNode{Val: 2}
	head.Left.Right = &TreeNode{Val: 4}
	head.Right = &TreeNode{Val: 6}
	head.Right.Right = &TreeNode{Val: 7}
	dh := deleteNode(head, 3)
	print(dh)
}
