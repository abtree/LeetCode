package main

import (
	"fmt"
	"sort"
)

func countSmaller(nums []int) []int {
	init := func() []int {
		set := map[int]struct{}{}
		for _, v := range nums {
			set[v] = struct{}{}
		}
		a := []int{}
		for k := range set {
			a = append(a, k)
		}
		sort.Ints(a)
		return a
	}
	a := init()
	c := make([]int, len(a)+1)
	ans := make([]int, len(nums))
	for i := len(nums) - 1; i >= 0; i-- {
		id := sort.SearchInts(a, nums[i]) + 1
		sum := 0
		pos := id - 1
		for pos > 0 {
			sum += c[pos]
			pos -= (pos & (-pos))
		}
		ans[i] = sum
		for id < len(c) {
			c[id] += 1
			id += (id & (-id))
		}
	}
	return ans
}

func main() {
	fmt.Println(countSmaller([]int{1, 0, 2}))
	fmt.Println(countSmaller([]int{5, 2, 6, 1}))
	fmt.Println(countSmaller([]int{2, 0, 1}))
	fmt.Println(countSmaller([]int{3, 2, 2, 1, 1, 1}))
}
