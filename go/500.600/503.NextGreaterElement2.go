package main

import (
	"fmt"
)

func nextGreaterElements(nums []int) []int {
	var getmax func(start, end int) (int, int)
	getmax = func(start, end int) (int, int) {
		if start == end {
			return nums[start], start
		}
		mid := (start + end) / 2
		n1, s1 := getmax(start, mid)
		n2, s2 := getmax(mid+1, end)
		if n1 > n2 {
			return n1, s1
		}
		return n2, s2
	}
	n := len(nums)
	nx, mm := getmax(0, n-1)
	ans := make([]int, n)
	ans[mm] = -1
	dp := []int{nx}
	i := mm - 1
	if i < 0 {
		i = n - 1
	}
	for i != mm {
		dplen := len(dp)
		for dplen > 0 && dp[dplen-1] <= nums[i] {
			dplen--
			dp = dp[:dplen]
		}
		if dplen > 0 {
			ans[i] = dp[dplen-1]
		} else {
			ans[i] = -1
		}
		dp = append(dp, nums[i])
		i--
		if i < 0 {
			i = n - 1
		}
	}
	return ans
}

func main() {
	fmt.Println(nextGreaterElements([]int{1, 2, 1}), "[2,-1,2]")
	fmt.Println(nextGreaterElements([]int{1, 2, 3, 4, 3}), "[2,3,4,-1,4]")
	fmt.Println(nextGreaterElements([]int{5, 4, 3, 2, 1}), "[-1,5,5,5,5]")
}
