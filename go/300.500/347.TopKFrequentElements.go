package main

import (
	"fmt"
	"sort"
)

type Pair struct {
	Key, Value int
}

func topKFrequent(nums []int, k int) []int {
	dp := map[int]int{}
	for _, v := range nums {
		dp[v]++
	}
	sce := []*Pair{}
	for k, v := range dp {
		sce = append(sce, &Pair{Key: v, Value: k})
	}
	sort.Slice(sce, func(i, j int) bool {
		return sce[i].Key > sce[j].Key
	})
	ret := make([]int, k)
	for i := 0; i < k; i++ {
		ret[i] = sce[i].Value
	}
	return ret
}

func main() {
	fmt.Println(topKFrequent([]int{1, 1, 1, 2, 2, 3}, 2))
	fmt.Println(topKFrequent([]int{1}, 1))
}
