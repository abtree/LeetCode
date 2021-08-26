package main

import "fmt"

func isUgly(n int) bool {
	if n < 1 {
		return false
	}
	facts := []int{2, 3, 5}
	for _, v := range facts {
		for n%v == 0 {
			n /= v
		}
	}
	return n == 1
}

func main() {
	fmt.Println(isUgly(6), true)
	fmt.Println(isUgly(8), true)
	fmt.Println(isUgly(14), false)
	fmt.Println(isUgly(1), true)
}
