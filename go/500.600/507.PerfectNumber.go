package main

import (
	"fmt"
	"math"
)

func checkPerfectNumber(num int) bool {
	if num == 1 {
		return false
	}
	x := int(math.Sqrt(float64(num)))
	sum := 1
	for x > 1 {
		if num%x == 0 {
			sum += x
			sum += num / x
		}
		x--
	}
	return sum == num
}

func main() {
	fmt.Println(checkPerfectNumber(28), true)
	fmt.Println(checkPerfectNumber(7), false)
}
