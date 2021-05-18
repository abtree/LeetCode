package main

import "fmt"

func rangeBitwiseAnd(left int, right int) int {
	cnt := 0
	for left < right {
		left >>= 1
		right >>= 1
		cnt++
	}
	return left << cnt
}

func rangeBitwiseAnd2(left int, right int) int {
	for left < right {
		right = right & (right - 1)
	}
	return right
}

func main() {
	fmt.Printf("%d -> 4 \n", rangeBitwiseAnd2(5, 7))
	fmt.Printf("%d -> 0 \n", rangeBitwiseAnd2(0, 0))
	fmt.Printf("%d -> 0 \n", rangeBitwiseAnd2(1, 2147483647))
}
