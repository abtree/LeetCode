package main

import (
	"fmt"
)

func isPowerOfThree(n int) bool {
	return n > 0 && 1162261467%n == 0
}

func isPowerOfThree1(n int) bool {
	if n == 1 {
		return true
	}
	i := 1
	p := 3
	queue := []int{}
	for i < n {
		queue = append(queue, p)
		if i*p == n {
			return true
		}
		if i*p > n {
			break
		}
		i *= p
		p *= p
	}
	for i < n {
		pos := 0
		if i*queue[pos] > n {
			return false
		}
		for _, v := range queue {
			if i*v == n {
				return true
			}
			if i*v > n {
				break
			}
			i *= v
		}
	}
	return false
}

func main() {
	fmt.Println(isPowerOfThree1(27), true)
	fmt.Println(isPowerOfThree1(3), true)
	fmt.Println(isPowerOfThree1(0), false)
	fmt.Println(isPowerOfThree1(9), true)
	fmt.Println(isPowerOfThree1(45), false)
}
