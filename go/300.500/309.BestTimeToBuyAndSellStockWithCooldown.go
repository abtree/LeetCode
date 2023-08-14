package main

import "fmt"

func maxProfit(prices []int) int {
	n := len(prices)
	if n < 2 {
		return 0
	}
	buy := make([]int, n)
	sell := make([]int, n)
	buy[0] = -prices[0]
	buy[1] = max(buy[0], -prices[1])
	sell[1] = max(buy[0]+prices[1], 0)
	for i := 2; i < n; i++ {
		buy[i] = max(sell[i-2]-prices[i], buy[i-1])
		sell[i] = max(sell[i-1], buy[i-1]+prices[i])
	}
	return max(buy[n-1], sell[n-1])
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func main() {
	fmt.Println(maxProfit([]int{1, 2, 3, 0, 2}), 3)
}
