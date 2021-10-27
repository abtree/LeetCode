package main

import "fmt"

func wiggleMaxLength(nums []int) int {
	i := 1
	for i < len(nums) && nums[i] == nums[i-1] {
		i++
	}
	if i >= len(nums) {
		return 1
	}
	big := true
	if nums[i] > nums[i-1] {
		big = false
	}
	dp := 2
	for i++; i < len(nums); i++ {
		if (big && nums[i] > nums[i-1]) || (!big && nums[i] < nums[i-1]) {
			dp++
			big = !big
		}
	}
	return dp
}

func main() {
	fmt.Println(wiggleMaxLength([]int{1, 7, 4, 9, 2, 5}), 6)
	fmt.Println(wiggleMaxLength([]int{1, 17, 5, 10, 13, 15, 10, 5, 16, 8}), 7)
	fmt.Println(wiggleMaxLength([]int{1, 2, 3, 4, 5, 6, 7, 8, 9}), 2)
	fmt.Println(wiggleMaxLength([]int{3, 3, 3, 2, 5}), 3)
}
