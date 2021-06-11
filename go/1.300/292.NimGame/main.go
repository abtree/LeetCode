package main

import "fmt"

func canWinNim(n int) bool {
	return n%4 != 0
}

func canWinNim2(n int) bool {
	if n < 4 {
		return true
	}
	b1, b2, b3 := true, true, true
	for i := 4; i <= n; i++ {
		b1, b2, b3 = b2, b3, !(b1 && b2 && b3)
	}
	return b3
}

func main() {
	fmt.Println(canWinNim2(2), true)
	fmt.Println(canWinNim2(4), false)
	fmt.Println(canWinNim2(7), true)
	fmt.Println(canWinNim2(23), true)
	fmt.Println(canWinNim2(40), false)
}
