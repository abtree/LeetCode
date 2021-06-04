package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	if root == nil || root == p || root == q {
		return root
	}
	left := lowestCommonAncestor(root.Left, p, q)
	right := lowestCommonAncestor(root.Right, p, q)
	if left != nil && right != nil {
		return root
	}
	if left == nil {
		return right
	}
	return left
}

func main() {
	head := &TreeNode{Val: 3}
	head.Left = &TreeNode{Val: 5}
	head.Right = &TreeNode{Val: 1}
	head.Left.Left = &TreeNode{Val: 6}
	head.Left.Right = &TreeNode{Val: 2}
	head.Left.Right.Left = &TreeNode{Val: 7}
	head.Left.Right.Right = &TreeNode{Val: 4}
	head.Right.Left = &TreeNode{Val: 0}
	head.Right.Right = &TreeNode{Val: 8}
	fmt.Println(lowestCommonAncestor(head, head.Left, head.Right).Val, 3)
	fmt.Println(lowestCommonAncestor(head, head.Left, head.Left.Right.Right).Val, 5)
}
