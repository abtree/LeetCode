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

func abs(i int) int {
	if i < 0 {
		return -i
	}
	return i
}

func findMinMoves(machines []int) int {
	tot := 0
	n := len(machines)
	for _, v := range machines {
		tot += v
	}
	if tot%n > 0 {
		return -1
	}
	avg := tot / n
	sum, ans := 0, 0
	for _, v := range machines {
		v -= avg
		sum += v
		ans = max(ans, max(abs(sum), v))
	}
	return ans
}

func main() {
	fmt.Println(findMinMoves([]int{1, 0, 5}), 3)
	fmt.Println(findMinMoves([]int{0, 3, 0}), 2)
	fmt.Println(findMinMoves([]int{0, 2, 0}), -1)
}
