package main

import "fmt"

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}

func predictTheWinner(nums []int) bool {
	size := len(nums) - 1
	var def func(pStart, pEnd, turn int) int
	def = func(pStart, pEnd, turn int) int {
		if pStart == pEnd {
			return nums[pStart] * turn
		}
		v1 := nums[pStart]*turn + def(pStart+1, pEnd, -turn)
		v2 := nums[pEnd]*turn + def(pStart, pEnd-1, -turn)
		if turn < 0 {
			return min(v1, v2)
		} else {
			return max(v1, v2)
		}
	}
	return def(0, size, 1) >= 0
}

func predictTheWinner1(nums []int) bool {
	size := len(nums)
	dp := make([][]int, size)
	for i, _ := range dp {
		dp[i] = make([]int, size)
	}
	for i := 0; i < size; i++ {
		dp[i][i] = nums[i]
	}
	for i := size - 2; i >= 0; i-- {
		for j := i + 1; j < size; j++ {
			dp[i][j] = max(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1])
		}
	}
	return dp[0][size-1] >= 0
}

func main() {
	fmt.Println(predictTheWinner([]int{1, 5, 2}), false)
	fmt.Println(predictTheWinner([]int{1, 5, 233, 7}), true)

	fmt.Println(predictTheWinner1([]int{1, 5, 2}), false)
	fmt.Println(predictTheWinner1([]int{1, 5, 233, 7}), true)
}
