package main

import (
	"fmt"
)

func findMaxLength(nums []int) int {
	sum := 0
	ans := 0
	dp := map[int]int{}
	for i, v := range nums {
		if v > 0 {
			sum++
		} else {
			sum--
		}
		if sum == 0 {
			ans = i + 1
		} else if j, ok := dp[sum]; ok {
			ans = max(ans, i-j)
		} else {
			dp[sum] = i
		}
	}
	return ans
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func main() {
	fmt.Println(findMaxLength([]int{0, 1}), 2)
	fmt.Println(findMaxLength([]int{0, 1, 0}), 2)
	fmt.Println(findMaxLength([]int{0, 1, 1}), 2)
}
