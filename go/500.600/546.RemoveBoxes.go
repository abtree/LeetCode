package main

import (
	"fmt"
)

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func removeBoxes(boxes []int) int {
	dp := [100][100][100]int{}
	var calculatePoints func(l, r, k int) int
	calculatePoints = func(l, r, k int) int {
		if l > r {
			return 0
		}
		r1, k1 := r, k
		for r1 > l && boxes[r1] == boxes[r1-1] {
			r1--
			k1++
		}
		if dp[l][r][k] == 0 {
			dp[l][r][k] = calculatePoints(l, r1-1, 0) + (k1+1)*(k1+1)
			for i := l; i < r1; i++ {
				if boxes[i] == boxes[r1] {
					dp[l][r][k] = max(dp[l][r][k], calculatePoints(i+1, r1-1, 0)+calculatePoints(l, i, k1+1))
				}
			}
		}
		return dp[l][r][k]
	}
	return calculatePoints(0, len(boxes)-1, 0)
}

func main() {
	fmt.Println(removeBoxes([]int{1, 3, 2, 2, 2, 3, 4, 3, 1}), 23)
	fmt.Println(removeBoxes([]int{1, 1, 1}), 9)
	fmt.Println(removeBoxes([]int{1}), 1)
}
