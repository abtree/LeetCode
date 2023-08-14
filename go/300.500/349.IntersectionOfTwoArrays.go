package main

import (
	"fmt"
	"sort"
)

func intersection(nums1 []int, nums2 []int) []int {
	sort.Ints(nums1)
	sort.Ints(nums2)
	i, j := 0, 0
	ret := []int{}
	for i < len(nums1) && j < len(nums2) {
		if nums1[i] == nums2[j] {
			ret = append(ret, nums1[i])
			i++
			for i < len(nums1) && nums1[i] == nums1[i-1] {
				i++
			}
			j++
			for j < len(nums2) && nums2[j] == nums2[j-1] {
				j++
			}
		} else if nums1[i] < nums2[j] {
			i++
			for i < len(nums1) && nums1[i] == nums1[i-1] {
				i++
			}
		} else {
			j++
			for j < len(nums2) && nums2[j] == nums2[j-1] {
				j++
			}
		}
	}
	return ret
}

func intersection1(nums1 []int, nums2 []int) []int {
	dp := map[int]bool{}
	for _, v := range nums1 {
		dp[v] = true
	}
	ret := []int{}
	for _, v := range nums2 {
		if x, ok := dp[v]; ok && x {
			ret = append(ret, v)
			dp[v] = false
		}
	}
	return ret
}

func main() {
	fmt.Println(intersection1([]int{1, 2, 2, 1}, []int{2, 2}))
	fmt.Println(intersection1([]int{4, 9, 5}, []int{9, 4, 9, 8, 4}))
}
