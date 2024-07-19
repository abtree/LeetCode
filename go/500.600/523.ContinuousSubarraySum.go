package main

import (
	"fmt"
)

func checkSubarraySum(nums []int, k int) bool {
	sum := 0
	dp := map[int]int{0: -1}
	for i, v := range nums {
		sum += v
		rem := sum % k
		if j, ok := dp[rem]; ok {
			if i-j > 1 {
				return true
			}
		} else {
			dp[rem] = i
		}
	}
	return false
}

func main() {
	fmt.Println(checkSubarraySum([]int{23, 2, 4, 6, 7}, 6), true)
	fmt.Println(checkSubarraySum([]int{23, 2, 6, 4, 7}, 6), true)
	fmt.Println(checkSubarraySum([]int{23, 2, 6, 4, 7}, 13), false)
}
