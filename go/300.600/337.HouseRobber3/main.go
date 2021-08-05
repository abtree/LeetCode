package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func rob(root *TreeNode) int {
	var dfs func(root *TreeNode) (int, int)
	dfs = func(root *TreeNode) (int, int) {
		if root == nil {
			return 0, 0
		}
		ln, ls := dfs(root.Left)
		rn, rs := dfs(root.Right)
		n := max(ln, ls) + max(rn, rs)
		s := ln + rn + root.Val
		return n, s
	}
	n, s := dfs(root)
	return max(n, s)
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func main() {
	root := &TreeNode{Val: 3}
	root.Left = &TreeNode{Val: 2}
	root.Right = &TreeNode{Val: 3}
	root.Left.Right = &TreeNode{Val: 3}
	root.Right.Right = &TreeNode{Val: 1}
	fmt.Println(rob(root), 7)

	root = &TreeNode{Val: 3}
	root.Left = &TreeNode{Val: 4}
	root.Right = &TreeNode{Val: 5}
	root.Left.Left = &TreeNode{Val: 1}
	root.Left.Right = &TreeNode{Val: 3}
	root.Right.Right = &TreeNode{Val: 1}
	fmt.Println(rob(root), 9)
}
