package main

import (
	"fmt"
	"math/rand"
	"sort"
)

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func minMoves2(nums []int) int {
	sort.Slice(nums, func(i, j int) bool {
		return nums[i] < nums[j]
	})
	n := len(nums)
	x := nums[n/2]
	ret := 0
	for _, y := range nums {
		ret += abs(y - x)
	}
	return ret
}

func minMoves3(nums []int) int {
	n := len(nums)
	x := quickSelect(nums, 0, n-1, n/2)
	ret := 0
	for _, y := range nums {
		ret += abs(y - x)
	}
	return ret
}

func quickSelect(nums []int, left, right, index int) int {
	p := partition(nums, left, right)
	if p == index {
		return nums[p]
	} else if p > index {
		return quickSelect(nums, left, p-1, index)
	} else {
		return quickSelect(nums, p+1, right, index)
	}
}

func partition(nums []int, left, right int) int {
	i := rand.Intn(right-left+1) + left
	x := nums[i]
	nums[i], nums[right] = nums[right], nums[i]
	p := left
	for j := left; j < right; j++ {
		if nums[j] <= x {
			if j != p {
				nums[p], nums[j] = nums[j], nums[p]
			}
			p++
		}
	}
	nums[p], nums[right] = nums[right], nums[p]
	return p
}

func main() {
	fmt.Println(minMoves2([]int{1, 2, 3}), 2)
	fmt.Println(minMoves2([]int{1, 10, 2, 9}), 16)

	fmt.Println(minMoves3([]int{1, 2, 3}), 2)
	fmt.Println(minMoves3([]int{1, 10, 2, 9}), 16)
}
