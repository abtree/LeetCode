package main

import (
	"fmt"
	"math"
)

func findRotateSteps(ring string, key string) int {
	n, m := len(ring), len(key)
	pos := make([][]int, 26)
	for i, c := range ring {
		pos[int(c-'a')] = append(pos[int(c-'a')], i)
	}
	dp := make([][]int, m)
	for i := range dp {
		dp[i] = make([]int, n)
		for j := range dp[i] {
			dp[i][j] = math.MaxInt
		}
	}
	for _, p := range pos[key[0]-'a'] {
		dp[0][p] = min(p, n-p) + 1
	}
	for i := 1; i < m; i++ {
		for _, j := range pos[key[i]-'a'] {
			for _, k := range pos[key[i-1]-'a'] {
				dp[i][j] = min(dp[i][j], dp[i-1][k]+min(abs(j-k), n-abs(j-k))+1)
			}
		}
	}
	return min(dp[m-1]...)
}

func min(a ...int) int {
	ret := a[0]
	for _, v := range a[1:] {
		if v < ret {
			ret = v
		}
	}
	return ret
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func main() {
	fmt.Println(findRotateSteps("caotmcaataijjxi", "oatjiioicitatajtijciocjcaaxaaatmctxamacaamjjx"), 137)
	fmt.Println(findRotateSteps("iotfo", "fioot"), 11)
	fmt.Println(findRotateSteps("abcde", "ade"), 6)
	fmt.Println(findRotateSteps("godding", "gd"), 4)
	fmt.Println(findRotateSteps("godding", "godding"), 13)
}
