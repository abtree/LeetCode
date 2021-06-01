package main

import "fmt"

func countDigitOne(n int) int {
	cnt := 0
	for i := 1; i <= n; i *= 10 {
		div := i * 10
		cnt += (n/div)*i + min(max(n%div-i+1, 0), i)
	}
	return cnt
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func main() {
	fmt.Println(countDigitOne(13), 6)
	fmt.Println(countDigitOne(0), 0)
	fmt.Println(countDigitOne(1234), 689)
}
