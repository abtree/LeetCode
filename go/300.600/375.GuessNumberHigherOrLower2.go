package main

import (
	"fmt"
	"math"
)

func getMoneyAmount(n int) int {
	if n <= 1 {
		return 0
	}
	tmp := make([]int, (n+1)*(n+1))
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i], tmp = tmp[:n+1], tmp[n+1:]
	}
	for j := 2; j <= n; j++ {
		for i := j - 1; i >= 1; i-- {
			dp[i][j] = math.MaxInt32
			for k := i + 1; k < j; k++ {
				dp[i][j] = min(k+max(dp[i][k-1], dp[k+1][j]), dp[i][j])
			}
			dp[i][j] = min(dp[i][j], i+dp[i+1][j])
			dp[i][j] = min(dp[i][j], j+dp[i][j-1])
		}
	}
	return dp[1][n]
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func main() {
	fmt.Println(getMoneyAmount(10), 16)
	fmt.Println(getMoneyAmount(50), 172)
}
