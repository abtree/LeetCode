package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func kthSmallest(root *TreeNode, k int) int {
	var fn func(*TreeNode, int) int
	ret := 0
	fn = func(root *TreeNode, cnt int) int {
		if root == nil {
			return cnt
		}
		cnt = fn(root.Left, cnt)
		if cnt > k {
			return cnt
		}
		cnt++
		if cnt == k {
			ret = root.Val
			return cnt + 1
		}
		return fn(root.Right, cnt)
	}
	fn(root, 0)
	return ret
}

func main() {
	head := &TreeNode{Val: 3}
	head.Left = &TreeNode{Val: 1}
	head.Right = &TreeNode{Val: 4}
	head.Left.Right = &TreeNode{Val: 2}
	fmt.Println(kthSmallest(head, 1), 1)

	head = &TreeNode{Val: 5}
	head.Left = &TreeNode{Val: 3}
	head.Right = &TreeNode{Val: 6}
	head.Left.Left = &TreeNode{Val: 2}
	head.Left.Right = &TreeNode{Val: 4}
	head.Left.Left.Left = &TreeNode{Val: 1}
	fmt.Println(kthSmallest(head, 3), 3)
}
