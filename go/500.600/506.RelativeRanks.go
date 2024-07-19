package main

import (
	"fmt"
	"sort"
	"strconv"
)

type pair struct {
	a, b int
}

func findRelativeRanks(score []int) []string {
	dp := make([]*pair, len(score))
	for i, v := range score {
		dp[i] = &pair{a: v, b: i}
	}
	sort.Slice(dp, func(i, j int) bool {
		return dp[i].a > dp[j].a
	})
	ans := make([]string, len(score))
	for i, v := range dp {
		if i == 0 {
			ans[v.b] = "Gold Medal"
		} else if i == 1 {
			ans[v.b] = "Silver Medal"
		} else if i == 2 {
			ans[v.b] = "Bronze Medal"
		} else {
			ans[v.b] = strconv.Itoa(i + 1)
		}
	}
	return ans
}

func main() {
	fmt.Println(findRelativeRanks([]int{5, 4, 3, 2, 1}), `["Gold Medal","Silver Medal","Bronze Medal","4","5"]`)
	fmt.Println(findRelativeRanks([]int{10, 3, 8, 9, 4}), `["Gold Medal","5","Bronze Medal","Silver Medal","4"]`)
}
