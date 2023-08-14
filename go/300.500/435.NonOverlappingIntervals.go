package main

import (
	"fmt"
	"sort"
)

func eraseOverlapIntervals(intervals [][]int) int {
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})
	n := len(intervals)
	dp := make([]int, n)
	dp[0] = 1
	for i := 1; i < n; i++ {
		dp[i] = 1
		for j := 0; j < i; j++ {
			if intervals[i][0] >= intervals[j][1] {
				dp[i] = max(dp[i], dp[j]+1)
			}
		}
	}
	r := 1
	for _, x := range dp {
		r = max(x, r)
	}
	return n - r
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func eraseOverlapIntervals1(intervals [][]int) int {
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})
	last := intervals[0]
	n := len(intervals)
	cnt := 1
	for i := 1; i < n; i++ {
		if intervals[i][0] >= last[1] {
			last = intervals[i]
			cnt++
			continue
		}
		if intervals[i][1] < last[1] {
			last = intervals[i]
		}
	}
	return n - cnt
}

func main() {
	fmt.Println(eraseOverlapIntervals1([][]int{{1, 2}, {2, 3}, {3, 4}, {1, 3}}), 1)
	fmt.Println(eraseOverlapIntervals1([][]int{{1, 2}, {1, 2}, {1, 2}}), 2)
	fmt.Println(eraseOverlapIntervals1([][]int{{1, 2}, {2, 3}}), 0)
}
