package main

import (
	"fmt"
)

func circularArrayLoop(nums []int) bool {
	n := len(nums)
	next := func(cur int) int {
		return ((cur+nums[cur])%n + n) % n
	}
	for i := range nums {
		if nums[i] == 0 {
			continue
		}
		slow := i
		fast := next(i)
		for nums[slow]*nums[fast] > 0 && nums[slow]*nums[next(fast)] > 0 {
			if slow == fast {
				if slow != next(slow) {
					return true
				} else {
					break
				}
			}
			slow = next(slow)
			fast = next(next(fast))
		}
		add := i
		for nums[add]*nums[next(add)] > 0 {
			x := add
			add = next(add)
			nums[x] = 0
		}
	}
	return false
}

func main() {
	fmt.Println(circularArrayLoop([]int{2, -1, 1, 2, 2}), true)
	fmt.Println(circularArrayLoop([]int{-1, 2}), false)
	fmt.Println(circularArrayLoop([]int{-2, 1, -1, -2, -2}), false)
	fmt.Println(circularArrayLoop([]int{1, -1, 5, 1, 4}), true)
	fmt.Println(circularArrayLoop([]int{-1, -2, -3, -4, -5, 6}), false)
}
