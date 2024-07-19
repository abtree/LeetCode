package main

import "fmt"

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func findMaxConsecutiveOnes(nums []int) int {
	last, m := 0, 0
	for _, v := range nums {
		if v == 0 {
			last = 0
		} else {
			last++
			m = max(m, last)
		}
	}
	return m
}

func main() {
	fmt.Println(findMaxConsecutiveOnes([]int{1, 1, 0, 1, 1, 1}), 3)
	fmt.Println(findMaxConsecutiveOnes([]int{1, 0, 1, 1, 0, 1}), 2)
}
