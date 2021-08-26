package main

import (
	"fmt"
	"math"
)

func countNumbersWithUniqueDigits(n int) int {
	if n == 0 {
		return 1
	}
	ans, dec, sum := 10, 9, 9
	for i := 1; i < n; i++ {
		sum *= dec
		dec--
		ans += sum
	}
	return ans
}

func countNumbersWithUniqueDigits1(n int) int {
	dp := make([]int, n+1)
	for i := 2; i <= n; i++ {
		dp[i] = dp[i-1] * 10
		dp[i] += (9*int(math.Pow(10, float64(i-2))) - dp[i-1]) * (i - 1)
	}
	sum := 0
	for _, v := range dp {
		sum += v
	}
	return int(math.Pow(10, float64(n))) - sum
}

func main() {
	fmt.Println(countNumbersWithUniqueDigits(2), countNumbersWithUniqueDigits1(2), 91)
}
