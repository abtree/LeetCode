package main

import (
	"fmt"
	"sort"
)

func findRightInterval(intervals [][]int) []int {
	n := len(intervals)
	kv := make(map[int]int, n)
	for i, x := range intervals {
		kv[x[0]] = i
	}
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})
	fn := func(start int) int {
		for i := start; i < n; i++ {
			if intervals[i][0] >= intervals[start][1] {
				return kv[intervals[i][0]]
			}
		}
		return -1
	}
	ret := make([]int, n)
	for i, x := range intervals {
		k := kv[x[0]]
		ret[k] = fn(i)
	}
	return ret
}

func findRightInterval1(intervals [][]int) []int {
	n := len(intervals)
	dp := make([][]int, n)
	for i, x := range intervals {
		dp[i] = []int{x[0], i}
	}
	sort.Slice(dp, func(i, j int) bool {
		return dp[i][0] < dp[j][0]
	})
	ret := make([]int, n)
	for i, x := range intervals {
		j := sort.Search(n, func(j int) bool {
			return dp[j][0] >= x[1]
		})
		if j < n {
			ret[i] = dp[j][1]
		} else {
			ret[i] = -1
		}
	}
	return ret
}

func findRightInterval2(intervals [][]int) []int {
	for i := range intervals {
		intervals[i] = append(intervals[i], i)
	}
	n := len(intervals)
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})
	ret := make([]int, n)
	for _, x := range intervals {
		j := sort.Search(n, func(j int) bool {
			return intervals[j][0] >= x[1]
		})
		if j < n {
			ret[x[2]] = intervals[j][2]
		} else {
			ret[x[2]] = -1
		}
	}
	return ret
}

func main() {
	fmt.Println(findRightInterval2([][]int{{1, 2}}))
	fmt.Println(findRightInterval2([][]int{{3, 4}, {2, 3}, {1, 2}}))
	fmt.Println(findRightInterval2([][]int{{1, 4}, {2, 3}, {3, 4}}))
	fmt.Println(findRightInterval2([][]int{{1, 1}, {3, 4}}))
}
