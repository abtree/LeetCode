package main

import "fmt"

func getSum(a int, b int) int {
	for b != 0 {
		a, b = a^b, (a&b)<<1
	}
	return a
}

func main() {
	fmt.Println(getSum(1, 2), 3)
	fmt.Println(getSum(-2, 3), 1)
	fmt.Println(getSum(2, -3), -1)
	fmt.Println(getSum(-2, -80), -82)
}
