package main

import (
	"fmt"
)

func nextGreaterElement(nums1 []int, nums2 []int) []int {
	dp := map[int]int{}
	st := []int{}
	for i := len(nums2) - 1; i >= 0; i-- {
		l := len(st)
		num := nums2[i]
		for l > 0 && num >= st[l-1] {
			st = st[:l-1]
			l--
		}
		if l > 0 {
			dp[num] = st[l-1]
		} else {
			dp[num] = -1
		}
		st = append(st, num)
	}
	ret := make([]int, len(nums1))
	for i, v := range nums1 {
		ret[i] = dp[v]
	}
	return ret
}

func main() {
	fmt.Println(nextGreaterElement([]int{4, 1, 2}, []int{1, 3, 4, 2}), "[-1,3,-1]")
	fmt.Println(nextGreaterElement([]int{2, 4}, []int{1, 2, 3, 4}), "[3,-1]")
}
