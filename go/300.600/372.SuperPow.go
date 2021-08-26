package main

import (
	"fmt"
	"math"
)

const base = 1337

func superPow(a int, b []int) int {
	size := len(b)
	if size <= 0 {
		return 1
	}
	a %= base
	last := b[size-1]
	b = b[:size-1]
	p1 := mypow(a, last)
	p2 := mypow(superPow(a, b), 10)
	return (p1 * p2) % base
}

func mypow(a, k int) int {
	if k == 0 {
		return 1
	}
	if k%2 == 1 {
		return (mypow(a, k-1) * a) % base
	} else {
		mid := mypow(a, k/2)
		return (mid * mid) % base
	}
}

func main() {
	fmt.Println(superPow(2, []int{3}), 8)
	fmt.Println(superPow(2, []int{1, 0}), 1024)
	fmt.Println(superPow(1, []int{4, 3, 3, 8, 5, 2}), 1)
	fmt.Println(superPow(math.MaxInt32, []int{2, 0, 0}), 1198)
}
