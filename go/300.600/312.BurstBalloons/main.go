package main

import "fmt"

func maxCoins(nums []int) int {
	n := len(nums)
	vals := make([]int, 0, n+2)
	vals = append(vals, 1)
	vals = append(vals, nums...)
	vals = append(vals, 1)
	dp := make([][]int, n+2)
	for i, _ := range dp {
		dp[i] = make([]int, n+2)
		for j := range dp[i] {
			dp[i][j] = -1
		}
	}
	var solve func(start, end int) int
	solve = func(start, end int) int {
		if start >= end-1 {
			return 0
		}
		if dp[start][end] != -1 {
			return dp[start][end]
		}
		for k := start + 1; k < end; k++ {
			sum := vals[start] * vals[k] * vals[end]
			sum += solve(start, k)
			sum += solve(k, end)
			dp[start][end] = max(dp[start][end], sum)
		}
		return dp[start][end]
	}
	return solve(0, n+1)
}

func maxCoins1(nums []int) int {
	n := len(nums)
	vals := make([]int, 0, n+2)
	vals = append(vals, 1)
	vals = append(vals, nums...)
	vals = append(vals, 1)
	dp := make([][]int, n+2)
	for i := range dp {
		dp[i] = make([]int, n+2)
	}
	for i := n - 1; i >= 0; i-- {
		for j := i + 2; j <= n+1; j++ {
			for k := i + 1; k < j; k++ {
				sum := vals[i] * vals[k] * vals[j]
				sum += dp[i][k]
				sum += dp[k][j]
				dp[i][j] = max(sum, dp[i][j])
			}
		}
	}
	return dp[0][n+1]
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func main() {
	fmt.Println(maxCoins([]int{3, 1, 5, 8}), maxCoins1([]int{3, 1, 5, 8}), 167)
	fmt.Println(maxCoins([]int{1, 5}), maxCoins1([]int{1, 5}), 10)
}
