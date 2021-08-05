package main

import "fmt"

func isPowerOfFour(n int) bool {
	return n > 0 && (n&(n-1)) == 0 && (n&0xaaaaaaaa) == 0
}

func main() {
	fmt.Println(isPowerOfFour(8), false)
	fmt.Println(isPowerOfFour(2), false)
	fmt.Println(isPowerOfFour(16), true)
	fmt.Println(isPowerOfFour(5), false)
	fmt.Println(isPowerOfFour(1), true)
}
