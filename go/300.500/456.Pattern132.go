package main

import (
	"fmt"
	"math"
	"math/rand"
)

type node struct {
	//二叉树的左右节点
	ch       [2]*node
	priority int
	val      int
	cnt      int
}

func (this *node) cmp(b int) int {
	switch {
	case b < this.val:
		return 0
	case b > this.val:
		return 1
	default:
		return -1
	}
}

func (this *node) rotate(d int) *node {
	x := this.ch[d^1]
	this.ch[d^1] = x.ch[d]
	x.ch[d] = this
	return x
}

type treap struct {
	root *node
}

func (this *treap) _put(o *node, val int) *node {
	if o == nil {
		return &node{priority: rand.Int(), val: val, cnt: 1}
	}
	if d := o.cmp(val); d >= 0 {
		o.ch[d] = this._put(o.ch[d], val)
		if o.ch[d].priority > o.priority {
			o = o.rotate(d ^ 1)
		}
	} else {
		o.cnt++
	}
	return o
}

func (this *treap) put(val int) {
	this.root = this._put(this.root, val)
}

func (this *treap) _delete(o *node, val int) *node {
	if o == nil {
		return nil
	}
	if d := o.cmp(val); d >= 0 {
		o.ch[d] = this._delete(o.ch[d], val)
		return o
	}
	if o.cnt > 1 {
		o.cnt--
		return o
	}
	if o.ch[1] == nil {
		return o.ch[0]
	}
	if o.ch[0] == nil {
		return o.ch[1]
	}
	d := 0
	if o.ch[0].priority > o.ch[1].priority {
		d = 1
	}
	o = o.rotate(d)
	o.ch[d] = this._delete(o.ch[d], val)
	return o
}

func (this *treap) delete(val int) {
	this.root = this._delete(this.root, val)
}

func (this *treap) upperBound(val int) (ub *node) {
	for o := this.root; o != nil; {
		if o.cmp(val) == 0 {
			ub = o
			o = o.ch[0]
		} else {
			o = o.ch[1]
		}
	}
	return
}

func find132pattern(nums []int) bool {
	n := len(nums)
	if n < 3 {
		return false
	}
	leftMin := nums[0]
	rights := &treap{}
	for _, v := range nums[2:] {
		rights.put(v)
	}
	for j := 1; j < n-1; j++ {
		if nums[j] > leftMin {
			ub := rights.upperBound(leftMin)
			if ub != nil && ub.val < nums[j] {
				return true
			}
		} else {
			leftMin = nums[j]
		}
		rights.delete(nums[j+1])
	}
	return false
}

func find132pattern1(nums []int) bool {
	n := len(nums)
	if n < 3 {
		return false
	}
	candidateK := []int{nums[n-1]}
	maxK := math.MinInt64
	for i := n - 2; i >= 0; i-- {
		if nums[i] < maxK {
			return true
		}
		for len(candidateK) > 0 && nums[i] > candidateK[len(candidateK)-1] {
			maxK = candidateK[len(candidateK)-1]
			candidateK = candidateK[:len(candidateK)-1]
		}
		if nums[i] > maxK {
			candidateK = append(candidateK, nums[i])
		}
	}
	return false
}

func main() {
	fmt.Println(find132pattern1([]int{1, 2, 3, 4}), false)
	fmt.Println(find132pattern1([]int{3, 1, 4, 2}), true)
	fmt.Println(find132pattern1([]int{-1, 3, 2, 0}), true)
}
