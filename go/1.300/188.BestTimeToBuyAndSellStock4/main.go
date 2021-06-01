package main

import "fmt"

func maxProfit(k int, prices []int) int {
	if k == 0 || len(prices) == 0 {
		return 0
	}
	buys := make([]int, k)
	sells := make([]int, k)
	for i := 0; i < k; i++ {
		buys[i] = -prices[0]
	}
	for i := 1; i < len(prices); i++ {
		for j := k - 1; j > 0; j-- {
			sells[j] = max2(sells[j], buys[j]+prices[i])
			buys[j] = max2(buys[j], sells[j-1]-prices[i])
		}
		sells[0] = max2(sells[0], buys[0]+prices[i])
		buys[0] = max2(buys[0], -prices[i])
	}
	return maxs(sells...)
}

func max2(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func maxs(a ...int) int {
	max := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > max {
			max = a[i]
		}
	}
	return max
}

func main() {
	fmt.Printf("%d -> 2 \n", maxProfit(2, []int{2, 4, 1}))
	fmt.Printf("%d -> 7 \n", maxProfit(2, []int{3, 2, 6, 5, 0, 3}))
}
