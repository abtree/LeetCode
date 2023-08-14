package main

import (
	"fmt"
	"math"
)

func maxRotateFunction(nums []int) int {
	v, s, r := 0, 0, math.MinInt32;
	for i, x := range nums{
		v += i*x
		s += x;
	}
	r = max(r, v)
	n := len(nums)
	for i:=n-1; i > 0;i--{
		v = (v+s)-(n*nums[i])
		r = max(r, v)
	}
	return r
}

func max(i, j int) int{
	if i > j{
		return i
	}
	return j
}

func main() {
	fmt.Println(maxRotateFunction([]int{4,3,2,6}), 26)
}