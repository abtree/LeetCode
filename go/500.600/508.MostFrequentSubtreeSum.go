package main

import (
	"fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func findFrequentTreeSum(root *TreeNode) []int {
	dp := map[int]int{}
	m := 0
	var dfs func(ro *TreeNode) int
	dfs = func(ro *TreeNode) int {
		l, r := 0, 0
		if ro.Left != nil {
			l = dfs(ro.Left)
		}
		if ro.Right != nil {
			r = dfs(ro.Right)
		}
		sum := l + r + ro.Val
		dp[sum] += 1
		if dp[sum] > m {
			m = dp[sum]
		}
		return sum
	}
	dfs(root)
	ans := []int{}
	for k, v := range dp {
		if v == m {
			ans = append(ans, k)
		}
	}
	return ans
}

func main() {
	root := &TreeNode{Val: 5}
	root.Left = &TreeNode{Val: 2}
	root.Right = &TreeNode{Val: -3}
	fmt.Println(findFrequentTreeSum(root), "[2,-3,4]")
	root = &TreeNode{Val: 5}
	root.Left = &TreeNode{Val: 2}
	root.Right = &TreeNode{Val: -5}
	fmt.Println(findFrequentTreeSum(root), "[2]")
}
