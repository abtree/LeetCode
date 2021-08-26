package main

import "fmt"

func minPatches(nums []int, n int) int {
	x, i, ret := 1, 0, 0
	size := len(nums)
	for x <= n {
		if i < size && x >= nums[i] {
			x += nums[i]
			i++
		} else {
			ret++
			x *= 2
		}
	}
	return ret
}

func main() {
	fmt.Println(minPatches([]int{1, 2, 31, 33}, 2147483647), 28)
	fmt.Println(minPatches([]int{1, 3}, 6), 1)
	fmt.Println(minPatches([]int{1, 5, 10}, 20), 2)
	fmt.Println(minPatches([]int{1, 2, 2}, 5), 0)
}
