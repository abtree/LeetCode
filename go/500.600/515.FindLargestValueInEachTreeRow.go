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

func largestValues(root *TreeNode) []int {
	if root == nil {
		return []int{}
	}
	queue := []*TreeNode{root}
	ans := []int{}
	for len(queue) > 0 {
		mx := math.MinInt
		qu := []*TreeNode{}
		for _, curr := range queue {
			mx = max(mx, curr.Val)
			if curr.Left != nil {
				qu = append(qu, curr.Left)
			}
			if curr.Right != nil {
				qu = append(qu, curr.Right)
			}
		}
		queue = qu
		ans = append(ans, mx)
	}
	return ans
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func main() {
	head := &TreeNode{Val: 1}
	head.Left = &TreeNode{Val: 3}
	head.Left.Left = &TreeNode{Val: 5}
	head.Left.Right = &TreeNode{Val: 3}
	head.Right = &TreeNode{Val: 2}
	head.Right.Right = &TreeNode{Val: 9}
	fmt.Println(largestValues(head), "[1,3,9]")

	head = &TreeNode{Val: 1}
	head.Left = &TreeNode{Val: 2}
	head.Right = &TreeNode{Val: 3}
	fmt.Println(largestValues(head), "[1,3]")
}
