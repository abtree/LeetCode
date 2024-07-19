package main

import (
	"fmt"
	"sort"
)

func arrayPairSum(nums []int) int {
	sort.Ints(nums)
	ret := 0
	n := len(nums)
	for i := 0; i < n; i += 2 {
		ret += nums[i]
	}
	return ret
}

func main() {
	fmt.Println(arrayPairSum([]int{1, 4, 3, 2}), 4)
	fmt.Println(arrayPairSum([]int{6, 2, 6, 5, 1, 2}), 9)
}
