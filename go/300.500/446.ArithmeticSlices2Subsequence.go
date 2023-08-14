package main

import "fmt"

func numberOfArithmeticSlices(nums []int) int {
	n := len(nums)
	dp := make([]map[int]int, n)
	ret := 0
	for i := range dp {
		dp[i] = map[int]int{}
	}
	for i, x := range nums {
		for j := 0; j < i; j++ {
			d := x - nums[j]
			if y, ok := dp[j][d]; ok {
				ret += y
				dp[i][d] += y + 1
			} else {
				dp[i][d] += 1
			}
		}
	}
	return ret
}

func main() {
	fmt.Println(numberOfArithmeticSlices([]int{2, 4, 6, 8, 10}), 7)
	fmt.Println(numberOfArithmeticSlices([]int{7, 7, 7, 7, 7}), 16)
}
