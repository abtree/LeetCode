package main

import (
	"fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func countNodes(root *TreeNode) int {
	if root == nil {
		return 0
	}
	//计算层数
	lv := 0
	node := root
	for node.Left != nil {
		lv++
		node = node.Left
	}
	//计算区间
	low := 1 << lv
	high := 1<<(lv+1) - 1
	for low < high {
		mid := (high-low+1)/2 + low
		if exists(root, lv, mid) {
			low = mid
		} else {
			high = mid - 1
		}
	}
	return low
}

func exists(root *TreeNode, lv, mid int) bool {
	bits := 1 << (lv - 1)
	for root != nil && bits > 0 {
		if (bits & mid) > 0 {
			root = root.Right
		} else {
			root = root.Left
		}
		bits >>= 1
	}
	return root != nil
}

func countNodes2(root *TreeNode) int {
	if root == nil {
		return 0
	}
	return 1 + countNodes2(root.Left) + countNodes2(root.Right)
}

func main() {
	head := &TreeNode{Val: 1}
	head.Left = &TreeNode{Val: 2}
	head.Right = &TreeNode{Val: 3}
	head.Left.Left = &TreeNode{Val: 4}
	head.Left.Right = &TreeNode{Val: 5}
	head.Right.Left = &TreeNode{Val: 6}
	fmt.Println(countNodes2(head), " -> 6")
	fmt.Println(countNodes2(nil), " -> 0")
	fmt.Println(countNodes2(&TreeNode{Val: 1}), " -> 1")
}
