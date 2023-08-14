package main

import (
	"fmt"
	"math/bits"
)

func hammingDistance(x int, y int) int {
	return bits.OnesCount(uint(x ^ y))
}

func hammingDistance1(x int, y int) int {
	z := x ^ y
	ret := 0
	for z > 0 {
		ret += z & 1
		z = z >> 1
	}
	return ret
}

func hammingDistance2(x int, y int) int {
	z := x ^ y
	ret := 0
	for z > 0 {
		ret++
		z = z & (z - 1)
	}
	return ret
}

func main() {
	fmt.Println(hammingDistance(1, 4), 2)
	fmt.Println(hammingDistance(3, 1), 1)

	fmt.Println(hammingDistance1(1, 4), 2)
	fmt.Println(hammingDistance1(3, 1), 1)

	fmt.Println(hammingDistance2(1, 4), 2)
	fmt.Println(hammingDistance2(3, 1), 1)
}
