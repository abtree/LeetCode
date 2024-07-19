package main

import (
	"fmt"
)

func findTargetSumWays(nums []int, target int) int {
	size := len(nums)
	var dfs func(pos, sum int) int
	dfs = func(pos, sum int) int {
		if pos >= size {
			if sum == target {
				return 1
			}
			return 0
		}
		n1 := dfs(pos+1, sum+nums[pos])
		n2 := dfs(pos+1, sum-nums[pos])
		return n1 + n2
	}
	return dfs(0, 0)
}

func findTargetSumWays1(nums []int, target int) int {
	sum := 0
	for _, v := range nums {
		sum += v
	}
	neg := sum - target
	if neg < 0 || neg&1 == 1 {
		return 0
	}
	neg >>= 1

	dp := make([]int, neg+1)
	dp[0] = 1
	for _, v := range nums {
		for j := neg; j >= v; j-- {
			dp[j] += dp[j-v]
		}
	}
	return dp[neg]
}

func main() {
	fmt.Println(findTargetSumWays1([]int{1, 1, 1, 1, 1}, 3), 5)
	fmt.Println(findTargetSumWays1([]int{1}, 1), 1)
}
