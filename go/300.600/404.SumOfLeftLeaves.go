package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func sumOfLeftLeaves(root *TreeNode) int {
	ret := 0
	var dfs func(root *TreeNode, left bool)
	dfs = func(root *TreeNode, left bool) {
		if root.Left == nil && root.Right == nil {
			if left {
				ret += root.Val
			}
			return
		}
		if root.Left != nil {
			dfs(root.Left, true)
		}
		if root.Right != nil {
			dfs(root.Right, false)
		}
	}
	if root != nil {
		dfs(root, false)
	}
	return ret
}

func main() {
	head := &TreeNode{Val: 3}
	head.Left = &TreeNode{Val: 9}
	head.Right = &TreeNode{Val: 20}
	head.Right.Left = &TreeNode{Val: 15}
	head.Right.Right = &TreeNode{Val: 7}
	fmt.Println(sumOfLeftLeaves(head), 24)
}