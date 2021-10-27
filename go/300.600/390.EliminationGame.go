package main

import (
	"fmt"
)

func lastRemaining(n int) int {
	//动态规划
	dp := make([]int, n+1)
	dp[1] = 1
	for i := 2; i <= n; i++ {
		if i&1 == 1 {
			dp[i] = dp[i-1]
		} else {
			dp[i] = 2 + i - 2*dp[i/2]
		}
	}
	return dp[n]
}

func lastRemaining1(n int) int {
	//递归
	if n == 1{
		return 1
	}
	if n&1 == 1{
		return lastRemaining1(n-1)
	}
	return 2+n-2*lastRemaining1(n/2)
}

func lastRemaining2(n int) int {
	//指针法
	start, step, islr := 1, 1, true
	for n > 1{
		if islr || n & 1 == 1{
			start += step;
		}
		step <<= 1
		n >>= 1
		islr = !islr
	}
	return start
}

func main() {
	fmt.Println(lastRemaining2(9), 6)
	fmt.Println(lastRemaining2(5), 2)
	fmt.Println(lastRemaining2(13), 6)
}