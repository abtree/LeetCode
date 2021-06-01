package main

import (
	"fmt"
	"math"
)

func isPowerOfTwo(n int) bool {
	if n <= 0 {
		return false
	}
	return n&(n-1) == 0
}

func main() {
	fmt.Println(isPowerOfTwo(1), true)
	fmt.Println(isPowerOfTwo(16), true)
	fmt.Println(isPowerOfTwo(3), false)
	fmt.Println(isPowerOfTwo(4), true)
	fmt.Println(isPowerOfTwo(5), false)
	fmt.Println(isPowerOfTwo(math.MinInt32), false)
}
