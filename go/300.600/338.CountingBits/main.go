package main

import "fmt"

func countBits(n int) []int {
	ret := make([]int, n+1)
	for i := 1; i <= n; i++ {
		ret[i] = ret[i&(i-1)] + 1
	}
	return ret
}

func main() {
	fmt.Println(countBits(2))
	fmt.Println(countBits(5))
}
