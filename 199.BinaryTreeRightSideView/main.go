package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func rightSideView(root *TreeNode) []int {
	if root == nil {
		return []int{}
	}
	q := []*TreeNode{}
	q = append(q, root)
	ret := []int{}
	for len(q) > 0 {
		size := len(q)
		for i := 0; i < size; i++ {
			cur := q[0]
			q = q[1:]
			if i == 0 {
				ret = append(ret, cur.Val)
			}
			if cur.Right != nil {
				q = append(q, cur.Right)
			}
			if cur.Left != nil {
				q = append(q, cur.Left)
			}
		}
	}
	return ret
}

func rightSideView2(root *TreeNode) []int {
	ans := []int{}
	return dfs(root, 1, ans)
}

func dfs(root *TreeNode, layer int, res []int) []int {
	if root == nil {
		return res
	}
	if len(res) < layer {
		res = append(res, root.Val)
	}
	res = dfs(root.Right, layer+1, res)
	res = dfs(root.Left, layer+1, res)
	return res
}

func main() {
	head := &TreeNode{Val: 1}
	head.Left = &TreeNode{Val: 2}
	head.Right = &TreeNode{Val: 3}
	head.Left.Right = &TreeNode{Val: 5}
	head.Right.Right = &TreeNode{Val: 4}
	fmt.Println(rightSideView(head))
	fmt.Println(rightSideView2(head))
}
