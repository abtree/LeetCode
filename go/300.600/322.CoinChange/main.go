package main

import "fmt"

func coinChange(coins []int, amount int) int {
	if amount == 0 {
		return 0
	}
	repeated := map[int]struct{}{}
	queue := []int{}
	queue = append(queue, 0)
	ret := 0
	for len(queue) > 0 {
		nq := []int{}
		ret++
		for _, v := range queue {
			for _, c := range coins {
				c += v
				if _, ok := repeated[c]; ok {
					continue //重复
				}
				if c < amount {
					repeated[c] = struct{}{}
					nq = append(nq, c)
				} else if c == amount {
					return ret
				}
			}
		}
		queue = nq
	}
	return -1
}

func coinChange1(coins []int, amount int) int {
	top := amount + 1
	dp := make([]int, top)
	for i, _ := range dp {
		dp[i] = top
	}
	dp[0] = 0
	for i, _ := range dp {
		for _, c := range coins {
			if c <= i {
				dp[i] = min(dp[i], dp[i-c]+1)
			}
		}
	}
	if dp[amount] > amount {
		return -1
	}
	return dp[amount]
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}

func main() {
	fmt.Println(coinChange1([]int{186, 419, 83, 408}, 6249), 20)
	fmt.Println(coinChange1([]int{1, 2, 5}, 11), 3)
	fmt.Println(coinChange1([]int{2}, 3), -1)
	fmt.Println(coinChange1([]int{1}, 0), 0)
	fmt.Println(coinChange1([]int{1}, 1), 1)
	fmt.Println(coinChange1([]int{1}, 2), 2)
	fmt.Println(coinChange1([]int{1, 2, 5}, 100), 20)
}
