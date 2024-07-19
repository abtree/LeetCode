package main

import (
	"fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var mlen = 0

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func diameterOfBinaryTree(root *TreeNode) int {
	mlen = 0
	dfs(root)
	return mlen
}

func dfs(root *TreeNode) int {
	l, r := 0, 0
	if root.Left != nil {
		l = dfs(root.Left) + 1
	}
	if root.Right != nil {
		r = dfs(root.Right) + 1
	}
	mlen = max(mlen, l+r)
	return max(l, r)
}

func main() {
	head := &TreeNode{Val: 1}
	head.Left = &TreeNode{Val: 2}
	head.Left.Left = &TreeNode{Val: 4}
	head.Left.Right = &TreeNode{Val: 5}
	head.Right = &TreeNode{Val: 3}
	fmt.Println(diameterOfBinaryTree(head), 3)

	head = &TreeNode{Val: 1}
	head.Left = &TreeNode{Val: 2}
	fmt.Println(diameterOfBinaryTree(head), 1)
}
