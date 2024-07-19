package main

import "fmt"

func subarraySum(nums []int, k int) int {
	mp := map[int]int{}
	mp[0] = 1
	ret, pre := 0, 0
	for _, x := range nums {
		pre += x
		if c, ok := mp[pre-k]; ok {
			ret += c
		}
		mp[pre]++
	}
	return ret
}

func main() {
	fmt.Println(subarraySum([]int{1, 1, 1}, 2), 2)
	fmt.Println(subarraySum([]int{1, 2, 3}, 3), 2)
}
