package main

import "fmt"

func numberOfArithmeticSlices(nums []int) int {
	n := len(nums)
	if n < 3 {
		return 0
	}
	ret := 0
	for i := 0; i < n-2; i++ {
		k := nums[i+1] - nums[i]
		for j := i + 2; j < n; j++ {
			if nums[j]-k == nums[j-1] {
				ret++
			} else {
				break
			}
		}
	}
	return ret
}

func main() {
	fmt.Println(numberOfArithmeticSlices([]int{1, 2, 3, 4}), 3)
	fmt.Println(numberOfArithmeticSlices([]int{1}), 0)
}
