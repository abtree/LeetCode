package main

import "fmt"

func isBadVersion(version int) bool {
	return version >= 4
}

func firstBadVersion(n int) int {
	end := n
	start := 0
	for start < end {
		mid := (start + end) / 2
		if isBadVersion(mid) {
			end = mid
		} else {
			start = mid + 1
		}
	}
	return start
}

func main() {
	fmt.Println(firstBadVersion(5), 4)
}
