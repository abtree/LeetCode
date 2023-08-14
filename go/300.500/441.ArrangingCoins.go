package main

import "fmt"

func arrangeCoins(n int) int {
	start, end := 1, n
	for end-start > 1 {
		mid := (start + end) / 2
		x := mid * (mid + 1) / 2
		if x == n {
			return mid
		}
		if x < n {
			start = mid
		} else {
			end = mid
		}
	}
	return start
}

func main() {
	fmt.Println(arrangeCoins(987654321), 44443)
	fmt.Println(arrangeCoins(5), 2)
	fmt.Println(arrangeCoins(8), 3)
}
