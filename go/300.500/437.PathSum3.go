package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var (
	ret int
	tar int
)

func pathSum(root *TreeNode, targetSum int) int {
	if root == nil {
		return 0
	}
	ret = 0
	tar = targetSum
	pointa(root)
	return ret
}

func pointa(root *TreeNode) {
	sum(root, 0)
	if root.Left != nil {
		pointa(root.Left)
	}
	if root.Right != nil {
		pointa(root.Right)
	}
}

func sum(root *TreeNode, x int) {
	x += root.Val
	if x == tar {
		ret++
	}
	if root.Left != nil {
		sum(root.Left, x)
	}
	if root.Right != nil {
		sum(root.Right, x)
	}
	x -= root.Val
}

var dp = map[int]int{}

func pathSum1(root *TreeNode, targetSum int) int {
	if root == nil {
		return 0
	}
	dp = map[int]int{}
	tar = targetSum
	dp[0] = 1
	return dfs(root, 0)
}

func dfs(root *TreeNode, sum int) int {
	sum += root.Val
	ret := 0
	if x, ok := dp[sum-tar]; ok {
		ret = x
	}
	dp[sum]++
	if root.Left != nil {
		ret += dfs(root.Left, sum)
	}
	if root.Right != nil {
		ret += dfs(root.Right, sum)
	}
	dp[sum]--
	return ret
}

func main() {
	head := &TreeNode{Val: 10}
	head.Left = &TreeNode{Val: 5}
	head.Left.Left = &TreeNode{Val: 3}
	head.Left.Left.Left = &TreeNode{Val: 3}
	head.Left.Left.Right = &TreeNode{Val: -2}
	head.Left.Right = &TreeNode{Val: 2}
	head.Left.Right.Right = &TreeNode{Val: 1}
	head.Right = &TreeNode{Val: -3}
	head.Right.Right = &TreeNode{Val: 11}
	fmt.Println(pathSum1(head, 8), 3)
	head = &TreeNode{Val: 5}
	head.Left = &TreeNode{Val: 4}
	head.Left.Left = &TreeNode{Val: 11}
	head.Left.Left.Left = &TreeNode{Val: 7}
	head.Left.Left.Right = &TreeNode{Val: 2}
	head.Right = &TreeNode{Val: 8}
	head.Right.Left = &TreeNode{Val: 13}
	head.Right.Right = &TreeNode{Val: 4}
	head.Right.Right.Left = &TreeNode{Val: 5}
	head.Right.Right.Right = &TreeNode{Val: 1}
	fmt.Println(pathSum1(head, 22), 3)
}
