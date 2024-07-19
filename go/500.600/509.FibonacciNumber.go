package main

import (
	"fmt"
	"math"
)

func fib(n int) int {
	if n == 0 {
		return 0
	}
	if n == 1 {
		return 1
	}
	a, b := 0, 1
	i := 1
	for i != n {
		a, b = b, a+b
		i++
	}
	return b
}

func fib1(n int) int {
	sq5 := math.Sqrt(5)
	p1 := math.Pow((1+sq5)/2, float64(n))
	p2 := math.Pow((1-sq5)/2, float64(n))
	return int(math.Round((p1 - p2) / sq5))
}

func main() {
	fmt.Println(fib1(2), 1)
	fmt.Println(fib1(3), 2)
	fmt.Println(fib1(4), 3)
}
