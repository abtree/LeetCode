package main

import "fmt"

type Node struct {
	Val         bool
	IsLeaf      bool
	TopLeft     *Node
	TopRight    *Node
	BottomLeft  *Node
	BottomRight *Node
}

func (t *Node) print() {
	fmt.Printf("[%v,%v]", t.Val, t.IsLeaf)
}

func intersect(quadTree1 *Node, quadTree2 *Node) *Node {
	if quadTree1.IsLeaf {
		if quadTree1.Val {
			return &Node{Val: true, IsLeaf: true}
		}
		return quadTree2
	}
	if quadTree2.IsLeaf {
		return intersect(quadTree2, quadTree1)
	}
	o1 := intersect(quadTree1.TopLeft, quadTree2.TopLeft)
	o2 := intersect(quadTree1.TopRight, quadTree2.TopRight)
	o3 := intersect(quadTree1.BottomLeft, quadTree2.BottomLeft)
	o4 := intersect(quadTree1.BottomRight, quadTree2.BottomRight)
	if o1.IsLeaf && o2.IsLeaf && o3.IsLeaf && o4.IsLeaf && o1.Val == o2.Val && o1.Val == o3.Val && o1.Val == o4.Val {
		return &Node{Val: o1.Val, IsLeaf: true}
	}
	return &Node{Val: false, IsLeaf: false, TopLeft: o1, TopRight: o2, BottomLeft: o3, BottomRight: o4}
}

func print(h *Node) {
	h.print()
	if h.TopLeft != nil {
		print(h.TopLeft)
	}
	if h.TopRight != nil {
		print(h.TopRight)
	}
	if h.BottomLeft != nil {
		print(h.BottomLeft)
	}
	if h.BottomRight != nil {
		print(h.BottomRight)
	}
}

func main() {
	head1 := &Node{Val: true, IsLeaf: false}
	head1.TopLeft = &Node{Val: true, IsLeaf: true}
	head1.TopRight = &Node{Val: true, IsLeaf: true}
	head1.BottomLeft = &Node{Val: false, IsLeaf: true}
	head1.BottomRight = &Node{Val: false, IsLeaf: true}
	head2 := &Node{Val: true, IsLeaf: false}
	head2.TopLeft = &Node{Val: true, IsLeaf: true}
	head2.TopRight = &Node{Val: true, IsLeaf: false}
	head2.BottomLeft = &Node{Val: true, IsLeaf: true}
	head2.BottomRight = &Node{Val: false, IsLeaf: true}
	head2.TopRight.TopLeft = &Node{Val: false, IsLeaf: true}
	head2.TopRight.TopRight = &Node{Val: false, IsLeaf: true}
	head2.TopRight.BottomLeft = &Node{Val: true, IsLeaf: true}
	head2.TopRight.BottomRight = &Node{Val: true, IsLeaf: true}
	ret := intersect(head1, head2)
	print(ret)
}
