package main

import "fmt"

func rob(nums []int) int {
	// size := len(nums)
	// if size == 0 {
	// 	return 0
	// }
	// if size == 1 {
	// 	return nums[0]
	// }
	// total1 := nums[0]
	// total2 := max(total1, nums[1])
	// for i := 2; i < size; i++ {
	// 	total1, total2 = total2, max(total1+nums[i], total2)
	// }
	total1, total2 := 0, 0
	for _, v := range nums {
		total1, total2 = total2, max(total1+v, total2)
	}
	return total2
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	fmt.Printf(" %d -> 4 \n", rob([]int{1, 2, 3, 1}))
	fmt.Printf(" %d -> 12 \n", rob([]int{2, 7, 9, 3, 1}))
	fmt.Printf(" %d -> 18 \n", rob([]int{9, 1, 1, 9}))
}
