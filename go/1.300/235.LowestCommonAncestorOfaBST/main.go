package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	if p.Val > q.Val {
		p, q = q, p
	}
	for root != nil {
		if root.Val < p.Val {
			root = root.Right
		} else if root.Val > q.Val {
			root = root.Left
		} else {
			return root
		}
	}
	return nil
}

func main() {
	head := &TreeNode{Val: 6}
	head.Left = &TreeNode{Val: 2}
	head.Right = &TreeNode{Val: 8}
	head.Left.Left = &TreeNode{Val: 0}
	head.Left.Right = &TreeNode{Val: 4}
	head.Left.Right.Left = &TreeNode{Val: 3}
	head.Left.Right.Right = &TreeNode{Val: 5}
	head.Right.Left = &TreeNode{Val: 7}
	head.Right.Right = &TreeNode{Val: 9}
	fmt.Println(lowestCommonAncestor(head, head.Left, head.Right).Val, 6)
	fmt.Println(lowestCommonAncestor(head, head.Left.Right, head.Left).Val, 2)
	fmt.Println(lowestCommonAncestor(head, head.Left.Right.Left, head.Left.Right.Right).Val, 4)
}
