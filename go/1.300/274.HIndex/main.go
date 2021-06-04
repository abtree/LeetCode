package main

import (
	"fmt"
	"sort"
)

func hIndex(citations []int) int {
	sort.Slice(citations, func(i, j int) bool {
		return citations[i] > citations[j]
	})
	for i := len(citations) - 1; i >= 0; i-- {
		if citations[i] > i {
			return i + 1
		}
	}
	return 0
}

func hIndex2(citations []int) int {
	n := len(citations)
	dp := make([]int, n+1)
	for _, v := range citations {
		if v > n {
			dp[n]++
		} else {
			dp[v]++
		}
	}
	s := 0
	for n > 0 {
		s += dp[n]
		if s >= n {
			return n
		}
		n--
	}
	return 0
}

func main() {
	fmt.Println(hIndex([]int{3, 0, 6, 1, 5}), hIndex2([]int{3, 0, 6, 1, 5}))
	fmt.Println(hIndex([]int{1, 3, 1}), hIndex2([]int{1, 3, 1}))
}
