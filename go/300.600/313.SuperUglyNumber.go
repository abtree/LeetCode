package main

import (
	"container/heap"
	"fmt"
	"sort"
)

type PriQueue struct {
	sort.IntSlice
}

func (pq *PriQueue) Push(x interface{}) {
	pq.IntSlice = append(pq.IntSlice, x.(int))
}

func (pq *PriQueue) Pop() interface{} {
	a := pq.IntSlice
	l := len(a) - 1
	v := a[l]
	pq.IntSlice = a[:l]
	return v
}

func nthSuperUglyNumber(n int, primes []int) int {
	queue := &PriQueue{}
	repeated := map[int]struct{}{}
	cur := 1
	heap.Push(queue, cur)
	repeated[1] = struct{}{}
	for n > 0 {
		cur = heap.Pop(queue).(int)
		for _, v := range primes {
			v *= cur
			if _, ok := repeated[v]; !ok {
				heap.Push(queue, v)
				repeated[v] = struct{}{}
			}
		}
		n--
	}
	return cur
}

func nthSuperUglyNumber1(n int, primes []int) int {
	if n == 1 {
		return 1
	}
	size := len(primes)
	dp := make([]int, n)
	pos := make([]int, size)
	vals := make([]int, size)
	dp[0] = 1
	for i := 1; i < n; i++ {
		for j, v := range pos {
			vals[j] = dp[v] * primes[j]
		}
		dp[i] = minelement(vals)
		for j, v := range vals {
			if dp[i] == v {
				pos[j]++
			}
		}
	}
	return dp[n-1]
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}

func minelement(vals []int) int {
	m := vals[0]
	for _, v := range vals {
		m = min(m, v)
	}
	return m
}

func main() {
	fmt.Println(nthSuperUglyNumber1(12, []int{2, 7, 13, 19}), 32)
}
