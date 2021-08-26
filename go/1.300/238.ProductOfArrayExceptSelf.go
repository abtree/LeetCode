package main

import "fmt"

func productExceptSelf(nums []int) []int {
	size := len(nums)
	ret := make([]int, size)
	ret[0] = 1
	for i := 1; i < size; i++ {
		ret[i] = ret[i-1] * nums[i-1]
	}
	r := nums[size-1]
	for i := size - 2; i > 0; i-- {
		ret[i] = ret[i] * r
		r *= nums[i]
	}
	ret[0] = r
	return ret
}

func main() {
	fmt.Println(productExceptSelf([]int{1, 2, 3, 4}))
}
