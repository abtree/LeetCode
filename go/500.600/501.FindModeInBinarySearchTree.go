package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func findMode(root *TreeNode) []int {
	ans := []int{}
	base, count, maxCount := 0, 0, 0
	update := func(val int) {
		if val == base {
			count++
		} else {
			count = 1
			base = val
		}
		if count == maxCount {
			ans = append(ans, val)
		} else if count > maxCount {
			ans = []int{val}
			maxCount = count
		}
	}
	var dfs func(r *TreeNode)
	dfs = func(r *TreeNode) {
		if r == nil {
			return
		}
		dfs(r.Left)
		update(r.Val)
		dfs(r.Right)
	}
	dfs(root)
	return ans
}

func main() {
	node := &TreeNode{Val: 1}
	node.Right = &TreeNode{Val: 2}
	node.Right.Left = &TreeNode{Val: 2}
	fmt.Println(findMode(node), "[2]")
	node = &TreeNode{Val: 0}
	fmt.Println(findMode(node), "[0]")
}
