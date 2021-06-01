package main

import "fmt"

func summaryRanges(nums []int) []string {
	left := 0
	ret := []string{}
	for i, v := range nums {
		if i+1 >= len(nums) || v+1 != nums[i+1] {
			if left != i {
				ret = append(ret, fmt.Sprintf("%v->%v", nums[left], nums[i]))
			} else {
				ret = append(ret, fmt.Sprint(nums[left]))
			}
			left = i + 1
		}
	}
	return ret
}

func main() {
	fmt.Println(summaryRanges([]int{0, 1, 2, 4, 5, 7}))
	fmt.Println(summaryRanges([]int{0, 2, 3, 4, 6, 8, 9}))
	fmt.Println(summaryRanges([]int{-1}))
	fmt.Println(summaryRanges([]int{}))
}
