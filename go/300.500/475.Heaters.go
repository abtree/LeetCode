package main

import (
	"fmt"
	"sort"
)

func abs(d int) int {
	if d < 0 {
		return -d
	}
	return d
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func findRadius(houses []int, heaters []int) int {
	sort.Ints(houses)
	sort.Ints(heaters)

	size := len(heaters)
	j := 0
	ma := 0
	for _, v := range houses {
		dis := abs(v - heaters[j])
		for j+1 < size && dis >= abs(v-heaters[j+1]) {
			j++
			dis = abs(v - heaters[j])
		}
		ma = max(ma, dis)
	}
	return ma
}

func main() {
	fmt.Println(findRadius([]int{1, 1, 1, 1, 1, 1, 999, 999, 999, 999, 999}, []int{499, 500, 501}), 498)
	fmt.Println(findRadius([]int{1, 2, 3}, []int{2}), 1)
	fmt.Println(findRadius([]int{1, 2, 3, 4}, []int{1, 4}), 1)
	fmt.Println(findRadius([]int{1, 5}, []int{2}), 3)
}
