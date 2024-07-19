package main

import (
	"fmt"
)

func magicalString(n int) int {
	if n < 4 {
		return 1
	}
	dp := make([]byte, n)
	dp[0] = '1'
	dp[1] = '2'
	dp[2] = '2'
	ret := 1
	i := 2
	j := 3
	for j < n {
		size := dp[i] - '0'
		c := byte('1')
		if dp[j-1] == '1' {
			c = '2'
		}
		for size > 0 && j < n {
			dp[j] = c
			if c == '1' {
				ret++
			}
			j++
			size--
		}
		i++
	}
	return ret
}

func main() {
	fmt.Println(magicalString(6), 3)
	fmt.Println(magicalString(1), 1)
}
