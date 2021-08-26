package main

import "fmt"

func singleNumber(nums []int) []int {
	ret := 0
	for _, v := range nums {
		ret ^= v
	}
	t := ret
	ret &= (-ret)
	a, b := 0, 0
	for _, v := range nums {
		if (v & ret) == 0 {
			a ^= v
		}
	}
	b = t ^ a
	return []int{a, b}
}

func main() {
	fmt.Println(singleNumber([]int{1, 2, 1, 3, 2, 5}))
	fmt.Println(singleNumber([]int{-1, 0}))
	fmt.Println(singleNumber([]int{0, 1}))
	fmt.Println(singleNumber([]int{1, 2, 3, 4, 5, 6, 7, 5, 4, 3, 2, 1}))
}
