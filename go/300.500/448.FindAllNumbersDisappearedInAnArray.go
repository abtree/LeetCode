package main

import "fmt"

func findDisappearedNumbers(nums []int) []int {
	for i := range nums {
		x := abs(nums[i])
		if nums[x-1] > 0 {
			nums[x-1] *= -1
		}
	}
	ret := []int{}
	for i, x := range nums {
		if x > 0 {
			ret = append(ret, i+1)
		}
	}
	return ret
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func main() {
	fmt.Println(findDisappearedNumbers([]int{4, 3, 2, 7, 8, 2, 3, 1}))
	fmt.Println(findDisappearedNumbers([]int{1, 1}))
}
