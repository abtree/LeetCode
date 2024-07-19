package main

import (
	"fmt"
)

func leastBricks(wall [][]int) int {
	n := len(wall)
	dp := map[int]int{}
	for _, w := range wall {
		s := len(w)
		t := 0
		for i := 0; i < s-1; i++ {
			t += w[i]
			dp[t]++
		}
	}
	m := 0
	for _, v := range dp {
		m = max(m, v)
	}
	return n - m
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func main() {
	fmt.Println(leastBricks([][]int{{1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2}, {2, 4}, {3, 1, 2}, {1, 3, 1, 1}}), 2)
	fmt.Println(leastBricks([][]int{{1}, {1}, {1}}), 3)
}
