package main

import (
	"container/heap"
	"fmt"
	"sort"
)

type priqueue struct {
	sort.IntSlice
}

func (pq *priqueue) Push(x interface{}) {
	pq.IntSlice = append(pq.IntSlice, x.(int))
}

func (pq *priqueue) Pop() interface{} {
	a := pq.IntSlice
	v := a[len(a)-1]
	pq.IntSlice = a[:len(a)-1]
	return v
}

func nthUglyNumber(n int) int {
	seen := map[int]struct{}{}
	q := &priqueue{IntSlice: sort.IntSlice{1}}
	fact := []int{2, 3, 5}
	ugly := 0
	for n > 0 {
		ugly = heap.Pop(q).(int)
		for _, v := range fact {
			v *= ugly
			if _, ok := seen[v]; !ok {
				heap.Push(q, v)
				seen[v] = struct{}{}
			}
		}
		n--
	}
	return ugly
}

func nthUglyNumber2(n int) int {
	dp := make([]int, n)
	dp[0] = 1
	p2, p3, p5 := 0, 0, 0
	for i := 1; i < n; i++ {
		n2, n3, n5 := dp[p2]*2, dp[p3]*3, dp[p5]*5
		dp[i] = min(min(n2, n3), n5)
		if dp[i] == n2 {
			p2++
		}
		if dp[i] == n3 {
			p3++
		}
		if dp[i] == n5 {
			p5++
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

func main() {
	fmt.Println(nthUglyNumber2(10), 12)
	fmt.Println(nthUglyNumber2(1), 1)
	fmt.Println(nthUglyNumber2(1407), 536870912)
}
