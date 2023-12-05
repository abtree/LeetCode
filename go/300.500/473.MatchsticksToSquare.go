package main

import (
	"fmt"
	"sort"
)

func makesquare(matchsticks []int) bool {
	sum := 0
	for _, x := range matchsticks {
		sum += x
	}
	if sum%4 != 0 {
		return false
	}
	sort.Slice(matchsticks, func(i, j int) bool {
		return matchsticks[i] > matchsticks[j]
	})
	elen := sum / 4
	var dfs func(index int) bool
	edges := make([]int, 4)
	size := len(matchsticks)
	dfs = func(index int) bool {
		if index == size {
			return true
		}
		for i := range edges {
			edges[i] += matchsticks[index]
			if edges[i] <= elen {
				if dfs(index + 1) {
					return true
				}
			}
			edges[i] -= matchsticks[index]
		}
		return false
	}
	return dfs(0)
}

func makesquare1(matchsticks []int) bool {
	sum := 0
	for _, x := range matchsticks {
		sum += x
	}
	if sum%4 != 0 {
		return false
	}
	elen := sum / 4
	dp := make([]int, 1<<len(matchsticks))
	for i := range dp {
		dp[i] = -1
	}
	dp[0] = 0
	for s := 1; s < len(dp); s++ {
		for k, v := range matchsticks {
			if s>>k&1 == 0 {
				continue
			}
			s1 := s &^ (1 << k)
			if dp[s1] >= 0 && dp[s1]+v <= elen {
				dp[s] = (dp[s1] + v) % elen
				break
			}
		}
	}
	return dp[len(dp)-1] == 0
}

func main() {
	fmt.Println(makesquare1([]int{1, 1, 2, 2, 2}), true)
	fmt.Println(makesquare1([]int{3, 3, 3, 3, 4}), false)
}
