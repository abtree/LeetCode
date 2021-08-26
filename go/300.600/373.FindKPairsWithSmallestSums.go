package main

import (
	"container/heap"
	"fmt"
)

type priCell struct {
	Val  int
	PosX int
	PoxY int
}

type priorityQueue []*priCell

// Len is the number of elements in the collection.
func (this priorityQueue) Len() int {
	return len(this)
}

// Less reports whether the element with
// index i should sort before the element with index j.
func (this priorityQueue) Less(i int, j int) bool {
	return this[i].Val < this[j].Val
}

// Swap swaps the elements with indexes i and j.
func (this priorityQueue) Swap(i int, j int) {
	this[i], this[j] = this[j], this[i]
}

func (this *priorityQueue) Push(x interface{}) {
	*this = append(*this, x.(*priCell))
}

func (this *priorityQueue) Pop() interface{} {
	old := *this
	ret := old[len(old)-1]
	*this = old[:len(old)-1]
	return ret
}

func kSmallestPairs(nums1 []int, nums2 []int, k int) [][]int {
	pq := &priorityQueue{}
	heap.Init(pq)
	for i := 0; i < k && i < len(nums1); i++ {
		heap.Push(pq, &priCell{
			Val:  nums1[i] + nums2[0],
			PosX: i,
			PoxY: 0,
		})
	}
	ret := [][]int{}
	for k > 0 && len(*pq) > 0 {
		k--
		ids := heap.Pop(pq).(*priCell)
		ret = append(ret, []int{nums1[ids.PosX], nums2[ids.PoxY]})
		if ids.PoxY < len(nums2)-1 {
			heap.Push(pq, &priCell{
				Val:  nums1[ids.PosX] + nums2[ids.PoxY+1],
				PosX: ids.PosX,
				PoxY: ids.PoxY + 1,
			})
		}
	}
	return ret
}

func main() {
	fmt.Println(kSmallestPairs([]int{-10, -4, 0, 0, 6}, []int{3, 5, 6, 7, 8, 100}, 10))
	fmt.Println(kSmallestPairs([]int{1, 1, 2}, []int{1, 2, 3}, 10))
	fmt.Println(kSmallestPairs([]int{1, 7, 11}, []int{2, 4, 6}, 3))
	fmt.Println(kSmallestPairs([]int{1, 1, 2}, []int{1, 2, 3}, 2))
	fmt.Println(kSmallestPairs([]int{1, 2}, []int{3}, 3))
}
