package main

import (
	"fmt"
	"math"
)

func integerReplacement(n int) int {
	if n <= 1{
		return 0;
	}
	if n == math.MaxInt32{
		return 32;
	}
	if n&1==1{
		return min(integerReplacement(n+1), integerReplacement(n-1))+1
	}else{
		return integerReplacement(n>>1)+1
	}
}

func min(i, j int) int{
	if i< j{
		return i
	}
	return j
}

func main() {
	fmt.Println(integerReplacement(math.MaxInt32), 32)
	fmt.Println(integerReplacement(200000000), 32)
	fmt.Println(integerReplacement(8), 3)
	fmt.Println(integerReplacement(7), 4)
	fmt.Println(integerReplacement(4), 2)
}