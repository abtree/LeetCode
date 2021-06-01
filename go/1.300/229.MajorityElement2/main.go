package main

import (
	"fmt"
	"sort"
)

func majorityElement(nums []int) []int {
	n := len(nums) / 3
	counts := map[int]int{}
	for _, v := range nums {
		counts[v]++
	}
	ret := []int{}
	for k, v := range counts {
		if v > n {
			ret = append(ret, k)
		}
	}
	return ret
}

func majorityElement2(nums []int) []int {
	size := len(nums)
	if size == 0 {
		return []int{}
	}
	if size == 1 {
		return []int{nums[0]}
	}
	sort.Slice(nums, func(i, j int) bool {
		return nums[i] < nums[j]
	})
	cnt := 1
	n := size / 3
	ret := []int{}
	for i, v := range nums {
		if i+1 < size && v == nums[i+1] {
			cnt++
		} else {
			if cnt > n {
				ret = append(ret, v)
			}
			cnt = 1
		}
	}
	return ret
}

func main() {
	fmt.Println(majorityElement([]int{3, 2, 3}))
	fmt.Println(majorityElement([]int{1}))
	fmt.Println(majorityElement([]int{1, 1, 1, 3, 3, 2, 2, 2}))

	fmt.Println(majorityElement2([]int{3, 2, 3}))
	fmt.Println(majorityElement2([]int{1}))
	fmt.Println(majorityElement2([]int{1, 1, 1, 3, 3, 2, 2, 2}))
}
