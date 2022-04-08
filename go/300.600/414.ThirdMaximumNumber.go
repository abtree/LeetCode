package main

import (
	"fmt"
)

func thirdMax(nums []int) int {
	var a, b, c *int
	for _, x := range nums {
		x := x
		if a == nil || x > *a {
			c, b, a = b, a, &x
		} else if *a > x && (b == nil || x > *b) {
			c, b = b, &x
		} else if b != nil && x < *b && (c == nil || x > *c) {
			c = &x
		}
	}
	if c == nil {
		return *a
	}
	return *c
}

func main() {
	fmt.Println(thirdMax([]int{1, 2, 2, 5, 3, 5}), 2)
	fmt.Println(thirdMax([]int{3, 2, 1}), 1)
	fmt.Println(thirdMax([]int{1, 2}), 2)
	fmt.Println(thirdMax([]int{2, 2, 3, 1}), 1)
}
