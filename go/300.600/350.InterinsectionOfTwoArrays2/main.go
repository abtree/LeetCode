package main

import (
	"fmt"
	"sort"
)

func intersect(nums1 []int, nums2 []int) []int {
	sort.Ints(nums1)
	sort.Ints(nums2)
	i, j := 0, 0
	ret := []int{}
	for i < len(nums1) && j < len(nums2) {
		if nums1[i] == nums2[j] {
			ret = append(ret, nums1[i])
			i++
			j++
		} else if nums1[i] < nums2[j] {
			i++
		} else {
			j++
		}
	}
	return ret
}

func intersect1(nums1 []int, nums2 []int) []int {
	dp := map[int]int{}
	for _, v := range nums1 {
		dp[v] += 1
	}
	ret := []int{}
	for _, v := range nums2 {
		if x, ok := dp[v]; ok && x > 0 {
			ret = append(ret, v)
			dp[v]--
		}
	}
	return ret
}

func main() {
	fmt.Println(intersect([]int{1, 2, 2, 1}, []int{2, 2}))
	fmt.Println(intersect([]int{4, 9, 5}, []int{9, 4, 9, 8, 4}))

	fmt.Println(intersect1([]int{1, 2, 2, 1}, []int{2, 2}))
	fmt.Println(intersect1([]int{4, 9, 5}, []int{9, 4, 9, 8, 4}))
}
