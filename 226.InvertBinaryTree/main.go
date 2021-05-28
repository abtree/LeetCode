package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func invertTree(root *TreeNode) *TreeNode {
	if root == nil {
		return root
	}
	root.Left, root.Right = root.Right, root.Left
	invertTree(root.Left)
	invertTree(root.Right)
	return root
}

func drop(root *TreeNode) {
	if root == nil {
		return
	}
	drop(root.Left)
	fmt.Printf("%d , ", root.Val)
	drop(root.Right)
}

func main() {
	head := &TreeNode{Val: 4}
	head.Left = &TreeNode{Val: 2}
	head.Right = &TreeNode{Val: 7}
	head.Left.Left = &TreeNode{Val: 1}
	head.Left.Right = &TreeNode{Val: 3}
	head.Right.Left = &TreeNode{Val: 6}
	head.Right.Right = &TreeNode{Val: 9}
	head = invertTree(head)
	fmt.Print("[")
	drop(head)
	fmt.Println("]")
}
