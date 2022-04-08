package main

import "fmt"

func canPartition(nums []int) bool {
	sum, max := 0, 0
	for _, x := range nums {
		sum += x
		if x > max {
			max = x
		}
	}
	if sum&1 == 1 {
		return false
	}
	sum >>= 1
	if sum < max {
		return false
	}
	n := len(nums)
	dp := make([][]bool, n)
	for i := range dp {
		dp[i] = make([]bool, sum+1)
	}
	for i := 0; i < n; i++ {
		dp[i][0] = true
	}
	dp[0][nums[0]] = true
	for i := 1; i < n; i++ {
		for j := 1; j <= sum; j++ {
			if j < nums[i] {
				dp[i][j] = dp[i-1][j]
			} else {
				dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]]
			}
		}
	}
	return dp[n-1][sum]
}

func main() {
	fmt.Println(canPartition([]int{100, 100, 99, 97}), false)
	fmt.Println(canPartition([]int{1, 5, 11, 5}), true)
	fmt.Println(canPartition([]int{1, 2, 3, 5}), false)
}
