package main

import (
	"fmt"
)

func singleNonDuplicate(nums []int) int {
	high := len(nums) - 2
	low := 0
	for low < high {
		mid := (high + low) >> 1
		mid -= mid & 1
		if nums[mid] != nums[mid+1] {
			high = mid
		} else {
			low = mid + 2
		}
	}
	return nums[low]
}

func main() {
	fmt.Println(singleNonDuplicate([]int{1, 1, 2, 3, 3, 4, 4, 8, 8}), 2)
	fmt.Println(singleNonDuplicate([]int{3, 3, 7, 7, 10, 11, 11}), 10)
}
