package main

import (
	"container/heap"
	"fmt"
)

type pair struct {
	Index int //索引
	Value int //值（用于排序）
}
type priorityQueue []*pair

func (pq priorityQueue) Len() int { return len(pq) }
func (pq priorityQueue) Less(i, j int) bool {
	return pq[i].Value > pq[j].Value
}
func (pq priorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}
func (pq *priorityQueue) Push(x interface{}) {
	pr := x.(*pair)
	*pq = append(*pq, pr)
}
func (pq *priorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	pr := old[n-1]
	*pq = old[:n-1]
	return pr
}

func maxSlidingWindow(nums []int, k int) []int {
	//通过优先队完成
	pq := make(priorityQueue, 0)
	heap.Init(&pq)
	for i := 0; i < k; i++ {
		heap.Push(&pq, &pair{Index: i, Value: nums[i]})
	}
	ret := []int{pq[0].Value}
	for i := k; i < len(nums); i++ {
		heap.Push(&pq, &pair{Index: i, Value: nums[i]})
		for pq[0].Index <= i-k {
			heap.Pop(&pq)
		}
		ret = append(ret, pq[0].Value)
	}
	return ret
}

func maxSlidingWindow2(nums []int, k int) []int {
	//通过单调队列
	n := len(nums)
	dp := make([]int, n)
	head, tail := 0, -1
	ret := []int{}
	for i, v := range nums {
		for tail >= head && v >= nums[dp[tail]] {
			tail--
		}
		tail++
		dp[tail] = i
		if i < k-1 {
			continue
		}
		for dp[head] <= i-k {
			head++
		}
		ret = append(ret, nums[dp[head]])
	}
	return ret
}

func main() {
	fmt.Println(maxSlidingWindow2([]int{1, 3, -1, -3, 5, 3, 6, 7}, 3))
	fmt.Println(maxSlidingWindow2([]int{1}, 1))
	fmt.Println(maxSlidingWindow2([]int{1, -1}, 1))
	fmt.Println(maxSlidingWindow2([]int{9, 11}, 2))
	fmt.Println(maxSlidingWindow2([]int{4, -2}, 2))
}
