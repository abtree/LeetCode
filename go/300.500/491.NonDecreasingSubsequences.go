package main

import (
	"fmt"
	"math"
)

func findSubsequences(nums []int) [][]int {
	if len(nums) < 2 {
		return [][]int{}
	}
	ans := [][]int{}
	had := map[string]struct{}{}
	temp := []int{}

	var fn func(i int)
	fn = func(i int) {
		for i < len(nums) {
			if temp[len(temp)-1] <= nums[i] {
				temp = append(temp, nums[i])
				key := fmt.Sprint(temp)
				if _, ok := had[key]; !ok {
					add := make([]int, len(temp))
					copy(add, temp)
					ans = append(ans, add)
					had[key] = struct{}{}
				}
				fn(i + 1)
				temp = temp[:len(temp)-1]
			}
			i++
		}
	}
	for i, v := range nums {
		temp = []int{v}
		fn(i + 1)
	}
	return ans
}

func findSubsequences1(nums []int) [][]int {
	temp := []int{}
	ans := [][]int{}
	var dfs func(cur, last int)
	dfs = func(cur, last int) {
		if cur == len(nums) {
			if len(temp) > 1 {
				t := make([]int, len(temp))
				copy(t, temp)
				ans = append(ans, t)
			}
			return
		}
		if nums[cur] >= last {
			temp = append(temp, nums[cur])
			dfs(cur+1, nums[cur])
			temp = temp[:len(temp)-1]
		}
		if nums[cur] != last {
			dfs(cur+1, last)
		}
	}
	dfs(0, math.MinInt32)
	return ans
}

func main() {
	fmt.Println(findSubsequences1([]int{4, 6, 7, 7}), "[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]")
	fmt.Println(findSubsequences1([]int{4, 4, 3, 2, 1}), "[[4,4]]")
}
