package main

import (
	"fmt"
	"sort"
)

func findPairs(nums []int, k int) int {
	sort.Ints(nums)
	n := len(nums)
	ans := 0
	for i := n - 1; i > 0; i-- {
		if i < n-1 && nums[i] == nums[i+1] {
			continue
		}
		for j := i - 1; j >= 0; j-- {
			if nums[i]-nums[j] < k {
				continue
			}
			if nums[i]-nums[j] == k {
				ans++
			}
			break
		}
	}
	return ans
}
func findPairs1(nums []int, k int) int {
	visited := map[int]struct{}{}
	ans := map[int]struct{}{}
	for _, v := range nums {
		if _, ok := visited[v-k]; ok {
			ans[v] = struct{}{}
		}
		if _, ok := visited[v+k]; ok {
			ans[v+k] = struct{}{}
		}
		visited[v] = struct{}{}
	}
	return len(ans)
}

func main() {
	fmt.Println(findPairs1([]int{3, 1, 4, 1, 5}, 2), 2)
	fmt.Println(findPairs1([]int{1, 2, 3, 4, 5}, 1), 4)
	fmt.Println(findPairs1([]int{1, 3, 1, 5, 4}, 0), 1)
}
