package main

import (
	"fmt"
)

func rotate(nums []int, k int) {
	size := len(nums)
	if size < 2 || k <= 0 {
		return
	}
	old := make([]int, size)
	copy(old, nums)
	k %= size
	for i := 0; i < size; i++ {
		nums[(i+k)%size] = old[i]
	}
}

func rotate2(nums []int, k int) {
	size := len(nums)
	if size < 2 || k <= 0 {
		return
	}
	k %= size
	count, start := 0, 0
	for count < size {
		cur := start
		value := nums[cur]
		for {
			cur = (cur + k) % size
			value, nums[cur] = nums[cur], value
			count++
			if cur == start {
				break
			}
		}
		start++
	}
}

func rotate3(nums []int, k int) {
	size := len(nums)
	if size < 2 || k <= 0 {
		return
	}
	k %= size
	reverse(nums, 0, size-1)
	reverse(nums, 0, k-1)
	reverse(nums, k, size-1)
}

func rotate4(nums []int, k int) {
	size := len(nums)
	if size < 2 || k <= 0 {
		return
	}
	k %= size
	a := nums[size-k:]
	a = append(a, nums[:size-k]...)
	copy(nums, a)
}

func reverse(nums []int, start, end int) {
	for start < end {
		nums[start], nums[end] = nums[end], nums[start]
		start++
		end--
	}
}

func main() {
	nums := []int{1, 2, 3, 4, 5, 6, 7}
	rotate4(nums, 3)
	fmt.Println(nums)

	nums = []int{-1, -100, 3, 99}
	rotate4(nums, 2)
	fmt.Println(nums)
}
