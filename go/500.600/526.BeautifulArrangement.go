package main

import (
	"fmt"
	"math/bits"
)

func countArrangement(n int) int {
	dp := make([][]int, n+1)
	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			if i%j == 0 || j%i == 0 {
				dp[i] = append(dp[i], j)
			}
		}
	}
	used := make([]int, n+1)
	ans := 0
	var dfs func(i int)
	dfs = func(i int) {
		if i > n {
			ans++
			return
		}
		for _, v := range dp[i] {
			if used[v] == 1 {
				continue
			}
			used[v] = 1
			dfs(i + 1)
			used[v] = 0
		}
	}
	dfs(1)
	return ans
}

func countArrangement1(n int) int {
	dp := make([]int, 1<<n)
	dp[0] = 1
	for mask := 1; mask < (1 << n); mask++ {
		num := bits.OnesCount(uint(mask))
		for i := 0; i < n; i++ {
			if mask>>i&1 > 0 && (num%(i+1) == 0 || (i+1)%num == 0) {
				dp[mask] += dp[mask^1<<i]
			}
		}
	}
	return dp[(1<<n)-1]
}

func main() {
	fmt.Println(countArrangement1(2), 2)
	fmt.Println(countArrangement1(1), 1)
	fmt.Println(countArrangement1(15), 24679)
}
