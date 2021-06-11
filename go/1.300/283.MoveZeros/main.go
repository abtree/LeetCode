package main

import "fmt"

func moveZeroes(nums []int) {
	i := 0
	for j, v := range nums {
		if v == 0 {
			continue
		}
		if i < j {
			nums[i], nums[j] = v, 0
		}
		i++
	}
}

func main() {
	ret := []int{0, 1, 0, 3, 12}
	moveZeroes(ret)
	fmt.Println(ret)
}
