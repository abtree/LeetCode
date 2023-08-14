package main

import "fmt"

func findDuplicates(nums []int) []int {
	ret := []int{}
	for _, c := range nums {
		x := abs(c)
		if nums[x-1] < 0 {
			ret = append(ret, x)
		} else {
			nums[x-1] *= -1
		}
	}
	return ret
}

func abs(i int) int {
	if i < 0 {
		return -i
	}
	return i
}

func main() {
	fmt.Println(findDuplicates([]int{4, 3, 2, 7, 8, 2, 3, 1}))
	fmt.Println(findDuplicates([]int{1, 1, 2}))
	fmt.Println(findDuplicates([]int{1}))
}
