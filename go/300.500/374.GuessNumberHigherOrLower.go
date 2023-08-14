package main

import "fmt"

var pick int

func guess(num int) int {
	if num < pick {
		return 1
	}
	if num > pick {
		return -1
	}
	return 0
}

func guessNumber(n int) int {
	s := 1
	for s < n {
		mid := s + (n-s)/2
		r := guess(mid)
		if r == 0 {
			return mid
		}
		if r > 0 {
			s = mid + 1
		} else {
			n = mid - 1
		}
	}
	return s
}

func main() {
	pick = 6
	fmt.Println(guessNumber(10), 6)
	pick = 1
	fmt.Println(guessNumber(1), 1)
	pick = 1
	fmt.Println(guessNumber(2), 1)
	pick = 2
	fmt.Println(guessNumber(2), 2)
}
