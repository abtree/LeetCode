package main

import (
	"fmt"
	"math"
)

func isPerfectSquare(num int) bool {
	x := int(math.Sqrt(float64(num)))
	return x*x == num
}

func isPerfectSquare1(num int) bool {
	if num == 1 {
		return true
	}
	x := num / 2
	for x*x > num {
		x = (x + num/x) / 2
	}
	return x*x == num
}

func main() {
	fmt.Println(isPerfectSquare(16), true)
	fmt.Println(isPerfectSquare(14), false)
	fmt.Println(isPerfectSquare1(16), true)
	fmt.Println(isPerfectSquare1(14), false)
}
