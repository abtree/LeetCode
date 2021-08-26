package main

import (
	"fmt"
	"math"
	"math/rand"
)

type node struct {
	ch       [2]*node
	priority int
	val      int
}

func (o *node) cmp(b int) int {
	switch {
	case b < o.val: //左子树
		return 0
	case b > o.val: //右子树
		return 1
	default:
		return -1 //当前节点
	}
}

// 将其中一个子节点提为父节点，保持树的平衡
func (o *node) rotate(d int) *node {
	x := o.ch[d^1]
	o.ch[d^1] = x.ch[d]
	x.ch[d] = o
	return x
}

type treap struct {
	root *node
}

func (t *treap) _put(o *node, val int) *node {
	if o == nil {
		return &node{priority: rand.Int(), val: val}
	}
	if d := o.cmp(val); d >= 0 {
		o.ch[d] = t._put(o.ch[d], val)
		if o.ch[d].priority > o.priority {
			o = o.rotate(d ^ 1)
		}
	}
	return o
}

func (t *treap) put(val int) {
	t.root = t._put(t.root, val)
}

func (t *treap) lowerBound(val int) (lb *node) {
	for o := t.root; o != nil; {
		switch c := o.cmp(val); {
		case c == 0: //查找左子树
			lb = o
			o = o.ch[0]
		case c > 0: //查找右子树
			o = o.ch[1]
		default:
			return o //返回当前节点
		}
	}
	return
}

func maxSumSubmatrix(matrix [][]int, k int) int {
	ans := math.MinInt32
	for i := range matrix {
		sum := make([]int, len(matrix[0]))
		for _, row := range matrix[i:] {
			for c, v := range row {
				sum[c] += v
			}
			t := &treap{}
			t.put(0)
			s := 0
			for _, v := range sum {
				s += v
				if lb := t.lowerBound(s - k); lb != nil {
					ans = max(ans, s-lb.val)
				}
				t.put(s)
			}
		}
	}
	return ans
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	fmt.Println(maxSumSubmatrix([][]int{{1, 0, 1}, {0, -2, 3}}, 2), 2)
	fmt.Println(maxSumSubmatrix([][]int{{2, 2, -1}}, 3), 3)
}
