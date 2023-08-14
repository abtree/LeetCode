package main

import "fmt"

type Node struct {
	Val      int
	Children []*Node
}

func levelOrder(root *Node) [][]int {
	if root == nil {
		return [][]int{}
	}
	ret := [][]int{}
	que := []*Node{root}
	for len(que) > 0 {
		nque := []*Node{}
		ret1 := []int{}
		for _, c := range que {
			ret1 = append(ret1, c.Val)
			for _, x := range c.Children {
				nque = append(nque, x)
			}
		}
		ret = append(ret, ret1)
		que = nque
	}
	return ret
}

func main() {
	head := &Node{Val: 1}
	head.Children = append(head.Children, &Node{Val: 3})
	head.Children = append(head.Children, &Node{Val: 2})
	head.Children = append(head.Children, &Node{Val: 4})
	head.Children[0].Children = append(head.Children[0].Children, &Node{Val: 5})
	head.Children[0].Children = append(head.Children[0].Children, &Node{Val: 6})
	ret := levelOrder(head)
	fmt.Println(ret)

	head = &Node{Val: 1}
	head.Children = append(head.Children, &Node{Val: 2})
	head.Children = append(head.Children, &Node{Val: 3})
	head.Children = append(head.Children, &Node{Val: 4})
	head.Children = append(head.Children, &Node{Val: 5})
	head.Children[1].Children = append(head.Children[1].Children, &Node{Val: 6})
	head.Children[1].Children = append(head.Children[1].Children, &Node{Val: 7})
	head.Children[2].Children = append(head.Children[2].Children, &Node{Val: 8})
	head.Children[3].Children = append(head.Children[3].Children, &Node{Val: 9})
	head.Children[3].Children = append(head.Children[3].Children, &Node{Val: 10})
	head.Children[1].Children[1].Children = append(head.Children[1].Children[1].Children, &Node{Val: 11})
	head.Children[1].Children[1].Children[0].Children = append(head.Children[1].Children[1].Children[0].Children, &Node{Val: 14})
	head.Children[2].Children[0].Children = append(head.Children[2].Children[0].Children, &Node{Val: 12})
	head.Children[3].Children[0].Children = append(head.Children[3].Children[0].Children, &Node{Val: 13})
	ret = levelOrder(head)
	fmt.Println(ret)
}
