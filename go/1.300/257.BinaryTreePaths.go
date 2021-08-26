package main

import (
	"fmt"
	"strconv"
	"strings"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func binaryTreePaths(root *TreeNode) []string {
	ret := []string{}
	ans := []string{}
	var dfs func(root *TreeNode)
	dfs = func(root *TreeNode) {
		if root == nil {
			return
		}
		ret = append(ret, strconv.Itoa(root.Val))
		if root.Left == nil && root.Right == nil {
			ans = append(ans, strings.Join(ret, "->"))
		} else {
			dfs(root.Left)
			dfs(root.Right)
		}
		ret = ret[:len(ret)-1]
	}
	dfs(root)
	return ans
}

func main() {
	head := &TreeNode{Val: 1}
	head.Left = &TreeNode{Val: 2}
	head.Right = &TreeNode{Val: 3}
	head.Left.Right = &TreeNode{Val: 5}
	fmt.Println(binaryTreePaths(head))
}
