package main

import (
	"fmt"
	"sort"
)

func wiggleSort(nums []int) {
	dp := make([]int, len(nums))
	copy(dp, nums)
	sort.Ints(dp)
	n := len(dp)
	i := n >> 1
	if n%2 == 0 {
		i--
	}
	j := n - 1
	for k := 0; k < n; k++ {
		nums[k] = dp[i]
		i--
		k++
		if k == n {
			return
		}
		nums[k] = dp[j]
		j--
	}
}

func main() {
	ret := []int{1, 1, 2, 1, 2, 2, 1}
	wiggleSort(ret)
	fmt.Println(ret)

	ret1 := []int{1, 5, 1, 1, 6, 4}
	wiggleSort(ret1)
	fmt.Println(ret1)

	ret2 := []int{1, 3, 2, 2, 3, 1}
	wiggleSort(ret2)
	fmt.Println(ret2)
}
