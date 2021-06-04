package main

import "fmt"

func missingNumber(nums []int) int {
	n := len(nums)
	t := n * (n + 1) / 2
	x := 0
	for _, v := range nums {
		x += v
	}
	return t - x
}

func missingNumber2(nums []int) int {
	n := len(nums)
	x := 0
	for n > 0 {
		x ^= n
		n--
	}
	for _, v := range nums {
		x ^= v
	}
	return x
}

func main() {
	fmt.Println(missingNumber([]int{3, 0, 1}), missingNumber2([]int{3, 0, 1}))
	fmt.Println(missingNumber([]int{0, 1}), missingNumber2([]int{0, 1}))
	fmt.Println(missingNumber([]int{9, 6, 4, 2, 3, 5, 7, 0, 1}), missingNumber2([]int{9, 6, 4, 2, 3, 5, 7, 0, 1}))
	fmt.Println(missingNumber([]int{0}), missingNumber2([]int{0}))
}
