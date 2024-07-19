package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var sum = 0

func createTreeNode(v int) *TreeNode {
	return &TreeNode{Val: v}
}

func convertBST(root *TreeNode) *TreeNode {
	sum = 0
	bfs(root)
	return root
}

func bfs(root *TreeNode) {
	if root == nil {
		return
	}
	bfs(root.Right)
	sum += root.Val
	root.Val = sum
	bfs(root.Left)
}

func print(root *TreeNode) {
	if root.Right != nil {
		print(root.Right)
	}
	fmt.Printf("%d,", root.Val)
	if root.Left != nil {
		print(root.Left)
	}
}

func convertBST1(root *TreeNode) *TreeNode {
	sum := 0
	node := root
	for node != nil {
		if node.Right == nil {
			sum += node.Val
			node.Val = sum
			node = node.Left
		} else {
			succ := getSucc(node)
			if succ.Left == nil {
				succ.Left = node
				node = node.Right
			} else {
				succ.Left = nil
				sum += node.Val
				node.Val = sum
				node = node.Left
			}
		}

	}
	return root
}

func getSucc(node *TreeNode) *TreeNode {
	succ := node.Right
	for succ.Left != nil && succ.Left != node {
		succ = succ.Left
	}
	return succ
}

func main() {
	root := createTreeNode(4)
	root.Left = createTreeNode(1)
	root.Left.Left = createTreeNode(0)
	root.Left.Right = createTreeNode(2)
	root.Left.Right.Right = createTreeNode(3)
	root.Right = createTreeNode(6)
	root.Right.Left = createTreeNode(5)
	root.Right.Right = createTreeNode(7)
	root.Right.Right.Right = createTreeNode(8)
	root = convertBST1(root)
	print(root)
	fmt.Println()
}
