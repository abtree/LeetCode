package main

import (
	"fmt"
)

func findSubstringInWraproundString(s string) int {
	dp := [26]int{}
	k := 0
	for i, ch := range s {
		p := int(ch)
		if i > 0 && (p-int(s[i-1]) == 1 || p-int(s[i-1]) == -25) {
			k++
		} else {
			k = 1
		}
		dp[p-int('a')] = max(dp[p-int('a')], k)
	}
	sum := 0
	for _, x := range dp {
		sum += x
	}
	return sum
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func main() {
	fmt.Println(findSubstringInWraproundString("a"), 1)
	fmt.Println(findSubstringInWraproundString("cac"), 2)
	fmt.Println(findSubstringInWraproundString("zab"), 6)
}
