package main

import "fmt"

func arrayNesting(nums []int) int {
	n := len(nums)
	vistied := make([]bool, n)
	ans := 0
	for i := 0; i < n; i++ {
		cnt := 0
		for !vistied[nums[i]] {
			vistied[nums[i]] = true
			i = nums[i]
			cnt++
		}
		ans = max(ans, cnt)
	}
	return ans
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func main() {
	fmt.Println(arrayNesting([]int{5, 4, 0, 3, 1, 6, 2}), 4)
	fmt.Println(arrayNesting([]int{0, 1, 2}), 1)
}
