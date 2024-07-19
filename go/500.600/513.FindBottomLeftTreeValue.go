package main

import (
	"fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func findBottomLeftValue(root *TreeNode) int {
	queue := []*TreeNode{root}
	ans := 0
	for len(queue) > 0 {
		n := []*TreeNode{}
		for i, cur := range queue {
			if i == 0 {
				ans = cur.Val
			}
			if cur.Left != nil {
				n = append(n, cur.Left)
			}
			if cur.Right != nil {
				n = append(n, cur.Right)
			}
		}
		queue = n
	}
	return ans
}

func main() {
	head := &TreeNode{Val: 2}
	head.Left = &TreeNode{Val: 1}
	head.Right = &TreeNode{Val: 3}
	fmt.Println(findBottomLeftValue(head), 1)

	head = &TreeNode{Val: 1}
	head.Left = &TreeNode{Val: 2}
	head.Left.Left = &TreeNode{Val: 4}
	head.Right = &TreeNode{Val: 3}
	head.Right.Left = &TreeNode{Val: 5}
	head.Right.Right = &TreeNode{Val: 6}
	head.Right.Left.Left = &TreeNode{Val: 7}
	fmt.Println(findBottomLeftValue(head), 7)
}
