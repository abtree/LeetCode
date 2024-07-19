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

func findLUSlength(a string, b string) int {
	if a == b {
		return -1
	}
	return max(len(a), len(b))
}

func main() {
	fmt.Println(findLUSlength("aba", "cdc"), 3)
	fmt.Println(findLUSlength("aaa", "bbb"), 3)
	fmt.Println(findLUSlength("aaa", "aaa"), -1)
}
