package main

import (
	"fmt"
)

func findComplement(num int) int {
	h := 0
	for i := 0; i <= 30; i++ {
		if num >= (1 << i) {
			h = i
		} else {
			break
		}
	}
	mask := (1 << (h + 1)) - 1
	return num ^ mask
}

func main() {
	fmt.Println(findComplement(2), 1)
	fmt.Println(findComplement(5), 2)
	fmt.Println(findComplement(1), 0)
}
