package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isSubtree(root *TreeNode, subRoot *TreeNode) bool {
	if root.Val == subRoot.Val {
		if checkSub(root, subRoot) {
			return true
		}
	}
	if root.Left != nil {
		if isSubtree(root.Left, subRoot) {
			return true
		}
	}
	if root.Right != nil {
		if isSubtree(root.Right, subRoot) {
			return true
		}
	}
	return false
}

func checkSub(root *TreeNode, subRoot *TreeNode) bool {
	if root == nil && subRoot == nil {
		return true
	}
	if root == nil || subRoot == nil {
		return false
	}
	if root.Val != subRoot.Val {
		return false
	}
	if checkSub(root.Left, subRoot.Left) && checkSub(root.Right, subRoot.Right) {
		return true
	}
	return false
}

func main() {
	root := &TreeNode{Val: 3}
	root.Left = &TreeNode{Val: 4}
	root.Left.Left = &TreeNode{Val: 1}
	root.Left.Right = &TreeNode{Val: 2}
	root.Right = &TreeNode{Val: 5}
	fmt.Println(isSubtree(root, root.Left), true)
	root1 := &TreeNode{Val: 3}
	root1.Left = &TreeNode{Val: 4}
	root1.Left.Left = &TreeNode{Val: 1}
	root1.Left.Right = &TreeNode{Val: 2}
	root1.Left.Right.Left = &TreeNode{Val: 0}
	root1.Right = &TreeNode{Val: 5}
	fmt.Println(isSubtree(root1, root.Left), false)
}
