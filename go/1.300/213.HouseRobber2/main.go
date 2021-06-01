package main

import "fmt"

func rob(nums []int) int {
	size := len(nums)
	if size == 0 {
		return 0
	}
	if size == 1 {
		return nums[0]
	}
	dp1 := nums[0]
	dp2 := max(nums[1], dp1)
	if size == 2 {
		return dp2
	}
	if size == 3 {
		return max(nums[2], dp2)
	}
	//first (0, n-2)
	for i := 2; i < size-1; i++ {
		dp1, dp2 = dp2, max(dp1+nums[i], dp2)
	}
	max1 := dp2
	dp1 = nums[1]
	dp2 = max(dp1, nums[2])
	for i := 3; i < size; i++ {
		dp1, dp2 = dp2, max(dp1+nums[i], dp2)
	}
	return max(max1, dp2)
}

func rob2(nums []int) int {
	size := len(nums)
	if size == 0 {
		return 0
	}
	if size == 1 {
		return nums[0]
	}
	return max(maxInSlice(nums[:size-1]), maxInSlice(nums[1:size]))
}

func maxInSlice(nums []int) int {
	dp1, dp2 := 0, 0
	for _, v := range nums {
		dp1, dp2 = dp2, max(dp1+v, dp2)
	}
	return dp2
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	fmt.Printf("%d -> 1 \n", rob2([]int{1}))
	fmt.Printf("%d -> 10 \n", rob2([]int{2, 2, 4, 3, 2, 5}))
	fmt.Printf("%d -> 3 \n", rob2([]int{2, 3, 2}))
	fmt.Printf("%d -> 4 \n", rob2([]int{1, 2, 3, 1}))
	fmt.Printf("%d -> 18 \n", rob2([]int{9, 1, 1, 9, 1}))
}
