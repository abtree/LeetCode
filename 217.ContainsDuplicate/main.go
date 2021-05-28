package main

import (
	"fmt"
	"sort"
)

func containsDuplicate(nums []int) bool {
	sort.Slice(nums, func(i, j int) bool { return nums[i] < nums[j] })
	for i := 1; i < len(nums); i++ {
		if nums[i-1] == nums[i] {
			return true
		}
	}
	return false
}

func containsDuplicate2(nums []int) bool {
	dup := map[int]struct{}{}
	for _, v := range nums {
		if _, ok := dup[v]; ok {
			return true
		}
		dup[v] = struct{}{}
	}
	return false
}

func main() {
	fmt.Println(containsDuplicate([]int{1, 2, 3, 1}), " -> true")
	fmt.Println(containsDuplicate([]int{1, 2, 3, 4}), " -> false")
	fmt.Println(containsDuplicate([]int{1, 1, 1, 3, 3, 4, 3, 2, 4, 2}), " -> true")

	fmt.Println(containsDuplicate2([]int{1, 2, 3, 1}), " -> true")
	fmt.Println(containsDuplicate2([]int{1, 2, 3, 4}), " -> false")
	fmt.Println(containsDuplicate2([]int{1, 1, 1, 3, 3, 4, 3, 2, 4, 2}), " -> true")
}
