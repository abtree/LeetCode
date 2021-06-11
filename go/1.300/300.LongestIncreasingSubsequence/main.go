package main

import "fmt"

func lengthOfLIS(nums []int) int {
	size := len(nums)
	dp := make([]int, size)
	for i, v := range nums {
		dp[i] = 1
		for j := 0; j < i; j++ {
			if nums[j] < v {
				dp[i] = max(dp[i], dp[j]+1)
			}
		}
	}
	ret := 0
	for _, v := range dp {
		ret = max(ret, v)
	}
	return ret
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func lengthOfLIS1(nums []int) int {
	size := len(nums)
	dp := []int{nums[0]}
	for i := 1; i < size; i++ {
		if nums[i] > dp[len(dp)-1] {
			dp = append(dp, nums[i])
		} else {
			start, end := 0, len(dp)-1
			for start < end {
				mid := (start + end) / 2
				if dp[mid] < nums[i] {
					start = mid + 1
				} else {
					end = mid
				}
			}
			dp[end] = nums[i]
		}
	}
	return len(dp)
}

func main() {
	fmt.Println(lengthOfLIS([]int{10, 9, 2, 5, 3, 7, 101, 18}), lengthOfLIS1([]int{10, 9, 2, 5, 3, 7, 101, 18}))
	fmt.Println(lengthOfLIS([]int{0, 1, 0, 3, 2, 3}), lengthOfLIS1([]int{0, 1, 0, 3, 2, 3}))
	fmt.Println(lengthOfLIS([]int{7, 7, 7, 7, 7, 7, 7}), lengthOfLIS1([]int{7, 7, 7, 7, 7, 7, 7}))
	fmt.Println(lengthOfLIS([]int{0, 1, 98, 99, 100, 2, 3, 4, 5, 6, 7, 8, 9}), lengthOfLIS1([]int{0, 1, 98, 99, 100, 2, 3, 4, 5, 6, 7, 8, 9}))
	fmt.Println(lengthOfLIS([]int{200, 201, 98, 99, 100, 101, 102, 103, 5, 6, 105, 8, 9}), lengthOfLIS1([]int{200, 201, 98, 99, 100, 101, 102, 103, 5, 6, 105, 8, 9}))
}
