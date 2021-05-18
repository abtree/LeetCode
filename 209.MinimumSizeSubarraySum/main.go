package main

import (
	"fmt"
	"math"
)

func minSubArrayLen(target int, nums []int) int {
	i, j := 0, 0
	total := 0
	ret := math.MaxInt32
	for i < len(nums) {
		for total < target && i < len(nums) {
			total += nums[i]
			i++
		}
		if total < target {
			break
		}
		for total >= target {
			total -= nums[j]
			j++
		}
		ret = min(i-j+1, ret)
	}
	if ret == math.MaxInt32 {
		return 0
	}
	return ret
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}

func main() {
	fmt.Printf("%d -> 2 \n", minSubArrayLen(7, []int{2, 3, 1, 2, 4, 3}))
	fmt.Printf("%d -> 1 \n", minSubArrayLen(4, []int{1, 4, 4}))
	fmt.Printf("%d -> 0 \n", minSubArrayLen(11, []int{1, 1, 1, 1, 1, 1, 1, 1}))
}
