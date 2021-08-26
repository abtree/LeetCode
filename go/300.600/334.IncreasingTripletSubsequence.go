package main

import (
	"fmt"
	"math"
)

func increasingTriplet(nums []int) bool {
	stk := make([]int, 2)
	for i, _ := range stk {
		stk[i] = math.MaxInt32
	}
	for _, v := range nums {
		pos := 2
		for pos > 0 && stk[pos-1] >= v {
			pos--
		}
		if pos == 2 {
			return true
		}
		stk[pos] = v
	}
	return false
}

func main() {
	fmt.Println(increasingTriplet([]int{1, 1, -2, 6}), false)
	fmt.Println(increasingTriplet([]int{20, 100, 10, 12, 5, 13}), true)
	fmt.Println(increasingTriplet([]int{1, 2, 3, 4, 5}), true)
	fmt.Println(increasingTriplet([]int{5, 4, 3, 2, 1}), false)
	fmt.Println(increasingTriplet([]int{2, 1, 5, 0, 4, 6}), true)
}
