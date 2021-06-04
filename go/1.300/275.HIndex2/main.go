package main

import "fmt"

func hIndex(citations []int) int {
	n := len(citations)
	end := n
	start := 0
	for start < end {
		mid := (end + start) / 2
		if citations[mid] < (n - mid) {
			start = mid + 1
		} else {
			end = mid
		}
	}
	return n - start
}

func main() {
	fmt.Println(hIndex([]int{0, 1, 3, 5, 6}), 3)
	fmt.Println(hIndex([]int{1, 1, 3}), 1)
}
