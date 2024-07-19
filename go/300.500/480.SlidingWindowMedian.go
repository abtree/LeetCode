package main

import (
	"container/heap"
	"fmt"
	"sort"
)

type hp struct {
	sort.IntSlice
	size int
}

func (h *hp) Push(v interface{}) {
	h.IntSlice = append(h.IntSlice, v.(int))
}
func (h *hp) Pop() interface{} {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
func (h *hp) push(v int) {
	h.size++
	heap.Push(h, v)
}
func (h *hp) pop() int {
	h.size--
	return heap.Pop(h).(int)
}
func (h *hp) prune(d *DualHeap) {
	for h.Len() > 0 {
		num := h.IntSlice[0]
		if h == d.small {
			num = -num
		}
		if x, has := d.delayed[num]; has {
			if x > 1 {
				d.delayed[num]--
			} else {
				delete(d.delayed, num)
			}
			heap.Pop(h)
		} else {
			break
		}
	}
}

type DualHeap struct {
	delayed map[int]int
	small   *hp
	large   *hp
	k       int
}

func NewDualHeap(k int) *DualHeap {
	return &DualHeap{
		delayed: make(map[int]int),
		small:   &hp{},
		large:   &hp{},
		k:       k,
	}
}

func (d *DualHeap) makeBalance() {
	if d.small.size > d.large.size+1 {
		d.large.push(-d.small.pop())
		d.small.prune(d)
	} else if d.small.size < d.large.size {
		d.small.push(-d.large.pop())
		d.large.prune(d)
	}
}

func (d *DualHeap) insert(num int) {
	if d.small.Len() == 0 || num <= -d.small.IntSlice[0] {
		d.small.push(-num)
	} else {
		d.large.push(num)
	}
	d.makeBalance()
}

func (d *DualHeap) erase(num int) {
	d.delayed[num]++
	if num <= -d.small.IntSlice[0] {
		d.small.size--
		if num == -d.small.IntSlice[0] {
			d.small.prune(d)
		}
	} else {
		d.large.size--
		if num == d.large.IntSlice[0] {
			d.large.prune(d)
		}
	}
	d.makeBalance()
}

func (d *DualHeap) getMedian() float64 {
	if d.k&1 > 0 {
		return float64(-d.small.IntSlice[0])
	}
	return float64(-d.small.IntSlice[0]+d.large.IntSlice[0]) / 2
}

func medianSlidingWindow(nums []int, k int) []float64 {
	dp := NewDualHeap(k)
	for _, num := range nums[:k] {
		dp.insert(num)
	}
	n := len(nums)
	ans := make([]float64, 1, n-k+1)
	ans[0] = dp.getMedian()
	for i := k; i < n; i++ {
		dp.insert(nums[i])
		dp.erase(nums[i-k])
		ans = append(ans, dp.getMedian())
	}
	return ans
}

func main() {
	fmt.Println(medianSlidingWindow([]int{1, 3, -1, -3, 5, 3, 6, 7}, 3), "[1,-1,-1,3,5,6]")
	fmt.Println(medianSlidingWindow([]int{1, 2, 3, 4, 2, 3, 1, 4, 2}, 3), "[2,3,3,3,2,3,2]")
}
