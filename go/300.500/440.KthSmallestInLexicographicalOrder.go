package main

import "fmt"

func findKthNumber(n int, k int) int {
	k--
	curr := 1
	fnsteps := func(curr int) int {
		step := 0
		first, last := curr, curr
		for first <= n {
			step += min(last, n) - first + 1
			first *= 10
			last = last*10 + 9
		}
		return step
	}

	for k > 0 {
		step := fnsteps(curr)
		if step <= k {
			k -= step
			curr++
		} else {
			k--
			curr *= 10
		}
	}
	return curr
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}

func main() {
	fmt.Println(findKthNumber(10, 3), 2)
	fmt.Println(findKthNumber(596516650, 593124772), 96947306)
	fmt.Println(findKthNumber(13, 2), 10)
	fmt.Println(findKthNumber(1, 1), 1)
}
