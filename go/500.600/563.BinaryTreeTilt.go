package main

import (
	"fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func findTilt(root *TreeNode) int {
	ret := 0
	var dfs func(head *TreeNode) int
	dfs = func(head *TreeNode) int {
		if head == nil {
			return 0
		}
		l := dfs(head.Left)
		r := dfs(head.Right)
		x := l - r
		if x < 0 {
			ret -= x
		} else {
			ret += x
		}
		return l + r + head.Val
	}
	dfs(root)
	return ret
}

func main() {
	head := &TreeNode{
		Val:   1,
		Left:  &TreeNode{Val: 2},
		Right: &TreeNode{Val: 3},
	}
	fmt.Println(findTilt(head), 1)

	head = &TreeNode{
		Val: 4,
		Left: &TreeNode{
			Val:   2,
			Left:  &TreeNode{Val: 3},
			Right: &TreeNode{Val: 5},
		},
		Right: &TreeNode{
			Val:   9,
			Right: &TreeNode{Val: 7},
		},
	}
	fmt.Println(findTilt(head), 15)

	head = &TreeNode{
		Val: 21,
		Left: &TreeNode{
			Val: 7,
			Left: &TreeNode{
				Val:   1,
				Left:  &TreeNode{Val: 3},
				Right: &TreeNode{Val: 3},
			},
			Right: &TreeNode{Val: 1},
		},
		Right: &TreeNode{
			Val:   14,
			Left:  &TreeNode{Val: 2},
			Right: &TreeNode{Val: 2},
		},
	}
	fmt.Println(findTilt(head), 9)
}
