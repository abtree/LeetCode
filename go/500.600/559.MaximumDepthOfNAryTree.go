package main

import "fmt"

type Node struct {
	Val      int
	Children []*Node
}

func maxDepth(root *Node) int {
	if root == nil {
		return 0
	}
	queue := []*Node{root}
	depth := 0
	for len(queue) > 0 {
		new_queue := []*Node{}
		depth++
		for _, cur := range queue {
			new_queue = append(new_queue, cur.Children...)
		}
		queue = new_queue
	}
	return depth
}

func main() {
	head := &Node{
		Val: 1,
		Children: []*Node{
			&Node{Val: 3, Children: []*Node{&Node{Val: 5}, &Node{Val: 6}}},
			&Node{Val: 2},
			&Node{Val: 4},
		},
	}
	fmt.Println(maxDepth(head), 3)

	head = &Node{Val: 1, Children: []*Node{
		&Node{Val: 2},
		&Node{Val: 3, Children: []*Node{
			&Node{Val: 6},
			&Node{Val: 7, Children: []*Node{
				&Node{Val: 11, Children: []*Node{
					&Node{Val: 14},
				}},
			}},
		}},
		&Node{Val: 4, Children: []*Node{
			&Node{Val: 8, Children: []*Node{
				&Node{Val: 12},
			}},
		}},
		&Node{Val: 5, Children: []*Node{
			&Node{Val: 9, Children: []*Node{
				&Node{Val: 13},
			}},
			&Node{Val: 10},
		}},
	}}
	fmt.Println(maxDepth(head), 5)
}
