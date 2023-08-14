package main

import (
	"fmt"
)

func fourSumCount(nums1 []int, nums2 []int, nums3 []int, nums4 []int) int {
	dp := map[int]int{}
	for _, a := range nums1 {
		for _, b := range nums2 {
			dp[a+b]++
		}
	}
	ans := 0
	for _, c := range nums3 {
		for _, d := range nums4 {
			if x, ok := dp[-c-d]; ok {
				ans += x
			}
		}
	}
	return ans
}

func main() {
	fmt.Println(fourSumCount([]int{-2, -1}, []int{-1, 2}, []int{0, 2}, []int{1, 2}), 2)
	fmt.Println(fourSumCount([]int{0}, []int{0}, []int{0}, []int{0}), 1)
}
