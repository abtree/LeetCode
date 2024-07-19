package main

import (
	"fmt"
	"math"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func getMinimumDifference(root *TreeNode) int {
	var pre *TreeNode
	ans := math.MaxInt
	var dfs func(root *TreeNode)
	dfs = func(root *TreeNode) {
		if root.Left != nil {
			dfs(root.Left)
		}
		if pre != nil {
			ans = min(ans, root.Val-pre.Val)
		}
		pre = root
		if root.Right != nil {
			dfs(root.Right)
		}
	}
	dfs(root)
	return ans
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}

func main() {
	root := &TreeNode{Val: 4}
	root.Left = &TreeNode{Val: 2}
	root.Left.Left = &TreeNode{Val: 1}
	root.Left.Right = &TreeNode{Val: 3}
	root.Right = &TreeNode{Val: 6}
	fmt.Println(getMinimumDifference(root), 1)

	root = &TreeNode{Val: 1}
	root.Left = &TreeNode{Val: 0}
	root.Right = &TreeNode{Val: 48}
	root.Right.Left = &TreeNode{Val: 12}
	root.Right.Right = &TreeNode{Val: 49}
	fmt.Println(getMinimumDifference(root), 1)
}
