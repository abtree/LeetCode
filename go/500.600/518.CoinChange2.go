package main

import (
	"fmt"
)

func change(amount int, coins []int) int {
	dp := make([]int, amount+1)
	dp[0] = 1
	for _, v := range coins {
		for i := v; i <= amount; i++ {
			dp[i] += dp[i-v]
		}
	}
	return dp[amount]
}

func main() {
	fmt.Println(change(5, []int{1, 2, 5}), 4)
	fmt.Println(change(3, []int{2}), 0)
	fmt.Println(change(10, []int{10}), 1)
}
