package main

import (
	"container/heap"
	"fmt"
	"sort"
)

type HighPriQueue struct {
	sort.IntSlice
}

func (pq *HighPriQueue) Push(x interface{}) {
	pq.IntSlice = append(pq.IntSlice, x.(int))
}

func (pq *HighPriQueue) Pop() interface{} {
	a := pq.IntSlice
	v := a[len(a)-1]
	pq.IntSlice = a[:len(a)-1]
	return v
}

func (pq *HighPriQueue) Top() float64 {
	return float64(pq.IntSlice[0])
}

type LowPriQueue struct {
	HighPriQueue
}

func (pq *LowPriQueue) Less(i int, j int) bool {
	if pq.IntSlice[i] > pq.IntSlice[j] {
		return true
	}
	return false
}

type MedianFinder struct {
	*LowPriQueue
	*HighPriQueue
}

/** initialize your data structure here. */
func Constructor() MedianFinder {
	return MedianFinder{
		LowPriQueue:  &LowPriQueue{},
		HighPriQueue: &HighPriQueue{},
	}
}

func (this *MedianFinder) AddNum(num int) {
	heap.Push(this.LowPriQueue, num)
	heap.Push(this.HighPriQueue, heap.Pop(this.LowPriQueue))
	if this.LowPriQueue.Len() < this.HighPriQueue.Len() {
		heap.Push(this.LowPriQueue, heap.Pop(this.HighPriQueue))
	}
}

func (this *MedianFinder) FindMedian() float64 {
	if this.LowPriQueue.Len() != this.HighPriQueue.Len() {
		return this.LowPriQueue.Top()
	}
	return (this.LowPriQueue.Top() + this.HighPriQueue.Top()) * 0.5
}

func main() {
	cls := Constructor()
	cls.AddNum(1)
	cls.AddNum(6)
	fmt.Println(cls.FindMedian(), 3.5)
	cls.AddNum(2)
	fmt.Println(cls.FindMedian(), 2)
	cls.AddNum(5)
	fmt.Println(cls.FindMedian(), 3.5)
	cls.AddNum(3)
	fmt.Println(cls.FindMedian(), 3)
	cls.AddNum(4)
	fmt.Println(cls.FindMedian(), 3.5)
}
