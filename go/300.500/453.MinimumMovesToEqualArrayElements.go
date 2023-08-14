package main

import (
	"fmt"
	"math"
)

func minMoves(nums []int) int {
	minN := math.MaxInt32
	for _, x := range nums {
		minN = min(x, minN)
	}
	ret := 0
	for _, x := range nums {
		ret += x - minN
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
	fmt.Println(minMoves([]int{1, 2, 3}), 3)
	fmt.Println(minMoves([]int{1, 1, 1}), 0)
}
