package main

import (
	"fmt"
	"math"
)

func integerBreak(n int) int {
	dp := make([]int, n+1)
	for i := 2; i <= n; i++ {
		curMax := 0
		for j := 1; j <= i/2; j++ {
			curMax = max(curMax, max(j*(i-j), j*dp[i-j]))
		}
		dp[i] = curMax
	}
	return dp[n]
}

func integerBreak1(n int) int {
	if n < 4 {
		return n - 1
	}
	dev := n / 3
	rem := n % 3
	if rem == 0 {
		return int(math.Pow(3, float64(dev)))
	} else if rem == 2 {
		return int(math.Pow(3, float64(dev))) * 2
	} else {
		return int(math.Pow(3, float64(dev-1))) * 4
	}
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func main() {
	fmt.Println(integerBreak1(2), 1)
	fmt.Println(integerBreak1(10), 36)
}
