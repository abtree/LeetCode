package main

import (
	"container/heap"
	"fmt"
	"sort"
)

type hp struct {
	sort.IntSlice
}

func (h *hp) Less(i int, j int) bool {
	return h.IntSlice[i] > h.IntSlice[j]
}

func (h *hp) Push(x any) {
	h.IntSlice = append(h.IntSlice, x.(int))
}

func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}

type pair struct {
	c, p int
}

func findMaximizedCapital(k int, w int, profits []int, capital []int) int {
	n := len(profits)
	arr := make([]*pair, n)
	for i, p := range profits {
		arr[i] = &pair{c: capital[i], p: p}
	}
	sort.Slice(arr, func(i, j int) bool {
		return arr[i].c < arr[j].c
	})
	h := &hp{}
	for cur := 0; k > 0; k-- {
		for cur < n && arr[cur].c <= w {
			heap.Push(h, arr[cur].p)
			cur++
		}
		if h.Len() == 0 {
			break
		}
		w += heap.Pop(h).(int)
	}
	return w
}

func main() {
	fmt.Println(findMaximizedCapital(2, 0, []int{1, 2, 3}, []int{0, 1, 1}), 4)
	fmt.Println(findMaximizedCapital(3, 0, []int{1, 2, 3}, []int{0, 1, 2}), 6)
}
