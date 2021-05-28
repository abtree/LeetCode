package main

import (
	"fmt"
	"sort"
)

func findKthLargest(nums []int, k int) int {
	sort.Slice(nums, func(i, j int) bool { return nums[j] < nums[i] })
	return nums[k-1]
}

func main() {
	fmt.Println(findKthLargest([]int{3, 2, 1, 5, 6, 4}, 2), " -> 5")
	fmt.Println(findKthLargest([]int{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4), " -> 4")
}
