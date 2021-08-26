package main

import "fmt"

func hammingWeight(num uint32) int {
	c := 0
	for i := 0; i < 32; i++ {
		if (num & 1) == 1 {
			c++
		}
		num >>= 1
	}
	return c
}

func main() {
	fmt.Printf("%d -> 3 \n", hammingWeight(11))
	fmt.Printf("%d -> 1 \n", hammingWeight(128))
	fmt.Printf("%d -> 31 \n", hammingWeight(4294967293))
}
